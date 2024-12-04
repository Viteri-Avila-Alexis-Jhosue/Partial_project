#pragma once
#ifndef BUSQUEDAS_H
#define BUSQUEDAS_H

#include <string>
#include "Persona.h"

class Busquedas {
public:
    Persona* busquedaSecuencial(const std::string& nombreArchivo, const std::string& cedula);
    void imprimirPersona(Persona* persona);

private:
    Persona* buscarCedulaRecursiva(std::ifstream& archivo, const std::string& cedula);
};

#endif