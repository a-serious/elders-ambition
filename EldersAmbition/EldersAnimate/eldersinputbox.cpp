#include "eldersinputbox.h"
#include "../eldersmap.h"
#include "eldersmessage.h"

EldersInputBox::EldersInputBox(EldersMap *parent, QString content, QStringList entries)
    : EldersAnimate(parent)
{
    this->content = content;
    this->entries = entries;
    black = new QPixmap(":/images/black");
    wall = new QPixmap(":/images/wall");
    rightedge = new QPixmap(":/images/right_edge");
    rightdownangle = new QPixmap(":/images/rightdown_angle");
    rightupangle = new QPixmap(":/images/rightup_angle");
    leftedge = new QPixmap(":/images/left_edge");
    leftdownangle = new QPixmap(":/images/leftdown_angle");
    leftupangle = new QPixmap(":/images/leftup_angle");
    upedge = new QPixmap(":/images/up_edge");
    downedge = new QPixmap(":/images/down_edge");
    leftmiddle = new QPixmap(":/images/left_middle");
    rightmiddle = new QPixmap(":/images/right_middle");
    middle = new QPixmap(":/images/middle");

    parent->setProperty("input", 0);
}

void EldersInputBox::input(int choice)
{
    for (int i = 1; i <= entries.size(); i++)
        if (choice - Qt::Key_0 == i)
        {
            wantDelete = true;
            parent->setProperty("input", i);
            //parent->appendAnimate(new EldersMessage(parent, "you choosed "+QString::number(i)), false);
        }
}

bool EldersInputBox::paint(QPainter *painter)
{
    if (wantDelete)
        return false;

    painter->setPen("white");
    int k = 1, l = 2, margin_top = 17;
    painter->drawPixmap(l*50, k*50, *leftupangle);
    for (l = 3; l <= 7; l++)
        painter->drawPixmap(l*50, k*50, *upedge);
    painter->drawPixmap(l*50, k*50, *rightupangle);
    k++;

    l = 2;
    painter->drawPixmap(l*50, k*50, *leftedge);
    for (l = 3; l <= 7; l++)
        painter->drawPixmap(l*50, k*50, *black);
    painter->drawPixmap(l*50, k*50, *rightedge);
    l = 3;
    painter->drawText(QRect(QPoint(80 + 16, 48 + 8), QPoint(272 - 16, 96 + 16 - 8)), Qt::AlignVCenter | Qt::TextWordWrap, content);

    for (auto i = entries.begin(); i != entries.end(); i++)
    {
        k++;
        l = 2;
        painter->drawPixmap(l*50, k*50, *leftmiddle);
        for (l = 3; l <= 7; l++)
            painter->drawPixmap(l*50, k*50, *middle);
        painter->drawPixmap(l*50, k*50, *rightmiddle);
        if(i+1 == entries.end())
        {
            k++;
            l = 2;
            painter->drawPixmap(l*50, k*50, *leftdownangle);
            for (l = 3; l <= 7; l++)
                painter->drawPixmap(l*50, k*50, *downedge);
            painter->drawPixmap(l*50, k*50, *rightdownangle);
            k--;
        }
        l = 3;
        if (i != entries.begin())
            painter->drawText(l*50, (k-1)*50 + 2*margin_top, (*(i-1)));
    }
    auto i = entries.end();
    painter->drawText(l*50, k*50 + 2*margin_top, (*(i-1)));

    return true;
}
