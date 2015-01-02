#include "eldersoperand.h"

EldersOperand::EldersOperand()
{
    value = NULL;
}

EldersOperand::EldersOperand(EldersVarient value)
{
    this->value = new EldersVarient(value);
}

EldersVarient EldersOperand::getValue(EldersMap *)
{
    if (value) return *value;
    throw "orz";
}
