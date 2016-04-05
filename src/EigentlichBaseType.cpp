#include "EigentlichBaseType.h"

#include <iostream>

float EigentlichBaseType::s_sigma = 1.0f;
std::random_device EigentlichBaseType::s_randomDevice;
std::mt19937 EigentlichBaseType::s_randomGenerator(s_randomDevice());
std::normal_distribution<float> EigentlichBaseType::s_keepTypeDistribution(0.0, s_sigma);
std::uniform_int_distribution<int>
EigentlichBaseType::s_chooseTypeDistribution(0, EigentlichBaseType::COUNT_TYPE - 1);


EigentlichBaseType::EigentlichBaseType(const Type type)
    : _type(this->chooseType(type))
{

}

EigentlichBaseType::EigentlichBaseType(const Type type, const auto value)
    : _type(this->chooseType(type))
{
    this->setValue(value);
}

void EigentlichBaseType::setValue(const auto value)
{
    switch (_type)
    {
    case INT:
        _data._int = value;
        break;

    case UINT:
        _data._uint = value;
        break;

    case FLOAT:
        _data._float = value;
        break;

    case DOUBLE:
        _data._double = value;
        break;

    default:
        std::cout << __PRETTY_FUNCTION__ << ": operation with this type is no be implemented." << std::endl;
        break;
    }
}

std::string EigentlichBaseType::typeName(const Type type)
{
    switch (type)
    {
    case INT:
        return "INT";
    case UINT:
        return "UINT";
    case FLOAT:
        return "FLOAT";
    case DOUBLE:
        return "DOUBLE";
    case STRING:
        return "STRING";
    default:
        return "UNKOWN";
    }
}

EigentlichBaseType::Type EigentlichBaseType::chooseType(const Type type)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    // Dice if the type will be accepted.
    const bool accepted = s_keepTypeDistribution(s_randomGenerator) < s_sigma;
    std::cout << "accept type " << this->typeName(type) << "? --> " << (accepted ? "jep" : "nope") << std::endl;

    // If the type is not be accepted choose a new one.
    if (accepted)
        return type;

    const Type newType = static_cast<Type>(s_chooseTypeDistribution(s_randomGenerator));

    std::cout << "dice the new type..." << std::endl;
    std::cout << "new type is " << this->typeName(newType) << std::endl;

    return newType;
}
