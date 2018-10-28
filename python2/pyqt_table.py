#coding:utf-8
"""
テーブル配置で、Pushボタンを配置
"""
import sys
from PyQt4 import QtGui
#from PyQt4.QtGui import *
#from PyQt4.QtCore import *

import PyQt4.QtCore as QtCore

class Example2(QtGui.QWidget):
    def __init__(self):
        super(Example2, self).__init__()
        self.initUI()

 
    def initUI(self):        
        btn = []
        for i in range(16):
            btn.append( QtGui.QPushButton(str(i)))

        self.connect(btn[0], QtCore.SIGNAL('clicked()'), self.btn0_Clicked)
        self.connect(btn[1], QtCore.SIGNAL('clicked()'), self.btn1_Clicked)
        self.connect(btn[2], QtCore.SIGNAL('clicked()'), self.btn2_Clicked)
        self.connect(btn[3], QtCore.SIGNAL('clicked()'), self.btn3_Clicked)
        self.connect(btn[4], QtCore.SIGNAL('clicked()'), self.btn4_Clicked)
        self.connect(btn[5], QtCore.SIGNAL('clicked()'), self.btn5_Clicked)
        self.connect(btn[6], QtCore.SIGNAL('clicked()'), self.btn6_Clicked)
        self.connect(btn[7], QtCore.SIGNAL('clicked()'), self.btn7_Clicked)
        self.connect(btn[8], QtCore.SIGNAL('clicked()'), self.btn8_Clicked)
        self.connect(btn[9], QtCore.SIGNAL('clicked()'), self.btn9_Clicked)
        self.connect(btn[10], QtCore.SIGNAL('clicked()'), self.btn10_Clicked)
        self.connect(btn[11], QtCore.SIGNAL('clicked()'), self.btn11_Clicked)
        self.connect(btn[12], QtCore.SIGNAL('clicked()'), self.btn12_Clicked)
        self.connect(btn[13], QtCore.SIGNAL('clicked()'), self.btn13_Clicked)
        self.connect(btn[14], QtCore.SIGNAL('clicked()'), self.btn14_Clicked)
        self.connect(btn[15], QtCore.SIGNAL('clicked()'), self.btn15_Clicked)


        ## Makeing Table GUI            
        table = QtGui.QTableWidget() ## テーブル配置のレイアウト
        table.setRowCount(4)         ## 縦方向に４マス
        table.setColumnCount(4)      ## 水平方向に４マス
        
        i=0
        vbox = QtGui.QVBoxLayout() ## 縦配置のレイアウト
        vbox.addStretch(1)
        for y in range(4):
            hbox = QtGui.QHBoxLayout()  ## 水平配置のレイアウト
            hbox.addStretch(1)
            for x in range(4):
                hbox.addWidget(btn[i])
                i=i+1
            vbox.addLayout(hbox)

        self.setLayout(vbox)
        self.setGeometry(300, 300, 300, 100)
        self.setWindowTitle('Number Table')    
 
        self.show()
        
        print("k")

    def btn0_Clicked(self):
        print("0")
 
    def btn1_Clicked(self):
        print("1")
 
    def btn2_Clicked(self):
        print("2")
 
    def btn3_Clicked(self):
        print("3")
 
    def btn4_Clicked(self):
        print("4")
 
    def btn5_Clicked(self):
        print("5")
 
    def btn6_Clicked(self):
        print("6")
 
    def btn7_Clicked(self):
        print("7")
 
    def btn8_Clicked(self):
        print("8")
 
    def btn9_Clicked(self):
        print("9")
 
    def btn10_Clicked(self):
        print("10")
 
    def btn11_Clicked(self):
        print("11")
 
    def btn12_Clicked(self):
        print("12")
 
    def btn13_Clicked(self):
        print("13")
 
    def btn14_Clicked(self):
        print("14")
 
    def btn15_Clicked(self):
        print("15")
 


        
def main():
    app = QtGui.QApplication(sys.argv)
    ex = Example2()
    sys.exit(app.exec_())

    
if __name__ == "__main__":
    main()
