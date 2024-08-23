QT = core testlib network
CONFIG += c++20 cmdline warn_off

SOURCES += \
        main.cpp \
        ServerHandlerConfig.cpp \
        ServerHandlerLogger.cpp \
        receivesocket.cpp \
        sslserver.cpp

HEADERS += \
    ServerHandlerConfig.hpp \
    ServerHandlerLogger.hpp \
    netutils.hpp \
    receivesocket.hpp \
    sslserver.hpp

DISTFILES +=

RESOURCES += \
    resources.qrc
