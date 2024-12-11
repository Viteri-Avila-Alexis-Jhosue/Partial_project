/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Proyecto 1, Parcial 1                               *
 * Autor:                          Camila Amores, Alexander Benavidez, Alexis Viteri   *
 * Fecha de creacion:              06/12/2024                                          *
 * Fecha de modificacion:          11/12/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 ***************************************************************************************/
#include "../include/Auto.h"

Auto::Auto(const string& placa, const string& marca, const string& color)
    : placa(placa), marca(marca), color(color) {}
    string Auto::getPlaca() const {
    return placa;
}

string Auto::getMarca() const {
    return marca;
}

string Auto::getColor() const {
    return color;
}

// Setters
void Auto::setPlaca(const string& placa) {
    this->placa = placa;
}

void Auto::setMarca(const string& marca) {
    this->marca = marca;
}

void Auto::setColor(const string& color) {
    this->color = color;
}
