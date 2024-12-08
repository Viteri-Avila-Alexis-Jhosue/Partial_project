#include "../include/Archivo.h"
#include <iostream>
#include <fstream>
#include <string>

void Archivo::cargarDatosDesdeArchivo(const std::string& filename) {
    std::ifstream archivo(filename);
        if (!archivo.is_open()) {
            std::cerr << "No se pudo abrir el archivo " << filename << std::endl;
            return;
        }

    std::string linea;
        while (std::getline(archivo, linea)) {
            std::cout << linea << std::endl;
        }
        archivo.close();
}
void Archivo::guardarDatosEnArchivo(const std::string& filename, const std::string& data) {
    std::ofstream archivo(filename, std::ios::app);  // Append mode
        if (!archivo.is_open()) {
            std::cerr << "No se pudo abrir el archivo " << filename << std::endl;
            return;
    }

        archivo << data << std::endl;
        archivo.close();
}