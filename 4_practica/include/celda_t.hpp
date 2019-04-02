#pragma once

template <class T>
class celda_t
{
  int nBloques, nCeldas;
  T *v;

public:
  celda_t(int x);
  celda_t();
  ~celda_t();
  bool buscar(const T &val) const;
  bool insertar(T &val);
  bool lleno() const;
};

#include "../src/celda_t.tpp"