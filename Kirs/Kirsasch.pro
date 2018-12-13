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
    player.cpp \
    level.cpp \
    landshaft.cpp \
    indicatorscene.cpp \
    healthbar.cpp \
    traponland.cpp \
    computer.cpp \
    eventqueue.cpp \
    gameevent.cpp \
    livingobject.cpp \
    simplymonster.cpp \
    dialog.cpp \
    menuscene.cpp \
    gamebutton.cpp \
    minimap.cpp

HEADERS  += mainwindow.h \
    gamescene.h \
    gameobject.h \
    hero.h \
    cellsmatrix.h \
    cell.h \
    main_settings.h \
    player.h \
    level.h \
    landshaft.h \
    indicatorscene.h \
    healthbar.h \
    traponland.h \
    computer.h \
    algorithm.h \
    eventqueue.h \
    gameevent.h \
    livingobject.h \
    simplymonster.h \
    dialog.h \
    menuscene.h \
    gamebutton.h \
    minimap.h

FORMS    += mainwindow.ui \
    dialog.ui

RESOURCES += \
    hero.qrc
