#Serveur

import socket
import threading
import time

import common_lib


STOP_PROG = False

ID = 0 #increases for each new connection
NB_CONNECTED = -1 #the first connexion increases it by 2 (don't know why omg)

# CLIENTS:dict[int, ThreadClient] = {} #redefine later


def set_ID(new_val:int):
    global ID
    ID = new_val

def set_NB_CONNECTED(new_val:int):
    global NB_CONNECTED
    NB_CONNECTED = new_val






class ThreadClient(threading.Thread):
    def __init__(self, id:int, name:str, sckt:socket.socket):
        threading.Thread.__init__(self)
        self.id = id
        self.name = name
        self.sckt:socket.socket = sckt


    def run(self):
        self.listen_messages()


    def get_socket(self) -> socket.socket:
        return self.sckt

    def get_name(self) -> str:
        return self.name



    def listen_messages(self):
        try:
            while True:
                receved_msg = self.sckt.recv(1024)
                receved_msg = str(receved_msg, 'utf-8') #décode message
                # sender_id = int(common_lib.extract_from_formated_msg(receved_msg, "id"))
                # current_time = common_lib.extract_from_formated_msg(receved_msg, "time")
                sender_name = common_lib.extract_from_formated_msg(receved_msg, "name")
                msg = common_lib.extract_from_formated_msg(receved_msg, "msg")

                if msg == "<client disconnection>":
                    disconnect_client(self.id, "<disconnection>")
                    break

                print(f"\n{sender_name}: {msg}")

                #envoyer le message aux autres clients
                send_message_to_all(msg, self.id)

            self.sckt.close()
        except:
            return





CLIENTS:dict[int, ThreadClient] = {}




def fake_connection():
    last_sckt = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    last_sckt.connect((common_lib.HOST, common_lib.PORT))
    last_sckt.close()




def wait_close_input():
    while True:
        a = str(input("At any moment, type \"CLOSE\" to close the server.\n"))
        if a == "CLOSE":
            break
    global STOP_PROG
    STOP_PROG = True





def test_new_socket(sckt:socket.socket) -> bool:
    common_lib.send_message("connected ?", sckt, 0, "<test>")
    answer = str(sckt.recv(1024), 'utf-8')
    answer = common_lib.extract_from_formated_msg(answer, "msg")
    if answer == "<connected !>":
        return True
    return False



def listen_for_new_client(sckt:socket.socket):
    global CLIENTS

    sckt.listen()

    while True:
        if STOP_PROG:
            break
        try:
            sckt_cl, _adress = sckt.accept()
            if STOP_PROG:
                break
            print("\nconnection incoming...")

            #waiting message containing the client name
            name_cl = str(sckt_cl.recv(1024), 'utf-8')
            name_cl = common_lib.extract_from_formated_msg(name_cl, "msg")


            #add the client to the dict
            set_ID(ID+1)
            set_NB_CONNECTED(NB_CONNECTED+1)
            thread_cl = ThreadClient(ID, name_cl, sckt_cl)
            CLIENTS.__setitem__(ID, thread_cl)

            #send an ID to the client
            common_lib.send_message(ID, sckt_cl, 0, " ")
            #send nb of connected to the client
            common_lib.send_message(NB_CONNECTED, sckt_cl, 0, " ")
            

            if not test_new_socket(sckt_cl):
                print("Test failed,  connection failed")
                continue
            print("Test passed")

            thread_cl.start()
            print(f"Connection of {name_cl} (id={ID})")
            send_message_to_all(f'<{name_cl} has connected>', server_indication=f"connection of {ID}")
        except Exception as e:
            print("Imcoming connection failed and canceled")
            print(e)
            del CLIENTS[ID]





def disconnect_client(key:int, reason:str):
    global CLIENTS

    print("\ndisconnection of client:", key)
    print(CLIENTS)
    discon_name:str = CLIENTS[key].get_name()
    discon_sckt:socket.socket = CLIENTS[key].get_socket()


    if reason == "<server closed>":
        common_lib.send_message(reason, discon_sckt, 0, reason)
        CLIENTS.pop(key)
    else:
        CLIENTS.pop(key)
        send_message_to_all(f'<{discon_name} has disconnected>', server_indication=f"disconnection of {key}")

    set_NB_CONNECTED(NB_CONNECTED-1)
    discon_sckt.close()
    print(CLIENTS)



def send_message_to_all(msg:str, sender:int = 0, server_indication:str = ""):
    for _key, client in CLIENTS.items():
        name = ""
        sckt = client.get_socket()

        # message from server
        if sender == 0:
            name = server_indication
        # message from a client
        else:
            name = CLIENTS[sender].get_name()

        common_lib.send_message(msg, sckt, sender, name)
























def main():
    #socket initialisation
    sckt = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sckt.bind((common_lib.HOST,common_lib.PORT))
    print("Socket initiated")



    #listen to clients connection
    listen_arrivals = threading.Thread(target=listen_for_new_client, args=(sckt,))
    listen_arrivals.start()

    #create and start thread that allow to close server via a defined input
    stop = threading.Thread(target=wait_close_input)
    stop.start()
    stop.join()

    #server closed by the user

    #stop listening for new connections
    fake_connection()

    #disconnect all remaining clients
    for key in list(CLIENTS.keys()):
        disconnect_client(key, "<server closed>")


    sckt.close()
    print("\nServer has closed")


if __name__ == "__main__":
    main()
