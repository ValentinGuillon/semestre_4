#Serveur

import socket
import threading

HOST = "localhost" #"127.0.0.1"
PORT = 65432
LOCK = threading.RLock()


class ThreadClient(threading.Thread):
    def __init__(self, \
                 id:int, \
                 sckt_server:socket.socket, \
                 sckt_client:socket.socket, \
                 sckt_other_client:socket.socket):

        threading.Thread.__init__(self)
        self.id = id
        self.sckt_server:socket.socket = sckt_server
        self.sckt_client:socket.socket = sckt_client
        self.sckt_other_client:socket.socket = sckt_other_client



    def run(self):
        self.listen_messages()


    def listen_messages(self):
        while True:
            message = self.sckt_client.recv(1024)
            message = str(message, 'utf-8') #décode message
            if message == "<client disconnected>":
                print(f"client {self.id} s'est déconnecté-é")
                self.send_message("<s'est déconnecté-e>")
                break
            print(f"client {self.id}: {message}")

            #envoyer le message à l'autre client
            self.send_message(message)

        self.sckt_client.close()
        


    def send_message(self, msg):
        msg = bytes(msg, 'utf-8') #décode message
        self.sckt_other_client.sendall(msg)





def main():
    #initialisation du socket
    sckt = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sckt.bind((HOST,PORT))
    print("Socket créée")

    #connexions des clients
    sckt.listen()
    print("Attente des 2 clients...")

    sckt_cl1, _adress = sckt.accept()
    print("Client 1 connecté-e...")
    sckt_cl2, _adress = sckt.accept()
    print("Les 2 clients sont connecté-e-s:")



    #listen clients' messages
    thrd_cl1 = ThreadClient(1, sckt, sckt_cl1, sckt_cl2)
    thrd_cl2 = ThreadClient(2, sckt, sckt_cl2, sckt_cl1)

    thrd_cl1.start()
    thrd_cl2.start()

    thrd_cl1.send_message('<ready>')
    thrd_cl2.send_message('<ready>')

    thrd_cl1.join()
    thrd_cl2.join()
    
    print("Déconnection des clients")
    sckt_cl1.close()
    sckt_cl2.close()



if __name__ == "__main__":
    main()