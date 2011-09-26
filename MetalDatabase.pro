#-------------------------------------------------
#
# Project created by QtCreator 2011-09-04T21:40:36
#
#-------------------------------------------------

QT       += core gui sql

TARGET = MetalDatabase
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tabinterfacewidget.cpp \
    dialogs/aboutdialog.cpp \
    dbactionstoolbar.cpp \
    picturedelegate.cpp \
    tables/carstable.cpp \
    tables/customerstable.cpp \
    cards/carscard.cpp \
    cards/cardconfigurator.cpp \
    tables/tableconfigurator.cpp

HEADERS  += mainwindow.h \
    tabinterfacewidget.h \
    dialogs/aboutdialog.h \
    dbactionstoolbar.h \
    picturedelegate.h \
    tables/tableconfigurator.h \
    cards/cardconfigurator.h
