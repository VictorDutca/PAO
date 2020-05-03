#-------------------------------------------------
#
# Project created by QtCreator 2020-03-28T10:02:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testGerarchia
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
        mainwindow.cpp \
    workout.cpp \
    corsa.cpp \
    nuoto.cpp \
    ciclismo.cpp \
    triathlon.cpp \
    schedules.cpp \
    testwindow.cpp \
    qfitwindow.cpp \
    xmlhandler.cpp

HEADERS += \
        mainwindow.h \
    workout.h \
    corsa.h \
    nuoto.h \
    ciclismo.h \
    triathlon.h \
    schedules.h \
    lista.h \
    testwindow.h \
    qfitwindow.h \
    xmlhandler.h

FORMS += \
        mainwindow.ui
