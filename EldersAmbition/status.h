#ifndef STATUS_H
#define STATUS_H

#include "eldersmap.h"
#include "levelwidget.h"
#include "propertywidget.h"
#include "itemwidget.h"
#include "buttonwidget.h"

#include <QWidget>

class Status : public QWidget
{
    Q_OBJECT
public:
    explicit Status(EldersMap *, QWidget *parent = 0);

public slots:
    void animate();

protected:
    void paintEvent(QPaintEvent *);

private:
    EldersMap *mMap;
    LevelWidget *mLevelWidget;//ymj
    PropertyWidget *mPropertyWidget;//ymj
    ItemWidget *mItemWidget;//ymj
    //ButtonWidget *mButtonWidget;//ymj
};

#endif // STATUS_H
