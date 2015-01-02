#include "eldersanimate.h"

EldersAnimate::EldersAnimate(EldersMap *parent)
{
    this->parent = parent;
    wantDelete = false;
}

EldersAnimate::EldersAnimate(EldersMap *parent, int duration)
{
    this->parent = parent;
    this->duration = duration;
    wantDelete = false;
}
