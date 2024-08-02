QT = core testlib statemachine xml concurrent core5compat
CONFIG += c++20 cmdline warn_off

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        runningconfig.cpp \
        statemanager.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    runningconfig.hpp \
    statemanager.hpp \
    states.hpp

STATECHARTS += \
    diagrams/CyberKillChain.scxml

DISTFILES += \
    diagrams/designconcept.qmodel \
    diagrams/designimplementation.qmodel
