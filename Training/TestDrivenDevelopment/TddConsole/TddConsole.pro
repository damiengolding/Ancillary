QT = core network xml testlib
CONFIG += c++20 cmdline warn_off

isActiveConfig(debug,debug|release){
    BUILD_CONFIG = Debug
}else{
    BUILD_CONFIG = Release
}

contains(BUILD_CONFIG,Debug){
    TARGET = tddcd
}else{
    TARGET = tddc
}

SOURCES += \
        main.cpp \
        src/benchmarktest.cpp \
        src/clientsocket.cpp \
        src/logger.cpp \
        src/signalclass.cpp \
        src/signaltest.cpp \
        src/xmltest.cpp

HEADERS += \
    inc/benchmarktest.hpp \
    inc/clientsocket.hpp \
    inc/logger.hpp \
    inc/signalclass.hpp \
    inc/signaltest.hpp \
    inc/xmltest.hpp

