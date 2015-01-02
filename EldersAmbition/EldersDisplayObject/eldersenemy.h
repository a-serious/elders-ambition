#ifndef ELDERSENEMY_H
#define ELDERSENEMY_H

#include "eldersdisplayobject.h"

class EldersEnemy : public EldersDisplayObject
{
    int cnt = 0;

public:
    QPixmap *pix[2];
    EldersEnemy(int, int, int, EldersMap *, QString);
    ~EldersEnemy();
    int damage(EldersMap *);
    virtual void paint(QPainter *);
    virtual bool move(EldersMap *);
};

#endif // ELDERSENEMY_H
