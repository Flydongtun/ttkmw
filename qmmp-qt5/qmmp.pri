#Common settings for Qmmp build

#Some conf to redirect intermediate stuff in separate dirs
UI_DIR=./.build/ui/
MOC_DIR=./.build/moc/
OBJECTS_DIR=./.build/obj
RCC_DIR=./.build/rcc

QT += widgets
DEFINES += QMMP_WS_X11

DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x050400

#Version

TTKMusicPlayer = 2.7.0.0
QMMP_VERSION = 1.2.1

#Comment/uncomment this if you want to change plugins list

CONFIG += JACK_PLUGIN
CONFIG += FLAC_PLUGIN
CONFIG += MUSEPACK_PLUGIN
CONFIG += FFMPEG_PLUGIN
CONFIG += MODPLUG_PLUGIN
CONFIG += WILDMIDI_PLUGIN
CONFIG += GME_PLUGIN
CONFIG += XMP_PLUGIN
CONFIG += FFAP_PLUGIN
CONFIG += OPUS_PLUGIN
CONFIG += OSS_PLUGIN #deprecated
CONFIG += PULSE_AUDIO_PLUGIN
CONFIG += ALSA_PLUGIN
CONFIG += OSS4_PLUGIN
CONFIG += AAC_PLUGIN
CONFIG += MPLAYER_PLUGIN
CONFIG += CDAUDIO_PLUGIN
CONFIG += BS2B_PLUGIN
CONFIG += SOXR_PLUGIN
CONFIG += LADSPA_PLUGIN
CONFIG += SRC_PLUGIN
CONFIG += UDISKS2_PLUGIN
CONFIG += HAL_PLUGIN
CONFIG += SID_PLUGIN
CONFIG += QTMULTIMEDIA_PLUGIN

#additional features

CONFIG += WITH_ENCA
CONFIG += WITH_SKINNED
CONFIG += WITH_QSUI

CONFIG -= $$DISABLED_PLUGINS
