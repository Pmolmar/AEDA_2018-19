#pragma once
#include <iostream>
#include "../src/NumberExeption.cpp"

class NumberBase
{
  private:
    int base;
    int digit;
    NumberBase(int B, int N) : base(B), digit(N)
    {
        if (base < 2 || digit < 1)
            throw wrong_number_exception();
    };
    ~NumberBase(){};

  protected:
    virtual void to_base(int val) = 0;
    virtual std::ostream &write(std::ostream &) const = 0;
    virtual NumberBase *duplicate() const = 0;

  public:
    virtual NumberBase *operator+(const NumberBase *) const = 0;
    virtual NumberBase *operator-(const NumberBase *) const = 0;
};