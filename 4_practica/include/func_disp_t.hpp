#pragma once
#include <iostream>

template <class T>
class func_disp_t
{
public:
  func_disp_t(){};
  ~func_disp_t(){};
  virtual int dispersion(const T &val, const int &sz) = 0;
};

template <class T>
class disp_lineal_t : public func_disp_t<T>
{
public:
  disp_lineal_t(){};
  ~disp_lineal_t(){};
  virtual int dispersion(const T &val, const int &sz)
  {
    return val.get() % sz;
  }
};