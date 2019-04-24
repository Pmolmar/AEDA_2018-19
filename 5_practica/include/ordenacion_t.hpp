#pragma once
#include <iostream>

template <class T>
class ordenacion_t
{
public:
  ordenacion_t(){};
  ~ordenacion_t(){};

  virtual void orden(T *v, int n) = 0;

  static ordenacion_t *create(int op); //encargado de alojar el switch
};

template <class T>
class seleccion_t : public ordenacion_t<T>
{
public:
  seleccion_t() { std::cout << std::endl
                            << "Seleccion." << std::endl; };
  ~seleccion_t(){};

  virtual void orden(T *v, int n)
  {
    int min;
    for (int i = 0; i < n - 1; i++)
    {
      min = i;
      for (int j = i + 1; j < n; j++)
        if (v[j] < v[min])
          min = j;
      T aux = v[min];
      v[min] = v[i];
      v[i] = aux;
    }
  };
};

template <class T>
class sacudida_t : public ordenacion_t<T>
{
public:
  sacudida_t() { std::cout << std::endl
                           << "Sacudida." << std::endl; };
  ~sacudida_t(){};
  virtual void orden(T *v, int n)
  {
    int ini = 1;
    int fin = n - 1;
    int cam = n;
    T x;
    while (ini < fin)
    {
      for (int j = fin; j >= ini; j--)
        if (v[j] < v[j - 1])
        {
          x = v[j - 1];
          v[j - 1] = v[j];
          v[j] = x;
          cam = j;
        }
      ini = cam + 1;
      for (int j = ini; j <= fin; j++)
        if (v[j] < v[j - 1])
        {
          x = v[j - 1];
          v[j - 1] = v[j];
          v[j] = x;
          cam = j;
        }
      fin = cam - 1;
    }
  };
};

template <class T>
class heap_sort_t : public ordenacion_t<T>
{
public:
  heap_sort_t() { std::cout << std::endl
                            << "HeapSort." << std::endl; };
  ~heap_sort_t(){};

  virtual void orden(T *v, int n)
  {
    T x;
    for (int i = (n / 2) - 1; i >= 0; i--)
      baja(i, v, n);

    for (int i = n - 1; i >= 0; i--)
    {
      x = v[0];
      v[0] = v[i];
      v[i] = x;
      baja(0, v, i - 1);
    }
  };

  void baja(int i, T *v, int n)
  {
    int h1, h2, h;
    T x = v[i];

    while (2 * i < n)
    {
      h1 = 2 * i + 1;
      h2 = h1 + 1;
      if (h1 == n)
        h = h1;
      else if (v[h1] > v[h2])
        h = h1;
      else
        h = h2;
      if (v[h].get() <= x.get())
        break;
      else
      {
        v[i] = v[h];
        v[h] = x;
        i = h;
      }
    }
  };
};

template <class T>
class merge_sort_t : public ordenacion_t<T>
{
public:
  merge_sort_t() { std::cout << std::endl
                             << "MergeSort." << std::endl; };
  ~merge_sort_t(){};

  virtual void orden(T *v, int n)
  {
    Msort(v, 0, n - 1);
  };

  void Msort(T *v, int ini, int fin)
  {
    if (ini < fin)
    {
      int cen = (ini + fin) / 2;
      Msort(v, ini, cen);
      Msort(v, cen + 1, fin);
      Mezcla(v, ini, cen, fin);
    }
  };

  void Mezcla(T *v, int ini, int cen, int fin)
  {
    int i = ini;
    int j = cen + 1;
    int k = ini;
    T aux[fin + 1];

    while ((i <= cen) && (j <= fin))
    {
      if (v[i] < v[j])
      {
        aux[k] = v[i];
        i++;
      }
      else
      {
        aux[k] = v[j];
        j++;
      }
      k++;
    }
    if (i > cen)
      while (j <= fin)
      {
        aux[k] = v[j];
        j++;
        k++;
      }
    else
      while (i <= cen)
      {
        aux[k] = v[i];
        i++;
        k++;
      }
    for (int k = ini; k <= fin; k++)
      v[k] = aux[k];
  };
};

template <class T>
class shell_sort_t : public ordenacion_t<T>
{
public:
  shell_sort_t() { std::cout << std::endl
                             << "ShellSort." << std::endl; };
  ~shell_sort_t(){};

  virtual void orden(T *v, int n)
  {
    double alfa = 0.5;
#ifdef Demostracion
    std::cout << "Inrotroduzca alfa: " << std::endl;
    std::cin >> alfa;
#endif

    int delta = n * alfa;
    while (delta > 0)
    {
      delta = delta / 2;
      deltasort(delta, v, n);
    }
  };

  void deltasort(int d, T *v, int n)
  {
    T x;
    int j;

    for (int i = d; i < n; i++)
    {
      x = v[i];
      j = i;
      while ((j > d) && (x < v[j - d]))
      {
        v[j] = v[j - d];
        j = j - d;
      }
      v[j] = x;
    }
  };
};

template <class T>
ordenacion_t<T> *ordenacion_t<T>::create(int op)
{
  switch (op)
  {
  case 0:
    return new seleccion_t<T>;
    break;
  case 1:
    return new sacudida_t<T>;
    break;
  case 2:
    return new heap_sort_t<T>;
    break;
  case 3:
    return new merge_sort_t<T>;
    break;
  case 4:
    return new shell_sort_t<T>;
    break;
  default:
    return new seleccion_t<T>;
    break;
  }
}