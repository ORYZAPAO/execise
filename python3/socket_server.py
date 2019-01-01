# -*- coding:utf-8 -*-
#
# (引用もと) https://qiita.com/msrks/items/0550603efc59f6e8ba09
#

import socket
from datetime import datetime
from time import sleep

s = socket.socket()

port = 88


s.bind(('', port))

while True:
    print('listening')
    s.listen(5)
    c, addr = s.accept()
    print('receiving')
    print(c.recv(4096))
    while True:
        print('sending')
        now = datetime.now().strftime("%Y/%m/%d %H:%M:%S")
        try:
            c.send(now)
        except:
            break
        sleep(1)
    c.close()
s.close()
