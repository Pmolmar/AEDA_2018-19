#include "DNI_t.hpp"

template <class T>
celda_t<T>::celda_t(int x) : nBloques(x),
                             nCeldas(0)
{
    v = new T[nBloques];
}

template <class T>
celda_t<T>::celda_t()
{
}

template <class T>
celda_t<T>::~celda_t()
{
}

template <class T>
bool celda_t<T>::buscar(const T &val) const
{
    for (int i = 0; i < nBloques; ++i)
    {
        if (v[i] == val)
        {
            return true;
        }
    }
    return false;
}

template <class T>
bool celda_t<T>::insertar(T &val)
{
    if (!lleno() && !buscar(val))
    {
        v[nCeldas] = val;
        nCeldas++;
        return true;
    }
    return false;
}

template <class T>
bool celda_t<T>::lleno() const
{
    return (nBloques-1 == nCeldas);
}