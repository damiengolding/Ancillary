QT       += core gui statemachine xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20 warn_off

SOURCES += \
    main.cpp \
    mainwindow.cpp \

HEADERS += \
    etg.hpp \
    mainwindow.hpp

FORMS += \
    mainwindow.ui

STATECHARTS += \
    EventsTransitionsGuards.scxml

