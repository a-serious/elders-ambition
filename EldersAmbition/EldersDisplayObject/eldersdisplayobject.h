#ifndef ELDERSDISPLAYOBJECT_H
#define ELDERSDISPLAYOBJECT_H

#include "../eldersobject.h"

class EldersMap;

#include <QPainter>
#include <QList>

class EldersExpression;

class EldersDisplayObject : public EldersObject
{
    QList<EldersExpression *>action;

protected:
    EldersMap *parent;
    virtual QString getLabel();

public:
    int x, y;
    EldersDisplayObject(int, int, int, EldersMap *);
    virtual ~EldersDisplayObject();
    virtual void paint(QPainter *) = 0;
    virtual bool move(EldersMap *) = 0;
    virtual void setProperty(QString, EldersVarient, bool = true);

    void setAction(EldersExpression *);
    bool runAction(EldersMap *, bool);
};

#endif // ELDERSDISPLAYOBJECT_H
