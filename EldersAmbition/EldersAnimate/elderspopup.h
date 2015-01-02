#ifndef ELDERSPOPUP_H
#define ELDERSPOPUP_H

#include "eldersanimate.h"

class EldersPopup : public EldersAnimate
{
    int cnt = 0;
    QString content;
    static QRect screen;
    QPixmap background;

public:
    EldersPopup(EldersMap *, QString);
    virtual bool paint(QPainter *);
};

#endif // ELDERSPOPUP_H
