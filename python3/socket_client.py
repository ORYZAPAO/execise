# coding: utf-8
#
# Network Socket クライアント
#

import socket

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    # サーバを指定
    s.connect(('192.168.10.1', 88))
    # サーバにメッセージを送る
    s.sendall(b'COM WAKEUP')
    # ネットワークのバッファサイズは1024。サーバからの文字列を取得する
    data = s.recv(1024)
    #
    print(repr(data))
