#ifndef ELDERSMERCHANT_H
#define ELDERSMERCHANT_H

#include "eldersdisplayobject.h"
#include "../EldersAnimate/eldersinputbox.h"

class EldersMerchant : public EldersDisplayObject
{
    int cnt = 0;
    QPixmap *pix[2];

public:
    EldersMerchant(int, int, int, QString, EldersMap *);
    ~EldersMerchant();
    virtual void paint(QPainter *);
    virtual bool move(EldersMap *);
};

#endif // ELDERSMERCHANT_H
