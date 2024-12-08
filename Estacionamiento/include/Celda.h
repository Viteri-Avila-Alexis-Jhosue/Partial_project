#ifndef CELDA_H
#define CELDA_H

#include "Auto.h"

class Celda {
private:
    int numero;             // Número de la celda
    bool ocupada;           // Estado de la celda
    Auto* autoEstacionado;  // Auto estacionado (nullptr si está vacía)

public:
    // Constructor
    Celda(int numero, bool ocupada = false, Auto* autoEstacionado = nullptr);
    Celda();
    // Getters y Setters
    int getNumero() const;
    void setNumero(int numero);

    bool estaOcupada() const;
    void setOcupada(bool ocupada);

    Auto* getAutoEstacionado() const;
    void setAutoEstacionado(Auto* autoEstacionado);
};

#endif // CELDA_H
