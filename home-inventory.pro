#-------------------------------------------------
#
# Project created by QtCreator 2017-06-16T16:23:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = home-inventory
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    services.cpp
HEADERS  += mainwindow.h \
    data.h \
    services.h \
    eventfilter.h
FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../usr/lib/x86_64-linux-gnu/release/ -lleveldb
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../usr/lib/x86_64-linux-gnu/debug/ -lleveldb
else:unix: LIBS += -L$$PWD/../../../../usr/lib/x86_64-linux-gnu/ -lleveldb

INCLUDEPATH += $$PWD/../../../../usr/include/leveldb
DEPENDPATH += $$PWD/../../../../usr/include/leveldb
