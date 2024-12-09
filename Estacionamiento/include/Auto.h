#ifndef AUTO_H
#define AUTO_H
#include <iostream>
#include <string>
#include "Persona.h" // Asegúrate de que este archivo contiene la definición completa de Persona
#include <fstream>
using namespace std;

class Auto {
private:
    string placa;
    Persona conductor; // Objeto de tipo Persona
    string tipo;       // Puede ser "sedán", "SUV", "camioneta", etc.
    string color;

public:
    // Constructor por defecto
    Auto();

    // Constructor parametrizado
    Auto(const string& placa, const Persona& conductor, const string& tipo, const string& color);

    // Getters
    string getPlaca() const;
    Persona getConductor() const;
    string getTipo() const;
    string getColor() const;

    // Setters
    void setPlaca(const string& placa);
    void setConductor(const Persona& conductor);
    void setTipo(const string& tipo);
    void setColor(const string& color);

    // Validar placa ecuatoriana
    bool validarPlaca(const string& placa) const;

    // Método para representar el auto como una cadena
    std::string toString() const;
};

#endif // AUTO_H
