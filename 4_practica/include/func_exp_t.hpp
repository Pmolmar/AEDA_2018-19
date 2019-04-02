#pragma once
#include <iostream>
#include <random>

template <class T>
class func_exp_t
{

public:
  func_exp_t(){};
  ~func_exp_t(){};
  virtual int exploracion(const T &val, const int &i) = 0;
};

template <class T>
class exp_redisp_t : public func_exp_t<T>
{
public:
  exp_redisp_t(){};
  ~exp_redisp_t(){};
  virtual int exploracion(const T &val, const int &i)
  {
    srand(val.get());
    for (int j = 0; j < i; ++j)
      rand();
    return rand();
  }
};
