#include "eldersany.h"
#include "eldersmap.h"

EldersAny::EldersAny(int x, int y, int level, EldersMap *parent)
    : EldersDisplayObject(x, y, level, parent)
{
    this->setProperty("pix", EldersVarient(":/images/keythree"));
    property["label"] = "any";
}

EldersAny::~EldersAny()
{
    delete pix;
}

#include <QDebug>

void EldersAny::setProperty(QString propertyName, EldersVarient propertyValue, bool)
{
    if (propertyName == "pix")
        pix = new QPixmap(parent->getResource(propertyValue.getString()));
    //qDebug() << propertyName << ":" << propertyValue.getString();
    EldersDisplayObject::setProperty(propertyName, propertyValue);
}

void EldersAny::paint(QPainter *painter)
{
    painter->drawPixmap(x, y, *pix);
}

bool EldersAny::move(EldersMap *map)
{
    return runAction(map, true);
}
