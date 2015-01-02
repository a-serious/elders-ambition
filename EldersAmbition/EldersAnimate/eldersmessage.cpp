#include "eldersmessage.h"

EldersMessage::EldersMessage(EldersMap *parent, QString content)
    : EldersAnimate(parent)
{
    this->content = content;
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
}

EldersMessage::~EldersMessage()
{
    delete black;
    delete wall;
    delete rightedge;
    delete rightdownangle;
    delete rightupangle;
    delete leftedge;
    delete leftdownangle;
    delete leftupangle;
    delete upedge;
    delete downedge;
}

bool EldersMessage::paint(QPainter *painter)
{
    if (wantDelete)
        return false;

    painter->save();
    painter->setOpacity(0.8);

    painter->drawPixmap(1*50, 2*50, *leftupangle);
    painter->drawPixmap(9*50, 2*50, *rightupangle);
    painter->drawPixmap(1*50, 8*50, *leftdownangle);
    painter->drawPixmap(9*50, 8*50, *rightdownangle);
    for(int i = 2; i <= 8; i++)
    {
        painter->drawPixmap(i*50, 2*50, *upedge);
        painter->drawPixmap(i*50, 8*50, *downedge);
    }
    for(int i = 3; i <= 7; i++)
    {
        painter->drawPixmap(1*50, i*50, *leftedge);
        painter->drawPixmap(9*50, i*50, *rightedge);
    }

    for (int i = 2; i <= 8; i++)
        for(int j = 3; j <= 7; j++)
            painter->drawPixmap(i*50, j*50, *black);

    int margin_top = 17;
    painter->setPen("white");
    painter->setFont(QFont("黑体", 14));
    painter->setOpacity(1);
    painter->drawText(QRect(3*50, margin_top + 3*50, 5*50, 3*50 + 16), content);

    painter->restore();

    return true;
}
