QT = core testlib network
CONFIG += c++20 cmdline warn_off

SOURCES += \
        main.cpp \
        ServerHandlerConfig.cpp \
        ServerHandlerLogger.cpp \
        receivesocket.cpp \
        signalhandler.cpp \
        sslserver.cpp

HEADERS += \
    ServerHandlerConfig.hpp \
    ServerHandlerLogger.hpp \
    netutils.hpp \
    receivesocket.hpp \
    signalhandler.hpp \
    sslserver.hpp

DISTFILES +=

RESOURCES += \
    resources.qrc
