#pragma once
#include <iostream>

template <class T>
class func_disp_t
{
public:
  func_disp_t(){};
  ~func_disp_t(){};
  virtual int dispersion(const T &val) = 0;
};

template <class T>
class disp_lineal_t : public func_disp_t<T>
{
private:
  int sz_;

public:
  disp_lineal_t(int sz): sz_(sz){};
  ~disp_lineal_t(){};
  virtual int dispersion(const T &val)
  {
    return val.get() % sz_;
  }
};