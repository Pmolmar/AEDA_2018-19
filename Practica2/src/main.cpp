#include <iostream>
#include "Number.hpp"

/*
Revisar la suma y la multiplicacion, dan fallos al pasar
los datos a un puntero, ha de tener solucion apatentemente facil
*/
//Añadir numeros negativos
//Añadri constructor de copia
//number<nbt>& operator=(const number<nbt>&)


template <int N, int B>
void testNumber(int v1,int v2)
{
    Number <N,B> N1(v1),N2(v2);
    Number <N,B> op;
    std::cout<<std::endl<<"Base "<<N<<std::endl<<"1 valor: ";
    N1.write(std::cout);
    std::cout<<"2 valor: ";
    N2.write(std::cout);
    op=N1.suma(N2);
    std::cout<<"Suma: ";
    op.write(std::cout);
    op=N1.multiplicacion(N2);
    std::cout<<"Multiplicacion: ";
    op.write(std::cout);
    std::cout<<std::endl;
}

int main() 
{
    try
    {
        int base,val1,val2;

        std::cout<< "Introduzca 1 numero: ";
        std::cin>>val1;
        std::cout<< "Introduzca 2 numero: ";
        std::cin>>val2;

        testNumber<2,10> (val1,val2);

        testNumber<10,10> (val1,val2);

        testNumber<16,10> (val1,val2);

        return 0;  
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

/*
basicamente rengo que crear una especializacion de template 
para base 2 que me permita representar los numeros negativos
en binario complemento a 2

template <nbt>
class number{atributo signo}

template<int N,class T>
class Number <N,2,T>{}
*/

//GUARDAR LOS NUMEROS 5 etc NO SU REPRESENTACION ASCII