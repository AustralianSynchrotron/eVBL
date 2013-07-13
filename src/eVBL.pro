#-------------------------------------------------
#
# Project created by QtCreator 2013-06-30T02:24:41
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = eVBL
TEMPLATE = app


SOURCES += main.cpp\
        evbl.cpp

HEADERS  += evbl.h \
    cvimagewidget.h

FORMS    += evbl.ui

INCLUDEPATH += opencv\\install\\debug\\include
LIBS += -L$$PWD\\opencv\\install\\debug\\lib

unix {
    LIBS += -lopencv_core \
    -lopencv_highgui \
    -lopencv_imgproc \
    -lopencv_features2d \
    -lopencv_calib3d
}

win32 {
    LIBS += -lopencv_core246d \
    -lopencv_highgui246d \
    -lopencv_imgproc246d \
    -lopencv_features2d246d \
    -lopencv_calib3d246d \
    -lopencv_photo246d
}
