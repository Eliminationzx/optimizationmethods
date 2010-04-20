TEMPLATE = app
QT = gui core
CONFIG += qt warn_on console release
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
FORMS = ui/mainwindow.ui ui/mapoporfunkcio.ui ui/CWdescent_fixwindow.ui ui/mainwindowPass.ui
HEADERS = src/mainwindowimpl.h \
 src/funkcio.h \
 src/mapoporfunkcioimpl.h \
 src/scenopormapo.h \
 src/spuro.h \
 src/spurosinkolauxkoordinatoj.h \
 src/cwdescentwinimpl.h \
 src/algoritmowin.h \
 src/Konstantoj.h \
 src/demonstrataqpointf.h \
 src/mainpassimpl.h
SOURCES = src/mainwindowimpl.cpp \
 src/main.cpp \
 src/funkcio.cpp \
 src/mapoporfunkcioimpl.cpp \
 src/scenopormapo.cpp \
 src/spuro.cpp \
 src/spurosinkolauxkoordinatoj.cpp \
 src/cwdescentwinimpl.cpp \
 src/algoritmowin.cpp \
 src/demonstrataqpointf.cpp \
 src/mainpassimpl.cpp
RESOURCES += ui/data.qrc
