#ifndef LISTA_DOBLE_CIRCULAR_H
#define LISTA_DOBLE_CIRCULAR_H

#include <iostream>
#include <fstream>
#include <string>
#include "Celda.h"      
#include "Registro.h"
#include "Nodo.h"

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

    // Métodos básicos
    void insertar(T dato) {
        Nodo<T>* nuevoNodo = new Nodo<T>(dato);

        if (!cabeza) {  // Si la lista está vacía
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

    void eliminar(int posicion) {
        if (!cabeza) return;

        Nodo<T>* actual = cabeza;
        int contador = 0;

        do {
            if (contador == posicion) {
                if (actual == cabeza) {
                    cabeza = cabeza->getSiguiente();
                }
                if (actual == cola) {
                    cola = cola->getAnterior();
                }
                actual->getAnterior()->setSiguiente(actual->getSiguiente());
                actual->getSiguiente()->setAnterior(actual->getAnterior());
                delete actual;
                return;
            }
            actual = actual->getSiguiente();
            contador++;
        } while (actual != cabeza);
    }

    void recorrer() {
        if (!cabeza) {
            std::cout << "La lista está vacía." << std::endl;
            return;
        }

        Nodo<T>* actual = cabeza;
        do {
            std::cout << actual->getDato() << std::endl;
            actual = actual->getSiguiente();
        } while (actual != cabeza);
    }

    void cargarDesdeArchivo(const std::string& nombreArchivo) {
        std::ifstream archivo(nombreArchivo);
        if (!archivo.is_open()) {
            std::cerr << "Error al abrir el archivo." << std::endl;
           
        }

        T dato;
        while (archivo >> dato) {
            insertar(dato);
        }
        archivo.close();
    }

    void guardarEnArchivo(const std::string& nombreArchivo) {
        std::ofstream archivo(nombreArchivo);
        if (!archivo.is_open()) {
            std::cerr << "Error al abrir el archivo para guardar." << std::endl;
            return;
        }

        Nodo<T>* actual = cabeza;
        do {
            archivo << actual->getDato() << std::endl;  // Suponemos que T tiene un operador de salida sobrecargado
            actual = actual->getSiguiente();
        } while (actual != cabeza);

        archivo.close();
    }

    Nodo<T>* buscarPorPlaca(const std::string& placa) {
        Nodo<T>* actual = cabeza;
        do {
            if (actual->getDato().getPlaca() == placa) {
                return actual;
            }
            actual = actual->getSiguiente();
        } while (actual != cabeza);
        return nullptr;  // Si no lo encuentra
    }

    Nodo<T>* buscarPorFecha(time_t fecha) {
        Nodo<T>* actual = cabeza;
        do {
            if (actual->getDato().getIngreso() == fecha) {
                return actual;
            }
            actual = actual->getSiguiente();
        } while (actual != cabeza);
        return nullptr;  // Si no lo encuentra
    }

    Nodo<T>* buscarPorPropietario(const std::string& propietario) {
        Nodo<T>* actual = cabeza;
        do {
            if (actual->getDato().getPropietario().getNombre() == propietario) {
                return actual;
            }
            actual = actual->siguiente;
        } while (actual != cabeza);
        return nullptr;  // Si no lo encuentra
    }
};

#endif // LISTA_DOBLE_CIRCULAR_H
