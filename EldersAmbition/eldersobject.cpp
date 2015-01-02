#include "eldersobject.h"
#include "EldersExpression/eldersvarient.h"
#include "eldersmap.h"

#include <QDebug>

EldersObject::EldersObject()
{
}

EldersVarient &EldersObject::operator[](QString propertyName)
{
    return property[propertyName];
}

const EldersVarient &EldersObject::operator[](QString propertyName) const
{
    return property.find(propertyName).value();
}

void EldersObject::setProperty(QString propertyName, EldersVarient propertyValue, bool)
{
    property[propertyName] = propertyValue;
}

bool EldersObject::inClass(QString c)
{
    return mClass.contains(c);
}

bool EldersObject::inClass(QList<QString> c)
{
    for (auto i = c.begin(); i != c.end(); i++)
        if (!mClass.contains(*i))
            return false;
    return true;
}

void EldersObject::appendClass(QList<QString> c)
{
    for (auto i = c.begin(); i != c.end(); i++)
        mClass.insert(*i);
}

void EldersObject::appendClass(QString c)
{
    mClass.insert(c);
}

void EldersObject::saveProperty(QTextStream *out)
{
    *out << property.size() << endl;
    for (QHash<QString, EldersVarient>::iterator i = property.begin(); i != property.end(); i++)
        *out << i.key() << ':' << i.value().getOutput() << endl;
}

/*
void EldersObject::loadProperty(QTextStream *in, EldersMap *map)
{
    int length = in->readLine().toInt();
    for (int i = 0; i < length; i++)
    {
        QRegExp rx("^(.*):(.*)$");
        rx.indexIn(in->readLine());
        property[rx.cap(1)] = EldersVarient::setInput(rx.cap(2));
        if (rx.cap(1) == "picked" && rx.cap(2) != "0")
            map->Tom()->inventory.push_back(dynamic_cast<EldersDisplayObject *>(this));
        else if (rx.cap(1) == "position_x")
            dynamic_cast<EldersDisplayObject *>(this)->x = rx.cap(2).toInt() * 32;
        else if (rx.cap(1) == "position_y")
            dynamic_cast<EldersDisplayObject *>(this)->y = rx.cap(2).toInt() * 32;
    }
}*/

void EldersObject::loadProperty(QTextStream *in, EldersMap *)
{
    int length = in->readLine().toInt();
    for (int i = 0; i < length; i++)
    {
        QRegExp rx("^(\\w*):(.*)$");
        rx.indexIn(in->readLine());
        setProperty(rx.cap(1), EldersVarient::setInput(rx.cap(2)));
    }
}
