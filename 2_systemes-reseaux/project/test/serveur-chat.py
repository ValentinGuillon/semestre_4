#Serveur

import socket

HOST = "127.0.0.1"
PORT = 65432

sckt = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sckt.bind((HOST,PORT))
print("Socket créée")
sckt.listen()
print("Attente de connexion...")
connexion, address = sckt.accept()

name = str(connexion.recv(1024), 'utf-8')

print(f"{name} est connecté-e")


msg = ""

while True:
        client_msg = connexion.recv(1024)
        if str(client_msg, 'utf-8') == 'exit':
            break
        print(f"{name}: {str(client_msg,'utf-8')}")
connexion.close()
print("Le client s'est déconnecté")