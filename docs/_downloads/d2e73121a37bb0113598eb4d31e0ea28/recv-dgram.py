#!/usr/bin/env python

import socket, sys, threading

def server(sock):    # thread start function
    while True:
        data = sock.recv(1024)
        print(data)

threads = []
for sockname in sys.argv[1:]:
    sock = socket.socket(socket.AF_UNIX, socket.SOCK_DGRAM)
    sock.bind(sockname)

    th = threading.Thread(target=server, args=(sock,))
    th.start()
    threads.append(th)

for th in threads:
    th.join()
