#include "eldersoperation.h"
#include "eldersreference.h"

EldersOperation::EldersOperation(EldersOperand *operand1, EldersOperand *operand0, QString mOperator)
{
    operand[0] = operand0, operand[1] = operand1, this->mOperator = mOperator;
}

EldersOperation::EldersOperation(EldersOperand *operand0, QString mOperator)
{
    operand[0] = operand0, operand[1] = NULL, this->mOperator = mOperator;
}

EldersVarient EldersOperation::getValue(EldersMap *map)
{
    if (mOperator == "+")
        return operand[0]->getValue(map) + operand[1]->getValue(map);
    if (mOperator == "-")
        return operand[0]->getValue(map) - operand[1]->getValue(map);
    if (mOperator == "*")
        return operand[0]->getValue(map) * operand[1]->getValue(map);
    if (mOperator == "/")
        return operand[0]->getValue(map) / operand[1]->getValue(map);
    if (mOperator == "%")
        return operand[0]->getValue(map) % operand[1]->getValue(map);
    if (mOperator == "^")
        return operand[0]->getValue(map) ^ operand[1]->getValue(map);
    if (mOperator == "&")
        return operand[0]->getValue(map) & operand[1]->getValue(map);
    if (mOperator == "<<")
        return operand[0]->getValue(map) << operand[1]->getValue(map);
    if (mOperator == ">>")
        return operand[0]->getValue(map) >> operand[1]->getValue(map);
    if (mOperator == "~")
        return ~(operand[0]->getValue(map));
    if (mOperator == "=")
    {
        EldersReference *x = dynamic_cast<EldersReference *>(operand[0]);
        if (!x)
            throw "Non-reference operand cannot be assigned any value.";
        return x->setValue(operand[1]->getValue(map), map);
    }
    if (mOperator == "<")
        return operand[0]->getValue(map) < operand[1]->getValue(map);
    if (mOperator == "<=")
        return operand[0]->getValue(map) <= operand[1]->getValue(map);
    if (mOperator == ">")
        return operand[0]->getValue(map) > operand[1]->getValue(map);
    if (mOperator == ">=")
        return operand[0]->getValue(map) >= operand[1]->getValue(map);
    if (mOperator == "==")
        return operand[0]->getValue(map) == operand[1]->getValue(map);
    if (mOperator == "!=")
        return operand[0]->getValue(map) != operand[1]->getValue(map);
    throw "Invalid operation \"" + mOperator + "\"";
}
