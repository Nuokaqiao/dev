#-------------------------------------------------
#
# Project created by QtCreator 2018-05-17T19:34:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RS_Test
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        rs_demo_gdal.cpp \
    scrollpicview.cpp \
    rsinfo.cpp \
    resampleinput.cpp \
    mouserect.cpp \
    imageinfo.cpp \
    histogram.cpp \
    filetoolarge.cpp \
    displaycontroller.cpp \
    display_change.cpp \
    axis_vertical.cpp \
    axis_horizontal.cpp

HEADERS += \
        rs_demo_gdal.h \
    scrollpicview.h \
    rsinfo.h \
    resampleinput.h \
    mouserect.h \
    imageinfo.h \
    histogram.h \
    filetoolarge.h \
    displaycontroller.h \
    display_change.h \
    axis_vertical.h \
    axis_horizontal.h

FORMS += \
        rs_demo_gdal.ui \
    rsinfo.ui \
    resampleinput.ui \
    mouserect.ui \
    imageinfo.ui \
    histogram.ui \
    filetoolarge.ui \
    displaycontroller.ui \
    display_change.ui \
    axis_vertical.ui \
    axis_horizontal.ui

unix:!macx: LIBS += -L$$PWD/../../../lib/gdal/lib/ -lgdal

INCLUDEPATH += $$PWD/../../../lib/gdal/include
DEPENDPATH += $$PWD/../../../lib/gdal/include

unix:!macx: LIBS += -L$$PWD/../../../lib/opencv/lib/ -lopencv_core



unix:!macx: LIBS += -L$$PWD/../../../lib/opencv/lib/ -lopencv_features2d


unix:!macx: LIBS += -L$$PWD/../../../lib/opencv/lib/ -lopencv_imgproc



unix:!macx: LIBS += -L$$PWD/../../../lib/opencv/lib/ -lopencv_highgui

unix:!macx: LIBS += -L$$PWD/../../../lib/opencv/lib/ -lopencv_imgcodecs

INCLUDEPATH += $$PWD/../../../lib/opencv/include
DEPENDPATH += $$PWD/../../../lib/opencv/include

unix:!macx: LIBS += -L$$PWD/../../../lib/opencv/proj.4/lib/ -lproj

INCLUDEPATH += $$PWD/../../../lib/opencv/proj.4/include
DEPENDPATH += $$PWD/../../../lib/opencv/proj.4/include
