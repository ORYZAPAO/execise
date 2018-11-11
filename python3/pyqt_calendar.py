# coding: utf-8
#
# QCalendarWidget,QHBoxLayout Sample
#

import sys
from PyQt5.QtWidgets import QApplication,QWidget,QCalendarWidget,QHBoxLayout
##from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QHBoxLayout

class ExampleWidget(QWidget):

    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        self.cal = QCalendarWidget()
        self.cal2 = QCalendarWidget()

        self.resize(640, 480)
        #self.move(300, 300)

        hbox = QHBoxLayout()
        hbox.addWidget(self.cal)
        hbox.addWidget(self.cal2)
        self.setLayout(hbox)

        self.setWindowTitle('sample')
        self.show()

if __name__ == '__main__':

    app = QApplication(sys.argv)
    ew = ExampleWidget()    
    sys.exit(app.exec_()) 
