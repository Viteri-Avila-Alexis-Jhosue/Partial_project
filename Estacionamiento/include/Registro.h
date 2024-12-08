#ifndef REGISTRO_H
#define REGISTRO_H

#include "Persona.h"
#include "Auto.h"
#include <string>
#include <ctime>

class Registro {
private:
    std::string placa;      // Placa del auto
    int celda;              // Número de celda ocupada
    std::string tipo;       // Tipo de auto
    Persona propietario;    // Propietario del auto
    std::time_t ingreso;    // Hora de ingreso
    std::time_t salida;     // Hora de salida (opcional)

public:
    // Constructor
    Registro(std::string placa, int celda, std::string tipo, Persona propietario, std::time_t ingreso);
    Registro();
    // Getters y Setters
    std::string getPlaca() const;
    void setPlaca(std::string placa);

    int getCelda() const;
    void setCelda(int celda);

    std::string getTipo() const;
    void setTipo(std::string tipo);

    Persona getPropietario() const;
    void setPropietario(Persona propietario);

    std::time_t getIngreso() const;
    void setIngreso(std::time_t ingreso);

    std::time_t getSalida() const;
    void setSalida(std::time_t salida);

    Auto registrar_por_primera_vez();

    void registrar_ingreso(Auto auto1);
    void registrar_salida(Auto auto1);
    std::string toString() const;
};

#endif // REGISTRO_H
