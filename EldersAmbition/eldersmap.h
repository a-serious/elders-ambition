#ifndef ELDERSMAP_H
#define ELDERSMAP_H

#include "EldersDisplayObject/eldersfloor.h"
#include "EldersDisplayObject/elderstom.h"
#include "EldersDisplayObject/eldersdisplayobject.h"
#include "eldersbacksound.h"
#include "EldersAnimate/eldersanimate.h"

#include <QMutex>
#include <QReadWriteLock>
#include <QTimer>
#include <QFile>
#include <QKeyEvent>
#include <QList>
#include <QWaitCondition>

class KeyThread;

class EldersMap : public EldersObject
{
    friend class Widget;

    EldersTom *mTom;

    EldersFloor *floor[121];
    EldersFloor *inventory[24];

    QTimer *animateTimer;

    void destoryList();
    void initialize();

    QStringList soundToPlay;
    QMutex soundListLock;

    QString mapPath;

public:
    int animateFlag = 0;
    QList<EldersAnimate *> animateList;
    QReadWriteLock animateListLock;

    EldersBackSound *mBackSound;

    bool move(int, int); // direction

    EldersMap();
    QList<EldersDisplayObject *> displayList;

    bool loadMap(QString = "");
    bool saveRecord(QFile * = NULL);
    bool loadRecord(QFile * = NULL);
    void paint(QPainter *);

    int eventFlag = 0;
    void keyPressEvent(QKeyEvent *);

    void appendPopup(QString, bool = false);
    void appendAnimate(EldersAnimate *, bool);
    void appendObject(EldersDisplayObject *);

    void appendSound(QString);

    QList<EldersObject *> findDisplayObject(QString, QString, QList<QString>);

    virtual void setProperty(QString, EldersVarient, bool = true);
    //bool eraseMapObject(QString, int, int);

    void setPath(QString);
    QString getResource(QString);

    EldersTom *Tom();
};

#endif // ELDERSMAP_H
