#include <iostream>
#include <stack>
#include <vector>
#include <cmath>

template <int B, int N, class T>
Number<B, N, T>::Number(int val):NumberBase(B,N)
{
    num = new T[N];
    if (pow(B, N) < val)
        throw OutOfRange();
    to_base(val);
}

template <int B, int N, class T>
Number<B, N, T>::~Number()
{
    delete[] num;
}

// template <int B, int N, class T>
// Number<B, N, T>::Number(const Number<B, N, T> &a)
// {
//     a.set_sig(signo);
//     for (int i = 0; i < N; ++i)
//         a.set_val(num[i], i);
// }

template <int B, int N, class T>
void Number<B, N, T>::to_base(int val)
{
    int aux = val;

    if (val < 0)
    {
        signo = -1;
        aux *= -1;
    }

    for (int i = 0; i < N; i++)
    {
        if (aux > 0)
        {
            num[i] = char(aux % B);
            aux = aux / B;
        }
        else
            num[i] = 0;
    }

    if (aux > B)
        throw NoNumber();
}

//no consigo comprender poque no funciona en hexadecimal la suma negativa
//se que es por ejemplo porque 15=f - 17=11 el programa primerp
//ejecuta el f-1=e y despues simplemente 0-1, el resultado es
// 1e pero deberia de ser -2, no se como sulucionarlo
template <int B, int N, class T>
Number<B, N, T> Number<B, N, T>::suma(const Number<B, N, T> &op) const
{
    Number<B,N,T> aux;
    int carry = 0;
    for (int i = 0; i < N; i++)
    {
        int val= num[i]*signo+op.num[i]*op.signo+carry;
        aux.num[i]= abs(val)%B;
        carry= val/B;
    }

    aux.set_sig(mayor(op));

    if (carry > 0)
        throw Overflow();

    return aux;
}

template <int B, int N, class T>
std::ostream &Number<B, N, T>::write(std::ostream &os) const
{
    if (signo == -1)
        os << "-";

    for (int i = N - 1; i >= 0; i--)
    {
        if (int(num[i]) < 10)
            os << int(num[i]);
        else
            os << char('a' + int(num[i]) - 10);
    }
    os << std::endl;

    return os;
}

template <int B, int N, class T>
Number<B, N, T> &Number<B, N, T>::operator=(const Number<B, N, T> &copy)
{
    for (int i = 0; i < N; i++)
        num[i] = copy.num[i];
    signo = copy.signo;

    return *this;
}

template <int B, int N, class T>
int Number<B, N, T>::mayor(const Number<B, N, T> &op) const
{
    for (int i = N - 1; i >= 0; i--)
    {
        if (num[i] > op.num[i])
            return signo;
        else if (num[i] < op.num[i])
            return op.signo;
    }
    return signo;
}

template <int B, int N, class T>
Number<B, N, T>::operator Number<B, N + 1, T>() const
{
    Number<B, N + 1, T> x;
    for (int i = 0; i < N; i++)
    {
        x.set_val(int(num[i]), i);
    }
    x.set_val(0, N);
    x.set_sig(signo);

    return x;
}

template <int B, int N, class T>
void Number<B, N, T>::set_val(int x, int pos)
{
    num[pos] = x;
}

template <int B, int N, class T>
void Number<B, N, T>::set_sig(int x)
{
    signo = x;
}

//nuevo

template <int B, int N, class T>
NumberBase *Number<B, N, T>::duplicate() const
{
    return new Number<B,N, T>(*this);
}

template <int B, int N, class T>
NumberBase *Number<B, N, T>::operator+(NumberBase *num) const
{
    Number<N,B,T> *sum=dynamic_cast<const Number<N,B,T>*>(num);
    if (sum != NULL)
    {
        NumberBase resul = duplicate();
        resul=*this + sum;
        NumberBase *fin=dynamic_cast<const Number<N,B,T>*>(resul);
        return fin;
    }
    else
        throw wrong_number_exception();
}

template <int B, int N, class T>
Number<B, N, T> *Number<B, N, T>::operator+(const  Number<B,N,T> *num) const
{
    return suma(num);
}

template <int B, int N, class T>
NumberBase *Number<B, N, T>::operator-(NumberBase *num) const
{
    Number<N,B,T> *sum=dynamic_cast<const Number<N,B,T>*>(num);
    sum.set_sing(sum.sign*-1);
    if (sum != NULL)
    {
        NumberBase resul = duplicate();
        resul=*this + sum;
        NumberBase *fin=dynamic_cast<const Number<N,B,T>*>(resul);
        return fin;
    }
    else
        throw wrong_number_exception();
}

template <int B, int N, class T>
Number<B, N, T> *Number<B, N, T>::operator-(const  Number<B,N,T> *num) const
{
    return suma(num);
}

