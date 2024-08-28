QT = core network xml
CONFIG += c++20 cmdline warn_off

SOURCES += \
    exec/commands.cpp \
        main.cpp \

HEADERS += \
    exec/commands.hpp \
    utils/netutils.hpp


isActiveConfig(debug,debug|release){
    TARGET = QSslRecond
    BUILD_TYPE = Debug
}
else{
    TARGET = QSslRecon
    BUILD_TYPE = Release
}

!build_pass:message("Building for: " $$BUILD_TYPE)
