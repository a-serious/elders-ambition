#ifndef BUTTONWIDGET_H
#define BUTTONWIDGET_H

#include "eldersbutton.h"

#include <QWidget>
#include <QGridLayout>

class ButtonWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ButtonWidget(QWidget *parent = 0);

public slots:

private:
    EldersButton *mEldersButton;

};

#endif // BUTTONWIDGET_H
