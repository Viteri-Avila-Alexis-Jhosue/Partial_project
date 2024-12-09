#include "../include/Auto.h"
#include "../include/Persona.h"
#include <regex>
#include <iostream>
using namespace std;

// Constructor por defecto
Auto::Auto()
    : placa("UNKNOWN"),
      conductor(Persona("Conductor Predeterminado", "1234567890","ajv@a.e","s","0983785507","2004-02-02")),
      tipo("UNKNOWN"),
      color("UNKNOWN") {}

Auto::Auto(const std::string& placa, const Persona& conductor, const std::string& tipo, const std::string& color)
    : placa(placa.empty() ? "UNKNOWN" : placa), 
      conductor(conductor), 
      tipo(tipo.empty() ? "UNKNOWN" : tipo), 
      color(color.empty() ? "UNKNOWN" : color) {
    // Validación de placa
    if (placa.empty()) {
        throw std::invalid_argument("La placa no puede estar vacia.");
    }
    
    // Validación de tipo
    if (tipo.empty()) {
        throw std::invalid_argument("El tipo no puede estar vacio.");
    }
    
    // Validación de color
    if (color.empty()) {
        throw std::invalid_argument("El color no puede estar vacio.");
    }
}

// Getters
string Auto::getPlaca() const {
    return placa;
}

Persona Auto::getConductor() const {
    return conductor;
}

string Auto::getTipo() const {
    return tipo;
}

string Auto::getColor() const {
    return color;
}

// Setters
void Auto::setPlaca(const string& placa) {
    if (validarPlaca(placa)) {
        this->placa = placa;
    } else {
        cout << "Placa no valida. Intente nuevamente." << endl;
    }
}

void Auto::setConductor(const Persona& conductor) {
    this->conductor = conductor;
}

void Auto::setTipo(const string& tipo) {
    this->tipo = tipo;
}

void Auto::setColor(const string& color) {
    this->color = color;
}

// Validar placa ecuatoriana
bool Auto::validarPlaca(const string& placa) const {
    // Define un patrón para placas ecuatorianas: AAA-#### o AAA####
    regex patron("^[A-Z]{3}-?[0-9]{4}$");
    return regex_match(placa, patron);
}
std::string Auto::toString() const {
    return placa + "," + conductor.toString() + "," + tipo + "," + color;
}
