#pragma once
#include <iostream>
#include "../src/NumberExeption.cpp"

class NumberBase
{
  private:
    int base;
    int digit;

  protected:
    virtual void to_base(int val) = 0;
    virtual std::ostream &write(std::ostream& os) const = 0;
    virtual NumberBase *duplicate() const = 0;

  public:
    NumberBase(int B, int N) : base(B), digit(N)
    {
        if (base < 2 || digit < 1)
            throw wrong_number_exception();
    };
    ~NumberBase(){};
    virtual NumberBase operator+(const NumberBase *) const = 0;
    virtual NumberBase operator-(const NumberBase *) const = 0;
    friend std::ostream& operator <<(std::ostream& os,const NumberBase& nu);

};
std::ostream& operator <<(std::ostream& os,const NumberBase& nu)
{
return nu.write(os);
}
