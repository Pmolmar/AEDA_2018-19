#pragma once
#include <iostream>

#include "cont_t.hpp"

class DNI_t
{
  int dni_;
public:
  DNI_t();
  ~DNI_t();
  bool operator==(const DNI_t &x);
  bool operator<(const DNI_t &x);
  int get() const;

  static cont_t cont;
  static cont_t max;
  static cont_t min;
  static cont_t iter;
};