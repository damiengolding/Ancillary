QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_propertysystem.cpp \
    connections/basicsignalclass.cpp \
    connections/basicslotclass.cpp \
    propertysystem.cpp \
    utils/autoconnect.cpp

HEADERS += \
    connections/basicsignalclass.hpp \
    connections/basicslotclass.hpp \
    propertysystem.hpp \
    utils/autoconnect.hpp

INCLUDEPATH += \
    connections/ \
    utils/
