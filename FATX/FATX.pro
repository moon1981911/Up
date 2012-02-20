#-------------------------------------------------
#
# Project created by QtCreator 2011-12-30T11:35:47
#
#-------------------------------------------------
include(IO/include.pri)
include(FATX/include.pri)

QT       -= gui

TARGET = FATX
TEMPLATE = lib
CONFIG += staticlib
DEFINES += UNICODE _UNICODE _LARGEFILE64_SOURCE

#QMAKE_CXXFLAGS += -D_FILE_OFFSET_BITS=64

win32{
QMAKE_CFLAGS_RELEASE += -Zi
QMAKE_CXXFLAGS_RELEASE += -Zi -g
QMAKE_LFLAGS_RELEASE += /DEBUG /OPT:REF}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

CONFIG(release, debug|release) {
 DEFINES += QT_NO_DEBUG_OUTPUT
}

HEADERS += \
    stdafx.h \
    typedefs.h \
    xexception.h

SOURCES += \
    stdafx.cpp \
    xexception.cpp






