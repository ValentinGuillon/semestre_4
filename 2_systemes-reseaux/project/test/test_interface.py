
from typing import Literal
import tkinter as tk



class Interface(tk.Tk):
    def __init__(self):
        tk.Tk.__init__(self)

        #window parameters
        self.title('Quick Tchat')
        self.geometry('400x415')
        self.config(bg='orange')


        self.rowconfigure(0, weight=1)
        self.columnconfigure(0, weight=1)

        self.discon_interf = tk.Frame(self)
        self.discon_interf.rowconfigure(0, weight=1)
        self.discon_interf.columnconfigure(0, weight=1)

        self.btn_connect = tk.Button(self.discon_interf, text='Connect', command=self.connect)
        self.btn_exit = tk.Button(self.discon_interf, text='Exit', command=self.destroy)
        self.bind('<Return>', lambda e:self.connect())

        self.discon_interf.grid()
        self.btn_connect.grid(row=0, column=0)
        self.btn_exit.grid(row=2, column=0)




    def disconnect(self):
        self.connect_interf.destroy()
        self.unbind('<Escape>')
        self.unbind('<Up>')
        self.unbind('<Down>')

        self.discon_interf = tk.Frame(self, bg='orange')
        for i in range(3):
            self.discon_interf.rowconfigure(i, weight=1)
        self.discon_interf.columnconfigure(0, weight=1)

        self.btn_connect = tk.Button(self.discon_interf, text='Connect', command=self.connect)
        self.btn_exit = tk.Button(self.discon_interf, text='Exit', command=self.destroy)
        self.bind('<Return>', lambda e:self.connect())

        self.discon_interf.grid()
        self.btn_connect.grid(row=0, column=0)
        self.btn_exit.grid(row=2, column=0)




    def connect(self):
        self.discon_interf.destroy()

        self.connect_interf = tk.Frame(self, bg='orange')
        self.bind('<Escape>', lambda e:self.disconnect())

        self.connect_interf.rowconfigure(0, weight=1)
        self.connect_interf.rowconfigure(1, weight=1)
        self.connect_interf.columnconfigure(0, weight=1)

        # === WIDGETS CREATION/CONFIG ===
        #messages space
        self.msgs_space = tk.Frame(self.connect_interf, bg='blue')

        self.tchat = tk.Text(self.msgs_space, bg='green', width=40, height=20, state='disabled')
        tchat_scroll = tk.Scrollbar(self.msgs_space, orient=tk.VERTICAL)

        tchat_scroll.config(command=self.tchat.yview)
        self.tchat.config(yscrollcommand=tchat_scroll.set)

        self.tchat.tag_configure('right', justify='right')
        self.tchat.tag_configure('left', justify='left')


        #messages' user's inputs
        self.text_bar = tk.Frame(self.connect_interf, bg='pink')
        
        self.txt = tk.StringVar()
        self.input_space = tk.Entry(self.text_bar, textvariable=self.txt)
        self.send_button = tk.Button(self.text_bar, text='SEND', command=lambda:self.create_msg_box("client", self.txt.get()))
        self.disconnect_button = tk.Button(self.text_bar, text='EXIT', command=self.disconnect)

        self.input_space.focus_set()
        self.bind('<Return>', lambda e:self.create_msg_box("client", self.txt.get()))
        self.bind('<Up>', lambda e:self.tchat.yview_scroll(-1, 'units'))
        self.bind('<Down>', lambda e:self.tchat.yview_scroll(1, 'units'))

        # === WIDGETS PLACEMENT ===
        self.connect_interf.grid()

        self.msgs_space.grid(row=0, column=0)
        self.tchat.pack(side='left')
        # tchat_scroll.pack(side='right')

        self.text_bar.grid(row=1, column=0)
        self.input_space.grid(column=1, row=0)
        self.send_button.grid(column=2, row=0)
        self.disconnect_button.grid(column=0, row=0)
    


    def create_msg_box(self, msg_from:Literal['client', 'server'], msg:str):
        if not msg:
            return

        # self.text = tk.Label(self.tchat, bg='red', text=msg)
        # self.text.pack(anchor='w', side='top')

        self.tchat.config(state='normal')

        if msg_from == 'client':
            self.tchat.insert(tk.END, msg+'\n', 'right')
        elif msg_from == 'server':
            self.tchat.insert(tk.END, msg+'\n', 'left')
        else:
            print(f'ERROR: in create_msg_box: no argument "{msg_from}"')

        self.tchat.config(state='disabled')

        self.txt.set("")
        self.tchat.see(tk.END)




def main():
    win = Interface()
    win.mainloop()


if __name__ == "__main__":
    main()