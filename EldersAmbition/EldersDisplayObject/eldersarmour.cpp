#include "eldersarmour.h"
#include "../eldersmap.h"

#include <QDebug>

EldersArmour::EldersArmour(int x, int y, int level, QString name, EldersMap *parent)
    : EldersInventory(x, y, level, parent)
{
    this->name = name;
    property["label"] = "armour_" + name;
    appendClass("armour");
    pix = new QPixmap(":/images/armour_" + name);
    switch(name.toInt())
    {
    case 1:
        property["defend"] = 100;
        break;
    case 2:
        property["defend"] = 200;
        break;
    default:
        property["defend"] = 300;
        break;
    }
}

bool EldersArmour::move(EldersMap *map)
{
    map->Tom()->property["defend"] += property["defend"].getInt();
    /*qDebug() <<"Tom:"<< map->Tom()->property["attack"].getInt() <<
                         map->Tom()->property["defend"].getInt() <<
                         map->Tom()->property["health"].getInt();*/
    return EldersInventory::move(map);
}
