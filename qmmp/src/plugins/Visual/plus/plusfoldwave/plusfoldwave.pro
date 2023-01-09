include($$PWD/../../Visual.pri)
include($$PWD/../../common/widget.pri)

DESTDIR = $$PLUGINS_PREFIX/Visual

HEADERS += plusfoldwave.h \
           visualplusfoldwavefactory.h
           
SOURCES += plusfoldwave.cpp \
           visualplusfoldwavefactory.cpp

unix{
    QMAKE_CLEAN = $$DESTDIR/lib$${TARGET}.so
}
