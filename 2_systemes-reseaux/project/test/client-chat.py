#Client

import socket

HOST = "127.0.0.1"  #Adresse IP du serveur
PORT = 65432  #Le port utilisé par le serveur

sckt = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print("Socket créée")

msg = input("How to call you ?\n>")

sckt.connect((HOST, PORT))
print(f"Connecté au serveur {HOST}")
sckt.sendall(bytes(msg, 'utf-8'))


msg  = ""
while True:
    msg = input("msg > ")
    sckt.sendall(bytes(msg, 'utf-8'))
    if msg == 'exit':
        break
    # server_msg = sckt.recv(1024)
    # print(f"Serveur:  {str(server_msg,'utf-8')}")
sckt.close()
print("Déconnexion")