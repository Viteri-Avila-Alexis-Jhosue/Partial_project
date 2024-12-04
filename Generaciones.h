#pragma once
#ifndef GENERACIONES_H
#define GENERACIONES_H

#include "Persona.h"
#include "Nodo.h"
#include <string>
#include <algorithm>
#include <iostream>


std::string generarCorreo(Nodo* cabeza, Persona& persona, bool esCircular);
std::string generarContrasena(Persona& persona);
std::string desencriptarContrasena(Persona& persona);
std::string encriptarSHA1(const std::string& input);

void contarVocalesYConsonantes(Nodo* nodo, int& vocales, int& consonantes);
void contarVocalesYConsonantesRec(Nodo* nodo, int& vocales, int& consonantes);

#endif // GENERACIONES_H