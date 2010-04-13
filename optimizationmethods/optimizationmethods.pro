TEMPLATE = app
QT = gui core
CONFIG += qt release warn_on console
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
FORMS = ui/mainwindow.ui ui/mapoporfunkcio.ui ui/CWdescent_fixwindow.ui
HEADERS = src/mainwindowimpl.h \
 src/funkcio.h \
 src/mapoporfunkcioimpl.h \
 src/scenopormapo.h \
 src/spuro.h \
 src/spurosinkolauxkoordinatoj.h \
 src/cwdescentwinimpl.h \
 src/algoritmowin.h \
 src/Konstantoj.h \
 src/demonstrataqpointf.h
SOURCES = src/mainwindowimpl.cpp \
 src/main.cpp \
 src/funkcio.cpp \
 src/mapoporfunkcioimpl.cpp \
 src/scenopormapo.cpp \
 src/spuro.cpp \
 src/spurosinkolauxkoordinatoj.cpp \
 src/cwdescentwinimpl.cpp \
 src/algoritmowin.cpp \
 src/demonstrataqpointf.cpp
RESOURCES += ui/data.qrc
