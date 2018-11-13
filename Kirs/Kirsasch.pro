#-------------------------------------------------
#
# Project created by QtCreator 2018-11-05T19:01:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Kirsasch
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gamescene.cpp \
    gameobject.cpp \
    hero.cpp \
    cellsmatrix.cpp \
    cell.cpp \
    game.cpp \
    player.cpp

HEADERS  += mainwindow.h \
    gamescene.h \
    gameobject.h \
    hero.h \
    cellsmatrix.h \
    cell.h \
    main_settings.h \
    game.h \
    player.h

FORMS    += mainwindow.ui
