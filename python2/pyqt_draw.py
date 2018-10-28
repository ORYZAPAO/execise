#coding:utf-8
"""
四角を描く
"""
from PyQt4 import QtGui
from PyQt4.QtCore import *
#from PyQt4.QtGui import *
import sys


class Widget(QtGui.QWidget):
    def __init__(self, parent=None):
        super(Widget, self).__init__(parent)
        self.setGeometry(300, 300, 300, 300)

    def paintEvent(self, event):
        painter = QtGui.QPainter(self)
        painter.begin(self)
        painter.setPen(Qt.red)
        painter.setBrush(Qt.yellow)
        painter.drawRect(10, 10, 100, 100)
        painter.end()
        print("pp")

def main():
    app = QtGui.QApplication(sys.argv)
    w = Widget()
    w.show()
    w.raise_()
    app.exec_()

if __name__ == '__main__':
    main()
    
