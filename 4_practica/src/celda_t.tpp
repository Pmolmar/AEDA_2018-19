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
    if (!lleno())
    {
        for (int i = 0; i < nBloques; ++i)
        {
            if (v[i] == val)
                return true;
        }
    }
    else
        return false;
}

template <class T>
bool celda_t<T>::insertar(T &val)
{

    if (!lleno())
    {
        for (int i = 0; i < nCeldas; ++i)
        {
            if (val == v[i])
                return true;
        }
        v[nCeldas] = val;
        nCeldas++;
        return true;
    }
    else
        return buscar(val);
}

template <class T>
bool celda_t<T>::lleno() const
{
    return (nBloques == nCeldas);
}