#ifndef ELDERSANIMATE_H
#define ELDERSANIMATE_H

class EldersMap;

#include <QWaitCondition>
#include <QMutex>
#include <QPainter>

#include "./EldersDisplayObject/eldersdisplayobject.h"

class EldersAnimate : public QWaitCondition, public QMutex
{
protected:
    EldersMap *parent;
public:
    bool wantDelete;
    int duration;
    EldersAnimate(EldersMap *);
    EldersAnimate(EldersMap *, int);
    virtual bool paint(QPainter *) = 0; // false -> please destroy me.
};

#endif // ELDERSANIMATE_H
