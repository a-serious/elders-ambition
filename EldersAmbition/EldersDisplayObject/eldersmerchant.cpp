#include "eldersmerchant.h"
#include "../eldersmap.h"

#include <QStringList>

EldersMerchant::EldersMerchant(int x, int y, int level, QString name, EldersMap *parent)
    : EldersDisplayObject(x, y, level, parent)
{
    property["label"] = "merchant_" + name;
    appendClass("merchant");
    pix[0] = new QPixmap(":/images/merchant_" + name + ".0");
    pix[1] = new QPixmap(":/images/merchant_" + name + ".1");

}

EldersMerchant::~EldersMerchant()
{
    delete pix[0];
    delete pix[1];
}

void EldersMerchant::paint(QPainter *painter)
{
    painter->drawPixmap(x, y, cnt-- > 10 ? *pix[0] : *pix[1]);
    if (property["label"].getString() == "merchant_3")
    {
        painter->drawPixmap(x-50, y, QPixmap(":/images/merchant_3.2"));
        painter->drawPixmap(x+50, y, QPixmap(":/images/merchant_3.3"));
    }
    if (cnt <= 0) cnt = 20;

}

bool EldersMerchant::move(EldersMap *map)
{
    return runAction(map, false);
}
