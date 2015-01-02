#include "widget.h"
#include "eldersmap.h"

#include "EldersAnimate/elderspopup.h"
#include "EldersExpression/eldersexpression.h"

#include <QPainter>
#include <QTimer>
#include <QKeyEvent>
#include <QQuickView>//ymj
#include <QDeclarativeView>//ymj

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(600, 550);//ymj

    //QQuickView *View = new QQuickView;
    //View->setSource(QUrl("qrc:/UI/MainWindowNew.qml"));
    //View->show();

    mMap = new EldersMap();

    mapToLoad = "";
    recToLoad = "";
    recToSave = "";
}

EldersMap *Widget::getMap()
{
    return mMap;
}

void Widget::saveRec(QString filename)
{
    recToSave = filename;
}

void Widget::loadRec(QString filename)
{
    recToLoad = filename;
}

void Widget::loadMap(QString filename)
{
    mapToLoad = filename;
}

bool loadingFlag = false;

void Widget::animate()
{
    if (loadingFlag)
        return;

    if (!mapToLoad.isEmpty())
    {
        loadingFlag = true;
        if (mMap->loadMap(mapToLoad))
            mMap->appendPopup("Map Load succeeded.", false);
        else
        {
            EldersExpression::onList.clear();
            EldersExpression::atList.clear();
            mMap->initialize();
            mMap->appendPopup("Bad Map. Info are shown in the console.", false);
        }
        mapToLoad = "";
        loadingFlag = false;
    }
    if (!recToLoad.isEmpty())
    {
        loadingFlag = true;
        if (mMap->loadRecord(new QFile(recToLoad)))
            mMap->appendPopup("Record Load succeeded.", false);
        else
        {
            EldersExpression::onList.clear();
            EldersExpression::atList.clear();
            mMap->initialize();
            mMap->appendPopup("Bad Record. Info are shown in the console.", false);
        }
        recToLoad = "";
        loadingFlag = false;
    }
    if (!recToSave.isEmpty())
    {
        loadingFlag = true;
        if (mMap->saveRecord(new QFile(recToSave)))
            mMap->appendPopup("Record Saved succeeded.", false);
        else
        {
            EldersExpression::onList.clear();
            EldersExpression::atList.clear();
            mMap->initialize();
            mMap->appendPopup("Bad operation. Info are shown in the console.", false);
        }
        recToSave = "";
        loadingFlag = false;
    }
    else
        repaint();
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    mMap->paint(&painter);
    painter.end();
}

void Widget::keyPressEvent(QKeyEvent *e)
{
    mMap->keyPressEvent(e);
}
