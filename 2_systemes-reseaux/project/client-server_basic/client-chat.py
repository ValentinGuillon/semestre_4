#Client

import socket

HOST = "127.0.0.1"  #Adresse IP du serveur
PORT = 65432  #Le port utilisé par le serveur

my_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print("Socket créée")
my_socket.connect((HOST, PORT))
print(f"Connecté au serveur {HOST}")
my_msg  = ""
while True:
    my_msg = input("Client : ")
    my_socket.sendall(bytes(my_msg, 'utf-8'))
    if my_msg == 'exit':
        break;
    server_msg = my_socket.recv(1024)
    print(f"Serveur:  {str(server_msg,'utf-8')}")
my_socket.close()
print("Déconnexion")