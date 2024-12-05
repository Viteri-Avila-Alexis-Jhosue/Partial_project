#pragma once
#ifndef WINDOW_ARBOL_AA_H
#define WINDOW_ARBOL_AA_H

#include <windows.h>
#include "ArbolAA.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void lanzarInterfazGraficaConArbolAA(ArbolAA* arbol);

#endif // WINDOW_ARBOL_AA_H
