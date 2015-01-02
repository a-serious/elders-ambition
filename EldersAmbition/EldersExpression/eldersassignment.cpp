#include "eldersassignment.h"

EldersAssignment::EldersAssignment(EldersOperand *operand)
{
    next = NULL;
    this->operand = operand;
}

void EldersAssignment::run(EldersMap *map)
{
    operand->getValue(map);
    EldersExpression::run(map);
}
