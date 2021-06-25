#-------------------------------------------------
#
# Project created by QtCreator 2021-06-20T17:08:19
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TCPClient
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    chat.cpp

HEADERS  += widget.h \
    chat.h

FORMS    += widget.ui \
    chat.ui
