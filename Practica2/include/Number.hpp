#pragma once

#include <stack>
#include <ostream>

template<int B, int N, class T=unsigned char>
class Number 
{
private:
    T* num;
    bool signo=false;
    void to_base(int val);//convierte entero en la base pedida
    bool overflow=false;//flag de overflow

public:
    Number(int val=0);
    ~Number(); 
    std::ostream& write(std::ostream& os)const;
    Number<B,N,T> suma(const Number<B,N,T>& op)const;
    Number<B,N,T> multiplicacion(const Number<B,N,T>& op)const;
    Number<B,N,T>& operator =(const Number<B,N,T>& copy);
};

#include "../src/Number.tpp"

/*Para poder pasar un numero a una base primero hacemos modulo(%), despues dividimos
por la base y repetimos hasta que quede mas pequeña 
    ej:
    pasar 546 a base decimal:
    546%10=6    pushback de 6;
    546/10=54   
    54%10=4     pushback de 4;
    54/10=5
    5%10=5      pushback de 5;
    5/10=0      termina;
*/

