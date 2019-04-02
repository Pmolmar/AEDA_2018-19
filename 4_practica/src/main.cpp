#include <iostream>
#include "DNI_t.hpp"
#include "tabla_hash_t.hpp"

int main()
{
    //invocar a tabla_hash_t con DNI pasado como parametro;
    DNI_t *a;
    for (int i = 0; i < 10; i++)
    {
        a = new DNI_t;
        std::cout << a->get() << "--";
    }
    std::cout << std::endl;

    int celda, bloque, fd, fe;

    std::cin >> celda >> bloque >> fd >> fe;

    tabla_hash_t<DNI_t> hash(celda, bloque, fd, fe);
}