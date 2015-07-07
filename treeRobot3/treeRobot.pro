#-------------------------------------------------
#
# Project created by QtCreator 2015-06-25T13:20:50
#
#-------------------------------------------------

QT       += core gui
QT       += serialport
QT       += multimedia
QT       += multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = treeRobot
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    serialport.cpp \
    util.cpp \
    slidervelocity.cpp

HEADERS  += mainwindow.h \
    serialport.h \
    treerobotconstant.h \
    util.h \
    slidervelocity.h

FORMS    += mainwindow.ui
