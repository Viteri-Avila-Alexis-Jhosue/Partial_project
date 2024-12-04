#pragma once
#ifndef NODO_H
#define NODO_H

#include "Persona.h"

class Nodo {
public:
    Persona dato;
    Nodo* siguiente;
    Nodo* anterior;

    Nodo(const Persona& p) : dato(p), siguiente(nullptr), anterior(nullptr) {}

    //Nodos para el arbol
    /*Nodo* derecha;
    Nodo* izquierda;
    Nodo* padre;

    Nodo(const Persona& p, Nodo* pad) : dato(p), izquierda(nullptr), derecha(nullptr), padre(pad) {}
    Nodo(const Persona& p) : dato(p), siguiente(nullptr), anterior(nullptr) {}

    //Metodos para la creacion del nodo de arbol

    void setDerecha(Nodo* derecha) {
        this->derecha = derecha;
    }

    Nodo*& getDerecha() {
        return derecha;
    }

    void setIzquierda(Nodo* izquierda) {
        this->izquierda = izquierda;
    }

    Nodo*& getIzquierda() {
        return izquierda;
    }

    Nodo*& getPadre() {
        return padre;
    }

    void setPadre(Nodo* padre) {
        this->padre = padre;
    }*/
};

#endif