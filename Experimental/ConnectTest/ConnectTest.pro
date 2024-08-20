QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_autoconnect.cpp \
    fakestate.cpp \
    simplesignal.cpp \
    simpleslot.cpp

HEADERS += \
    fakestate.hpp \
    simplesignal.hpp \
    simpleslot.hpp \
    testconnect.hpp
