#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
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
        cin >> anio_publish;
        cout << "Numero de paginas: ";
        cin >> num_paginas;
        cin.ignore();
        
        libros.push_back(l);
        
        cout << "Desea agregar más libros a la biblioteca: (s/n) " << endl;
        cin >> continuar;
      
    }
    bibliotecas.push_back(b);
    cout << "BIBLIOTECA REGISTRADA\n";
}

void mostrar_informacion(const list<biblioteca> &bibliotecas){
if (bibliotecas.empty()){
    cout << "No hay bibliotecas " << endl;
}

    for(const auto &b : bibliotecas){
     cout << "Nombre: " << b.nombre;
     cout << "Ubicacion " << b.ubicacion;
     cout << "Libros:\n ";
        for (const auto &l : b.libros){
            cout << l.titulo << endl;
            
            
        }
        
    }
}

void ordenar_bibliotecas(list<biblioteca> &bibliotecas){
    //ordenar la biblioteca por su nombre de forma alfabetica
    bibliotecas.sort([]( const biblioteca &a, const biblioteca &b){
    return a.nombre < b.nombre; 
    });

    
}

void buscar_biblioteca(const list <biblioteca> &bibliotecas){
    //busqueda de una biblioteca por su nombre y mostrar toda su informacion relacionada
if (bibliotecas.empty()){
    cout << "No hay bibliotecas registradas "<< endl;
    return;
}

    string busqueda;
    cout << "Ingrese el nombre de la biblioteca que desea buscar:\n ";
    getline(cin, busqueda);
 auto encontrada =  find_if(bibliotecas.begin(), bibliotecas.end()),[&] (const biblioteca &b) {return b.nombre == busqueda; });
if (encontrada != bibliotecas.end()){
    cout << "BIBLIOTECA ENCONTRADA\n "; 
     cout << "Nombre: " << encontrada -> nombre << endl;
     cout << "Ubicacion: " << encontrada -> ubicacion << endl;
     cout << "Libros:\n ";
    for (const auto &l : encontrada -> libros){

        cout << " | " << l.titulo << " | " << l.autor << " | " << l.anio_publicacion << " | " 
        << l.num_paginas << "paginas\n ";
        
}
} else {

    cout << "No se encontro una biblioteca con ese nombre\n ":
}   
    
}


int main()
{
    list<biblioteca> bibliotecas;
    int opcion;
    do{
        cout << "--------MENU---------" << endl;
        cout << "1. agregar biblioteca\n";
        cout << "2. mostrar informacion\n";
        cout << "3. ordenar bibliotecas\n";
        cout << "4. buscar bibliotecas\n";
        cout << "5. Salir\n";
        switch (opcion){
            case 1:
                solicitar_informacion(bibliotecas);
            break;

            case 2:
            mostrar_informacion(bibliotecas);
            break;

            case 3:

            
              

            
        }
        
        
    }while (opcion != 5);

    return 0;
}
