
import tkinter as tk

import socket
import threading
import time
from typing import Literal

import common_lib

LOCK = threading.RLock()

INTERFACE_NAME = "Quick Tchat"
DISPLAY_TIME = True

THREAD_RUNNING = False


def switch_THREAD_RUNNING():
    global THREAD_RUNNING
    if THREAD_RUNNING:
        THREAD_RUNNING = False
    else:
        THREAD_RUNNING = True


class Quick_Tchat(tk.Tk):
    def __init__(self):
        tk.Tk.__init__(self)
        self.sckt:socket.socket = None
        self.thr_listen:threading.Thread

        self.name:str = ""
        self.id:int = 0
        self.nb_connected:int = 0 #including this instance

        self.connected = False


        #window parameters
        self.title(INTERFACE_NAME)
        self.geometry('400x500')
        self.config(bg='orange')


        self.rowconfigure(0, weight=1)
        self.columnconfigure(0, weight=1)

        self.interface_disconnected()



    def swich_DISPLAY_TIME(self):
        global DISPLAY_TIME
        if DISPLAY_TIME:
            DISPLAY_TIME = False
        else:
            DISPLAY_TIME = True
        self.update_interface_connected()




    def interface_disconnected(self, to_destroy:tk.Frame = None):
        self.disconnect()

        if to_destroy:
            to_destroy.destroy()
        
        self.title(INTERFACE_NAME)

        self.discon_interf = tk.Frame(self, bg='orange')
        for i in range(6):
            self.discon_interf.rowconfigure(i, weight=1)
        self.discon_interf.columnconfigure(0, weight=1)

        self.var_name = tk.StringVar()

        self.entry_name = tk.Entry(self.discon_interf, textvariable=self.var_name, justify='center')
        self.label_info = tk.Label(self.discon_interf, bg='orange', justify='center')
        self.btn_connect = tk.Button(self.discon_interf, text='Connect', command=lambda:self.interface_connected(self.var_name.get(), self.discon_interf))
        self.btn_exit = tk.Button(self.discon_interf, text='Exit', command=self.destroy)

        self.discon_interf.grid()
        self.entry_name.grid(row=1, column=0)
        self.btn_connect.grid(row=2, column=0)
        self.label_info.grid(row=3, column=0)
        self.btn_exit.grid(row=4, column=0)

        self.entry_name.focus_set()

        self.bind("<Return>", lambda e: self.interface_connected(self.var_name.get(), self.discon_interf))
        self.bind("<Escape>", lambda e: self.destroy())

        


    def start_reset_label_info_thread(self):
        self.reset_lab_info = threading.Thread(target=self.reset_label_info)
        self.reset_lab_info.start()

    def reset_label_info(self):
        if THREAD_RUNNING:
            return
        with LOCK:
            switch_THREAD_RUNNING()
            if self.connected:
                switch_THREAD_RUNNING()
                return
            time.sleep(2)
            if self.connected:
                switch_THREAD_RUNNING()
                return
            if self.label_info:
                self.label_info.config(text="")
            switch_THREAD_RUNNING()


    def update_interface_connected(self):
        if not self.connected:
            return

        if self.nb_connected >= 2:
            self.send_button.config(state='normal')
            self.input_space.config(state='normal')
            self.input_space.focus_set()
            self.bind("<Return>", lambda e: self.send_message(self.txt.get()))

        else:
            self.send_button.config(state='disabled')
            self.input_space.config(state='disabled')
            self.unbind("<Return>")


        self.lab_nb_connected.config(text=f"Connected: {self.nb_connected}")
        if DISPLAY_TIME:
            self.btn_show_hide_date.config(text=f"Date\nON")
        else:
            self.btn_show_hide_date.config(text=f"Date\nOFF")
        
        self.bind("<Escape>", lambda e: self.interface_disconnected(self.connect_interf))




    def interface_connected(self, name:str, to_destroy:tk.Frame = None):
        if not self.connect(name):
            return

        if to_destroy:
            to_destroy.destroy()


        self.title(INTERFACE_NAME + " - " + self.name)
        #interface
        self.connect_interf = tk.Frame(self, bg='orange')

        # === WIDGETS CREATION/CONFIG ===
        #infos space
        self.lab_nb_connected = tk.Label(self.connect_interf, bg="orange")
        self.btn_show_hide_date = tk.Button(self.connect_interf, command=self.swich_DISPLAY_TIME)


        #messages space
        self.tchat = tk.Text(self.connect_interf, bg='green', width=40, height=20, state='disabled')
        tchat_scroll = tk.Scrollbar(self.connect_interf, orient=tk.VERTICAL)

        tchat_scroll.config(command=self.tchat.yview)
        self.tchat.config(yscrollcommand=tchat_scroll.set)

        self.tchat.tag_configure('right', justify='right')
        self.tchat.tag_configure('left', justify='left')
        self.tchat.tag_configure('center', justify='center')


        #messages' user's inputs
        self.text_bar = tk.Frame(self.connect_interf, bg='pink')
        
        self.txt = tk.StringVar()
        self.input_space = tk.Entry(self.text_bar, textvariable=self.txt, state='disabled')
        self.send_button = tk.Button(self.text_bar, text='SEND', state='disabled', command=lambda:self.send_message(self.txt.get()))
        self.disconnect_button = tk.Button(self.text_bar, text='EXIT', command=lambda:self.interface_disconnected(self.connect_interf))




        # === WIDGETS PLACEMENT ===
        #global frames
        self.connect_interf.grid()
        self.text_bar.grid(row=2, column=0, columnspan=4)

        #infos space
        self.lab_nb_connected.grid(row=0, column=0, columnspan=3)
        self.btn_show_hide_date.grid(row=0, column=3)

        #messages space=
        self.tchat.grid(row=1, column=0, columnspan=4)
        # tchat_scroll.pack(side='right')

        #messages' user's inputs
        self.disconnect_button.grid(row=0, column=0)
        self.input_space.grid(row=0, column=1)
        self.send_button.grid(row=0, column=2)




        self.update_interface_connected()

        msg = common_lib.formate_message("<connected>")
        current_time = common_lib.extract_from_formated_msg(msg, "time")
        self.create_msg_box("<connected>", current_time)


        #listen incoming messages
        self.thr_listen = threading.Thread(target=self.listen)
        self.thr_listen.start()

        




    def disconnect(self):
        if not self.sckt:
            return

        common_lib.send_message('<client disconnection>', self.sckt, self.id, self.name)
        self.connected = False
        self.thr_listen = None
        print("\nDisconnected")




    def connect(self, name:str) -> bool:
        name_incorrect = True
        if not name:
            self.label_info.config(text="<Give a name to connect>")
        elif common_lib.SPLITER in name:
            self.label_info.config(text=f"<Name has illegal character ({common_lib.SPLITER})>")
        elif len(name) > 15:
            self.label_info.config(text=f"<Name is too long (max 15)>")
        else:
            name_incorrect = False

        if name_incorrect:
            self.start_reset_label_info_thread()
            return False

	
        #initiate socket
        self.sckt = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

        try:
            print("\nEtablishing connection...")
            self.sckt.connect((common_lib.HOST, common_lib.PORT))
            #send name
            self.name = name
            common_lib.send_message(name, self.sckt, 0, " ")

            #receive id
            msg = self.sckt.recv(1024)
            msg = str(msg, 'utf-8')
            new_id = int(common_lib.extract_from_formated_msg(msg, "msg"))
            self.id = new_id

            #received nb_connected
            msg = self.sckt.recv(1024)
            msg = str(msg, 'utf-8')
            nb_connected = int(common_lib.extract_from_formated_msg(msg, "msg"))
            self.nb_connected = nb_connected

            print(f'Connection successful to server "{common_lib.HOST}"')
        except:
            print(f'Connection failed to server "{common_lib.HOST}"')
            self.label_info.config(text="<Connection failed>")
            self.start_reset_label_info_thread()
            return False

        self.connected = True
        return True





    def send_message(self, msg:str):
        if not msg:
            return
        
        self.txt.set("")
        msg = common_lib.send_message(msg, self.sckt, self.id, self.name)



    def listen(self):
        while True:
            if not self.connected:
                break

            try:
                received_msg = str(self.sckt.recv(1024), 'utf-8')
                print("\nmsg received:", received_msg)
                if not received_msg:
                    continue

                sender_id = int(common_lib.extract_from_formated_msg(received_msg, "id"))
                sender_name = common_lib.extract_from_formated_msg(received_msg, "name")
                current_time = common_lib.extract_from_formated_msg(received_msg, "time")
                msg = common_lib.extract_from_formated_msg(received_msg, "msg")
                
                #message from any client
                if sender_id != 0:
                    self.create_msg_box(msg, current_time, sender_id, sender_name)
                    continue


                #message from server
                if sender_name == "<test>":
                    print("Test from server received")
                    msg = common_lib.send_message("<connected !>", self.sckt, self.id, self.name)
                elif "disconnection of" in sender_name:
                    self.nb_connected -= 1
                    if not int(sender_name.split("disconnection of ")[1]) == self.id:
                        self.create_msg_box(msg, current_time)
                elif "connection of" in sender_name:
                    self.nb_connected += 1
                    if not int(sender_name.split("connection of ")[1]) == self.id:
                        self.create_msg_box(msg, current_time)
                elif "server closed" in sender_name:
                    self.nb_connected = 0
                    self.create_msg_box(msg, current_time)
                    self.sckt.close()

                self.update_interface_connected()
 
            except OSError as o:
                print(o)
                self.interface_disconnected(self.connect_interf)




    def create_msg_box_time(self, current_time:str, side:Literal['left', 'center', 'right']):
        if DISPLAY_TIME:
            self.tchat.insert(tk.END, f'\n{current_time}', side)


    def create_msg_box(self, msg:str, current_time:str="", sender_id:int = 0, sender:str = "server"):
        if not msg:
            return

        self.tchat.config(state='normal')

        #message from server
        if sender_id == 0:
            self.create_msg_box_time(current_time, 'center')
            self.tchat.insert(tk.END, f'\n{msg}\n', 'center')

        #message from myself
        elif sender_id == self.id:
            self.create_msg_box_time(current_time, 'right')
            self.tchat.insert(tk.END, f'\nME:\n{msg}\n', 'right')

        #message from someone else
        else:
            self.create_msg_box_time(current_time, 'left')
            self.tchat.insert(tk.END, f'\n{sender}:\n{msg}\n', 'left')


        self.tchat.config(state='disabled')

        self.txt.set("")
        self.tchat.see(tk.END)




def main():
    win = Quick_Tchat()
    win.mainloop()


if __name__ == "__main__":
    main()

