#-------------------------------------------------
#
# Project created by QtCreator 2021-06-21T09:25:36
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TCPServer
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    mythread.cpp \
    sqlite.cpp \
    record.cpp

HEADERS  += widget.h \
    mythread.h \
    sqlite.h \
    record.h

FORMS    += widget.ui \
    record.ui
