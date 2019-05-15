#include "DNI_t.hpp"

cont_t DNI_t::cont;

DNI_t::DNI_t() : dni_(rand() % 99999999)
{
}

DNI_t::~DNI_t()
{
}

bool DNI_t::operator==(const DNI_t &x)
{
    ++cont;
    return dni_ == x.get();
}

bool DNI_t::operator<(const DNI_t &x)
{
    ++cont;
    return dni_ < x.get();
}

bool DNI_t::operator>(const DNI_t &x)
{
    ++cont;
    return dni_ > x.get();
}

int DNI_t::get() const
{
    return dni_;
}

void DNI_t::set(int num)
{
    dni_ = num;
}

void DNI_t::operator=(const DNI_t &a)
{
    set(a.get());
}
