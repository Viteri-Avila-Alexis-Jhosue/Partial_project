/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Proyecto 1, Parcial 1                               *
 * Autor:                          Camila Amores, Alexander Benavidez, Alexis Viteri   *
 * Fecha de creacion:              06/12/2024                                          *
 * Fecha de modificacion:          11/12/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 ***************************************************************************************/
#include "../include/Registro.h"

Registro::Registro(const Auto& autoPermitido, const Propietario& propietario)
    : autoPermitido(autoPermitido), propietario(propietario) {}
