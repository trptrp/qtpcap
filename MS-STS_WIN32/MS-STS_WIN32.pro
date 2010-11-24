#-------------------------------------------------
#
# Project created by QtCreator 2010-10-28T21:50:46
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = MS-STS_WIN32
CONFIG   += console
CONFIG   -= app_bundle

CONFIG += mobility
INSTALLS += target sources

symbian {
    TARGET.UID3 = 0xA000A646
    include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)
}

TEMPLATE = app
win32: LIBS	+= -L E:\MS-STS_WIN32\Lib -lwpcap \
       -lwsock32

SOURCES += main.cpp \
    capture_if_dlg.c

HEADERS += \
    qtpcap.h \
    capture_if_dlg.h

FORMS +=

OTHER_FILES += \
    symbianpkgrules.pri
