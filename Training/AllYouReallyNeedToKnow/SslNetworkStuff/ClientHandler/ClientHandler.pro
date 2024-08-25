QT = core testlib network
CONFIG += c++20 cmdline warn_off

SOURCES += \
        main.cpp \
        ClientHandlerConfig.cpp \
        ClientHandlerLogger.cpp \

HEADERS += \
    ClientHandlerConfig.hpp \
    ClientHandlerLogger.hpp \

RESOURCES += \
    resources.qrc
