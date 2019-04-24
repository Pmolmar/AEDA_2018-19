#include <iostream>

#include "ordenacion_t.hpp"
#include "DNI_t.hpp"

#define VEC 20

int main()
{
    int sz;
    std::cout << "Introduzca tamaño del vector: " << std::endl;
    std::cin >> sz;

#ifdef Demostracion
    int op;

    std::cout << "0-Seleccion." << std::endl;
    std::cout << "1-Sacudida." << std::endl;
    std::cout << "2-HeapSort." << std::endl;
    std::cout << "3-MergeSort." << std::endl;
    std::cout << "4-ShellSort." << std::endl;
    std::cout << "Introduzca opcion: " << std::endl;
    std::cin >> op;

    DNI_t *v = new DNI_t[sz];
    ordenacion_t<DNI_t> *func;

    std::cout << std::endl
              << "Vector desordenado " << std::endl;
    for (int i = 0; i < sz; i++)
    {
        DNI_t a;
        v[i] = a;
        std::cout << v[i].get() << " ";
    }
    std::cout << std::endl;

    func = func->create(op);

    std::cout << "Vector ordenado " << std::endl;
    func->orden(v, sz);
    for (int i = 0; i < sz; i++)
    {
        std::cout << v[i].get() << " ";
    }
#endif

#ifdef Estadistica
    int res[VEC][5];

    for (int it = 0; it < VEC; ++it)
    {
        DNI_t *v = new DNI_t[sz];
        ordenacion_t<DNI_t> *func;

        for (int j = 0; j < sz; j++)
        {
            DNI_t a;
            v[j] = a;
        }
        for (int i = 0; i < 5; ++i)
        {
            DNI_t *x = new DNI_t[sz];
            for (int j = 0; j < sz; j++)
            {
                x[j] = v[j];
            }

            func = func->create(i);
            func->orden(x, sz);

            res[it][i] = DNI_t::cont.get_cont();

            DNI_t::cont.reset();
        }
    }
    int max[5];
    int min[5];
    int med[5];

    std::cout << "max[x]  min[x]  med[x]" << std::endl;

    for (int x = 0; x < 5; ++x)
    {
        max[x] = 0;
        min[x] = 99999;
        med[x] = 0;

        for (int i = 0; i < VEC; ++i)
        {
            if (res[i][x] > max[x])
                max[x] = res[i][x];
            if (res[i][x] < min[x])
                min[x] = res[i][x];
            med[x] += res[i][x];
        }
        med[x] = med[x] / VEC;

        std::cout << max[x] << '\t' << min[x] << '\t' << med[x] << std::endl;
    }
#endif

    return 0;
}