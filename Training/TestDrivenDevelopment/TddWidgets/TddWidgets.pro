QT       += core gui testlib
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++20

isActiveConfig(debug,debug|release){
    BUILD_CONFIG = Debug
}else{
    BUILD_CONFIG = Release
}

contains(BUILD_CONFIG,Debug){
    TARGET = tddwd
}else{
    TARGET = tddw
}

SOURCES += \
    dialog/preferencesdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    preferencestest.cpp \
    widgetstest.cpp \
    wizard/confirmationwizardpage.cpp \
    wizard/introwizardpage.cpp \
    wizard/projectwizardpage.cpp \
    wizard/testwizard.cpp \
    wizardtest.cpp

HEADERS += \
    dialog/preferencesdialog.hpp \
    mainwindow.hpp \
    preferencestest.hpp \
    widgetstest.hpp \
    wizard/confirmationwizardpage.hpp \
    wizard/introwizardpage.hpp \
    wizard/projectwizardpage.hpp \
    wizard/testwizard.hpp \
    wizardtest.hpp

FORMS += \
    dialog/preferencesdialog.ui \
    mainwindow.ui \
    wizard/confirmationwizardpage.ui \
    wizard/introwizardpage.ui \
    wizard/projectwizardpage.ui \
    wizard/testwizard.ui

RESOURCES += \
    res/resources.qrc

DISTFILES += \
    models/preferencestest.qmodel \
    models/widgetstest.qmodel \
    models/wizardtest.qmodel
