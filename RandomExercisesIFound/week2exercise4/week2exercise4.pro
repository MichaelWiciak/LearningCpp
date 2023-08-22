TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        currency.cpp \
        euro.cpp \
        main.cpp \
        pound.cpp \
        yuan.cpp

HEADERS += \
    currency.h \
    euro.h \
    pound.h \
    yuan.h
