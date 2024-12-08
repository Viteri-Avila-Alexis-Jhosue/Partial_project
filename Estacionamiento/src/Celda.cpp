#include "../include/Celda.h"

// Constructor
Celda::Celda(int numero, bool ocupada, Auto* autoEstacionado)
    : numero(numero), ocupada(ocupada), autoEstacionado(autoEstacionado) {}

// Getters y Setters
int Celda::getNumero() const { return numero; }
void Celda::setNumero(int numero) { this->numero = numero; }

bool Celda::estaOcupada() const { return ocupada; }
void Celda::setOcupada(bool ocupada) { this->ocupada = ocupada; }

Auto* Celda::getAutoEstacionado() const { return autoEstacionado; }
void Celda::setAutoEstacionado(Auto* autoEstacionado) {
    this->autoEstacionado = autoEstacionado;
}
