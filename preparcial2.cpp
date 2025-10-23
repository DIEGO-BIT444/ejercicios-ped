#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
struct coleccion_libros
{
    string titulo;
    string autor;
    int anio_publish;
    int num_paginas;
};

struct biblioteca
{
    string nombre;
    string ubicacion;
    vector<coleccion_libros> libros;
};
struct nodo
{
    biblioteca datos;
    nodo *siguiente;
};

void solicitar_informacion(list<biblioteca> &bibliotecas)
{

    biblioteca b;
    cout << "Ingrese el nombre del la biblioteca: ";
    getline(cin >> ws, b.nombre);
    cout << "Ingrese la ubicacion de la biblioteca: ";
    getline(cin >> ws, b.ubicacion);

    char continuar = 's';
    cout << "\nAhora ingrese los libros de la bilbioteca: " << endl;

    while (continuar == 's' || continuar == 'S')
    {
        coleccion_libros l;
        cout << "Titulo: ";
        getline(cin >> ws, l.titulo);
        cout << "autor: ";
        getline(cin >> ws, l.autor);
        cout << "Año de publicacion: ";
        getline(cin >> ws, l.anio_publish);
        cout << "Numero de paginas: ";
        getline(cin >> ws, l.num_paginas);

    }
}
int main()
{
    list<biblioteca> bibliotecas;

    return 0;
}
