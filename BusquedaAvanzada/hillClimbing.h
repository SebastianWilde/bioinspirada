#ifndef HILLCLIMBING_H_INCLUDED
#define HILLCLIMBING_H_INCLUDED
#include "funciones.h"
int generar(int sol)
{
    int distribucion [] = {4,3,2,1};
    int j = Probabilidad(4,distribucion,0.5);
   // cout<<"El bit que muta es: "<<j<<endl;
    string ind = int_to_bits(sol);
    //cout <<"individuo antes de la mutacion" <<ind<<endl;
    if (ind[j] == '0') ind[j] = '1';
    else ind[j] = '0';
    //cout <<"este es el individuo" <<ind<<endl;
    return bit_to_int(ind);
}

int hClimbing(int (*eval)(int))
{
    srand(time(NULL));
    int sol = rand() % 16;
    int valor = eval(sol);
    double tiempo = 1.0;
    while (tiempo>0.0)
    {
        int nuevaSol = generar (sol);
        int nuevoValor = eval(nuevaSol);
        if (nuevoValor>valor) sol=nuevaSol;
        tiempo -=0.1;
    }
    return sol;
}

#endif // HILLCLIMBING_H_INCLUDED
