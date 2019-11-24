import socket
import time
from sys import exit
import random
#from signal import signal, SIGPIPE, SIG_DFL 

#signal(SIGPIPE,SIG_DFL) 
#print(socket.gethostname())
#print(socket.gethostbyname('en0'))

HOST = ''  # Standard loopback interface address (localhost)
PORT = 40000 #random.randrange(1025,65535)    # Port to listen on (non-privileged ports are > 1023)
print(str(PORT)+"\n")
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    s.bind((HOST, PORT))
    s.listen()
    count = 0
    while True:
        conn, addr = s.accept()
        with conn:
            print('Connected by', addr)
            if True: 	#RUNS AND SENDS DATA ONE TIME
                #data = conn.recv(1024)
                string = str(count) + ':45:3:4'
                #if not data:
                #   break
                conn.send(string.encode('utf-8'))
                print(count)            
                count += 1
            conn.close()		#CLOSE THE CONNECTION
s.close()				#CLOSE THE SOCKET
 

        #print(data.decode())
