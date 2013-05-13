#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import SimpleCV
import PySide
from PySide import QtGui, QtCore
sys.modules['PyQt4'] = PySide
from PIL import ImageQt


def cvImageToQPixMap(image):
    return QtGui.QPixmap(ImageQt.ImageQt(image.getPIL()))


class MainWindow(QtGui.QWidget):
    def __init__(self):
        super(MainWindow, self).__init__()
        self.initUi()
        self.controlsFrame.snapshotButton.clicked.connect(self.snapshot)

    def initUi(self):
        self.setWindowTitle('eVBL Area Detector')
        self.liveCameraFrame = LiveCameraFrame(self)
        self.controlsFrame = ControlsFrame(self)
        self.snapshotFrame = SnapshotFrame(self)
        grid = QtGui.QGridLayout()
        grid.setSpacing(10)
        grid.addWidget(self.liveCameraFrame, 0, 0)
        grid.addWidget(self.snapshotFrame, 0, 1, 2, 1)
        grid.addWidget(self.controlsFrame, 1, 0)
        self.setLayout(grid)

    def snapshot(self):
        self.snapshotFrame.loadImage(self.liveCameraFrame.image)

class LiveCameraFrame(QtGui.QFrame):
    width = 200
    height = 200
    refreshRate = 50. # Hz

    def __init__(self, parent):
        super(LiveCameraFrame, self).__init__()
        self.camera = SimpleCV.Camera()
        self.lastImage = None

        self.initUi()

        self.timer = QtCore.QBasicTimer()
        self.timer.start(1000/LiveCameraFrame.refreshRate, self)

    def initUi(self):
        self.setMinimumSize(LiveCameraFrame.width, LiveCameraFrame.height)
        self.label = QtGui.QLabel(self)
        self.label.setMinimumSize(LiveCameraFrame.width, LiveCameraFrame.height)

    def updateImage(self):
        self.image = self.camera.getImage()
        scaledImage = self.image.adaptiveScale( (LiveCameraFrame.width, LiveCameraFrame.height) )
        pixmap = cvImageToQPixMap(scaledImage)
        self.label.setPixmap(pixmap)

    def timerEvent(self, event):
        self.updateImage()


class ControlsFrame(QtGui.QFrame):
    def __init__(self, parent):
        super(ControlsFrame, self).__init__()
        self.initUi()

    def initUi(self):
        self.setMinimumSize(200, 400)
        self.setBackgroundRole(QtGui.QPalette.Base)
        self.setAutoFillBackground(True)
        self.snapshotButton = QtGui.QPushButton('Capture')
        vbox = QtGui.QVBoxLayout()
        vbox.addWidget(self.snapshotButton)
        vbox.addStretch(1)
        self.setLayout(vbox)


class SnapshotFrame(QtGui.QFrame):
    width = 600
    height = 600
    def __init__(self, parent):
        super(SnapshotFrame, self).__init__()
        self.initUi()

    def initUi(self):
        self.setMinimumSize(SnapshotFrame.width, SnapshotFrame.height)
        self.label = QtGui.QLabel(self)
        self.label.setMinimumSize(SnapshotFrame.width, SnapshotFrame.height)
    
    def loadImage(self, image):
        scaledImage = image.adaptiveScale( (SnapshotFrame.width, SnapshotFrame.height) )
        pixmap = cvImageToQPixMap(scaledImage)
        self.label.setPixmap(pixmap)

def main():
    app = QtGui.QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())

if __name__ == '__main__':
    main()
