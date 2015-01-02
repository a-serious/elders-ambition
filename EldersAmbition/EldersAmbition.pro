#-------------------------------------------------
#
# Project created by QtCreator 2013-12-10T18:51:05
#
#-------------------------------------------------

QT += core gui declarative qml quick
QT += multimedia
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AldersAmbition
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    widget.cpp \
    status.cpp \
    levelwidget.cpp \
    propertywidget.cpp \
    itemwidget.cpp \
    buttonwidget.cpp \
    eldersbutton.cpp \
    EldersAnimate/eldersanimate.cpp \
    EldersAnimate/eldersinputbox.cpp \
    EldersAnimate/elderslevel.cpp \
    EldersAnimate/eldersmessage.cpp \
    EldersAnimate/eldersmove.cpp \
    EldersAnimate/eldersopen.cpp \
    EldersAnimate/elderspopup.cpp \
    EldersAnimate/elderstele.cpp \
    EldersAnimate/elderswisdom.cpp \
    EldersDisplayObject/eldersaltwall.cpp \
    EldersDisplayObject/eldersany.cpp \
    EldersDisplayObject/eldersarmour.cpp \
    EldersDisplayObject/eldersdestination.cpp \
    EldersDisplayObject/eldersdisplayobject.cpp \
    EldersDisplayObject/eldersdoor.cpp \
    EldersDisplayObject/eldersenemy.cpp \
    EldersDisplayObject/eldersfloor.cpp \
    EldersDisplayObject/eldershelper.cpp \
    EldersDisplayObject/eldersinventory.cpp \
    EldersDisplayObject/elderskey.cpp \
    EldersDisplayObject/eldersmedicine.cpp \
    EldersDisplayObject/eldersmerchant.cpp \
    EldersDisplayObject/eldersstairs.cpp \
    EldersDisplayObject/eldersteleport.cpp \
    EldersDisplayObject/elderstom.cpp \
    EldersDisplayObject/elderswall.cpp \
    EldersDisplayObject/eldersweapon.cpp \
    EldersDisplayObject/elderswit.cpp \
    EldersExpression/eldersassignment.cpp \
    EldersExpression/elderscondition.cpp \
    EldersExpression/eldersexpression.cpp \
    EldersExpression/eldersgoto.cpp \
    EldersExpression/eldersoperand.cpp \
    EldersExpression/eldersoperation.cpp \
    EldersExpression/eldersreference.cpp \
    EldersExpression/eldersvarient.cpp \
    eldersbacksound.cpp \
    eldersmap.cpp \
    eldersobject.cpp \
    elderssoundobject.cpp

HEADERS  += mainwindow.h \
    widget.h \
    status.h \
    levelwidget.h \
    propertywidget.h \
    itemwidget.h \
    buttonwidget.h \
    EldersAnimate/eldersanimate.h \
    EldersAnimate/eldersinputbox.h \
    EldersAnimate/elderslevel.h \
    EldersAnimate/eldersmessage.h \
    EldersAnimate/eldersmove.h \
    EldersAnimate/eldersopen.h \
    EldersAnimate/elderspopup.h \
    EldersDisplayObject/eldersaltwall.h \
    EldersDisplayObject/eldersany.h \
    EldersDisplayObject/eldersarmour.h \
    EldersDisplayObject/eldersdestination.h \
    EldersDisplayObject/eldersdisplayobject.h \
    EldersDisplayObject/eldersdoor.h \
    EldersDisplayObject/eldersenemy.h \
    EldersDisplayObject/eldersfloor.h \
    EldersDisplayObject/eldershelper.h \
    EldersDisplayObject/eldersinventory.h \
    EldersDisplayObject/elderskey.h \
    EldersDisplayObject/eldersmedicine.h \
    EldersDisplayObject/eldersmerchant.h \
    EldersDisplayObject/eldersstairs.h \
    EldersDisplayObject/eldersteleport.h \
    EldersDisplayObject/elderstom.h \
    EldersDisplayObject/elderswall.h \
    EldersDisplayObject/eldersweapon.h \
    EldersDisplayObject/elderswit.h \
    eldersbutton.h \
    eldersbacksound.h \
    eldersmap.h \
    eldersobject.h \
    elderssoundobject.h \
    EldersExpression/eldersassignment.h \
    EldersExpression/elderscondition.h \
    EldersExpression/eldersexpression.h \
    EldersExpression/eldersgoto.h \
    EldersExpression/eldersoperand.h \
    EldersExpression/eldersoperation.h \
    EldersExpression/eldersreference.h \
    EldersExpression/eldersvarient.h \
    EldersAnimate/elderstele.h \
    EldersAnimate/elderswisdom.h

RESOURCES += \
    assets.qrc \
    maps.qrc
