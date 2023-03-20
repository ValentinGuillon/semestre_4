#Serveur

import socket

HOST = "127.0.0.1"
PORT = 65432

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((HOST,PORT))
print("Socket créée")
s.listen()
print("Reception des appels")
connexion, address = s.accept()
print(f"Connecté à {address}")
my_msg = ""
while True:
        client_msg = connexion.recv(1024)
        if str(client_msg, 'utf-8') == 'exit':
            break;
        print(f"Client:  {str(client_msg,'utf-8')}")
        my_msg = input("Serveur: ")
        connexion.sendall(bytes(my_msg, 'utf-8'))
connexion.close()
print("Le client s'est déconnecté")