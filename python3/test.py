# -*- coding: utf-8 -*-
import sys

if( len(sys.argv) <= 1 ):
    print("Usage :")


def printFile(filename):
    with open(filename,"rb") as fl:
        linelist = fl.readlines()
        for line in linelist:
            line.rstrip("¥n")
            line = line[:-1]
            print(line)
    

    
filename = sys.argv[1]
printFile(filename)


    
