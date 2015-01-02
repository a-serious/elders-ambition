#include "levelwidget.h"

LevelWidget::LevelWidget(EldersMap *map, QWidget *parent) :
    QWidget(parent)
{
    mMap = map;
    setFixedSize(200, 76);
}

void LevelWidget::animate()
{
    repaint();
}

void LevelWidget::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setFont(QFont("Arial", 15));

    painter.drawText(10, 25, QString("严肃的刘小雨同学"));
    //TODO:Need to modify the string as the level change

    QPen pen;
    pen.setColor(QColor("yellow"));
    painter.setPen(pen);

    painter.drawText(120, 55, QString("Level ") + QString::number((*mMap->Tom())["level"].getInt()));

    painter.end();
}
