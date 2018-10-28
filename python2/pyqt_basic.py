#coding:utf-8
"""
最小のプログラムでウィンドウを表示させるためのプログラム
"""
import sys
from PyQt4 import QtGui
#from PyQt4.QtGui import *
#from PyQt4.QtCore import *

##class Example(QtGui.QMainWindow): ## QMainWindow?
class Example(QtGui.QWidget):
    def __init__(self):
        super(Example, self).__init__()
        self.initUI()

    def initUI(self):
        
        title     = QtGui.QLabel('Title')
        titleEdit = QtGui.QLineEdit()

        layout = QtGui.QVBoxLayout()
        layout.addWidget(title)
        layout.addWidget(titleEdit)

        self.groupBox = QtGui.QGroupBox("Header")
        orivbox = QtGui.QVBoxLayout()
        orivbox.addLayout(layout)

        self.setLayout(orivbox) 
        self.show()
        
        print("k")
        
def main():
    app = QtGui.QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())

    
if __name__ == "__main__":
    main()
