#include <iostream>
#include <exception>

class NumberExeption: public std::exception
{
};

class NoNumber: public NumberExeption
{
	public:
		virtual const char* what(void) const throw()
		{
			return "Entrada no admitida.";//preguntar sobre como detectar que lo que pasamos por parametros no es la var indicada
		}
};

class OutOfRange: public NumberExeption
{
	public:
		virtual const char* what(void) const throw()
		{
			return "Numero fuera del rango.";
		}
};

class Overflow: public NumberExeption
{
	public:
		virtual const char* what(void) const throw()
		{
			return "Se ha generado overflow.";
		}
};

class wrong_number_exception: public NumberExeption
{
	public:
		virtual const char* what(void) const throw()
		{
			return "Parametros no aceptados.";
		}
};




