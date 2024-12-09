#include "../include/Parqueadero.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Constructor
Parqueadero::Parqueadero() {
    celdas.resize(CAPACIDAD_TOTAL, nullptr); // Inicializa las celdas como vacías (nullptr)
}
// Constructor con cantidad de celdas
Parqueadero::Parqueadero(int cantidad) {
    celdas.resize(cantidad, nullptr); // Inicializa las celdas como vacías (nullptr)
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
// Método para marcar una casilla como ocupada
void Parqueadero::marcarCasillaOcupada(int indice) {
    if (indice >= 0 && indice < CAPACIDAD_TOTAL && celdas[indice] == nullptr) {
        // Aquí asumes que un auto debe ser colocado en la celda
        celdas[indice] = new Auto();  // Aquí deberías inicializar el auto apropiadamente
    }
}

// Método para marcar una casilla como libre
void Parqueadero::marcarCasillaLibre(int indice) {
    if (indice >= 0 && indice < CAPACIDAD_TOTAL && celdas[indice] != nullptr) {
        delete celdas[indice];  // Elimina el auto de la celda
        celdas[indice] = nullptr;
    }
}

// Método para mostrar el estado del parqueadero (similar a 'verParqueadero')
void Parqueadero::mostrarEstado() const {
    verParqueadero();  // Usa el método ya definido para mostrar el estado
}
