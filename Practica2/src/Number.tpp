#include <iostream>
#include <stack>
#include <vector>
#include <cmath>

template<int B, int N, class T>
Number<B,N,T>::Number(int val) 
{
    //el try este creo que es un poco freestyle mio
    try
    {
        num=new T[N];
        to_base(val); 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

template<int B, int N, class T>
Number<B,N,T>::~Number() 
{
    delete[] num;
}

template<int B, int N, class T>
void Number<B,N,T>::to_base(int val)
{
    int aux=val,i=0;

    if(val<0)
    {
        signo=true;
        val*-1;
    }

    while(aux>0)
    {
        num[i]=char(aux%B);
        aux=aux/B;
        ++i;
    }

    if(i>N)
    {
        std::cerr<<"El numero no puede ser representado."<<std::endl;
        overflow=true;
    }
    else
    {
        for(; i < N; i++)
        {
            num[i]=0;
        }
    }
}

template<int B, int N, class T>
Number<B,N,T> Number<B,N,T>::suma(const Number<B,N,T>& op)const
{
    Number<B,N> aux;
    int carry=0,j=0;
    for(int i = 0; i < N; i++)
    { 
        aux.num[i]=char((int(num[i])+int(op.num[i])+carry)%B);  
        std::cout<<int(aux.num[i]);
        if(int(num[i])+int(op.num[i])>=B)
            carry=1; 
        else
            carry=0;  
    }    
    if(carry>0)
        aux.overflow=true;

    //problema, aux esta apuntado a una region de memoria que al terminar es borrada, 
    //por eso devuleve 0, como hago para mandar la direccion sin borrarla(?);

    return aux;
    
}

template<int B, int N, class T>
std::ostream& Number<B,N,T>::write(std::ostream& os)const
{
    if(!overflow)
    {
        bool cero=true;
        for(int i = N-1; i >=0; i--)
        {
            if(cero)
            {
                if(static_cast<int>(num[i])!=0)
                {
                    cero=false;
                    if(static_cast<int>(num[i])<9)
                        os<<int(num[i]);
                    else
                       os<<char('a'+int(num[i])-10);
                }
            }
            else
            {
                if(static_cast<int>(num[i])<9)
                    os<<int(num[i]);
                else
                    os<<char('a'+int(num[i])-10);
            }
        }
        if(cero)
            os<<"0";
        os<<std::endl;
    }
    else
    {
        os<<"Generado Overflow."<<std::endl;
    }
    
    return os;
}


//esto esta pocho revisar
template<int B, int N, class T>
Number<B,N,T> Number<B,N,T>::multiplicacion(const Number<B,N,T>& op)const
{
    Number<B,N,T> multi ;
    int iter=0,mult=0;
    for(int i = 0; i < N; i++)
    {
        iter=int(num[i]);
        mult+=iter*pow(B,i);
    }

    for(int i = 0; i < mult; i++)
    {
        multi=op.suma(multi);
    }
    
    return multi;
}