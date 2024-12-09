#ifndef REGISTRO_H
#define REGISTRO_H

#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include "Auto.h"

class Registro {
private:
    string placa;      // Placa del auto
    int celda;              // Número de celda ocupada
    string ingreso;    // Fecha y hora de ingreso (formato string)
    string salida;     // Fecha y hora de salida (formato string)

public:
    // Constructor
    Registro(string placa, int celda, string ingreso, string salida);
    Registro();
    
    string getPlaca() const;
    void setPlaca(string placa);

    int getCelda() const;
    void setCelda(int celda);

    string getIngreso() const;
    void setIngreso(string ingreso);

    string getSalida() const;
    void setSalida(string salida);

    void registrar_ingreso(Auto auto1);  // Método para registrar el ingreso de un auto
    void registrar_salida(Auto auto1);
    string toString() const;
    Auto registrar_por_primera_vez();
};

#endif // REGISTRO_H
