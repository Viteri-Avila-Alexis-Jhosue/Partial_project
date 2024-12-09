#ifndef LISTA_DOBLE_CIRCULAR_H
#define LISTA_DOBLE_CIRCULAR_H

#include <iostream>
#include <stdexcept>
#include <ctime>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip> 
#include "Celda.h"      
#include "Registro.h"
#include "Nodo.h"
#include "Persona.h"
#include "Auto.h"

template <typename T>
class Lista_Doble_Circular {
private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;

public:
    // Constructor
    Lista_Doble_Circular() : cabeza(nullptr), cola(nullptr) {}

    // Destructor
    ~Lista_Doble_Circular() {
        if (!cabeza) return;
        Nodo<T>* actual = cabeza;
        do {
            Nodo<T>* siguiente = actual->getSiguiente();
            delete actual;
            actual = siguiente;
        } while (actual != cabeza);
    }

    void insertar(const T& dato) {
        Nodo<T>* nuevoNodo = new Nodo<T>(dato);
        if (!cabeza) {
            cabeza = nuevoNodo;
            cola = nuevoNodo;
            cabeza->setSiguiente(cabeza);
            cabeza->setAnterior(cabeza);
        } else {
            cola->setSiguiente(nuevoNodo);
            nuevoNodo->setAnterior(cola);
            nuevoNodo->setSiguiente(cabeza);
            cabeza->setAnterior(nuevoNodo);
            cola = nuevoNodo;
        }
    }

    // Función para cargar datos desde archivo
void cargarDesdeArchivoRegistro(const std::string& rutaArchivo) {
    std::ifstream archivo(rutaArchivo);
    if (!archivo.is_open()) {
        throw std::runtime_error("No se pudo abrir el archivo: " + rutaArchivo);
    }

    std::string linea;
    while (getline(archivo, linea)) {
        std::istringstream stream(linea);
        Registro registro;

        // Leer los atributos de Registro
        size_t pos = linea.find(',');
        registro.setPlaca(linea.substr(0, pos));
        linea.erase(0, pos + 1);

        pos = linea.find(',');
        registro.setCelda(stoi(linea.substr(0, pos)));
        linea.erase(0, pos + 1);

        pos = linea.find(',');
        std::string fechaIngreso = linea.substr(0, pos);
        linea.erase(0, pos + 1);
        registro.setIngreso(fechaIngreso);  // Guardar como string

        // Leer la fecha y hora de salida (si existe)
        pos = linea.find(',');
        std::string fechaSalida = linea.substr(0, pos);
        linea.erase(0, pos + 1);

        // Si hay fecha de salida, se asigna como string, de lo contrario se asigna una cadena vacía
        if (!fechaSalida.empty()) {
            registro.setSalida(fechaSalida);  // Guardar como string
        } else {
            registro.setSalida("");  // Asignar una cadena vacía si no hay fecha de salida
        }

        // Insertar el registro en la lista
        insertar(registro);
    }

    archivo.close();
}


    void cargarDesdeArchivoPersona(const std::string& rutaArchivo) {
        std::ifstream archivo(rutaArchivo);
        if (!archivo.is_open()) {
            throw std::runtime_error("No se pudo abrir el archivo: " + rutaArchivo);
        }

        std::string linea;
        while (getline(archivo, linea)) {
            std::istringstream stream(linea);
            Persona persona;

            // Dividir los datos por comas y asignar a los atributos de Persona
            size_t startPos = 0;
            size_t commaPos = linea.find(',');

            persona.setNombre(linea.substr(startPos, commaPos - startPos));
            startPos = commaPos + 1;

            commaPos = linea.find(',', startPos);
            persona.setCedula(linea.substr(startPos, commaPos - startPos));
            startPos = commaPos + 1;

            commaPos = linea.find(',', startPos);
            persona.setCorreo(linea.substr(startPos, commaPos - startPos));
            startPos = commaPos + 1;

            commaPos = linea.find(',', startPos);
            persona.setDireccion(linea.substr(startPos, commaPos - startPos));
            startPos = commaPos + 1;

            persona.setEdad(stoi(linea.substr(startPos, linea.find(',', startPos) - startPos)));
            startPos = linea.find(',', startPos) + 1;

            persona.setTelefono(linea.substr(startPos, linea.find(',', startPos) - startPos));
            startPos = linea.find(',', startPos) + 1;

            persona.setFechaNacimiento(linea.substr(startPos));

            // Insertar la persona en la lista
            insertar(persona);
        }

        archivo.close();
    }

    void cargarDesdeArchivoAuto(const std::string& rutaArchivo) {
        std::ifstream archivo(rutaArchivo);
        if (!archivo.is_open()) {
            throw std::runtime_error("No se pudo abrir el archivo: " + rutaArchivo);
        }

        std::string linea;
        while (getline(archivo, linea)) {
            std::istringstream stream(linea);
            Auto autoObj;

            // Leer los atributos de Auto
            size_t pos = linea.find(',');
            autoObj.setPlaca(linea.substr(0, pos));
            linea.erase(0, pos + 1);

            pos = linea.find(',');
            autoObj.setTipo(linea.substr(0, pos));
            linea.erase(0, pos + 1);

            pos = linea.find(',');
            autoObj.setColor(linea.substr(0, pos));

            // Leer los datos del conductor (Persona)
            std::string datosConductor = linea.substr(pos + 1);
            Persona conductor;

            size_t startPos = 0;
            size_t commaPos = datosConductor.find(',');

            conductor.setNombre(datosConductor.substr(startPos, commaPos - startPos));
            startPos = commaPos + 1;

            commaPos = datosConductor.find(',', startPos);
            conductor.setCedula(datosConductor.substr(startPos, commaPos - startPos));
            startPos = commaPos + 1;

            commaPos = datosConductor.find(',', startPos);
            conductor.setCorreo(datosConductor.substr(startPos, commaPos - startPos));
            startPos = commaPos + 1;

            commaPos = datosConductor.find(',', startPos);
            conductor.setDireccion(datosConductor.substr(startPos, commaPos - startPos));
            startPos = commaPos + 1;

            conductor.setEdad(stoi(datosConductor.substr(startPos, commaPos - startPos)));
            startPos = commaPos + 1;

            commaPos = datosConductor.find(',', startPos);
            conductor.setTelefono(datosConductor.substr(startPos, commaPos - startPos));
            startPos = commaPos + 1;

            conductor.setFechaNacimiento(datosConductor.substr(startPos));

            // Asignar el conductor al auto
            autoObj.setConductor(conductor);

            // Insertar el Auto en la lista
            insertar(autoObj);
        }

        archivo.close();
    }
    Nodo<T>* buscarPorPlaca(const std::string& placa) {
    if (!cabeza) return nullptr; // Si la lista está vacía, no hay nada que buscar

    Nodo<T>* actual = cabeza;
    do {
        if (actual->getDato().getPlaca() == placa) {
            return actual; // Devolver el nodo completo encontrado
        }
        actual = actual->getSiguiente();
    } while (actual != cabeza); // Volver al inicio si no se encuentra en la lista

    return nullptr; // Si no se encontró ningún nodo con esa placa
}

};

#endif // LISTA_DOBLE_CIRCULAR_H
