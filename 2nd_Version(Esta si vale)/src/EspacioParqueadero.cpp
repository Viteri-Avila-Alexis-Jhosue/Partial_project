/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Proyecto 1, Parcial 1                               *
 * Autor:                          Camila Amores, Alexander Benavidez, Alexis Viteri   *
 * Fecha de creacion:              06/12/2024                                          *
 * Fecha de modificacion:          11/12/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 ***************************************************************************************/
#include "../include/EspacioParqueadero.h"
#include "../include/Nodo.h"

// Crear un nuevo nodo de espacio
Nodo* EspacioParqueadero::crearEspacio(const string& id) {
    return new Nodo(id);
}

// Ocupar un espacio con la placa del auto
void EspacioParqueadero::ocuparEspacio(Nodo* espacio, const string& placa) {
    if (!espacio->ocupado) {
        espacio->ocupado = true;
        espacio->placa = placa;
        espacio->horaIngreso = time(nullptr);
        cout << "El espacio " << espacio->id << " ocupado por un auto con placa " << placa << "." << endl;
    } else {
        cout << "El espacio " << espacio->id << " ya se encuentra ocupado." << endl;
    }
}

// Liberar un espacio ocupado
void EspacioParqueadero::liberarEspacio(Nodo* espacio) {
    if (espacio->ocupado) {
        espacio->ocupado = false;
        espacio->placa = "";
        espacio->horaIngreso = 0;
        cout << "Lugar " << espacio->id << " libere." << endl;
    } else {
        cout << "El lugar " << espacio->id << " ya esta disponible." << endl;
    }
}

// Obtener el estado de un espacio
string EspacioParqueadero::obtenerEstado(const Nodo* espacio) const {
    if (espacio->ocupado) {
        return "Ocupado por " + espacio->placa;
    }
    return "Vacio";
}