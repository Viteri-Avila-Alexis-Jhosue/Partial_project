#pragma once
#ifndef MENUS_H
#define MENUS_H

#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Lista.h"
#include "Persona.h"
#include "Validacion.h"
#include "Busquedas.h"
#include "ArbolAA.h"

void setConsoleColor(WORD color);
void mostrarMenu(int opcion);
void mostrarSubMenu(int opcion);
void mostrarSubMenu2(int opcion);
void mostrarMenuOrden(int opcion);
void ingresarDatos(Lista& lista);
bool cedulaRegistradaEnArchivo(const string& cedula);

void encriptador(Nodo* act, int nume);
void encriptado(Lista& lista, int num);
void contarVocalesYConsonantes(Lista& lista);
void reemplazarEnCedula();

void mostrarMenuBusqueda(int opcion);
void menuBusqueda(Lista& lista);
void mostrarSubMenuCombinarListas(int opcion);

void mostrarAdicional(int opcion);
void menuAdicional(Lista& lista);

void MenuShellMain();
void subMenuListaShell(Lista& lista);

void MenuRadixMain();
void subMenuListaRadix(Lista& lista);

void MenuIntercambio();
void subMenuListaIntercambio(Lista& lista);

void MenuQuicksortMain();
void subMenuListaQuicksort(Lista& lista);

void MenuDistribucion();
void subMenuListaDistribucion(Lista& lista);

void MenuBurbujaMain();
void subMenuListaBurbuja(Lista& lista);

#endif