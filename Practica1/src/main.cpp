#include <iostream>
#include "Number.hpp"

int main() 
{
    int base,val1,val2;

    std::cout<< "Introduzca base (2,10,16): ";
    std::cin>>base;
    //numero maximo de base 25 letras del alfabeto + 10 numeros

    std::cout<< "Introduzca 1 numero: ";
    std::cin>>val1;
    std::cout<< "Introduzca 2 numero: ";
    std::cin>>val2;

    if(base==10)
    {
        const Number<10,10> dec1 (val1);
        dec1.write(std::cout);

        const Number<10,10> dec2 (val2);
        dec2.write(std::cout);

        Number<10,10> decsum (0);
        //suma
        decsum=dec1.suma(dec2);
        decsum.write(std::cout);
        //multiplicacion
        decsum=dec1.multiplicacion(dec2);
        decsum.write(std::cout);
    }
    else if(base==2)
    {
        Number<2,10> bin1 (val1);
        bin1.write(std::cout);

        Number<2,10> bin2 (val2);
        bin2.write(std::cout);
        
        Number<2,10> binsum (0);
        //suma    
        binsum=bin1.suma(bin2);
        binsum.write(std::cout);
        //multiplicacion
        binsum=bin1.multiplicacion(bin1);
        binsum.write(std::cout);
    }
    else if(base==16)
    {  
        Number<16,10> hex1 (val1);
        hex1.write(std::cout);

        Number<16,10> hex2 (val2);
        hex2.write(std::cout);

        Number<16,10> hexsum (0);
        //suma
        hexsum=hex1.suma(hex2);
        hexsum.write(std::cout);
        //multiplicacion
        hexsum=hex1.multiplicacion(hex2);
        hexsum.write(std::cout);
    }
    else
    {
        std::cout<<"Base no implementada"<<std::endl;
    }
    
}

