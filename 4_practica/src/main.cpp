#include <iostream>
#include "tabla_hash_t.hpp"

int main()
{
    int celda, bloque, fd, fe;
    double factor, relleno;

    std::cout << "Introduzca numero de celdas: ";
    std::cin >> celda;
    std::cout << "Introduzca numero de bloques: ";
    std::cin >> bloque;
    std::cout << "Introduzca funcion de dispersion: ";
    std::cin >> fd;
    std::cout << "Introduzca funcion de exploracion: ";
    std::cin >> fe;
    std::cout << "Introduzca % (0.X) de relleno: ";
    std::cin >> relleno;

    tabla_hash_t<DNI_t> hash(celda, bloque, fd, fe);

    factor = celda * bloque * relleno;
    DNI_t *a[2 * int(factor)];

    std::cout<<"Celdas\tClaves\tDisp\tExp\tCarga\tPruebas"<<std::endl;
    std::cout<<celda<<"\t"<<2*int(factor)<<"\t"<<fd<<"\t"<<fe<<"\t"<<relleno<<"\t"<<factor<<std::endl;
    std::cout << std::endl;
    std::cout<<"\t\tMaximo\tMedio\tMinimo"<<std::endl;

    int i;
    for (i = 0; i < int(factor); i++)
    {
        a[i] = new DNI_t;
        hash.insertar(*a[i]);
    }
    std::cout<<"Insertar\t"<<DNI_t::max.get_cont()<<"\t"<<DNI_t::cont.get_cont()/int(factor)<<"\t"<<DNI_t::min.get_cont();
    DNI_t::cont.reset();
    DNI_t::min.reset();
    DNI_t::max.reset();

    std::cout << std::endl;

    for (; i < 2*int(factor); i++)
    {
        a[i] = new DNI_t;
        hash.buscar(*a[i]);
    }
    std::cout<<"Buscar\t\t"<<DNI_t::max.get_cont()<<"\t"<<DNI_t::cont.get_cont()/2*int(factor)<<"\t"<<DNI_t::min.get_cont();
    std::cout << std::endl;
}