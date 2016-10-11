#ifndef ___EIGENTLICH_INT_H___
#define ___EIGENTLICH_INT_H___

#include "EigentlichBaseType.h"

class EigentlichInt : public EigentlichBaseType
{
public:
    EigentlichInt(void) : EigentlichBaseType(EigentlichBaseType::INT) { }
    EigentlichInt(const int value) : EigentlichBaseType(EigentlichBaseType::INT, value) { }
    virtual ~EigentlichInt(void) = default;

    EigentlichInt operator +(const EigentlichBaseType& right) const;

private:
    int performOperation(const Operator op, const EigentlichBaseType& right) const;
};

std::ostream& operator<<(std::ostream& os, const EigentlichInt& value)
{
    os << value.getInt();
    return os;
}

#endif
