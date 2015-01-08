#include "elderspopup.h"
#include "../eldersmap.h"

EldersPopup::EldersPopup(EldersMap *parent, QString content)
    : EldersAnimate(parent)
{
    this->content = content;
    parent->appendSound(":/sounds/popup");
    background = QPixmap(":/images/black");
}

QRect EldersPopup::screen(1 * 50, 4 * 50 + 24, 9 * 50, 50 + 25);

bool EldersPopup::paint(QPainter *painter)
{
    painter->save();
    if (cnt < 10)
    {
        painter->setOpacity(cnt / 10.0);
    }
    else if (cnt < 30)
    {
        painter->setOpacity(1);
    }
    else if (cnt < 40)
    {
        painter->setOpacity((40 - cnt) / 10.0);
    }

    if (cnt < 40)
    {
        painter->setBrush(QBrush(background));
        painter->drawRect(screen);

        painter->setPen("chocolate");
        painter->setFont(QFont("黑体", 17, 2));
        painter->drawText(screen, Qt::AlignCenter, content);
    }
    else
    {
        painter->restore();
        return false;
    }
    painter->restore();
    cnt++;
    return true;
}
