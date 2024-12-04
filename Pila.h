#pragma once
#ifndef PILA_H
#define PILA_H

#include <stack>
#include <iostream>

class Pila {
private:
    std::stack<int> pila;

public:
    void push(int valor) {
        pila.push(valor);
    }

    void pop() {
        if (!pila.empty()) {
            pila.pop();
        }
    }

    int top() const {
        if (!pila.empty()) {
            return pila.top();
        }
        throw std::out_of_range("La pila está vacía");
    }

    bool empty() const {
        return pila.empty();
    }

    void reemplazar(int viejo, int nuevo) {
        if (pila.empty()) {
            return;
        }
        int topElem = pila.top();
        pila.pop();
        reemplazar(viejo, nuevo);
        if (topElem == viejo) {
            pila.push(nuevo);
        }
        else {
            pila.push(topElem);
        }
    }

    void imprimir() {
        std::stack<int> aux = pila;
        while (!aux.empty()) {
            std::cout << aux.top() << " ";
            aux.pop();
        }
        std::cout << std::endl;
    }
};

#endif // PILA_H