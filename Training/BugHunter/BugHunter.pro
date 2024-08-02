isActiveConfig(debug,debug|release){
    BUILD_TYPE = debug
    TARGET = bughunterd
}else{
    BUILD_TYPE = release
    TARGET = bughunter
}

QT = core testlib xml

CONFIG += c++20 cmdline warn_off

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        src/bugconfig.cpp \
        src/bugs1.cpp \
        src/bugs2.cpp \
        src/bugs3.cpp \
        src/errantthread.cpp \
        src/naughtyobject.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    inc/bugconfig.hpp \
    inc/bugs.hpp \
    inc/errantthread.hpp \
    inc/naughtyobject.hpp
