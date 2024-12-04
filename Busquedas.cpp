#include "Busquedas.h"
#include "Persona.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

Persona* Busquedas::buscarCedulaRecursiva(ifstream& archivo, const string& cedula) {
    string linea;
    while (getline(archivo, linea)) {
        size_t pos = linea.find("Cedula: " + cedula);
        if (pos != string::npos) {
            Persona* persona = new Persona();

            // Primera línea: Nombre y Apellido
            stringstream ss(linea);
            string nombre, segundoNombre, apellido;

            // Leer el nombre completo
            size_t posNombre = linea.find("Nombre: ");
            if (posNombre != string::npos) {
                posNombre += 8; // Saltar "Nombre: "
                size_t posComa = linea.find(",", posNombre);
                nombre = linea.substr(posNombre, posComa - posNombre);

                // Leer el apellido
                size_t posApellido = linea.find("Apellido: ", posComa);
                if (posApellido != string::npos) {
                    posApellido += 10; // Saltar "Apellido: "
                    size_t posCedula = linea.find(",", posApellido);
                    apellido = linea.substr(posApellido, posCedula - posApellido);
                }
            }

            persona->setNombre(nombre);
            persona->setApellido(apellido);

            // Segunda línea: Correo, Contrasena Inicial y Contrasena
            if (getline(archivo, linea)) {
                size_t posCorreo = linea.find("Correo: ");
                if (posCorreo != string::npos) {
                    posCorreo += 8; // Saltar "Correo: "
                    size_t posArroba = linea.find("@", posCorreo);
                    string correo = linea.substr(posCorreo, posArroba - posCorreo);
                    persona->setCorreo(correo);

                    // Leer contrasenia inicial
                    size_t posContrasenaInicial = linea.find("Contrasenia inicial: ", posArroba);
                    if (posContrasenaInicial != string::npos) {
                        posContrasenaInicial += 20; // Saltar "Contrasenia inicial: "
                        size_t posComa = linea.find(",", posContrasenaInicial);
                        string contrasenaInicial = linea.substr(posContrasenaInicial, posComa - posContrasenaInicial);
                        persona->setContrasenaInicial(contrasenaInicial);

                        // Leer contrasenia
                        size_t posContrasena = linea.find("Contrasenia: ", posComa);
                        if (posContrasena != string::npos) {
                            posContrasena += 13; // Saltar "Contrasenia: "
                            string contrasena = linea.substr(posContrasena);
                            persona->setContrasena(contrasena);
                        }
                    }
                }
            }

            return persona;
        }
    }
    return nullptr;
}

Persona* Busquedas::busquedaSecuencial(const string& nombreArchivo, const string& cedula) {
    ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        Persona* persona = buscarCedulaRecursiva(archivo, cedula);
        archivo.close();
        return persona;
    }
    else {
        cout << "No se pudo abrir el archivo." << endl;
        return nullptr;
    }
}

void Busquedas::imprimirPersona(Persona* persona) {
    if (persona != nullptr) {
        cout << "Cedula Encontrada!" << endl;
        cout << "Nombre: " << persona->getNombre() << ", Apellido: " << persona->getApellido() << endl;

        cout << "Correo: " << persona->getCorreo() << "@espe.edu.ec"
            << ", Contrasenia inicial: " << persona->getContrasenaInicial()
            << ", Contrasenia: " << persona->getContrasena() << std::endl;
        delete persona;
    }
    else {
        cout << "Usuario no encontrado." << endl;
    }
}