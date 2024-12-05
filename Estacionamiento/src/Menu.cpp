/*
Universidad de las Fuerzas Armadas ESPE
Programa para crear menu
Alexis Viteri
Fecha de creacion:  23/10/2024
Ultima fecha de modificacion:   05/12/2024
Estructura de Datos
NRC:  1978
*/
#include "../include/Menu.h"
#include <iostream>
#include <conio.h> // Para _getch()

#ifdef _WIN32
#include <windows.h> // Para limpiar pantalla en Windows
#define CLEAR() system("cls")
#else
#include <cstdlib>
#define CLEAR() system("clear")
#endif

Menu::Menu() : selectedIndex(0), title("") {}

void Menu::addOption(const std::string& option) {
    options.push_back(option);
}

void Menu::addTitle(const std::string& title) {
    this->title = title;
}

void Menu::displayMenu() {
    bool running = true;

    while (running) {
        CLEAR();

        // Mostrar el título si está definido
        if (!title.empty()) {
            std::cout << title << "\n";
        }

        std::cout << "\n";

        for (size_t i = 0; i < options.size(); ++i) {
            if (static_cast<int>(i) == selectedIndex) {
                std::cout << "==> " << options[i] << " \n";
            } else {
                std::cout << "  " << options[i] << "\n";
            }
        }

        int key = _getch();
        switch (key) {
            case 72: // Flecha arriba
                selectedIndex = (selectedIndex - 1 + options.size()) % options.size();
                break;
            case 80: // Flecha abajo
                selectedIndex = (selectedIndex + 1) % options.size();
                break;
            case 13: // Enter
                running = false;
                break;
        }
    }
}

int Menu::getSelectedOption() {
    return selectedIndex;
}
