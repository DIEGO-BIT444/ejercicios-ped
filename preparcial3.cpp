#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

struct Player {
    int id;
    string nombre;
    int nivel;
    string clase;
    int poder;

    bool operator<(const Player& other) const {
        return id < other.id;
    }
};

set<Player> players;
map<string, set<int>> jugadoresPorClase;
unordered_map<int, Player> accesoRapido;
vector<int> niveles;

void guardarJugador() {
    Player p;
    cout << "\nIngrese ID: ";
    cin >> p.id;
    cin.ignore();

    cout << "Ingrese nombre: ";
    getline(cin, p.nombre);

    cout << "Ingrese nivel: ";
    cin >> p.nivel;
    cin.ignore();

    cout << "Ingrese clase: ";
    getline(cin, p.clase);

    cout << "Ingrese poder: ";
    cin >> p.poder;
    cin.ignore();

    players.insert(p);
    jugadoresPorClase[p.clase].insert(p.id);
    accesoRapido[p.id] = p;
    niveles.push_back(p.nivel);

    cout << " Jugador guardado.\n";
}

void mostrarJugadores() {
    cout << "\n--- Players (ordenados por ID) ---\n";
    for (const auto& p : players) {
        cout << p.id << " - " << p.nombre
             << " | Clase: " << p.clase
             << " | Nivel: " << p.nivel
             << " | Poder: " << p.poder << endl;
    }
}

void mostrarPorClase() {
    cout << "\n--- Clasificación por Clase ---\n";
    for (const auto& [clase, ids] : jugadoresPorClase) {
        cout << clase << " → ";
        for (int id : ids) cout << id << " ";
        cout << endl;
    }
}

void mostrarTop3() {
    vector<Player> fuertes(players.begin(), players.end());
    sort(fuertes.begin(), fuertes.end(), [](auto& a, auto& b) {
        return a.poder > b.poder;
    });

    cout << "\n TOP 3 más fuertes \n";
    for (int i = 0; i < 3 && i < fuertes.size(); i++) {
        cout << i+1 << ". " << fuertes[i].nombre
             << " | Clase: " << fuertes[i].clase
             << " | Nivel: " << fuertes[i].nivel
             << " | Poder: " << fuertes[i].poder << endl;
    }
}

void filtrarPorPoder(int x) {
    cout << "\n--- Players con poder > " << x << " ---\n";
    for (const auto& p : players) {
        if (p.poder > x)
            cout << p.id << " - " << p.nombre << " (" << p.clase << ") Poder: " << p.poder << endl;
    }
}

void buscarNivel(int n) {
    sort(niveles.begin(), niveles.end());
    bool existe = binary_search(niveles.begin(), niveles.end(), n);
    cout << "\n¿Existe el nivel " << n << "? " << (existe ? "Sí" : "No") << endl;
}

int main() {
    cout << "Sistema RPG Online\n";
    char op = 's';

    while (op == 's' || op == 'S') {
        guardarJugador();
        cout << "\n¿Desea guardar otro? (s/n): ";
        cin >> op;
    }

    mostrarJugadores();
    mostrarPorClase();
    mostrarTop3();

    int minimo;
    cout << "\nIngrese poder mínimo para filtrar: ";
    cin >> minimo;
    filtrarPorPoder(minimo);

    int nivelBuscado;
    cout << "\nIngrese nivel a buscar: ";
    cin >> nivelBuscado;
    buscarNivel(nivelBuscado);

    return 0;
}
