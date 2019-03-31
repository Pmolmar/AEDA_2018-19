#pragma once
#include <iostream>

#include "celda_t.hpp"
#include "func_disp_t.hpp"
#include "func_exp_t.hpp"
#include "DNI_t.hpp"

template <typename T>
class tabla_hash_t
{
  private:
    int nCeldas, nBloques;
    celda_t<T>* V;
    func_disp_t<T>* D;
    func_exp_t<T>* E;
    
  public:
    tabla_hash_t(int c, int b, int fd, int fe);
    ~tabla_hash_t();
};

#include "../src/tabla_hash_t.tpp"