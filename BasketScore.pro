#-------------------------------------------------
#
# Project created by QtCreator 2018-10-31T13:12:20
#
#-------------------------------------------------

QT       += core gui
QT += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BasketScore
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
        ScoreBoard.cpp \
    ScoreDialog.cpp \
    musicdialog.cpp

HEADERS  += mainwindow.h \
	ScoreBoard.h \
    ScoreDialog.h \
    musicdialog.h

FORMS    += mainwindow.ui \
    ScoreDialog.ui \
    musicdialog.ui

RESOURCES += \
    resources.qrc

DISTFILES += \
    out-2.new.wav
