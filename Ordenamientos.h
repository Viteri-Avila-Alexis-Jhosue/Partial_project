#pragma once
#ifndef ORDENAMIENTOS_H
#define ORDENAMIENTOS_H

#include <algorithm>
#include <string>
#include <cctype>
#include "Nodo.h"
#include "Lista.h"
#include "Persona.h"

void shellSortPersonas(Nodo* cabeza, Nodo* cola, bool esCircular, int criterio);
void shellSort(std::string& str);

void radixSort(std::string& str);
void radixSortPersonas(Nodo*& cabeza, Nodo* cola, bool esCircular, int criterio);

void bubbleSortPersonas(Nodo* cabeza, Nodo* cola, bool esCircular, int criterio);
void bubbleSort(std::string& str);

void quickSortPersonas(Nodo*& cabeza, Nodo*& cola, bool esCircular, int criterio);
void quickSort(std::string& str);

void intercambioPersonas(Nodo* cabeza, Nodo* cola, bool esCircular, int criterio);
void intercambio(std::string& str);

void BucketSort(Nodo*& cabeza, Nodo*& cola, bool esCircular, int n);
void invertirStringDesdeIndice(string& str, int indice);
void inversoString(Nodo* cabeza, Nodo* cola, bool esCircular, int criterio);
#endif // ORDENAMIENTOS_H