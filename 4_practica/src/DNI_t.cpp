#include "DNI_t.hpp"

cont_t DNI_t::cont;
cont_t DNI_t::max;
cont_t DNI_t::min;
cont_t DNI_t::iter;

DNI_t::DNI_t() : dni_(rand() % 99999999)
{
}

DNI_t::~DNI_t()
{
}

bool DNI_t::operator==(const DNI_t &x)
{
    if (min.get_cont() > iter.get_cont())
        min.set_cont(iter.get_cont());
    if (max.get_cont() < iter.get_cont())
        max.set_cont(iter.get_cont());
    ++iter;
    ++cont;
    return dni_ == x.get();
}

bool DNI_t::operator<(const DNI_t &x)
{
    ++cont;
    return dni_ < x.get();
}

int DNI_t::get() const
{
    return dni_;
}
