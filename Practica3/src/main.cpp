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

        switch (base)
        {
            case 2:
                aux1=new binary(val1);
                aux2=new binary(val2);
                break;

            case 8:
                aux1=new octal(val1);
                aux2=new octal(val2);
                break;
            
            case 10:
                aux1=new decimal(val1);
                aux2=new decimal(val2);
                break;
            
            case 16:
                aux1=new hexadec(val1);
                aux2=new hexadec(val2);
                break;
        
            default:
                std::cout<<"Base no implemtada.";
                break;
        }
        std::cout<<"Valor 1 en base "<<base<<": "<<*aux1<<std::endl;
        std::cout<<"Valor 2 en base "<<base<<": "<<*aux2<<std::endl;
        //std::cout<<"Suma: "<<aux1+aux2<< std::endl;
        std::cout<<"Resta: "<<aux1-aux2<< std::endl;
        
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