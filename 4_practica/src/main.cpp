#include <iostream>
#include "DNI_t.hpp"

int main()
{
    //invocar a tabla_hash_t con DNI pasado como parametro;
    DNI_t *a;
    for (int i = 0; i < 10; i++)
    {
        a = new DNI_t;
        std::cout << a->get_DNI() << "--";
    }
    std::cout << std::endl;
}