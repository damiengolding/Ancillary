QT = core

TEMPLATE = lib
CONFIG += c++20

SOURCES += \
    rundll.cpp

HEADERS += \
    rundll.hpp

LIBS += -luser32
DEF_FILE = exports.def
DISTFILES += exports.def

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
