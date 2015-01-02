#ifndef ELDERSCONDITION_H
#define ELDERSCONDITION_H

#include "eldersexpression.h"
#include "eldersoperand.h"

class EldersCondition : public EldersExpression
{
    EldersExpression *trueBranch, *falseBranch;
    EldersExpression *trueTail, *falseTail;
    EldersOperand *condition;

public:
    EldersCondition(EldersOperand *);
    virtual void run(EldersMap *);
    virtual void setNext(EldersExpression *);

    void pushTrueBranch(EldersExpression *, EldersExpression *);
    void pushFalseBranch(EldersExpression *, EldersExpression *);
};

#endif // ELDERSCONDITION_H
