include($$PWD/../../Visual.pri)
include($$PWD/../../common/widget.pri)

DESTDIR = $$PLUGINS_PREFIX/Visual

HEADERS += normalflowwave.h \
           visualnormalflowwavefactory.h

SOURCES += normalflowwave.cpp \
           visualnormalflowwavefactory.cpp

unix{
    QMAKE_CLEAN = $$DESTDIR/lib$${TARGET}.so
}
