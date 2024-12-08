#include "../include/Parqueadero.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Constructor
Parqueadero::Parqueadero() {
    celdas.resize(CAPACIDAD_TOTAL, nullptr); // Inicializa las celdas como vacías (nullptr)
}


// Ver historial
vector<string> Parqueadero::verHistorial() const {
    return historial;
}

// Buscar auto
int Parqueadero::buscarAuto(const string& placa) const {
    for (int i = 0; i < CAPACIDAD_TOTAL; i++) {
        if (celdas[i] != nullptr && celdas[i]->getPlaca() == placa) {
            return i; // Retorna el índice de la celda
        }
    }
    return -1; // No encontrado
}

// Ver parqueadero
void Parqueadero::verParqueadero() const {
    for (int i = 0; i < CAPACIDAD_TOTAL; i++) {
        if (celdas[i] == nullptr) {
            cout << "[O] "; // Celda vacía
        } else {
            cout << "[X] "; // Celda ocupada
        }
        if ((i + 1) % 10 == 0) { // Imprime 10 celdas por línea
            cout << endl;
        }
    }
}

// Consultar disponibilidad
int Parqueadero::consultarDisponibilidad() const {
    int disponibles = 0;
    for (const auto& celda : celdas) {
        if (celda == nullptr) {
            disponibles++;
        }
    }
    return disponibles;
}
