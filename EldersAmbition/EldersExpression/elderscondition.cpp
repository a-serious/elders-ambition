#include "elderscondition.h"

#include <QDebug>

EldersCondition::EldersCondition(EldersOperand *condition)
{
    this->condition = condition;
    trueBranch = falseBranch = NULL;
    next = NULL;
}

void EldersCondition::run(EldersMap *map)
{
    if (condition->getValue(map).isTrue())
    {
        if (trueBranch)
            trueBranch->run(map);
    }
    else
    {
        if (falseBranch)
            falseBranch->run(map);
    }
}

void EldersCondition::setNext(EldersExpression *next)
{
    this->next = next;
    trueTail->setNext(next);
    if (falseBranch)
        falseTail->setNext(next);
    else
        falseBranch = next;
}

void EldersCondition::pushTrueBranch(EldersExpression *branch, EldersExpression *tail)
{
    trueBranch = branch;
    trueTail = tail;
}

void EldersCondition::pushFalseBranch(EldersExpression *branch, EldersExpression *tail)
{
    falseBranch = branch;
    falseTail = tail;
}
