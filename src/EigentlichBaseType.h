#ifndef ___EIGENTLICH_BASE_TYPE_H___
#define ___EIGENTLICH_BASE_TYPE_H___

#include <string>
#include <random>
#include <iostream>

class EigentlichBaseType
{
protected:
    enum Type {
        INT = 0,
        UINT,
        FLOAT,
        DOUBLE,
        STRING,
        COUNT_TYPE
    };

    explicit EigentlichBaseType(const Type type);
    explicit EigentlichBaseType(const Type type, const auto value)
        : _type(this->chooseType(type))
    {
        this->setValue(value);
    }
    virtual ~EigentlichBaseType(void) = default;

    Type _type;

    union Data {
        int          _int;
        unsigned int _uint;
        float        _float;
        double       _double;
//        std::string  _string;

//        Data() { }
//        ~Data() { }
    } _data;

public:
    void setValue(const auto value)
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
            std::cout << __PRETTY_FUNCTION__ << ": operation with this type is not implemented." << std::endl;
            break;
        }
    }

    int getInt(void) const;
    unsigned int getUnsignedInt(void) const;
    float getFloat(void) const;
    double getDouble(void) const;

protected:
    // Operator stuff.
    enum Operator {
        ADD = 0,
        SUB,
        MUL,
        DIV,
        COUNT_OPERATOR
    };

    Operator chooseOperator(const Operator op) const;

private:
    Type chooseType(const Type type) const;
    bool keepType(void) const;
    bool keepOperator(void) const;

    static std::string typeName(const Type type);
    static std::string operatorName(const Operator op);

    static float s_sigma;
    static std::random_device s_randomDevice;
    static std::mt19937 s_randomGenerator;
    static std::normal_distribution<float> s_keepTypeDistribution;
    static std::normal_distribution<float> s_keepOperationDistribution;
    static std::uniform_int_distribution<int> s_chooseTypeDistribution;
    static std::uniform_int_distribution<int> s_chooseOperatorDistribution;
};


#endif
