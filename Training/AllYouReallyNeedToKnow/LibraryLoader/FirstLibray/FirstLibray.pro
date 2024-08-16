QT -= gui
QT += core

TEMPLATE = lib
DEFINES += FIRSTLIBRAY_LIBRARY LIBEXPORT

CONFIG += c++20 warn_off

SOURCES += \
    firstlibray.cpp

HEADERS += \
    FirstLibray_global.hpp \
    firstlibray.hpp

