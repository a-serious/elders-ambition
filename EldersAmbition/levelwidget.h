#ifndef LEVELWIDGET_H
#define LEVELWIDGET_H

#include "eldersmap.h"

#include <QWidget>

class LevelWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LevelWidget(EldersMap *, QWidget *parent = 0);

public slots:
    void animate();

protected:
    void paintEvent(QPaintEvent *);

private:
    EldersMap *mMap;

};

#endif // LEVELWIDGET_H
