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
    lib/ui/simulatewidget.cpp \
    lib/draw/houseitem.cpp \
    lib/data/globalcanvasdata.cpp \
    lib/draw/wall.cpp \
    lib/draw/window.cpp \
    lib/draw/door.cpp \
    lib/draw/device.cpp \
    lib/draw/floor.cpp \
    lib/tool/tool.cpp \
    lib/tool/drawdevicetool.cpp \
    lib/tool/drawdoortool.cpp \
    lib/tool/drawwindowtool.cpp \
    lib/tool/drawfloortool.cpp \
    lib/tool/drawwalltool.cpp \
    lib/tool/selectiontool.cpp \
    lib/data/filereaderfactory.cpp \
    lib/data/filewriterfactory.cpp \
    lib/data/jsonfilereader.cpp \
    lib/data/jsonfilewriter.cpp

HEADERS += \
        mainwindow.h \
    lib/ui/dwellercanvas.h \
    simulatewindow.h \
    lib/ui/simulatewidget.h \
    lib/draw/houseitem.h \
    lib/data/globalcanvasdata.h \
    lib/draw/wall.h \
    lib/draw/window.h \
    lib/draw/door.h \
    lib/draw/device.h \
    lib/draw/floor.h \
    lib/tool/tool.h \
    lib/tool/drawdevicetool.h \
    lib/tool/drawdoortool.h \
    lib/tool/drawwindowtool.h \
    lib/tool/drawfloortool.h \
    lib/tool/drawwalltool.h \
    lib/tool/selectiontool.h \
    lib/data/filereaderfactory.h \
    lib/data/filewriterfactory.h \
    lib/data/jsonfilereader.h \
    lib/data/jsonfilewriter.h

SUBDIRS += \
    Dweller.pro

RESOURCES += \
    dweller.qrc

OTHER_FILES += \
    simulator.qml \
    lib/simulator.js

DISTFILES += \
    lib/ui/ButtonImage.qml
