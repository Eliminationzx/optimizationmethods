TEMPLATE = app
QT = gui core
CONFIG += qt debug warn_on console
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
FORMS = ui/mapoporfunkcio.ui
HEADERS = src/funkcio.h src/mapoporfunkcioimpl.h src/scenopormapo.h src/spuro.h
SOURCES = src/main.cpp \
 src/funkcio.cpp \
 src/mapoporfunkcioimpl.cpp \
 src/scenopormapo.cpp \
 src/spuro.cpp
