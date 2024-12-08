#include "../include/Persona.h"
#include <iostream>
#include <sstream>
#include <ctime>
using namespace std;

// Constructor por defecto
Persona::Persona()
    : nombre(""), cedula(0), correo(""), direccion(""), edad(0), telefono(""), fechaNacimiento("") {}

// Constructor parametrizado
Persona::Persona(string nombre, int cedula, string correo, string direccion, string telefono, string fechaNacimiento)
    : nombre(nombre), cedula(cedula), correo(correo), direccion(direccion), telefono(telefono), fechaNacimiento(fechaNacimiento) {
    this->edad = calcularEdad(fechaNacimiento); // Calcula la edad automáticamente
}

// Getters
string Persona::getNombre() const {
    return nombre;
}

int Persona::getCedula() const {
    return cedula;
}

string Persona::getCorreo() const {
    return correo;
}

string Persona::getDireccion() const {
    return direccion;
}

int Persona::getEdad() const {
    return edad;
}

string Persona::getTelefono() const {
    return telefono;
}

string Persona::getFechaNacimiento() const {
    return fechaNacimiento;
}

// Setters
void Persona::setNombre(const string& nombre) {
    this->nombre = nombre;
}

void Persona::setCedula(int cedula) {
    this->cedula = cedula;
}

void Persona::setCorreo(const string& correo) {
    this->correo = correo;
}

void Persona::setDireccion(const string& direccion) {
    this->direccion = direccion;
}

void Persona::setEdad(int edad) {
    this->edad = edad;
}

void Persona::setTelefono(string telefono) {
    this->telefono = telefono;
}

void Persona::setFechaNacimiento(const string& fechaNacimiento) {
    this->fechaNacimiento = fechaNacimiento;
}

// Método para calcular la edad
int Persona::calcularEdad(const string& fechaNacimiento) {
    // Fecha actual del sistema
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    int anioActual = now->tm_year + 1900; // tm_year cuenta desde 1900
    int mesActual = now->tm_mon + 1;     // tm_mon cuenta de 0 a 11
    int diaActual = now->tm_mday;

    // Fecha de nacimiento
    int anioNacimiento, mesNacimiento, diaNacimiento;
    sscanf(fechaNacimiento.c_str(), "%d-%d-%d", &anioNacimiento, &mesNacimiento, &diaNacimiento);

    // Calcular edad
    int edadCalculada = anioActual - anioNacimiento;
    if (mesActual < mesNacimiento || (mesActual == mesNacimiento && diaActual < diaNacimiento)) {
        edadCalculada--;
    }

    return edadCalculada;
}
std::string Persona::toString() const {
    std::ostringstream oss;
    oss << nombre << "," 
        << cedula << "," 
        << correo << "," 
        << direccion << "," 
        << edad << "," 
        << telefono << "," 
        << fechaNacimiento;
    return oss.str();
}