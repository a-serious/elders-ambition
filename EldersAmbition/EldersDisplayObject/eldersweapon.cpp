#include "eldersweapon.h"

#include <QDebug>

EldersWeapon::EldersWeapon(int x, int y, int level, QString name, EldersMap *parent)
    : EldersInventory(x, y, level, parent)
{
    this->name = name;
    property["label"] = "weapon_" + name;
    appendClass("weapon");
    pix = new QPixmap(":/images/weapon_" + name);
    switch(name.toInt())
    {
    case 1:
        property["attack"] = 100;
        break;
    case 2:
        property["attack"] = 200;
        break;
    default:
        property["attack"] = 300;
        break;
    }
}

bool EldersWeapon::move(EldersMap *map)
{
    map->Tom()->property["attack"] += property["attack"].getInt();
    /*qDebug() <<"Tom:"<< map->Tom()->property["attack"].getInt() <<
                         map->Tom()->property["defend"].getInt() <<
                         map->Tom()->property["health"].getInt();*/
    return EldersInventory::move(map);
}
