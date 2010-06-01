TEMPLATE = app
QT = gui core
CONFIG += qt release warn_on console
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
FORMS = ui/mainwindow.ui ui/aboutProgram.ui ui/license.ui ui/helpBrowser.ui
HEADERS = src/mainwindowimpl.h src/aboutprogramimpl.h src/licensedlgimpl.h src/helpbrowserimpl.h
SOURCES = src/mainwindowimpl.cpp \
 src/main.cpp \
 src/aboutprogramimpl.cpp \
 src/licensedlgimpl.cpp \
 src/helpbrowserimpl.cpp
RESOURCES += ui/data.qrc
