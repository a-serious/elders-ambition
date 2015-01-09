#include "elderstele.h"
#include "../eldersmap.h"

EldersTele::EldersTele(EldersMap *parent, QString content)
    : EldersAnimate(parent)
{
    floor = new QPixmap(":/images/floor");
    wall = new QPixmap(":/images/wall");
    chosen = new QPixmap(":/images/black");
    this->content = content;
    int currentLevel = parent->Tom()->property["level"].getInt();
    if (currentLevel <= 0) currentLevel = 1;
    xChoose = 2 + (currentLevel - 1) % 6;
    yChoose = 4 + (currentLevel - 1) / 6;
}

EldersTele::~EldersTele()
{
    delete floor;
    delete wall;
    delete chosen;
}

bool EldersTele::paint(QPainter *painter)
{
    if (wantDelete)
        return false;

    int offset = 25;
    for (int i = 1; i < 8; i++)
    {
        painter->drawPixmap(i*50 + offset, 2*50, *wall);
        painter->drawPixmap((i + 1)*50 + offset, 8*50, *wall);
    }
    for (int i = 2; i < 8; i++)
    {
        painter->drawPixmap(1*50 + offset, (i + 1)*50, *wall);
        painter->drawPixmap(8*50 + offset, i*50, *wall);
    }

    for (int i = 2; i < 8; i++)
        for (int j = 3; j < 8; j++)
            if (i == xChoose && j == yChoose)
                painter->drawPixmap(i*50 + offset, j*50, *chosen);
            else
                painter->drawPixmap(i*50 + offset, j*50, *floor);

    painter->setPen("white");
    painter->setFont(QFont("黑体", 14));
    painter->drawText(QRect(2*50 + offset, 3*50, 200, 50), Qt::AlignVCenter | Qt::AlignLeft, content);

    painter->setFont(QFont("黑体", 14, 3));

    int k = 1;
    for (int j = 4; j < 8 && k <= parent->Tom()->property["range"].getInt(); j++)
        for (int i = 2; i < 8 && k <= parent->Tom()->property["range"].getInt(); i++)
        {
            painter->drawText(QRect(i*50 + offset, j*50, 50, 50), Qt::AlignCenter, QString::number(k));
            k++;
        }

    return true;
}

void EldersTele::input(int choice)
{
    switch (choice)
    {
    case Qt::Key_Up:
        if (yChoose - 1 >= 4)
            yChoose--;
        break;
    case Qt::Key_Down:
        if ((yChoose+1-4)*6 + (xChoose-2) + 1 <= parent->Tom()->property["range"].getInt())
            yChoose++;
        break;
    case Qt::Key_Left:
        if (xChoose - 1 >= 2)
            xChoose--;
        break;
    case Qt::Key_Right:
        if ((yChoose-4)*6 + (xChoose+1-2) + 1 <= parent->Tom()->property["range"].getInt() &&
                (xChoose+1-2) < 6)
            xChoose++;
        break;
    case Qt::Key_Return:
    case Qt::Key_Enter:
        int target = xChoose - 2 + (yChoose - 4) * 6 + 1;
        parent->Tom()->setProperty("level", EldersVarient(target), false);
        wantDelete = true;
        break;
    }
}
