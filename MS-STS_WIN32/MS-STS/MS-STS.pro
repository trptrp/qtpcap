CONFIG      += designer plugin debug_and_release
TARGET      = $$qtLibraryTarget(ms_stsplugin)
TEMPLATE    = lib

HEADERS     = ms_stsplugin.h
SOURCES     = ms_stsplugin.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(ms_sts.pri)
