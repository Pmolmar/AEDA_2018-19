#include "exepciones_t.hpp"
#include "celda_t.hpp"
#include "func_disp_t.hpp"
#include "func_exp_t.hpp"
#include "cont_t.hpp"
#include "DNI_t.hpp"

template <class T>
tabla_hash_t<T>::tabla_hash_t(int c, int b, int fd, int fe) : nCeldas(c),
                                                              nBloques(b)
{

    V = new celda_t<T> *[nCeldas];
    for (int i = 0; i < nCeldas; i++)
        V[i] = new celda_t<T>(nBloques);

    switch (fd)
    {
    case 0:
        D = new disp_lineal_t<T>(nCeldas);
        break;

    default:
        throw No_Val();
        break;
    }

    switch (fe)
    {
    case 0:
        E = new exp_redisp_t<T>(nCeldas);
        break;

    default:
        throw No_Val();
        break;
    }
}

template <class T>
tabla_hash_t<T>::~tabla_hash_t()
{
}

template <class T>
bool tabla_hash_t<T>::buscar(const T &val) const
{
    DNI_t::iter.reset();
    if (V[D->dispersion(val)]->buscar(val))
        return true;

    for (int i = 1; i < nCeldas; ++i)
    {
        if (V[E->exploracion(val, i)]->buscar(val))
            return true;
    }
    return false;
}

template <class T>
bool tabla_hash_t<T>::insertar(T &val)
{
    DNI_t::iter.reset();
    if (V[D->dispersion(val)]->insertar(val))
        return true;

    for (int i = 1; i <= nCeldas; ++i)
    {
        if (V[E->exploracion(val, i)]->insertar(val))
            return true;
    }
    return false;
}