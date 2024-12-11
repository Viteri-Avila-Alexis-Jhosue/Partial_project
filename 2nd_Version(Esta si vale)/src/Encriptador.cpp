/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Proyecto 1, Parcial 1                               *
 * Autor:                          Camila Amores, Alexander Benavidez, Alexis Viteri   *
 * Fecha de creacion:              06/12/2024                                          *
 * Fecha de modificacion:          11/12/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 ***************************************************************************************/
    #include "../include/Encriptador.h"

    std::string Encriptador::encriptarCesar(const std::string& texto, int desplazamiento) {
        std::string textoEncriptado = texto;
        
        for (char& c : textoEncriptado) {
            if (isalpha(c)) {  // Solo encriptar letras
                char limite = islower(c) ? 'a' : 'A';
                c = (c - limite + desplazamiento) % 26 + limite;
            }
        }
        
        return textoEncriptado;
    }
    std::string Encriptador::desencriptarCesar(const std::string& texto, int desplazamiento) {
        return encriptarCesar(texto, -desplazamiento);
    }
