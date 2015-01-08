#include "elderskey.h"
#include "../EldersAnimate/elderspopup.h"

const int EldersKey::yellow = 0;
const int EldersKey::blue = 1;
const int EldersKey::red = 2;
const int EldersKey::silver = 3;

EldersKey::EldersKey(int x, int y, int level, EldersMap *parent, int color)
    : EldersInventory(x, y, level, parent)
{
    property["label"] = "key";
    appendClass("key");
    property["color"] = color;
    this->color = color;
    switch(color)
    {
    case yellow:
        pix = new QPixmap(":/images/key_yellow");
        break;
    case blue:
        pix = new QPixmap(":/images/key_blue");
        break;
    case red:
        pix = new QPixmap(":/images/key_red");
        break;
    default:
        pix = new QPixmap(":/images/key_silver"); // didn't find this kind of key...
        break;
    }
}

bool EldersKey::move(EldersMap *map)
{
    bool ret = EldersInventory::move(map);
    switch (color)
    {
    case yellow:
        parent->appendPopup("您获得了一只滚轮鼠标");
        break;
    case blue:
        parent->appendPopup("您获得了一只光电鼠标");
        break;
    case red:
        parent->appendPopup("您获得了一只无线鼠标");
        break;
    }
    return ret;
}

QString EldersKey::getLabel()
{
    return property["label"].getString() + "_" + QString::number(color);
}
