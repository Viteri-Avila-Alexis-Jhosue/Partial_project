/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Proyecto 1, Parcial 1                               *
 * Autor:                          Camila Amores, Alexander Benavidez, Alexis Viteri   *
 * Fecha de creacion:              06/12/2024                                          *
 * Fecha de modificacion:          11/12/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 ***************************************************************************************/
#ifndef REGISTRO_H
#define REGISTRO_H

#include "Auto.h"
#include "Propietario.h"

class Registro {
public:
    Auto autoPermitido;
    Propietario propietario;

    Registro(const Auto& autoPermitido, const Propietario& propietario);
};

#endif // REGISTRO_H
