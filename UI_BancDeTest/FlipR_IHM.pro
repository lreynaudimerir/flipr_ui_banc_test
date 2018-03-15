#-------------------------------------------------
#
# Project created by QtCreator 2018-02-26T09:30:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FlipR_IHM
TEMPLATE = app

PRECOMPILED_HEADER +=

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
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
    c_sigfox_detection.cpp \
    c_flipr.cpp \
    c_flipr_data_saver.cpp \
    c_flipr_data_byte_reader.cpp

HEADERS += \
        mainwindow.h \
    c_sigfox_detection.h \
    c_flipr.h \
    c_flipr_data_saver.h \
    c_flipr_data_byte_reader.h \
    e_mode_flipr_data_reader.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    ressource_flipr.qrc

DISTFILES += \
    DYMO.Label.Framework.tlb


