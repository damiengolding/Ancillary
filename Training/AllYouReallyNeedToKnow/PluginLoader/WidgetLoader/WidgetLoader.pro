QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20 warn_off

isActiveConfig(debug,debug|release){
    TARGET=widgetloaderd
    BUILD_TYPE=Debug
}else{
    TARGET=widgetloader
    BUILD_TYPE=Release
}


SOURCES += \
    main.cpp \
    mainwindow.cpp \

HEADERS += \
    mainwindow.hpp \
    widgetplugin.hpp

FORMS += \
    mainwindow.ui

