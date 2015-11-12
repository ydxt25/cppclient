TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    tcpclient.cpp

HEADERS += \
    tcpclient.h

LIBS +=-lboost_system -lboost_date_time
