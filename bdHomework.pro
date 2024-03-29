#-------------------------------------------------
#
# Project created by QtCreator 2019-05-23T19:49:18
#
#-------------------------------------------------

QT       += core gui sql axcontainer printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bdHomework
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        add_client.cpp \
        graph.cpp \
        login.cpp \
        main.cpp \
        mainwindow.cpp \
        qcpdocumentobject.cpp \
        qcustomplot.cpp \
        update_record.cpp

HEADERS += \
        add_client.h \
        graph.h \
        login.h \
        mainwindow.h \
        qcpdocumentobject.h \
        qcustomplot.h \
        update_record.h

FORMS += \
        add_client.ui \
        graph.ui \
        login.ui \
        mainwindow.ui \
        update_record.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
