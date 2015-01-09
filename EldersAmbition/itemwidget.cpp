#include "itemwidget.h"

ItemWidget::ItemWidget(EldersMap *map, QWidget *parent) :
    QWidget(parent)
{
    mMap = map;
    setFixedSize(200, 269);
}

void ItemWidget::animate()
{
    repaint();
}

void ItemWidget::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setFont(QFont("黑体", 10));

    QPen pen;
    pen.setColor(QColor("yellow"));
    painter.setPen(pen);

    painter.drawText(10, 15, QString("当前物品"));

    int j = 0;
    for (auto i = mMap->Tom()->inventory.begin(); i != mMap->Tom()->inventory.end(); i++)
    {
        int x = j % 4;
        int y = j / 4;
        (**i)["position_x"] = x, (**i)["position_y"] = y;
        (*i)->x = x * 45 , (*i)->y = y * 45 + 20;//ymj
        (*i)->paint(&painter);
        j++;
    }

    painter.end();
}
