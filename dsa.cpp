#include <iostream>
using namespace std;
struct nodo
{
    string nombre;
    int prioridad;
    nodo *next;
};
void agregar_tarea(nodo *&head, string nombre, int prioridad)
{
    nodo *nueva_tarea = new nodo();
    nueva_tarea->prioridad = prioridad;
    nueva_tarea->nombre = nombre;
    nueva_tarea->next = head;
    head = nueva_tarea;
}

void mostrar_tareas(nodo *& head)
{
    nodo *actual = head;
    while (actual != nullptr)
    {
        cout << "Tareas registradas: " << endl;
        cout << actual->prioridad << " -> ";
        cout << actual->nombre << " -> ";
        actual = actual->next;
    }
    cout << " Lista vacia " << endl;
}

int main()
{
    nodo *head = nullptr;
    nodo* prioridad;
    nodo* nombre;
    cout << "Ingrese la prioridad de la tarea: " << endl;
    cin >> prioridad.nodo;
    cout << "Ingrese el nombre de la tarea: " << endl;
    cin >> nombre.nodo;
    agregar_tarea(head, prioridad, nombre) return 0;
}
