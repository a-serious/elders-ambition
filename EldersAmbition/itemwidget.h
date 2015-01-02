#ifndef ITEMWIDGET_H
#define ITEMWIDGET_H

#include "eldersmap.h"

#include <QWidget>

class ItemWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ItemWidget(EldersMap *, QWidget *parent = 0);

public slots:
    void animate();

protected:
    void paintEvent(QPaintEvent *);

private:
    EldersMap *mMap;

};

#endif // ITEMWIDGET_H
