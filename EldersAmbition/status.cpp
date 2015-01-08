#include "status.h"

#include <QDebug>
#include <QGridLayout>

Status::Status(EldersMap *map, QWidget *parent) :
    QWidget(parent)
{
    mMap = map;
    setFixedSize(200, 540);

    mLevelWidget = new LevelWidget(map, this);//ymj
    mPropertyWidget = new PropertyWidget(map, this);//ymj
    mItemWidget = new ItemWidget(map, this);//ymj
    //mButtonWidget = new ButtonWidget(this);

    //levelWidget->setFixedSize(200, 76);
    //propertyWidget->setFixedSize(200, 144);
    //itemWidget->setFixedSize(200, 144);

    //ymj
    mLevelWidget->setAutoFillBackground(true); // 这句要加上, 否则可能显示不出背景图.
    QPalette mLevelPalette = mLevelWidget->palette();
    mLevelPalette.setBrush(QPalette::Window, QBrush(QPixmap(":/images/assets/Images/3.png").scaled(
                mLevelWidget->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation))); // 使用平滑的缩放方式
    mLevelWidget->setPalette(mLevelPalette); // 至此, 已给widget加上了背景图.

    mPropertyWidget->setAutoFillBackground(true); // 这句要加上, 否则可能显示不出背景图.
    QPalette mPropertyPalette = mPropertyWidget->palette();
    mPropertyPalette.setBrush(QPalette::Window, QBrush(QPixmap(":/images/assets/Images/1.png").scaled(
                mPropertyWidget->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation))); // 使用平滑的缩放方式
    mPropertyWidget->setPalette(mPropertyPalette); // 至此, 已给widget加上了背景图.

    mItemWidget->setAutoFillBackground(true); // 这句要加上, 否则可能显示不出背景图.
    QPalette mItemPalette = mItemWidget->palette();
    mItemPalette.setBrush(QPalette::Window, QBrush(QPixmap(":/images/assets/Images/1b.png").scaled(
                mItemWidget->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation))); // 使用平滑的缩放方式
    mItemWidget->setPalette(mItemPalette); // 至此, 已给widget加上了背景图.
    //ymj

    QGridLayout *layout = new QGridLayout;
    //layout->addWidget(View);//ymj
    layout->addWidget(mLevelWidget, 0, 0);//ymj
    layout->addWidget(mPropertyWidget, 1, 0);//ymj
    layout->addWidget(mItemWidget, 2, 0);//ymj
    //layout->addWidget(mButtonWidget, 3, 0);

    layout->setContentsMargins(0,0,35,150);//ymj,left,top,right,bottom
    layout->setSpacing(0);

    this->setLayout(layout);//ymj

}

void Status::animate()
{
    repaint();
}

void Status::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setFont(QFont("Arial", 15));

    //painter.drawText(0, 20, QString("EldersTom"));
    //painter.drawText(0, 60, QString("生命: ") + QString::number((*mMap->Tom())["health"].getInt()));
    //painter.drawText(0, 90, QString("攻击: ") + QString::number((*mMap->Tom())["attack"].getInt()));
    //painter.drawText(0, 120, QString("防御: ") + QString::number((*mMap->Tom())["defend"].getInt()));
    //painter.drawText(0, 150, QString("经验: ") + QString::number((*mMap->Tom())["exp"].getInt()));
    //painter.drawText(0, 180, QString("金钱: ") + QString::number((*mMap->Tom())["money"].getInt()));
    //painter.setFont(QFont("Arial", 17, 5));
    //painter.drawText(0, 220, QString("Level ") + QString::number((*mMap->Tom())["level"].getInt()));

    painter.end();

    //ymj
   /* QPainter levelPainter;
    levelPainter.begin(levelWidget);
    levelPainter.setRenderHint(QPainter::Antialiasing);

    levelPainter.setFont(QFont("Arial", 11));

    levelPainter.drawText(10, 10, QString("HAHA"));

    levelPainter.end();*/
    //ymj
}
