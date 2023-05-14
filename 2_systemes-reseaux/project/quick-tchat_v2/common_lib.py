
import socket
from typing import Literal
import time

SPLITER:str = ":::"

HOST = "localhost" #"127.0.0.1"
PORT = 65432
# LOCK = threading.RLock()


def formate_message(raw_msg:str, sender:int = 0, name:str = "server"):
    current_time = time.strftime("%d-%m-%y %Hh%M")
    return f"{sender}{SPLITER}{name}{SPLITER}{current_time}{SPLITER}{raw_msg}"


#formate the received msg and send it to the socket
def send_message(raw_msg:str, sckt:socket.socket, sender_id:int, sender_name:str):
    msg = formate_message(raw_msg, sender_id, sender_name)
    msg = bytes(msg, 'utf-8') #encode
    try:
        sckt.sendall(msg)
    except:
        return


def extract_from_formated_msg(formated_msg:str, target:Literal["id", "name", "time", "msg"]) -> str:
    splited = formated_msg.split(SPLITER)
    try:
        if target == "id":
            return splited[0]
        elif target == "name":
            return splited[1]
        elif target == "time":
            return splited[2]
        elif target == "msg":
            return splited[3]
    except:
        return ""
