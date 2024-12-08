#ifndef PERSONA_H
#define PERSONA_H

#include <string>
using namespace std;

class Persona {
private:
    string nombre;
    int cedula;
    string correo;
    string direccion;
    int edad;
    string telefono;
    string fechaNacimiento; // Formato: "YYYY-MM-DD"

public:
    // Constructor por defecto
    Persona();

    // Constructor parametrizado
    Persona(string nombre, int cedula, string correo, string direccion, string telefono, string fechaNacimiento);

    // Getters
    string getNombre() const;
    int getCedula() const;
    string getCorreo() const;
    string getDireccion() const;
    int getEdad() const;
    string getTelefono() const;
    string getFechaNacimiento() const;

    // Setters
    void setNombre(const string& nombre);
    void setCedula(int cedula);
    void setCorreo(const string& correo);
    void setDireccion(const string& direccion);
    void setEdad(int edad);
    void setTelefono(string telefono);
    void setFechaNacimiento(const string& fechaNacimiento);

    // Método para calcular la edad
    int calcularEdad(const string& fechaNacimiento);

     std::string toString() const;
};

#endif // PERSONA_H
