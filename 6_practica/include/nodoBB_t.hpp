#pragma once
#include <iostream>

template <class T>
class nodoBB_t
{
private:
    T val_;
    nodoBB_t *izq_;
    nodoBB_t *dch_;

public:
    nodoBB_t(){};
    nodoBB_t(T val)
    {
        val_ = val;
        izq_ = NULL;
        dch_ = NULL;
    };
    ~nodoBB_t(){};

    T get_val() { return val_; }

    void set_izq(nodoBB_t *nodo) { izq_ = nodo; }
    nodoBB_t *get_izq() { return izq_; }

    void set_dch(nodoBB_t *nodo) { dch_ = nodo; }
    nodoBB_t *get_dch() { return dch_; }
};