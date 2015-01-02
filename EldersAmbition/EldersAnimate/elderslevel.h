#ifndef ELDERSLEVEL_H
#define ELDERSLEVEL_H

#include "eldersanimate.h"

#include <QRect>

class EldersLevel : public EldersAnimate
{
    int cnt = 0;
    int level;
    QString buffer;
    static QRect screen;

public:
    EldersLevel(EldersMap *, int);
    virtual bool paint(QPainter *);
};

#endif // ELDERSLEVEL_H
