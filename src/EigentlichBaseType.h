#ifndef ___EIGENTLICH_BASE_TYPE_H___
#define ___EIGENTLICH_BASE_TYPE_H___

#include <string>
#include <random>
#include <iostream>

class EigentlichBaseType
{
protected:
    enum class Type {
        INT = 0,
        UINT,
        FLOAT,
        DOUBLE,
//        STRING,
        COUNT_TYPE
    };

    // Operator stuff.
    enum class Operator {
        ADD = 0,
        SUB,
        MUL,
        DIV,
        COUNT_OPERATOR
    };

    EigentlichBaseType(void) = delete;
    explicit EigentlichBaseType(const Type type);
    explicit EigentlichBaseType(const int value);
    explicit EigentlichBaseType(const unsigned int value);
    explicit EigentlichBaseType(const float value);
    explicit EigentlichBaseType(const double value);
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

    template <class T>
    void setValue(const T value)
    {
         switch (_type)
        {
        case Type::INT:
            _data._int = value;
            break;

        case Type::UINT:
            _data._uint = value;
            break;

        case Type::FLOAT:
            _data._float = value;
            break;

        case Type::DOUBLE:
            _data._double = value;
            break;

        default:
            std::cout << __PRETTY_FUNCTION__ << ": operation with this type is not implemented." << std::endl;
            break;
        }
    }

    template <class T>
    T& value(void) 
    {
        switch (_type)
        {
        case Type::INT:
            return _data._int;

        case Type::UINT:
            return _data._uint;

        case Type::FLOAT:
            return _data._float;

        case Type::DOUBLE:
            return _data._double;

        default:
            std::cout << __PRETTY_FUNCTION__ << ": method for the given type is not implemented." << std::endl;
            break;
        }

        return 0;
    }

    template <class T>
    T value(void) const
    {
        switch (_type)
        {
        case Type::INT:
            return _data._int;

        case Type::UINT:
            return _data._uint;

        case Type::FLOAT:
            return _data._float;

        case Type::DOUBLE:
            return _data._double;

        default:
            std::cout << __PRETTY_FUNCTION__ << ": method for the given type is not implemented." << std::endl;
            break;
        }

        return 0;
    }

    template <class T>
    T performOperation(const Operator op, const EigentlichBaseType& right) const
    {
        T result = this->value<T>();

        switch(this->chooseOperator(op))
        {
        case Operator::ADD:
            result += right.value<T>();
            break;

        case Operator::SUB:
            result -= right.value<T>();
            break;

        case Operator::MUL:
            result *= right.value<T>();
            break;

        case Operator::DIV:
            result /= right.value<T>();
            break;

        default:
            std::cout << __PRETTY_FUNCTION__ << ": unkown operator." << std::endl;
            return 0;
        }

        return result;
    }

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
