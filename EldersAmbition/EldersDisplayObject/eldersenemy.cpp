#include "eldersenemy.h"
#include "../eldersmap.h"

#include <QPainter>
#include <QDebug>

EldersEnemy::EldersEnemy(int x, int y, int level, EldersMap *parent, QString name)
    : EldersDisplayObject(x, y, level, parent)
{
    property["label"] = "enemy_" + name;
    appendClass("enemy");
    pix[0] = new QPixmap(":/images/enemy_" + name + ".0");
    pix[1] = new QPixmap(":/images/enemy_" + name + ".1");
    switch(name.toInt())
    {
    case 1:
        property["attack"] = 10;
        property["defend"] = 100;
        property["health"] = 100;
        property["exp"] = 100;
        property["money"] = 100;
        break;
    case 2:
        property["attack"] = 80;
        property["defend"] = 200;
        property["health"] = 200;
        property["exp"] = 200;
        property["money"] = 200;
        break;
    case 3:
        property["attack"] = 230;
        property["defend"] = 100;
        property["health"] = 300;
        property["exp"] = 300;
        property["money"] = 300;
        break;
    case 4:
        property["attack"] = 200;
        property["defend"] = 130;
        property["health"] = 400;
        property["exp"] = 400;
        property["money"] = 400;
        break;
    case 5:
        property["attack"] = 100;
        property["defend"] = 200;
        property["health"] = 500;
        property["exp"] = 500;
        property["money"] = 500;
        break;
    default:
        property["attack"] = 70;
        property["defend"] = 100;
        property["health"] = 16000;
        property["exp"] = 600;
        property["money"] = 600;
        break;
    }
}

EldersEnemy::~EldersEnemy()
{
    delete pix[0];
    delete pix[1];
}

int EldersEnemy::damage(EldersMap *map)
{
    int kill = map->Tom()->property["attack"].getInt() - property["defend"].getInt();
    int casualty = property["attack"].getInt() - map->Tom()->property["defend"].getInt();
    int enemyHealth = property["health"].getInt();
    if (casualty <= 0) return 0;
    if (kill <= 0) return -1;
    int turns = (enemyHealth % kill) ? (enemyHealth / kill + 1) : (enemyHealth / kill);
    Q_ASSERT(turns > 0);
    return (turns - 1) * casualty;
}

void EldersEnemy::paint(QPainter *painter)
{
    painter->drawPixmap(x, y, cnt-- > 10 ? *pix[0] : *pix[1]);
    if (property["label"].getString() == "enemy_31")
        {
            painter->drawPixmap(x-50, y-100, QPixmap(":/images/enemy_31.00"));
            painter->drawPixmap(x, y-100, QPixmap(":/images/enemy_31.01"));
            painter->drawPixmap(x+50, y-100, QPixmap(":/images/enemy_31.02"));
            painter->drawPixmap(x-50, y-50, QPixmap(":/images/enemy_31.10"));
            painter->drawPixmap(x, y-50, QPixmap(":/images/enemy_31.11"));
            painter->drawPixmap(x+50, y-50, QPixmap(":/images/enemy_31.12"));
            painter->drawPixmap(x-50, y, QPixmap(":/images/enemy_31.20"));
            painter->drawPixmap(x+50, y, QPixmap(":/images/enemy_31.22"));
        }
    if (cnt <= 0) cnt = 20;
}

bool EldersEnemy::move(EldersMap *map)
{
    /*qDebug() << property["label"].getString() <<
                property["attack"].getInt() <<
                property["defend"].getInt() <<
                property["health"].getInt();*/
    bool ret;

    int kill = map->Tom()->property["attack"].getInt() - property["defend"].getInt();
    int casualty = property["attack"].getInt() - map->Tom()->property["defend"].getInt();
    int tomHealth = map->Tom()->property["health"].getInt();
    int enemyHealth = property["health"].getInt();


    if (kill <= 0)
    {
        //qDebug() << "can't break defence!!";
        ret = false;
    }
    else if(casualty <= 0)
    {
        //qDebug() << "Tom health left:" << map->Tom()->property["health"].getInt();
        map->Tom()->property["exp"] += property["exp"].getInt();
        map->Tom()->property["money"] += property["money"].getInt();
        property["enabled"] = 0;
        parent->appendSound(":/sounds/attack");
        ret = true;
    }
    else
    {
        int turns = (enemyHealth % kill) ? (enemyHealth / kill + 1) : (enemyHealth / kill);
        Q_ASSERT(turns > 0);
        int damage = (turns - 1) * casualty;
        if (damage >= tomHealth)
            ret = false;
        else
        {
            map->Tom()->property["exp"] += property["exp"].getInt();
            map->Tom()->property["money"] += property["money"].getInt();
            map->Tom()->property["health"] -= damage;
            property["enabled"] = 0;
            parent->appendSound(":/sounds/attack");
            ret = true;
        }
    }
    ret = runAction(map, ret);
    if (ret)
        parent->appendPopup(QString("获得经验: ") + QString::number(property["exp"].getInt()) +
                "  金币: " + QString::number(property["money"].getInt()));

    return ret;
}
