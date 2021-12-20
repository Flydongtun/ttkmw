include($$PWD/../zed.pri)

DESTDIR = $$PLUGINS_PREFIX/Input
TARGET = $${TARGET}

HEADERS += decoderpsffactory.h \
           decoder_psf.h \
           psfhelper.h \
           psfmetadatamodel.h
    
SOURCES += decoderpsffactory.cpp \
           decoder_psf.cpp \
           psfhelper.cpp \
           psfmetadatamodel.cpp

INCLUDEPATH += $$EXTRA_PREFIX/libpsf/include

unix{
    QMAKE_CLEAN = $$DESTDIR/lib$${TARGET}.so
    LIBS += -L$$EXTRA_PREFIX/libpsf/lib -lpsf$$STATIC_LIBRARY_SUFFIX
}

win32{
    LIBS += -L$$EXTRA_PREFIX/libpsf/lib -lpsf
}