#Client

import socket
import threading

HOST = "localhost" #"127.0.0.1"  #Adresse IP du serveur
PORT = 65432  #Le port utilisé par le serveur
LOCK = threading.RLock()


class ThreadCommunication(threading.Thread):
    def __init__(self, sckt:socket.socket, func:str):
        threading.Thread.__init__(self)
        self.sckt:socket.socket = sckt
        self.func:str = func

    def run(self):
        if self.func == "listen":
            self.listen()
        elif self.func == "send":
            self.send_messages()


    def listen(self):
        while 1:
            try:
                server_msg = self.sckt.recv(1024)
                server_msg = str(server_msg,'utf-8') #décode message
                if server_msg:
                    print(f"\nServeur: {server_msg}\nmsg > ", end="")
            except:
                break

    def send_messages(self):
        while True:
            msg = input("msg > ")
            self.sckt.sendall(bytes(msg, 'utf-8'))
            if msg == 'exit':
                break






def main():
    sckt = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print("Socket créée")

    # msg = input("How to call you ?\n>")

    sckt.connect((HOST, PORT))
    print(f"Connecté au serveur {HOST}")
    # sckt.sendall(bytes(msg, 'utf-8'))


    #communication

    #écoute de messages
    thr_listen = ThreadCommunication(sckt, "listen")
    #envoie de messages
    thr_send = ThreadCommunication(sckt, "send")

    thr_listen.start()
    thr_send.start()

    thr_send.join()
    #pas besoin d'attendre listen


    sckt.close()
    print("Déconnexion")


if __name__ == "__main__":
    main()
