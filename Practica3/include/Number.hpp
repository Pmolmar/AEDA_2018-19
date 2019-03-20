#pragma once

#include <iostream>
#include "NumberBase.hpp"

template<int B, int N, class T=unsigned char>
class Number: public NumberBase 
{
private:
    T* num;
    int signo=1;
    void to_base(int val);//convierte entero en la base pedida

public:
    Number(int val=0);
    ~Number();
    Number(Number<B,N,T>* a);

    Number<B,N,T> suma(const Number<B,N,T> *op)const;
    Number<B,N,T>& operator =(const Number<B,N,T>& copy);

    operator Number<B,N+1,T> ( )const;
    int mayor(const Number<B,N,T>* op)const;
    void set_val(int x, int pos);
    void set_sig(int x);

    std::ostream& write(std::ostream& os)const;
    Number<B,N,T> operator+(const Number<B,N,T> *nu)const;
    Number<B,N,T> operator-(const Number<B,N,T> *nu)const;
    NumberBase operator+(const NumberBase *nu)const;
    NumberBase operator-(const NumberBase *nu)const;
    friend std::ostream& operator <<(std::ostream& os,const Number<B,N,T>& nu);       
    NumberBase *duplicate()const;
};

template<int N, class T>
class Number <2,N,T>: public NumberBase
{
private:
    T* num;
    int signo=1;
    void to_base(int val);//convierte entero en la base pedida
    void complementador();//transforma a complemento a 2

public:
    Number(int val=0);
    ~Number();
    Number(Number<2,N,T>* a);

    Number<2,N,T> suma(const Number<2,N,T>* op)const; 
    Number<2,N,T>& operator =(const Number<2,N,T>& copy);  

    operator Number<2,N+1,T> ( )const;
    void set_val(int x, int pos);
    void set_sig(int x);

    std::ostream& write(std::ostream& os)const;
    Number<2,N,T> operator+(const Number<2,N,T> *nu)const;
    Number<2,N,T> operator-(const Number<2,N,T> *nu)const;
    NumberBase operator+(const NumberBase *nu)const;
    NumberBase operator-(const NumberBase *nu)const;
    friend std::ostream& operator <<(std::ostream& os,const Number<2,N,T>& nu);
    NumberBase *duplicate()const;
};


class binary: public Number<2,8>
{
    public:
        binary(int num): Number<2,8>(num){}
};

class octal: public Number<8,8>
{
    public:
        octal(int num): Number<8,8>(num){}
};

class decimal: public Number<10,8>
{
    public:
        decimal(int num): Number<10,8>(num){}
};

class hexadec: public Number<16,8>
{
    public:
        hexadec(int num): Number<16,8>(num){}
};

#include "../src/Number.tpp"
