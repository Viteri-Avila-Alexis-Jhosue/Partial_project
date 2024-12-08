#ifndef NODO_H
#define NODO_H

template <typename T>
class Nodo {
private:
    T dato;                  // Dato almacenado en el nodo
    Nodo<T>* siguiente;      // Puntero al siguiente nodo
    Nodo<T>* anterior;       // Puntero al nodo anterior

public:
    // Constructor
    Nodo(T dato) : dato(dato), siguiente(nullptr), anterior(nullptr) {}

    // Getters y Setters
    T getDato() const {
        return dato;
    }

    void setDato(T dato) {
        this->dato = dato;
    }

    Nodo<T>* getSiguiente() const {
        return siguiente;
    }

    void setSiguiente(Nodo<T>* siguiente) {
        this->siguiente = siguiente;
    }

    Nodo<T>* getAnterior() const {
        return anterior;
    }

    void setAnterior(Nodo<T>* anterior) {
        this->anterior = anterior;
    }
};

#endif // NODO_H
