#pragma once
#include <iostream>

template <class T>
class func_disp_t
{

  public:
    func_disp_t();
    ~func_disp_t();
    virtual void dispersion() = 0;
};

template <class T>
class func_suma_t : public func_disp
{
  private:
    int sz_;

  public:
    func_suma_t();
    ~func_suma_t();
    virtual void dispersion();
};

#include "../src/func_disp_t.tpp"