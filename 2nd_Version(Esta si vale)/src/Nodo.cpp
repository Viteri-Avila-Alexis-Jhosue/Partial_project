/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Proyecto 1, Parcial 1                               *
 * Autor:                          Camila Amores, Alexander Benavidez, Alexis Viteri   *
 * Fecha de creacion:              06/12/2024                                          *
 * Fecha de modificacion:          11/12/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 ***************************************************************************************/
#include "../include/Nodo.h"
#include <iostream>

Nodo::Nodo(const string& id)
    : id(id), ocupado(false), placa(""), horaIngreso(0), siguiente(nullptr), anterior(nullptr) {}

void Nodo::mostrarEstado() const {
    cout << "Espacio " << id << ": "
         << (ocupado ? "Ocupado" : "Libre")
         << ", Placa: " << (placa.empty() ? "N/A" : placa)
         << ", Hora Ingreso: " << (horaIngreso == 0 ? "N/A" : ctime(&horaIngreso)) << endl;
}
