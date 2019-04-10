#-------------------------------------------------
#
# Project created by QtCreator 2019-04-10T13:11:45
#
#-------------------------------------------------

QT       -= gui

TARGET = CopyFile
TEMPLATE = lib

DEFINES += COPYFILE_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS



SOURCES += \
        CopyFile.cpp \
    CopyHelper.cpp

HEADERS += \
        CopyFile.h \
        copyfile_global.h \ 
    CopyHelper.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
