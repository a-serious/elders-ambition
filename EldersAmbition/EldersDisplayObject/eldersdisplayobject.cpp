#include "eldersdisplayobject.h"
#include "../EldersExpression/eldersexpression.h"
#include "../EldersExpression/eldersvarient.h"

EldersDisplayObject::EldersDisplayObject(int x, int y, int level, EldersMap *parent)
{
    property["position_x"] = x;
    property["position_y"] = y;
    property["level"] = level;
    this->x = x * 50, this->y = y * 50;//ymj
    this->parent = parent;
    property["picked"] = 0;
    property["enabled"] = 1;
    property["id"] = "";
}

EldersDisplayObject::~EldersDisplayObject()
{
    /*
    for (auto i = action.begin(); i != action.end(); i++)
        if (*i)
            delete *i;
    */
}

QString EldersDisplayObject::getLabel()
{
    return property["label"].getString();
}

void EldersDisplayObject::setProperty(QString propertyName, EldersVarient propertyValue, bool)
{
    if (propertyName == "position_x")
        x = propertyValue.getInt() * 50;//ymj
    if (propertyName == "position_y")
        y = propertyValue.getInt() * 50;//ymj
    if (propertyName == "label")
        return;
    if (propertyName == "drop")
    {
        EldersDisplayObject *nonConst = const_cast<EldersDisplayObject *>(this);
        nonConst->property["enabled"] = 0;
        nonConst->setProperty("picked", 0);
        return;
    }
    if (propertyName == "pick")
    {
        EldersDisplayObject *nonConst = const_cast<EldersDisplayObject *>(this);
        nonConst->setProperty("picked", 1);
        return;
    }
    if (propertyName == "picked")
    {
        if (propertyValue.isTrue())
        {
            property["enabled"] = 0;
            for (auto i = parent->Tom()->inventory.begin(); i != parent->Tom()->inventory.end(); i++)
                if ((*i)->getLabel() >= getLabel())
                {
                    parent->Tom()->inventory.insert(i, this);
                    goto exit;
                }
            parent->Tom()->inventory.append(this);
        }
        else
            parent->Tom()->inventory.removeAll(this);
    }
exit:
    EldersObject::setProperty(propertyName, propertyValue);
}

void EldersDisplayObject::setAction(EldersExpression *action)
{
    this->action.append(action);
}

bool EldersDisplayObject::runAction(EldersMap *map, bool mask)
{
    map->property["return"] = mask;
    EldersExpression::setEnvironment(this);
    for (auto i = action.begin(); i != action.end(); i++)
        (*i)->run(map);
    EldersExpression::setEnvironment(NULL);
    return map->property["return"].getInt();
}
