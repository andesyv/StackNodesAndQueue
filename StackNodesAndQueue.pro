TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    charnode.cpp \
    charstack.cpp \
    nodedl.cpp

HEADERS += \
    charnode.h \
    charstack.h \
    node.h \
    stack.h \
    queue.h \
    nodedl.h
