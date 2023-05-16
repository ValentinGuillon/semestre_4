
import socket
from typing import Literal
import time

SPLITER:str = ":::"

HOST = "localhost" #"127.0.0.1"
PORT = 65432
# LOCK = threading.RLock()


def formate_message(raw_msg:str, sender_id:int = 0, sender_name:str = "server"):
    current_time = time.strftime("%d-%m-%y %Hh%M")
    return f"{sender_id}{SPLITER}{sender_name}{SPLITER}{current_time}{SPLITER}{raw_msg}"


#formate the received msg and send it to the socket
def send_message(raw_msg:str, connection:socket.socket, sender_id:int, sender_name:str):
    msg = formate_message(raw_msg, sender_id, sender_name)
    msg = bytes(msg, 'utf-8') #encode
    try:
        connection.sendall(msg)
    except:
        return


def extract_from_formated_msg(formated_msg:str, target:Literal["id", "name", "time", "msg"]) -> str:
    splited_msg:list = formated_msg.split(SPLITER)
    try:
        if target == "id":
            return splited_msg[0]
        elif target == "name":
            return splited_msg[1]
        elif target == "time":
            return splited_msg[2]
        elif target == "msg":
            return splited_msg[3]
    except:
        return ""
