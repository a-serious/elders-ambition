#ifndef ELDERSSOUNDOBJECT_H
#define ELDERSSOUNDOBJECT_H

#include "eldersobject.h"

class EldersSoundObject : public EldersObject
{
public:
    EldersSoundObject();
    virtual void play(int = 0) = 0;
    virtual void stop() = 0;
};

#endif // ELDERSSOUNDOBJECT_H
