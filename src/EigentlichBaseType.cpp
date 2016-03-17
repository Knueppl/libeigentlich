#include "EigentlichBaseType.h"

std::random_device EigentlichBaseType::s_randomDevice;
std::mt19937 EigentlichBaseType::s_randomGenerator(s_randomDevice());
std::normal_distribution<float> EigentlichBaseType::s_distribution(0.0, 0.2);


EigentlichBaseType::EigentlichBaseType(const Type type)
{

}

EigentlichBaseType::EigentlichBaseType(const Type type, const auto value)
{

}

EigentlichBaseType::Type EigentlichBaseType::chooseType(const Type type)
{
    return type;
}
