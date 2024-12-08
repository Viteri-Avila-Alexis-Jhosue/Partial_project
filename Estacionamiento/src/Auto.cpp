#include "../include/Auto.h"
#include "../include/Persona.h"
#include <regex>
#include <iostream>
using namespace std;

// Constructor por defecto
Auto::Auto()
    : placa(""), conductor(Persona()), tipo(""), color("") {}

// Constructor parametrizado
Auto::Auto(const string& placa, const Persona& conductor, const string& tipo, const string& color)
    : placa(placa), conductor(conductor), tipo(tipo), color(color) {}

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
        cout << "Placa no válida. Intente nuevamente." << endl;
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