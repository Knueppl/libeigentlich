#include "EigentlichInt.h"

#include <iostream>

EigentlichInt EigentlichInt::operator+ (const EigentlichBaseType &right) const
{
    return EigentlichInt(this->performOperation (ADD, right));
}

int EigentlichInt::performOperation(const Operator op, const EigentlichBaseType& right) const
{
    int result = _data._int;

    switch(this->chooseOperator(ADD))
    {
    case ADD:
        result += right.getInt ();
        break;

    case SUB:
        result -= right.getInt ();
        break;

    case MUL:
        result *= right.getInt ();
        break;

    case DIV:
        result /= right.getInt ();
        break;

    default:
        std::cout << __PRETTY_FUNCTION__ << ": unkown operator." << std::endl;
        return 0;
    }

    return result;
}
