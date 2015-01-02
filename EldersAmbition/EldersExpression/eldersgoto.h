#ifndef ELDERSGOTO_H
#define ELDERSGOTO_H

#include "eldersexpression.h"

class EldersGoto : public EldersExpression
{
public:
    QString label;
    EldersGoto(QString);
    //virtual void run(EldersMap *);
};

#endif // ELDERSGOTO_H
