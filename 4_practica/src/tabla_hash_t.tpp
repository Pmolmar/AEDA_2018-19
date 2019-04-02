#include "exepciones_t.hpp"
#include "celda_t.hpp"
#include "func_disp_t.hpp"
#include "func_exp_t.hpp"

template <class T>
tabla_hash_t<T>::tabla_hash_t(int c, int b, int fd, int fe) : nCeldas(c),
                                                              nBloques(b)
{
    V = new celda_t<T>(nBloques)[nCeldas];
    //V = new celda_t<T>[nCeldas];

    switch (fd)
    {
    case 0:
        D = new disp_lineal_t<T>;
        break;

    default:
        throw No_Val();
        break;
    }

    switch (fe)
    {
    case 0:
        E = new exp_redisp_t<T>;
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
    return (V[D->dispersion(val)]->buscar(val));
}

template <class T>
bool tabla_hash_t<T>::insertar(T &val)
{
    return (V[D->dispersion(val)]->insertar(val));
}