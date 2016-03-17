#ifndef ___EIGENTLICH_BASE_TYPE_H___
#define ___EIGENTLICH_BASE_TYPE_H___

#include <string>
#include <random>

class EigentlichBaseType
{
protected:

    enum Type {
        INT,
        UINT,
        FLOAT,
        DOUBLE,
        STRING,
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

private:
    Type chooseType(const Type type);

    static std::random_device s_randomDevice;
    static std::mt19937 s_randomGenerator;
    static std::normal_distribution<float> s_distribution;
};

#endif
