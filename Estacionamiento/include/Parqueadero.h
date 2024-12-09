#ifndef PARQUEADERO_H
#define PARQUEADERO_H

#include <vector>
#include <string>
#include "Auto.h"
using namespace std;

class Parqueadero {
private:
    static const int CAPACIDAD_TOTAL = 300; // Número total de celdas
    vector<Auto*> celdas; // Vector de punteros a objetos Auto (nullptr si la celda está vacía)
    vector<string> historial; // Historial de ingresos y salidas en texto o estructura

public:
    // Constructor sin argumentos
    Parqueadero();
    
    // Constructor con cantidad de celdas
    Parqueadero(int cantidad);

    // Métodos
    vector<string> verHistorial() const; // Muestra el historial completo
    int buscarAuto(const string& placa) const; // Busca un auto por placa y devuelve el índice de la celda
    void verParqueadero() const; // Imprime el estado actual del parqueadero
    int consultarDisponibilidad() const; // Devuelve el número de celdas disponibles
    void marcarCasillaOcupada(int indice);
    void marcarCasillaLibre(int indice);
    void mostrarEstado() const;
};


#endif // PARQUEADERO_H
