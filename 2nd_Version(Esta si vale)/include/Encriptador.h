/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Proyecto 1, Parcial 1                               *
 * Autor:                          Camila Amores, Alexander Benavidez, Alexis Viteri   *
 * Fecha de creacion:              06/12/2024                                          *
 * Fecha de modificacion:          11/12/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 ***************************************************************************************/
#ifndef ENCRIPTADOR_H
#define ENCRIPTADOR_H

#include <string>

class Encriptador {
public:
    std::string encriptarCesar(const std::string& texto, int desplazamiento);
     std::string desencriptarCesar(const std::string& texto, int desplazamiento);
};

#endif // ENCRIPTADOR_H
