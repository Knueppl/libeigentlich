#ifndef ___EIGENTLICH_BASE_TYPE_H___
#define ___EIGENTLICH_BASE_TYPE_H___

#include <string>

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

    EigentlichBaseType(void);
    EigentlichBaseType(const auto value);

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
};

#endif
