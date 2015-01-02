#ifndef ELDERSTOM_H
#define ELDERSTOM_H

#include "eldersdisplayobject.h"

class EldersKey;

#include <QSound>
#include <QMap>

class EldersTom : public EldersDisplayObject
{
    QPixmap *Pix[4][3];
    QPixmap *pix;
    QList<EldersKey *> backupKey0;
    QList<EldersKey *> backupKey1;
    QList<EldersKey *> backupKey2;

public:
    EldersTom(int, int, int, EldersMap *);
    QList<EldersDisplayObject *> inventory;

    virtual void paint(QPainter *painter);
    void changePic(int, int);
    virtual bool move(EldersMap *);
    virtual void setProperty(QString, EldersVarient, bool = true);
    virtual EldersVarient &operator[](QString);
    virtual const EldersVarient &operator[](QString) const;
    bool haveInventory(QString);
    bool consumeInventory(QString);
    bool consumeInventory(QString, int);
};

#endif // ELDERSTOM_H
