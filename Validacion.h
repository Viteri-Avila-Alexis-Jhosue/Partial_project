#pragma once

#include"Pila.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <conio.h>

using namespace std;

string ingresarStringValidado();
int ingresarEntero();
string ingresarLetra();
bool validar(string numero);
bool validarEntero(string numero);
bool validarLetra(string palabra);
bool validarCedula(string cedula);
string ingresarCedula();
char* ingresar(char* msj);

Pila convertirCedulaAPila(const string& cedula);