#-------------------------------------------------
#
# Project created by QtCreator 2010-10-26T20:39:24
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = testpcap2
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

win32: LIBS	+= -L G:\qtpcap\Lib -lwpcap \
       -lwsock32
       INCLUDEPATH	+= G:\qtpcap\Include


SOURCES += main.cpp

HEADERS += \
    qtpcap.h
