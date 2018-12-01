#ifndef ___EIGENTLICH_INT_H___
#define ___EIGENTLICH_INT_H___

#include "EigentlichBaseType.h"

class EigentlichInt : public EigentlichBaseType
{
public:
    EigentlichInt(void) : EigentlichBaseType(EigentlichBaseType::Type::INT) { }
    EigentlichInt(const int value) : EigentlichBaseType(value) { }
    virtual ~EigentlichInt(void) = default;

    EigentlichInt operator+(const EigentlichInt& right) const
    {
        return { this->performOperation<int>(Operator::ADD, right) };
    }
    EigentlichInt operator-(const EigentlichInt& right) const
    {
        return { this->performOperation<int>(Operator::SUB, right) };
    }
    EigentlichInt operator*(const EigentlichInt& right) const
    {
        return { this->performOperation<int>(Operator::MUL, right) };
    }
    EigentlichInt operator/(const EigentlichInt& right) const
    {
        return { this->performOperation<int>(Operator::DIV, right) };
    }

    EigentlichInt& operator=(const EigentlichInt& right)
    {
        this->setValue<int>(right.value<int>());
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const EigentlichInt& value);
};

std::ostream& operator<<(std::ostream& os, const EigentlichInt& value)
{
    os << value.value<int>();
    return os;
}

#endif
