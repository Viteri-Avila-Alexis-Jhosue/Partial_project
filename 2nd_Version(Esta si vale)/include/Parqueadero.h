/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Proyecto 1, Parcial 1                               *
 * Autor:                          Camila Amores, Alexander Benavidez, Alexis Viteri   *
 * Fecha de creacion:              06/12/2024                                          *
 * Fecha de modificacion:          11/12/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 ***************************************************************************************/
#ifndef PARQUEADERO_H
#define PARQUEADERO_H

#include "EspacioParqueadero.h"
#include <vector>
#include <fstream>
#include <sstream>

class Parqueadero {
private:
    Nodo* head; // Nodo inicial de la lista doblemente enlazada circular
    EspacioParqueadero manejadorEspacios;
    const int capacidad = 60;
    const string archivoParqueadero = "output/parqueadero.txt";

    void inicializarEspacios();
    void cargarDesdeArchivo();
    void guardarEnArchivo();

public:
    Parqueadero();
    ~Parqueadero();

    void mostrarEstado() const;
    bool estacionarAuto(const string& placa, const string& espacioId);
    bool retirarAuto(const string& placa);
};

#endif // PARQUEADERO_H
