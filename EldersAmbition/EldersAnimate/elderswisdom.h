#ifndef ELDERSWISDOM_H
#define ELDERSWISDOM_H

#include "eldersanimate.h"
#include "../eldersmap.h"

class EldersWisdom : public EldersAnimate
{
    int cnt = 0;
    QPixmap *black, *wall;

public:
    EldersWisdom(EldersMap *);
    ~EldersWisdom();
    virtual bool paint(QPainter *);
};

#endif // ELDERSWISDOM_H
