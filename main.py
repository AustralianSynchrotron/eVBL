#!/usr/bin/env python
# -*- coding: utf-8 -*-

import SimpleCV
import sys
from PySide import QtGui, QtCore

#image_path = 'resources/TEST_AS_Unknown_532nm_1000_4_AUTOLIGHT.bmp'
#image = SimpleCV.Image(image_path)
#image.show()


class MainWindow(QtGui.QWidget):
    def __init__(self):
        super(MainWindow, self).__init__()
        self.initUi()

    def initUi(self):
        self.setWindowTitle('eVBL Area Detector')
        liveCamera = LiveCameraFrame(self)
        controls = ControlsFrame()
        snapshot = SnapshotFrame()
        grid = QtGui.QGridLayout()
        grid.setSpacing(10)
        grid.addWidget(liveCamera, 0, 0)
        grid.addWidget(snapshot, 0, 1, 2, 1)
        grid.addWidget(controls, 1, 0)
        self.setLayout(grid)


class LiveCameraFrame(QtGui.QFrame):
    def __init__(self, parent):
        super(LiveCameraFrame, self).__init__()

        self.timer = QtCore.QBasicTimer()
        self.timer.start(1000, self)

        self.initUi()

    def initUi(self):
        self.setMinimumSize(200, 200)
        self.setBackgroundRole(QtGui.QPalette.Base)
        self.setAutoFillBackground(True)

    def timerEvent(self, event):
        pass


class ControlsFrame(QtGui.QFrame):
    def __init__(self):
        super(ControlsFrame, self).__init__()
        self.initUi()

    def initUi(self):
        self.setMinimumSize(200, 400)
        self.setBackgroundRole(QtGui.QPalette.Base)
        self.setAutoFillBackground(True)


class SnapshotFrame(QtGui.QFrame):
    def __init__(self):
        super(SnapshotFrame, self).__init__()
        self.initUi()

    def initUi(self):

        self.setMinimumSize(600, 600)
        self.setBackgroundRole(QtGui.QPalette.Base)
        self.setAutoFillBackground(True)

def main():
    app = QtGui.QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())

if __name__ == '__main__':
    main()
