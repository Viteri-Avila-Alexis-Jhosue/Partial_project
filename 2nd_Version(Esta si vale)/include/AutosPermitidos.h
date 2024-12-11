/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Proyecto 1, Parcial 1                               *
 * Autor:                          Camila Amores, Alexander Benavidez, Alexis Viteri   *
 * Fecha de creacion:              06/12/2024                                          *
 * Fecha de modificacion:          11/12/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 ***************************************************************************************/
#ifndef AUTOSPERMITIDOS_H
#define AUTOSPERMITIDOS_H

#include "Auto.h"
#include "Propietario.h"
#include "Registro.h"  // Incluir el encabezado de Registro
#include <vector>
#include <string>

class AutosPermitidos {
private:
    std::vector<Registro> registros;  // Vector de objetos Registro
    const std::string archivo = "output/Autos.txt";

    void cargarDesdeArchivo();
    void guardarEnArchivo();
    void guardarPropietarios();

public:
    AutosPermitidos();
    void agregarAuto(const Auto& autoPermitido, const Propietario& propietario);
    bool buscarAuto(const std::string& placa) const;
    void eliminarAuto(const std::string& placa);
    void mostrarAutos() const;
    void mostrarAutoPorPlaca(const string& placa) const;
    void mostrarPropietarios();
    Auto devolverAuto(const std::string& placa) const ;
};

#endif // AUTOSPERMITIDOS_H
