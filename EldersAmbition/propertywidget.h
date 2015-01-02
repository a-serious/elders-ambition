#ifndef PROPERTYWIDGET_H
#define PROPERTYWIDGET_H

#include "eldersmap.h"

#include <QWidget>

class PropertyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PropertyWidget(EldersMap *, QWidget *parent = 0);

public slots:
    void animate();

protected:
    void paintEvent(QPaintEvent *);

private:
    EldersMap *mMap;

};

#endif // PROPERTYWIDGET_H
