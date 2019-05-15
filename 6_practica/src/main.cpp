#include <iostream>
#include "../include/arbolBB_t.hpp"
#include "../include/nodoBB_t.hpp"

int main()
{
    std::cout<<"Modo demostracion: "<<std::endl;
    ABB_t<int> *prueba;
    prueba = new  ABB_t<int>;

    prueba->write(std::cout);
    for(int i=0; i<5; ++i)
    {
        int x;
        std::cin>>x;
        prueba->insertar(x);
        prueba->write(std::cout);
    }
    return 0;
}