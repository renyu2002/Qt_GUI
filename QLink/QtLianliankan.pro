#-------------------------------------------------

# Project created by QtCreator 2016-07-11T10:49:28
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtLianliankan
TEMPLATE = app


SOURCES += main.cpp\
    game_model.cpp \
    main_game_window.cpp

HEADERS  += \
    game_model.h \
    main_game_window.h

FORMS    += main_game_window.ui

RESOURCES += \
    res.qrc
