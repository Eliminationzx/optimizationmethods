TEMPLATE = app
QT = gui core
CONFIG += qt warn_on release console
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
FORMS = ui/mainwindow.ui \
 ui/CWdescent_fixwindow.ui \
 ui/mainwindowPass.ui \
 ui/CWdescent_md.ui \
 ui/FasterDescent.ui \
 ui/HuGi.ui \
 ui/NeMi.ui \
 ui/NotWen.ui \
 ui/aboutProgram.ui \
 ui/licenzo.ui \
 ui/helpBrowser.ui
RESOURCES += ui/data.qrc
INCLUDEPATH += /usr/include/qwt-qt4/
LIBS += /usr/lib/libqwt-qt4.so
DEPENDPATH += /usr/include/qwt-qt4
SOURCES += src/aboutprogramimpl.cpp \
 src/algoritmowin.cpp \
 src/cwdescent_mdimpl.cpp \
 src/cwdescentwinimpl.cpp \
 src/demonstrataqpointf.cpp \
 src/fasterdescentimpl.cpp \
 src/funkcio.cpp \
 src/helpbrowserimpl.cpp \
 src/hugiimpl.cpp \
 src/licenzodlgimpl.cpp \
 src/main.cpp \
 src/mainpassimpl.cpp \
 src/mainwindowimpl.cpp \
 src/mapoporfunkcioimpl.cpp \
 src/nemiimpl.cpp \
 src/notwenimpl.cpp \
 src/signalantoporpointf.cpp \
 src/spectrogramdata.cpp \
 src/spuro.cpp \
 src/spurohugi.cpp \
 src/spuroNeMi.cpp \
 src/spurosinkolauxkoordinatoj.cpp \
 src/spurosinkolauxkoordinatoj_md.cpp
HEADERS += src/aboutprogramimpl.h \
 src/algoritmowin.h \
 src/cwdescent_mdimpl.h \
 src/cwdescentwinimpl.h \
 src/demonstrataqpointf.h \
 src/fasterdescentimpl.h \
 src/funkcio.h \
 src/HelpBrowser.h \
 src/helpbrowserimpl.h \
 src/hugiimpl.h \
 src/Konstantoj.h \
 src/licenzodlgimpl.h \
 src/mainpassimpl.h \
 src/mainwindowimpl.h \
 src/mapoporfunkcioimpl.h \
 src/nemiimpl.h \
 src/notwenimpl.h \
 src/signalantoporpointf.h \
 src/spectrogramdata.h \
 src/spuro.h \
 src/spurohugi.h \
 src/spuroNeMi.h \
 src/spurosinkolauxkoordinatoj.h \
 src/spurosinkolauxkoordinatoj_md.h
