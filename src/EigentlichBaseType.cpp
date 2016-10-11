#include "EigentlichBaseType.h"

float EigentlichBaseType::s_sigma = 1.0f;
std::random_device EigentlichBaseType::s_randomDevice;
std::mt19937 EigentlichBaseType::s_randomGenerator(s_randomDevice());
std::normal_distribution<float> EigentlichBaseType::s_keepTypeDistribution(0.0, s_sigma);
std::normal_distribution<float> EigentlichBaseType::s_keepOperationDistribution(0.0, s_sigma);
std::uniform_int_distribution<int>
EigentlichBaseType::s_chooseTypeDistribution(0, EigentlichBaseType::COUNT_TYPE - 1);
std::uniform_int_distribution<int>
EigentlichBaseType::s_chooseOperatorDistribution(0, EigentlichBaseType::COUNT_OPERATOR - 1);


EigentlichBaseType::EigentlichBaseType(const Type type)
    : _type(this->chooseType(type))
{

}

int EigentlichBaseType::getInt(void) const
{
    switch (_type)
    {
    case INT:
        return _data._int;

    case UINT:
        return _data._uint;

    case FLOAT:
        return _data._float;

    case DOUBLE:
        return _data._double;

    default:
        std::cout << __PRETTY_FUNCTION__ << ": method for the given type is not implemented." << std::endl;
        break;
    }

    return 0;
}

unsigned int EigentlichBaseType::getUnsignedInt(void) const
{
    switch (_type)
    {
    case INT:
        return _data._int;

    case UINT:
        return _data._uint;

    case FLOAT:
        return _data._float;

    case DOUBLE:
        return _data._double;

    default:
        std::cout << __PRETTY_FUNCTION__ << ": method for the given type is not implemented." << std::endl;
        break;
    }

    return 0;
}

float EigentlichBaseType::getFloat(void) const
{
    switch (_type)
    {
    case INT:
        return _data._int;

    case UINT:
        return _data._uint;

    case FLOAT:
        return _data._float;

    case DOUBLE:
        return _data._double;

    default:
        std::cout << __PRETTY_FUNCTION__ << ": method for the given type is not implemented." << std::endl;
        break;
    }

    return 0;
}

double EigentlichBaseType::getDouble(void) const
{
    switch (_type)
    {
    case INT:
        return _data._int;

    case UINT:
        return _data._uint;

    case FLOAT:
        return _data._float;

    case DOUBLE:
        return _data._double;

    default:
        std::cout << __PRETTY_FUNCTION__ << ": method for the given type is not implemented." << std::endl;
        break;
    }

    return 0;
}

//EigentlichBaseType EigentlichBaseType::operator+(const EigentlichBaseType& right)
//{
//
//}

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
        return "UNKOWN TYPE";
    }
}

std::string EigentlichBaseType::operatorName(const Operator op)
{
    switch (op)
    {
    case ADD:
        return "ADD";
    case SUB:
        return "SUB";
    case MUL:
        return "MUL";
    case DIV:
        return "DIV";
    default:
        return "UNKOWN OPERATOR";
    }
}

//EigentlichBaseType EigentlichBaseType::doOperation(const EigentlichBaseType right, const Operator op)
//{
//    switch (op)
//    {
//    case ADD:
//
//        switch (right._type)
//        {
//        case INT:
//
//            switch (_type)
//            {
//            case INT:
//                
//            }
//        }
//    }
//}

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

