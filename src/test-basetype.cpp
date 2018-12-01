#include <iostream>

#include "EigentlichInt.h"

int main(void)
{
    for (int i = 0; i < 100; i++)
    {
        const EigentlichInt a(5), b(3);
        const EigentlichInt c = a + b;
        std::cout << a << " + " << b << " = " << c << std::endl << std::endl << std::endl;
    }
}
