#include <iostream>
#include <stack>
#include <vector>

template<int B, int N, class T>
Number<B,N,T>::Number(int val) 
{
    to_base(val);
}

template<int B, int N, class T>
Number<B,N,T>::~Number() 
{

}

template<int B, int N, class T>
void Number<B,N,T>::to_base(int val)
{
    int aux=val,i=0;
    if(B>10)
    {
        while(aux>0)
        {
            if(aux%B>=10)
            {
                char letra=static_cast<char>('a'+aux%B-10);
                num[i]=letra;
            }
            else
            {
                num[i]=(static_cast<char>('0'+aux%B));
            }            
            aux=aux/B;
            ++i;
        }
    }
    else
    {
        while(aux>0)
        {
            num[i]=(static_cast<char>('0'+aux%B));
            aux=aux/B;
            ++i;
        }
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
            num[i]='0';
        }
    }
}

template<int B, int N, class T>
Number<B,N,T> Number<B,N,T>::suma(const Number<B,N,T>& op)const
{
    Number<B,N> aux(0);
    int carry=0,op1=0,op2=0;
    for(int i = 0; i < N; i++)
    {
        if(B>10)
        {
            //transforma en un mismo codigo numerico los operandos      
            ((static_cast<int>(op.num[i])-57)>9)?(op1=(static_cast<int>(op.num[i])-97)+10):(op1=(static_cast<int>(op.num[i])-48));

            ((static_cast<int>(num[i])-57)>9)?(op2=(static_cast<int>(num[i])-97)+10):(op2=(static_cast<int>(num[i])-48));
            
            int iter=op1+op2+carry;
            while(iter>=B)
            {
                iter=iter-B;
            }
            if(iter>9)
                aux.num[i]='a'+iter-10;
            else
                aux.num[i]='0'+iter;    
           
            if((op1+op2)>=B)
                carry++; 
            else
                carry=0;         
        }
        else
        {
            aux.num[i]='0'+(static_cast<int>(op.num[i])+static_cast<int>(num[i])-96+carry)%B;
            carry=(static_cast<int>(op.num[i])+static_cast<int>(num[i])-96)/B;
        }

    }    
    if(carry>0)
        aux.overflow=true;

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
                if(num[i]!='0')
                {
                    cero=false;
                    os<<num[i];
                }
            }
            else
            {
                os<<num[i];
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
    Number<B,N,T> multi (0);
    int iter=0;
    for(int i = 0; i < N; i++)
    {
        if(num[i]>97)
            iter+=(static_cast<int>(op.num[i])-97);
        else    
            iter+=(static_cast<int>(num[i])-48);
    }

    for(int i = 0; i < iter; i++)
    {
        multi=op.suma(multi);
    }
    
    return multi;
}