template <int B,int N, class T>
std::ostream& Number<B,N,T>::operator <<(Number<B,N,T>* num)const
{
    return num.write(std::cout);
}

//--------------------------------------------------------------------

//especializacion binaria de number

//--------------------------------------------------------------------

template <int N, class T>
Number<2, N, T>::Number(int val):NumberBase(2,N)
{
    num = new T[N];
    if (pow(2, N) < val)
        throw OutOfRange();
    to_base(val);
}

template <int N, class T>
Number<2, N, T>::~Number()
{
    delete[] num;
}

// template <int N, class T>
// Number<2, N, T>::Number(const Number<2, N, T> &a)
// {
//     a.set_sig(signo);
//     for (int i = 0; i < N; ++i)
//         a.set_val(num[i], i);
// }

template <int N, class T>
void Number<2, N, T>::to_base(int val)
{
    int aux = val;

    if (val < 0)
    {
        signo = -1;
        aux *= -1;
    }

    for (int i = 0; i < N; i++)
    {
        if (aux > 0)
        {
            num[i] = char(aux % 2);
            aux = aux / 2;
        }
        else
            num[i] = 0;
    }

    if (aux > 2)
        throw NoNumber();

    if (signo == -1)
        complementador();
}

template <int N, class T>
void Number<2, N, T>::complementador()
{
    Number<2, N> aux;
    aux.to_base(1);

    for (int i = 0; i < N; i++)
    {
        if (num[i] == 1)
            num[i] = 0;
        else if (num[i] == 0)
            num[i] = 1;
    }

    *this = suma(aux);
}

template <int N, class T>
Number<2, N, T> Number<2, N, T>::suma(const Number<2, N, T> &op) const
{
    Number<2, N> aux;
    int carry = 0;
    for (int i = 0; i < N; i++)
    {
        aux.num[i] = (num[i] + op.num[i] + carry) % 2;
        if (num[i] + op.num[i] + carry >= 2)
            carry = 1;
        else
            carry = 0;
    }

    if (carry > 0 && op.signo != -1 || carry > 0 && signo != -1)
        throw Overflow();

    return aux;
}

template <int N, class T>
std::ostream &Number<2, N, T>::write(std::ostream &os) const
{
    if (signo == -1)
        os << "-";

    for (int i = N - 1; i >= 0; i--)
    {
        if (static_cast<int>(num[i]) < 9)
            os << int(num[i]);
        else
            os << char('a' + int(num[i]) - 10);
    }
    os << std::endl;

    return os;
}

template <int N, class T>
Number<2, N, T> &Number<2, N, T>::operator=(const Number<2, N, T> &copy)
{
    delete[] num;
    num = new T[N];

    for (int i = 0; i < N; i++)
        num[i] = copy.num[i];

    return *this;
}

template <int N, class T>
Number<2, N, T>::operator Number<2, N + 1, T>() const
{
    Number<2, N + 1, T> x;
    for (int i = 0; i < N; i++)
    {
        x.set_val(int(num[i]), i);
    }
    if (signo == -1)
        x.set_val(1, N);
    else
        x.set_val(0, N);

    x.set_sig(signo);

    return x;
}

template <int N, class T>
void Number<2, N, T>::set_val(int x, int pos)
{
    num[pos] = x;
}

template <int N, class T>
void Number<2, N, T>::set_sig(int x)
{
    signo = x;
}

//nuevo

template <int N, class T>
NumberBase *Number<2, N, T>::duplicate() const
{
    return new Number<2, N, T>(*this);
}

template <int N, class T>
NumberBase *Number<2, N, T>::operator+(const  NumberBase *num) const
{
    Number<2, N, T> *sum = dynamic_cast<const Number<2, N, T>>(num);
    if (sum != NULL)
    {
        Number<2, N, T> *resul= dynamic_cast<Number<2, N, T>*>(duplicate());
        return *resul=*this + *sum;
    }
    else
        throw wrong_number_exception();
}

template <int N, class T>
Number<2, N, T> *Number<2, N, T>::operator+(const  Number<2, N, T> *num) const
{
    return suma(num);
}

template <int N, class T>
NumberBase *Number<2, N, T>::operator-(const  NumberBase *num) const
{
   Number<2, N, T> *sum = dynamic_cast<const Number<2, N, T>>(num);
    sum.set_sing(sum.sign*-1);
    if (sum != NULL)
    {
        Number<2, N, T> *resul= dynamic_cast<Number<2, N, T>*>(duplicate());
        return *resul=*this + *sum;
    }
    else
        throw wrong_number_exception();
}

template <int N, class T>
Number<2, N, T> *Number<2, N, T>::operator-(const  Number<2, N, T> *num) const
{
    return suma(num);
}

template <int N, class T>
std::ostream& Number<2,N,T>::operator <<(Number<2,N,T>* num)const
{
    return num.write(std::cout);
}