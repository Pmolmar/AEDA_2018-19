#pragma once
#include <iostream>
#include "nodoBB_t.hpp"

template <class T>
class arbolBB_t
{
private:
    nodoBB_t<T>* raiz_ = NULL;

public:
    arbolBB_t(){};
    ~arbolBB_t(){};

    virtual bool buscar(int val) = 0;
    virtual void insertar(int val) = 0;
    virtual void eliminar(int val) = 0;
};

template <class T>
class ABB_t : public arbolBB_t<T>
{
private:
    nodoBB_t<T> *raiz_ ;

public:
    ABB_t(){raiz_=NULL;};
    ~ABB_t(){};

    virtual bool buscar(int val) { return BuscarRama(raiz_, val); }

    virtual void insertar(int val) { InsertarRama(raiz_, val); }

    virtual void eliminar(int val) { EliminarRama(raiz_, val); }

    void write(std::ostream &os)
    {
        if (raiz_ == NULL)
            os << "Arbol vacio \n[.]\n";
        else
        {
            nodoBB_t<T> *nodo = raiz_;
            int i = 0;
            recorrido(os, nodo, i);
        }
    }

private:
    bool BuscarRama(nodoBB_t<T> *nodo, int val)
    {
        if (nodo == NULL)
            return false;
        if (val == nodo->get_val())
            return true;
        if (val < nodo->get_val())
            return BuscarRama(nodo->get_izq(), val);
        return BuscarRama(nodo->get_dch(), val);
    };

    void InsertarRama(nodoBB_t<T> *nodo, int val)
    {
        if (nodo == NULL)
            nodo = new nodoBB_t(val);
        else if (val < nodo->get_val())
            InsertarRama(nodo->get_izq(), val);
        else
            InsertarRama(nodo->get_dch(), val);
    };

    void EliminarRama(nodoBB_t<T> *nodo, int val)
    {
        if (nodo == NULL)
            return;
        if (val < nodo->get_val())
            EliminarRama(nodo->get_izq(), val);
        else if (val > nodo->get_val())
            EliminarRama(nodo->get_dch(), val);
        else
        {
            nodoBB_t<T> *Eliminado = nodo;
            if (nodo->get_dch() == NULL)
                nodo = nodo->get_izq();
            else if (nodo->get_izq() == NULL)
                nodo = nodo->get_dch();
            else
                sustituye(Eliminado, nodo->get_izq());
            delete (Eliminado);
        }
    };
    void sustituye(nodoBB_t<T> *eliminado, nodoBB_t<T> *sust)
    {
        if (sust->get_dch() != NULL)
            sustituye(eliminado, sust->get_dch());
        else
        {
            // eliminado->Info = sust->Info;
            // eliminado->Clave = sust->Clave;
            eliminado = sust;
            sust = sust->get_izq();
        }
    };

    void recorrido(std::ostream &os, nodoBB_t<T> *nodo, int i)
    {
        os << "Nivel " << i << ": [" << nodo->get_val() << "] ";
        
        if (nodo->get_izq() != NULL)
            recorrido(os, nodo->get_izq(), ++i);

        if (nodo->get_dch() != NULL)
            recorrido(os, nodo->get_dch(), ++i);
    }
};