#pragma once
#include <iostream>

#include "cont_t.hpp"

class DNI_t
{
    int dni_;
    static cont_t cont;

  public:
    DNI_t();
    ~DNI_t();
    bool operator==(const DNI_t &x);
    bool operator<(const DNI_t &x);
    int get_DNI() const;
};