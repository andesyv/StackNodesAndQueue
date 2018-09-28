TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    charnode.cpp \
    charstack.cpp

HEADERS += \
    charnode.h \
    charstack.h \
    node.h \
    stack.h \
    queue.h \
    nodedl.h \
    stackdl.h \
    smartstackdl.h \
    smartnodedl.h
