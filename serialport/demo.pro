#-------------------------------------------------
#
# Project created by QtCreator 2015-05-13T19:26:10
#
#-------------------------------------------------

QT       += core gui
QT       += serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = demo
TEMPLATE = app


SOURCES += main.cpp\
        serialport.cpp

HEADERS  += serialport.h

FORMS    += serialport.ui

DISTFILES += \
    CMakeLists.txt
