#ifndef ELDERSTELE_H
#define ELDERSTELE_H

#include "eldersanimate.h"

class EldersTele : public EldersAnimate
{
    QPixmap *floor, *wall, *chosen;
    QString content;
    int xChoose, yChoose;

public:
    EldersTele(EldersMap *, QString = "你想去哪层?");
    ~EldersTele();
    virtual bool paint(QPainter *);
    void input(int);
};

#endif // ELDERSTELE_H
