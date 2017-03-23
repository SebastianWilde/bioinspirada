#ifndef GRILLA_H_INCLUDED
#define GRILLA_H_INCLUDED
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "Nido.h"
#include "Agente.h"
using namespace std;
class Grilla
{
    public:
    char **Tabla;
    int Size, nidox,nidoy,cantidadComida;
    vector < vector<int> > posComida, posFeromona; // almacena las posiciones de la comida y las feromonas
    vector <char> feromona;
    Nido * nido;
    Agente * agente;
    Grilla(int);
    void PrintGrilla();
    void ActulizarGrilla();
    void GenerarComida(int);//recibe la cantidad de Comida;
    void Simular();
};

Grilla::Grilla(int tam)
{
    Size=tam;
    /*Generacion del tablero*/
    Tabla=new char*[Size];
    for (int i=0;i<Size;i++)
        Tabla[i]=new char[Size];
    /*Llenando el tablero con null*/
    for (int i=0;i<Size;i++)
        for(int j=0;j<Size;j++)
            Tabla[i][j]=' ';
    /*Posicion del nido*/
    int nidox = rand() % Size;
    int nidoy = rand() % Size;
    nido = new Nido (nidox,nidoy);
    Tabla[nido->posy][nido->posx]=nido->name;
    /* Generador de comida*/
    cantidadComida = rand() % 10+1 ;
    GenerarComida(cantidadComida);
    /* Generador de agente*/
    agente=new Agente(8,8,'A');
    Tabla[agente->posy][agente->posx]='A';
}

bool contains (vector <int> vec, int num)
{
    bool aux;
    for (int i=0;i<(int)vec.size();i++)
        aux=vec[i]==num;
    return aux;
}

void Grilla::GenerarComida(int cant)
{
    vector<int> generatedValues;
    for (int i=0;i<cant;i++)
    {
        int posx = rand() % Size;
        while(contains(generatedValues, posx) || posx==nidox)
        {
            posx = rand() % Size;
        }
        int posy = rand() % Size;
        while(contains(generatedValues, posy) || posy==nidoy)
        {
            posy = rand() % Size;
        }
        vector <int> aux1 ={posx,posy};
        Tabla[posy][posx] = 'C';
        posComida.push_back(aux1);
    }
}

void Grilla::PrintGrilla()
{
//    ActulizarTablero();
    cout<<endl<<"--------------------------------------"<<endl;
    cout<<endl<<"Cantidad de comida: "<<cantidadComida<<endl;
    agente->Print();
    nido->print();
    cout<<endl;
    for (int i=0;i<Size;i++)
    {
        for (int j=0;j<Size;j++)
            cout<<Tabla[i][j]<<"|";
        cout<<endl;
    }
    return;
}
void Grilla::ActulizarGrilla()
{
    /*Limpiar el tablero*/
//    for (int i=0;i<Size;i++)
//        for(int j=0;j<Size;j++)
//            Tabla[i][j]=' ';
    for (int i=0;i<(int)feromona.size();i++)
    {
        Tabla[posFeromona[i][1]][posFeromona[i][0]]=feromona[i];
    }
    for (int i=0;i<(int)posComida.size();i++)
    {
        Tabla[posComida[i][1]][posComida[i][0]]='C';
    }
    Tabla[agente->posy][agente->posx]=agente->name;
    Tabla[nido->posy][nido->posx]=nido->name;
    return;
}
void Grilla::Simular()
{
    PrintGrilla();
    Sleep(1000);
//    int auxX=agente->posx;
//    int auxY=agente->posy;
    agente->Move(Tabla,Size,nido,posComida,posFeromona,feromona);
//    if (agente->Move(Tabla,Size,nido))
//    {
//        int aux = Contener(posComida,auxX,auxY);
//        posComida.erase (posComida.begin()+(aux+1));
//        cantidadComida=posComida.size();
//    }
    cantidadComida=posComida.size();
    ActulizarGrilla();
    //system("cls");
    PrintGrilla();
}
#endif // GRILLA_H_INCLUDED
