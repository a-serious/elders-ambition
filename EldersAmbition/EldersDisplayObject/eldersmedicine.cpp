#include "eldersmedicine.h"
#include "../eldersmap.h"

#include <QDebug>

EldersMedicine::EldersMedicine(int x, int y, int level, QString name, EldersMap *parent)
    : EldersDisplayObject(x, y, level, parent)
{
    property["label"] = "medicine_" + name;
    appendClass("medicine");
    pix = new QPixmap(":/images/medicine_" + name);
    switch(name.toInt())
    {
    case 1:
        property["health"] = 100;
        break;
    case 2:
        property["health"] = 200;
        break;
    case 3:
        property["attack"] = 200;
        break;
    case 4:
        property["defend"] = 200;
        break;
    }
}

EldersMedicine::~EldersMedicine()
{
    delete pix;
}

void EldersMedicine::paint(QPainter *painter)
{
    painter->drawPixmap(x, y, *pix);
}

bool EldersMedicine::move(EldersMap *map)
{
    if (property["label"].getString() == "medicine_1" || property["label"].getString() == "medicine_2")
        map->Tom()->property["health"] += property["health"].getInt();
    else if (property["label"].getString() == "medicine_3")
        map->Tom()->property["attack"] += property["attack"].getInt();
    else
        map->Tom()->property["defend"] += property["defend"].getInt();

    property["enabled"] = 0;
    /*qDebug() <<"Tom:"<< map->Tom()->property["attack"].getInt() <<
                         map->Tom()->property["defend"].getInt() <<
                         map->Tom()->property["health"].getInt();*/
    bool ret = runAction(map, false);

    QString label = property["label"].getString(), t;
    if (label == "medicine_1")
        t = "您获得了小血瓶 生命加" + QString::number(property["health"].getInt());
    else if (label == "medicine_2")
        t = "您获得了大血瓶 生命加" + QString::number(property["health"].getInt());
    else if (label == "medicine_3")
        t = "您获得了红宝石 攻击加" + QString::number(property["attack"].getInt()) + "点";
    else if (label == "medicine_4")
        t = "您获得了蓝宝石 防御加" + QString::number(property["defend"].getInt()) + "点";
    map->appendPopup(t);

    return ret;
}
