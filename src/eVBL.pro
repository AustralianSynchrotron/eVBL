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

INCLUDEPATH += opencv\\include
LIBS += -L$$PWD\\opencv\\lib

unix {
    LIBS += -lopencv_core \
    -lopencv_highgui \
    -lopencv_imgproc \
    -lopencv_features2d \
    -lopencv_calib3d
}

win32 {
    LIBS += -lopencv_core245d \
    -lopencv_highgui245d \
    -lopencv_imgproc245d \
    -lopencv_features2d245d \
    -lopencv_calib3d245d \
    -lopencv_photo245d
}
