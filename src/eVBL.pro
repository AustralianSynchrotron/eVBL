#-------------------------------------------------
#
# Project created by QtCreator 2013-06-30T02:24:41
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = eVBL
TEMPLATE = app

CONFIG +=static -static-libgcc

SOURCES += main.cpp\
        evbl.cpp

HEADERS  += evbl.h \
    cvimagewidget.h

FORMS    += evbl.ui

Debug:INCLUDEPATH += opencv\\install\\debug\\include
Debug:LIBS += -L$$PWD\\opencv\\install\\debug\\lib
Release:INCLUDEPATH += opencv\\install\\release\\include
Release:LIBS += -L$$PWD\\opencv\\install\\release\\lib
Release:LIBS += -L$$PWD\\opencv\\install\\release\\share\\OpenCV\\3rdparty\\lib
Release:INCLUDEPATH += "C:\Program Files\Microsoft SDKs\Windows\v7.1\Include"
Release:LIBS += "C:\Program Files\Microsoft SDKs\Windows\v7.1\Lib\Vfw32.Lib"

unix {
    LIBS += -lopencv_core \
    -lopencv_highgui \
    -lopencv_imgproc \
    -lopencv_features2d \
    -lopencv_calib3d
}

win32 {
    Debug:LIBS += -lopencv_highgui246d \
    -lopencv_imgproc246d \
    -lopencv_features2d246d \
    -lopencv_calib3d246d \
    -lopencv_photo246d
    Release:LIBS += -lopencv_highgui246 \
    -lopencv_imgproc246 \
    -lopencv_features2d246 \
    -lopencv_calib3d246 \
    -lopencv_photo246   \
    -lVfw32 \
    -llibtiff \
    -llibjasper \
    -lIlmImf \
    -lopencv_core246

}
