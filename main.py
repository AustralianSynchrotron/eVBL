#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import SimpleCV
import PySide
from PySide import QtGui, QtCore
sys.modules['PyQt4'] = PySide
from PIL import ImageQt


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
    width = 200
    height = 200
    refreshRate = 50. # Hz

    def __init__(self, parent):
        super(LiveCameraFrame, self).__init__()
        self.camera = SimpleCV.Camera()

        self.initUi()

        self.timer = QtCore.QBasicTimer()
        self.timer.start(1000/LiveCameraFrame.refreshRate, self)

    def initUi(self):
        self.setMinimumSize(LiveCameraFrame.width, LiveCameraFrame.height)
        self.label = QtGui.QLabel(self)
        self.label.setMinimumSize(LiveCameraFrame.width, LiveCameraFrame.height)

    def updateImage(self):
        image = self.camera.getImage()
        scaledImage = image.adaptiveScale( (LiveCameraFrame.width, LiveCameraFrame.height) )
        pixmap = QtGui.QPixmap(ImageQt.ImageQt(scaledImage.getPIL()))
        self.label.setPixmap(pixmap)

    def timerEvent(self, event):
        self.updateImage()


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
