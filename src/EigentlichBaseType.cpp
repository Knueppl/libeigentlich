#include "EigentlichBaseType.h"

float EigentlichBaseType::s_sigma = 1.0f;
std::random_device EigentlichBaseType::s_randomDevice;
std::mt19937 EigentlichBaseType::s_randomGenerator(s_randomDevice());
std::normal_distribution<float> EigentlichBaseType::s_keepTypeDistribution(0.0, s_sigma);
std::normal_distribution<float> EigentlichBaseType::s_keepOperationDistribution(0.0, s_sigma);
std::uniform_int_distribution<int>
EigentlichBaseType::s_chooseTypeDistribution(0, static_cast<int>(EigentlichBaseType::Type::COUNT_TYPE) - 1);
std::uniform_int_distribution<int>
EigentlichBaseType::s_chooseOperatorDistribution(0, static_cast<int>(EigentlichBaseType::Operator::COUNT_OPERATOR) - 1);


EigentlichBaseType::EigentlichBaseType(const Type type)
    : _type(this->chooseType(type))
{

}

EigentlichBaseType::EigentlichBaseType(const int value)
    : _type(this->chooseType(Type::INT))
{
    this->setValue<int>(value);
}

EigentlichBaseType::EigentlichBaseType(const unsigned int value)
    : _type(this->chooseType(Type::UINT))
{
    this->setValue<unsigned int>(value);
}

EigentlichBaseType::EigentlichBaseType(const float value)
    : _type(this->chooseType(Type::FLOAT))
{
    this->setValue<float>(value);
}

EigentlichBaseType::EigentlichBaseType(const double value)
    : _type(this->chooseType(Type::DOUBLE))
{
    this->setValue<double>(value);
}



std::string EigentlichBaseType::typeName(const Type type)
{
    switch (type)
    {
    case Type::INT:
        return "INT";
    case Type::UINT:
        return "UINT";
    case Type::FLOAT:
        return "FLOAT";
    case Type::DOUBLE:
        return "DOUBLE";
//    case Type::STRING:
//        return "STRING";
    default:
        return "UNKOWN TYPE";
    }
}

std::string EigentlichBaseType::operatorName(const Operator op)
{
    switch (op)
    {
    case Operator::ADD:
        return "ADD";
    case Operator::SUB:
        return "SUB";
    case Operator::MUL:
        return "MUL";
    case Operator::DIV:
        return "DIV";
    default:
        return "UNKOWN OPERATOR";
    }
}

EigentlichBaseType::Type EigentlichBaseType::chooseType(const Type type) const
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    // Dice if the type will be accepted.
    const bool accepted = this->keepType ();
    std::cout << "accept type " << this->typeName(type) << " ? --> " << (accepted ? "jep" : "nope") << std::endl;

    // If the type is not be accepted choose a new one.
    if (accepted)
        return type;

    const Type newType = static_cast<Type>(s_chooseTypeDistribution(s_randomGenerator));

    std::cout << "dice the new type..." << std::endl;
    std::cout << "new type is " << this->typeName(newType) << std::endl;

    return newType;
}

EigentlichBaseType::Operator EigentlichBaseType::chooseOperator(const Operator op) const
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    // Dice if the operator will be accepted.
    const bool accepted = this->keepOperator();
    std::cout << "accpet operator " << this->operatorName(op) << " ? --> " << (accepted ? "jep" : "nope")
              << std::endl;

    // If not dice a new operator.
    if (accepted)
        return op;

    const Operator newOperator = static_cast<Operator>(s_chooseOperatorDistribution(s_randomGenerator));

    std::cout << "dice the new operator..." << std::endl;
    std::cout << "new operator is " << this->operatorName(newOperator) << std::endl;

    return newOperator;
}

bool EigentlichBaseType::keepType(void) const
{
    return s_keepTypeDistribution(s_randomGenerator) < s_sigma;
}

bool EigentlichBaseType::keepOperator(void) const
{
    return s_keepOperationDistribution(s_randomGenerator) < s_sigma;
}

