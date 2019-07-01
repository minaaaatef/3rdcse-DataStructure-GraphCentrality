import sys
from PyQt4 import QtGui, QtCore
from shutil import copyfile
from PyQt4.QtWebKit import QWebView
import subprocess
import os
from data import Data_Visualisation
import webbrowser
import os

class Window(QtGui.QMainWindow):

    def __init__(self):
        super(Window, self).__init__()
        self.setGeometry(50, 50, 500, 300)
        self.setWindowTitle("Data Structure")
        self.home()

    def home(self):
        btn = QtGui.QPushButton("Choose File", self)
        btn.clicked.connect(self.file_open)
        btn.resize(btn.minimumSizeHint())
        btn.move(20, 20)
        self.moodLabel = QtGui.QLabel("Choose Mood", self)
        self.moodLabel.move(130 , 0)
        self.styleChoice = QtGui.QLabel("", self)
        self.styleChoice.move(50, 150)


        comboBox = QtGui.QComboBox(self)

        comboBox.addItem("")
        comboBox.addItem("Degree Centrality")
        comboBox.addItem("Closeness Centrality")

        comboBox.move(130, 20)
        comboBox.activated[str].connect(self.style_choice)




        self.show()

    def file_open(self):
        name = QtGui.QFileDialog.getOpenFileName(self, 'Open File')
        copyfile(name, 'inputFile.txt')
        p = open('output.txt','w')
        subprocess.check_call([r"SocialMediaAnalysis.exe"],stdout=p)
        algorithm = 0
        algor_1  = "Degree Centrality"
        algor_1_list = []
        algor_2  = "Closeness Centrality"
        algor_2_list = []
        p = open('output.txt', 'r')
        lines = p.readlines()

        for line in lines:
            print("s")
            line = line.strip()
            print(line)
            if line == algor_1.strip() or algorithm == algor_1.strip():
                if line.strip() == algor_1.strip():
                    algorithm = algor_1.strip()
                elif line == 'Start':
                    continue
                elif line == 'Stop':
                    algorithm = 0
                else:
                    algor_1_list.append(line)

            if line == algor_2.strip() or algorithm == algor_2.strip():
                if line.strip() == algor_2.strip():
                    algorithm = algor_2.strip()
                elif line == 'Start':
                    continue
                elif line == 'Stop':
                    algorithm = 0
                else:
                    algor_2_list.append(line)

        Data_Visualisation(algor_1_list,algor_2_list)







    def style_choice(self, text):
        print(text)
        self.styleChoice.setText(text)
        new = 2
        cwd = os.getcwd()
        if text != '':
            url = cwd + "/"+text + ".html"
            print(url)
            webbrowser.open(url, new=new)




def run():
    app = QtGui.QApplication(sys.argv)
    GUI = Window()
    sys.exit(app.exec_())


run()
