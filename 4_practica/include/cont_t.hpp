#pragma once

class cont_t
{
    unsigned int cont_;

  public:
    cont_t() : cont_(0){};
    ~cont_t(){};
    void reset() { cont_ = 0; };
    void operator++() { cont_++; };
    unsigned int get_cont() { return cont_; };
};