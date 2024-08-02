QT += testlib xml network
QT -= gui
CONFIG += qt console warn_off depend_includepath testcase
CONFIG -= app_bundle
TEMPLATE = app

isActiveConfig(debug,debug|release){
    BUILD_CONFIG = Debug
}else{
    BUILD_CONFIG = Release
}

contains(BUILD_CONFIG,Debug){
    TARGET = tddmd
}else{
    TARGET = tddm
}

TDD_SOURCES = ..\TddConsole\src
TDD_INCLUDES = ..\TddConsole\inc

SOURCES +=  \
    $$TDD_SOURCES\xmltest.cpp \
    $$TDD_SOURCES\benchmarktest.cpp \
    $$TDD_SOURCES\signaltest.cpp \
    $$TDD_SOURCES\signalclass.cpp \
    $$TDD_SOURCES\clientsocket.cpp \
    benchmark_test.cpp \
    signal_test.cpp \
    tddtestcase.cpp \
    xml_test.cpp

HEADERS += $$TDD_INCLUDES\xmltest.hpp \
    $$TDD_INCLUDES\benchmarktest.hpp \
    $$TDD_INCLUDES\signaltest.hpp \
    $$TDD_INCLUDES\signalclass.hpp \
    $$TDD_INCLUDES\clientsocket.hpp \
    tddtestcase.hpp

INCLUDEPATH += ..\TddConsole\inc
# INCLUDEPATH += $$TDD_INCLUDES\inc
