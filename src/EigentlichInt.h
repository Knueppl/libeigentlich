#ifndef ___EIGENTLICH_INT_H___
#define ___EIGENTLICH_INT_H___

#include "EigentlichBaseType.h"

class EigentlichInt : public EigentlichBaseType
{
public:
    EigentlichInt(void) : EigentlichBaseType(EigentlichBaseType::INT) { }
    EigentlichInt(const auto value) : EigentlichBaseType(EigentlichBaseType::INT, value) { }
};

#endif
