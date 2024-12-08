// Archivo.h
#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <iostream>
#include <fstream>
#include <string>

class Archivo {
public:
    // Función para cargar datos desde un archivo
    void cargarDatosDesdeArchivo(const std::string& filename);
    // Función para guardar datos en un archivo
    void guardarDatosEnArchivo(const std::string& filename, const std::string& data);
};

#endif
