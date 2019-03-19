#include <iostream>
#include "Number.hpp"
#include "NumberBase.hpp"

int main() 
{
    
        int val1=0,val2=0,base;

        std::cout<< "Introduzca 1 numero: ";
        std::cin>>val1;
        std::cout<< "Introduzca 2 numero: ";
        std::cin>>val2;
        std::cout<< "Introduzca base: ";
        std::cin>>base;

    try
    {
        NumberBase *aux1;
        NumberBase *aux2;

      //  aux1=new decimal<val1>;

     //   (*aux1+aux2).write(std::cout);
       // (*aux1-aux2).write(std::cout);
    }
    catch (NumberExeption& e)
	{
		std::cout << e.what() << std::endl;
	} 
        
    return 0;  
}

/*
desde el programa principal, si se genera overflow al numero contenedor se le aumenta el tamaño
*/