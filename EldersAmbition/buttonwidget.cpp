#include "buttonwidget.h"

ButtonWidget::ButtonWidget(QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(200, 100);

    mEldersButton = new EldersButton(this);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(mEldersButton, 0, 0);

    this->setLayout(layout);
}
