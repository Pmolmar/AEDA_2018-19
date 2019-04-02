#pragma once

#include <iostream>
#include <exception>

class exepciones_t : public std::exception
{
};

class No_Val : public exepciones_t
{
  public:
    virtual const char *what(void) const throw()
    {
        return "Parametro fuera de rango";
    }
};