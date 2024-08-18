QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_propertysystem.cpp \
    connections/basicsignalclass.cpp \
    connections/basicslotclass.cpp \
    custom/myvariant.cpp \
    property/goodcitizen.cpp \
    propertysystem.cpp \
    utils/autoconnect.cpp

HEADERS += \
    connections/basicsignalclass.hpp \
    connections/basicslotclass.hpp \
    custom/myvariant.hpp \
    property/goodcitizen.hpp \
    propertysystem.hpp \
    utils/autoconnect.hpp \
    utils/enumconvertor.hpp

INCLUDEPATH += \
    connections/ \
    utils/
