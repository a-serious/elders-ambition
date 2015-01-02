#ifndef ELDERSBACKSOUND_H
#define ELDERSBACKSOUND_H

#include "elderssoundobject.h"

#include <QtMultimedia/QSound>
#include <QMutex>

class EldersBackSound : public EldersSoundObject
{
    QSound *mSound[5];
    int now;
    QMutex soundMutex;

public:
    EldersBackSound();
    virtual void play(int = 0);
    virtual void stop();
    void change(int);
};

#endif // ELDERSBACKSOUND_H
