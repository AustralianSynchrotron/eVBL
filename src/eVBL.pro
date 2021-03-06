#-------------------------------------------------
#
# Project created by QtCreator 2013-06-30T02:24:41
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Detector_Gadget_v1-2-1
TEMPLATE = app

CONFIG +=static -static-libgcc

SOURCES += main.cpp\
        evbl.cpp \
    settings.cpp \
    about.cpp \
    help.cpp

HEADERS  += evbl.h \
    cvimagewidget.h \
    settings.h \
    about.h \
    help.h

FORMS    += evbl.ui \
    settings.ui \
    about.ui \
    help.ui

QTPLUGIN += dsengine

Debug:INCLUDEPATH += opencv\\install\\debug\\include
Debug:LIBS += -L$$PWD\\opencv\\install\\debug\\lib
Release:INCLUDEPATH += opencv\\install\\release\\include
Release:LIBS += -L$$PWD\\opencv\\install\\release\\lib
Release:LIBS += -L$$PWD\\opencv\\install\\release\\share\\OpenCV\\3rdparty\\lib
Release:LIBS += -L$$PWD\\opencv\\3rdparty\\lib
#Release:INCLUDEPATH += "C:\Program Files\Microsoft SDKs\Windows\v7.1\Include"
#Release:INCLUDEPATH += -L$$PWD\\opencv\\3rdparty\\include\\ffmpeg_
#Release:LIBS += "C:\Program Files\Microsoft SDKs\Windows\v7.1\Lib\Vfw32.Lib"


unix {
    LIBS += -lopencv_core \
    -lopencv_highgui \
    -lopencv_imgproc \
    -lopencv_features2d \
    -lopencv_calib3d
}

win32 {
    Debug:LIBS += -lopencv_core246d \
    -lopencv_highgui246d \
    -lopencv_imgproc246d \
    -lopencv_features2d246d \
    -lopencv_calib3d246d \
    -lopencv_photo246d
    Release:LIBS += -lopencv_imgproc246 \
    -lopencv_highgui246 \
    -lopencv_features2d246 \
    -lopencv_calib3d246 \
    -lopencv_photo246 \
    -llibtiff \
    -llibjpeg \
    -llibjasper \
    -lIlmImf \
    -lVfw32 \
    -lavcodec \
    -lavdevice \
    -lavformat \
    -lavutil \
    -lgcc \
    -lmingwex_ \
    -lswscale \
    -lwsock32 \
    -lopencv_video246 \
    -lopencv_core246 \
    -lzlib
}

RC_FILE = icon.rc

RESOURCES += \
    images.qrc \
    helpdocs.qrc

OTHER_FILES +=


