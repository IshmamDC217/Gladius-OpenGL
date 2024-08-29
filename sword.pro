QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
TARGET = triforce
INCLUDEPATH += . /opt/local/include
CONFIG += c++11
QT += widgets opengl gui
LIBS += -lopengl32 -lglu32

SOURCES += \
    main.cpp \
    swordwidgets.cpp \
    swordwindow.cpp
HEADERS += \
    swordwidgets.h \
    swordwindow.h

FORMS += \
    swordwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
