#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Menus.h"


using namespace std;

enum OpcionesPrincipal {
    ORDENAMIENTO_INTERCAMBIO,
    ORDENAMIENTO_BURBUJA,
    ORDENAMIENTO_SHELL,
    ORDENAMIENTO_RAPIDO,
    ORDENAMIENTO_RADITZ,
    ORDENAMIENTO_DISTRIBUCION,
    NUM_OPCIONES_PRINCIPAL
};

void mostrarMenuPrincipal(int opcion) {
    system("cls");
    const char* opciones[] = {
        "Ordenamiento de Intercambio",
        "Ordenamiento de Burbuja",
        "Ordenamiento de Shell",
        "Ordenamiento Quicksort",
        "Ordenamiento Raditz",
        "Ordenamiento de Distribucion"
    };

    cout << "******************************" << endl;
    cout << "Seleccione el tipo de ordenamiento:" << endl;
    cout << "******************************" << endl;
    for (int i = 0; i < NUM_OPCIONES_PRINCIPAL; ++i) {
        if (i == opcion) {
            setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE); // Cambiar color
            cout << " --> " << opciones[i] << "\n";
            setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Restaurar color
        }
        else {
            cout << "     " << opciones[i] << "\n";
        }
    }
    cout << "******************************" << endl;
}

int main() {
    int opcion = 0;
    bool continuar = true;

    while (continuar) {
        mostrarMenuPrincipal(opcion);

        int tecla = _getch();
        switch (tecla) {
        case 72: // Flecha arriba
            opcion = (opcion - 1 + NUM_OPCIONES_PRINCIPAL) % NUM_OPCIONES_PRINCIPAL;
            break;
        case 80: // Flecha abajo
            opcion = (opcion + 1) % NUM_OPCIONES_PRINCIPAL;
            break;
        case 13: // Enter
            switch (opcion) {
            case ORDENAMIENTO_INTERCAMBIO:
                // Llamar a la funci�n de ordenamiento de Intercambio
                MenuIntercambio();
                break;
            case ORDENAMIENTO_BURBUJA:
                // Llamar a la funci�n de ordenamiento de Burbuja
                MenuBurbujaMain();
                break;
            case ORDENAMIENTO_SHELL:
                // Llamar a la funci�n de ordenamiento de Shell
                MenuShellMain();
                break;
            case ORDENAMIENTO_RAPIDO:
                // Llamar a la funci�n de ordenamiento Quicksort
                MenuQuicksortMain();
                break;
            case ORDENAMIENTO_RADITZ:
                // Llamar a la funci�n de ordenamiento Raditz
                MenuRadixMain();
                break;
            case ORDENAMIENTO_DISTRIBUCION:
                // Llamar a la funci�n de ordenamiento de Distribuci�n
                MenuDistribucion();
                break;
            }
        }
    }

    return 0;
}