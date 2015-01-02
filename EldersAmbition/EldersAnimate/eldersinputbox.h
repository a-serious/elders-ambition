#ifndef ELDERSINPUTBOX_H
#define ELDERSINPUTBOX_H

#include "eldersanimate.h"

#include <QStringList>

class EldersInputBox : public EldersAnimate
{
    QString content;
    QStringList entries;
    QPixmap *black, *wall, *upedge, *downedge, *rightedge, *leftedge, *rightupangle, *leftupangle, *rightdownangle, *leftdownangle, *leftmiddle, *rightmiddle, *middle;

public:
    EldersInputBox(EldersMap *, QString, QStringList);
    void input(int);
    virtual bool paint(QPainter *);
};

#endif // ELDERSINPUTBOX_H
