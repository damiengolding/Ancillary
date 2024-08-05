QT -= gui
QT += widgets

TEMPLATE = lib
DEFINES += FIRSTWIDGET_LIBRARY

CONFIG += c++20 warn_off

SOURCES += \
    firstwidget.cpp

HEADERS += \
    FirstWidget_global.hpp \
    firstwidget.hpp
