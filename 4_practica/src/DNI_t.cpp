#include "DNI_t.hpp"

DNI_t::DNI_t():
dni_(rand()%99999999)
{
}

DNI_t::~DNI_t() 
{}

bool DNI_t::operator ==(const DNI_t& x)
{
    ++cont;
    return dni_==x.get_DNI();
}

bool DNI_t::operator <(const DNI_t& x) 
{
    ++cont;
    return dni_<x.get_DNI();
}

int DNI_t::get_DNI() const
{
    return dni_;
}
