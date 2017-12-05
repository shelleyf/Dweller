#-------------------------------------------------
#
# Project created by QtCreator 2017-11-21T18:42:20
#
#-------------------------------------------------

QT += qml quick quickwidgets widgets script

TARGET = Dweller
TEMPLATE = app

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    lib/ui/qsshelper.cpp \
    lib/ui/dwellercanvas.cpp \
    simulatewindow.cpp \
    lib/ui/simulatewidget.cpp

HEADERS += \
        mainwindow.h \
    lib/ui/dwellercanvas.h \
    simulatewindow.h \
    lib/ui/simulatewidget.h

SUBDIRS += \
    Dweller.pro

RESOURCES += \
    dweller.qrc

OTHER_FILES += \
    simulator.qml \
    lib/simulator.js

DISTFILES += \
    lib/ui/ButtonImage.qml
