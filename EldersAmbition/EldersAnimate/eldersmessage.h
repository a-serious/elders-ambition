#ifndef ELDERSMESSAGE_H
#define ELDERSMESSAGE_H

#include "eldersanimate.h"

class EldersMessage : public EldersAnimate
{
    QString content;
    QPixmap *black, *wall, *upedge, *downedge, *rightedge, *leftedge, *rightupangle, *leftupangle, *rightdownangle, *leftdownangle;

public:
    EldersMessage(EldersMap *, QString);
    ~EldersMessage();
    virtual bool paint(QPainter *);
};

#endif // ELDERSMESSAGE_H
