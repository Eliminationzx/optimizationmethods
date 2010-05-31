TEMPLATE = app
QT = gui core
CONFIG += qt warn_on release
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
FORMS = ui/mainwindow.ui \
 ui/mapoporfunkcio.ui \
 ui/CWdescent_fixwindow.ui \
 ui/mainwindowPass.ui \
 ui/CWdescent_md.ui \
 ui/FasterDescent.ui \
 ui/HuGi.ui \
 ui/NeMi.ui \
 ui/NotWen.ui \
 ui/aboutProgram.ui \
 ui/licenzo.ui
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
 src/mainpassimpl.h \
 src/signalantoporpointf.h \
 src/cwdescent_mdimpl.h \
 src/fasterdescentimpl.h \
 src/hugiimpl.h \
 src/nemiimpl.h \
 src/spurosinkolauxkoordinatoj_md.h \
 src/spuroNeMi.h \
 src/HelpBrowser.h \
 src/notwenimpl.h \
 src/aboutprogramimpl.h \
 src/licenzodlgimpl.h \
 src/spurohugi.h
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
 src/mainpassimpl.cpp \
 src/signalantoporpointf.cpp \
 src/cwdescent_mdimpl.cpp \
 src/fasterdescentimpl.cpp \
 src/hugiimpl.cpp \
 src/nemiimpl.cpp \
 src/spurosinkolauxkoordinatoj_md.cpp \
 src/spuroNeMi.cpp \
 src/notwenimpl.cpp \
 src/aboutprogramimpl.cpp \
 src/licenzodlgimpl.cpp \
 src/spurohugi.cpp
RESOURCES += ui/data.qrc
