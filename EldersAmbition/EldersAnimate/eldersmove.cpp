#include "eldersmove.h"
#include "../EldersDisplayObject/elderstom.h"

EldersMove::EldersMove(EldersMap *parent, int direction, int distance, EldersDisplayObject *target, int duration)
    : EldersAnimate(parent)
{
    this->direction = direction;
    this->distance = distance;
    this->target = target;
    if (duration < 0)
        this->duration = distance * 8;
    else
        this->duration = duration;
    this->step = this->distance * 50 / this->duration;
}

bool EldersMove::paint(QPainter *)  // false -> please destroy me.
{
    int dx[4]={0, -step, 0, step}, dy[4]={step, 0, -step, 0};
    if (duration > 0)
    {
        EldersTom *tom = dynamic_cast<EldersTom *>(target);
        if(tom) tom->changePic(direction, duration);
        target->x += dx[direction];
        target->y += dy[direction];
        duration--;
        return true;
    }
    else
    {
        EldersTom *tom = dynamic_cast<EldersTom *>(target);
        if(tom) tom->changePic(direction, duration);
        (*target)["position_x"] += dx[direction] / step;
        (*target)["position_y"] += dy[direction] / step;
        return false;
    }
}
