/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Proyecto 1, Parcial 1                               *
 * Autor:                          Camila Amores, Alexander Benavidez, Alexis Viteri   *
 * Fecha de creacion:              06/12/2024                                          *
 * Fecha de modificacion:          11/12/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 ***************************************************************************************/
#ifndef AUTO_H
#define AUTO_H

#include <string>
using namespace std;

class Auto {
public:
    string placa;
    string marca;
    string color;

    Auto(const string& placa, const string& marca, const string& color);
    string getPlaca() const;
    string getMarca() const;
    string getColor() const;

    // Setters
    void setPlaca(const string& placa);
    void setMarca(const string& marca);
    void setColor(const string& color);
};

#endif // AUTO_H
