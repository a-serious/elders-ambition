#include "eldershelper.h"

#include "eldersarmour.h"
#include "eldersdoor.h"
#include "eldersenemy.h"
#include "eldersfloor.h"
#include "elderskey.h"
#include "eldersstairs.h"
#include "elderstom.h"
#include "elderswall.h"
#include "eldersweapon.h"
#include "eldersmedicine.h"
#include "elderswit.h"
#include "eldersmerchant.h"
#include "eldersteleport.h"
#include "eldersdestination.h"
#include "eldersaltwall.h"
#include "eldersany.h"
#include "eldersfloor.h"

#include "../eldersmap.h"

#include <QRegExp>

QHash<QString, QString> EldersHelper::alias = QHash<QString, QString>();

EldersDisplayObject *EldersHelper::createObject(QString target, QString Id, QList<QString> Class, int x, int y, int level, EldersMap *map)
{
    static bool isFirstTime = 1;
    if (isFirstTime)
    {
        isFirstTime = 0;
        EldersHelper::alias.clear();
        alias["a"] = "armour";
        alias["dr"] = "door";
        alias["e"] = "enemy";
        alias["k"] = "key";
        alias["up"] = "up";
        alias["dn"] = "down";
        alias["t"] = "tom";
        alias["w"] = "wall";
        alias["s"] = "weapon"; // sword
        alias["m"] = "medicine";
        alias["wi"] = "wit";
        alias["me"] = "merchant";
        alias["te"] = "teleport";
        alias["d"] = "destination";
        alias["aw"] = "altwall";
        alias["an"] = "any";
        alias["f"] = "floor";
    }
    QRegExp rx("^([a-zA-Z0-9]*)(_(\\S*))?");
    rx.indexIn(target);

    QString category = rx.cap(1);
    QString detail = (rx.captureCount() >= 2) ? rx.cap(3) : "";
    if (alias.find(category) != alias.end())
        target = (category = alias[category]) + ((detail.isEmpty()) ? "" : "_" + detail);

    EldersDisplayObject *ret = NULL;
    if (category == "armour")
        ret = new EldersArmour(x, y, level, detail, map);
    else if (category == "door")
        ret = new EldersDoor(x, y, level, map, detail.toInt());
    else if (category == "enemy")
        ret = new EldersEnemy(x, y, level, map, detail);
    else if (category == "key")
        ret = new EldersKey(x, y, level, map, detail.toInt());
    else if (category == "up")
        ret = new EldersStairs(x, y, level, map, 1);
    else if (category == "down")
        ret = new EldersStairs(x, y, level, map, -1);
    else if (category == "tom")
    {
        map->Tom()->setProperty("position_x", x);
        map->Tom()->setProperty("position_y", y);
        map->Tom()->setProperty("level", level);
    }
    else if (category == "wall")
        ret = new EldersWall(x, y, level, map);
    else if (category == "weapon")
        ret = new EldersWeapon(x, y, level, detail, map);
    else if (category == "medicine")
        ret = new EldersMedicine(x, y, level, detail, map);
    else if (category == "wit")
        ret = new EldersWit(x, y, level, map);
    else if (category == "merchant")
        ret = new EldersMerchant(x, y, level, detail, map);
    else if (category == "teleport")
        ret = new EldersTeleport(x, y, level, map);
    else if (category == "destination")
        ret = new EldersDestination(x, y, level, detail.toInt(), map);
    else if (category == "altwall")
        ret = new EldersAltWall(x, y, level, map, detail);
    else if (category == "any")
        ret = new EldersAny(x, y, level, map);
    else if (category == "floor")
        ret = new EldersFloor(x, y, level, map);
    else
        throw "No such label...";

    if (ret)
    {
        ret->appendClass(Class);
        (*ret)["id"] = Id;
    }

    return ret;
}
