QT = core testlib
CONFIG += c++20 cmdline warn_off

SOURCES += \
        fsmclass.cpp \
        fsmmachine.cpp \
        main.cpp \

HEADERS += \
    IFiniteStateMachine.hpp \
    fsm_includes.hpp \
    fsmclass.hpp \
    fsmmachine.hpp \

