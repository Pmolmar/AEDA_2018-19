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
    // Number(const Number<B,N,T>& a);

    Number<B,N,T> suma(const Number<B,N,T>& op)const;
    Number<B,N,T>& operator =(const Number<B,N,T>& copy);

    operator Number<B,N+1,T> ( )const;
    int mayor(const Number<B,N,T>& op)const;
    void set_val(int x, int pos);
    void set_sig(int x);

    std::ostream& write(std::ostream& os)const;
    Number<B,N,T> *operator+(const Number<B,N,T> *num)const;
    Number<B,N,T> *operator-(const Number<B,N,T> *num)const;
    NumberBase *operator+(NumberBase *num)const;
    NumberBase *operator-(NumberBase *num)const;
    std::ostream& operator <<(Number<B,N,T>* num)const;    
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
    // Number(const Number<2,N,T>& a);

    Number<2,N,T> suma(const Number<2,N,T>& op)const; 
    Number<2,N,T>& operator =(const Number<2,N,T>& copy);  

    operator Number<2,N+1,T> ( )const;
    void set_val(int x, int pos);
    void set_sig(int x);

    std::ostream& write(std::ostream& os)const;
    Number<2,N,T> *operator+(const Number<2,N,T> *num)const;
    Number<2,N,T> *operator-(const Number<2,N,T> *num)const;
    NumberBase *operator+(const NumberBase *num)const;
    NumberBase *operator-(const NumberBase *num)const;
    std::ostream& operator <<(Number<2,N,T>* num)const;
    NumberBase *duplicate()const;
};

template<class T>
class binary: public Number<2,8,T>
{
    public:
        binary(int num): Number<2,8,T>(num){}
};

template<class T>
class octal: public Number<8,8,T>
{
    public:
        octal(int num): Number<8,8,T>(num){}
};

template<class T>
class decimal: public Number<10,8,T>
{
    public:
        decimal(int num): Number<10,8,T>(num){}
};

template<class T>
class hexadec: public Number<16,8,T>
{
    public:
        hexadec(int num): Number<16,8,T>(num){}
};

#include "../src/Number.tpp"
