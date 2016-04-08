#ifndef ___EIGENTLICH_BASE_TYPE_H___
#define ___EIGENTLICH_BASE_TYPE_H___

#include <string>
#include <random>

class EigentlichBaseType
{
protected:
//public:
    enum Type {
        INT = 0,
        UINT,
        FLOAT,
        DOUBLE,
        STRING,
        COUNT_TYPE
    };

    EigentlichBaseType(const Type type);
    EigentlichBaseType(const Type type, const auto value);

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

    void setValue(const auto value);

//    EigentlichBaseType operator+(const EigentlichBaseType& right);

private:

    enum Operator {
        ADD = 0,
        SUB,
        MUL,
        DIV,
        COUNT_OPERATOR
    };

//    EigentlichBaseType doOperation(const EigentlichBaseType right, const Operator op);
    Type chooseType(const Type type);
    Operator chooseOperator(const Operator op);
    bool isAccepted(void);

    static std::string typeName(const Type type);
    static std::string operatorName(const Operator op);

    static float s_sigma;
    static std::random_device s_randomDevice;
    static std::mt19937 s_randomGenerator;
    static std::normal_distribution<float> s_keepTypeDistribution;
    static std::uniform_int_distribution<int> s_chooseTypeDistribution;
    static std::uniform_int_distribution<int> s_chooseOperatorDistribution;
};

#endif
