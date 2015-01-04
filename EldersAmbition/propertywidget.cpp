#include "propertywidget.h"

PropertyWidget::PropertyWidget(EldersMap *map, QWidget *parent) :
    QWidget(parent)
{
    mMap = map;
    setFixedSize(200, 144);
}

void PropertyWidget::animate()
{
    repaint();
}

void PropertyWidget::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setFont(QFont("Arial", 10));

    QPen pen;
    pen.setColor(QColor("yellow"));
    painter.setPen(pen);

    painter.drawText(10, 15, QString("当前属性"));

    painter.setFont(QFont("Arial", 12));

    pen.setColor(QColor("black"));
    painter.setPen(pen);

    painter.drawText(10, 35, QString("生命: ") + QString::number((*mMap->Tom())["health"].getInt()));
    painter.drawText(10, 55, QString("攻击: ") + QString::number((*mMap->Tom())["attack"].getInt()));
    painter.drawText(10, 75, QString("防御: ") + QString::number((*mMap->Tom())["defend"].getInt()));
    painter.drawText(10, 95, QString("经验: ") + QString::number((*mMap->Tom())["exp"].getInt()));
    painter.drawText(10, 115, QString("金钱: ") + QString::number((*mMap->Tom())["money"].getInt()));
    painter.drawText(10, 135, QString("人民币: ") + QString::number((*mMap->Tom())["RMB"].getInt()));

    painter.end();
}
