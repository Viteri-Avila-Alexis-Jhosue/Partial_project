/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Proyecto 1, Parcial 1                               *
 * Autor:                          Camila Amores, Alexander Benavidez, Alexis Viteri   *
 * Fecha de creacion:              06/12/2024                                          *
 * Fecha de modificacion:          11/12/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 ***************************************************************************************/
#include "../include/Menu.h"

int main() {
    
    Parqueadero parqueadero;
    HistorialEstacionamiento historial;
    AutosPermitidos autosPermitidos;

    Menu menu(&parqueadero, &historial, &autosPermitidos);
    
    menu.iniciar();

    return 0;
}
