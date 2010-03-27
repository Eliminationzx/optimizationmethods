TEMPLATE = app
QT = gui core
CONFIG += qt debug warn_on console
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
FORMS = ui/mainwindowimpl.ui ui/mapoporfunkcio.ui
HEADERS = src/mainwindowimpl.h \
 src/bazomapo.h \
 src/funkcio.h \
 src/mapoporfunkcioimpl.h \
 src/scenopormapo.h
SOURCES = src/mainwindowimpl.cpp \
 src/main.cpp \
 src/bazomapo.cpp \
 src/funkcio.cpp \
 src/mapoporfunkcioimpl.cpp \
 src/scenopormapo.cpp
