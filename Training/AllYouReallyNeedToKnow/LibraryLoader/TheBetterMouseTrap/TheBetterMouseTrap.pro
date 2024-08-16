QT = core testlib
CONFIG += c++20 cmdline warn_off

isActiveConfig(debug,debug|release){
    TARGET=mousetrapd
    BUILD_TYPE=Debug
}else{
    TARGET=mousetrap
    BUILD_TYPE=Release
}

SOURCES += \
        main.cpp \
    mousetrapconfig.cpp \
    mousetraplogger.cpp

HEADERS += \
    mousetrapconfig.hpp \
    mousetraplogger.hpp
