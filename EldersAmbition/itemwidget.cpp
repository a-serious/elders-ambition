#include "itemwidget.h"

ItemWidget::ItemWidget(EldersMap *map, QWidget *parent) :
    QWidget(parent)
{
    mMap = map;
    setFixedSize(200, 144);
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

    painter.setFont(QFont("Arial", 10));

    QPen pen;
    pen.setColor(QColor("yellow"));
    painter.setPen(pen);

    painter.drawText(10, 15, QString("当前物品"));

    int j = 0;
    for (auto i = mMap->Tom()->inventory.begin(); i != mMap->Tom()->inventory.end(); i++)
    {
        int x = j % 6;
        int y = j / 6;
        (**i)["position_x"] = x, (**i)["position_y"] = y;
        (*i)->x = x * 32 + 3, (*i)->y = y * 32 + 20;//ymj
        (*i)->paint(&painter);
        j++;
    }

    painter.end();
}
