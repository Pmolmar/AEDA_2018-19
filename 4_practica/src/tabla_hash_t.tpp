template <typename T>
tabla_hash_t<T>::tabla_hash_t(int c, int b, int fd, int fe) : nCeldas(c),
                                                              nBloques(b)
{
    V= new celda_t[nCeldas];
}

template <typename T>
tabla_hash_t<T>::~tabla_hash_t()
{
}