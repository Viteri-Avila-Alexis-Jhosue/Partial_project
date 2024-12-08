#include "../include/Archivo.h"
#include "../include/Auto.h"
#include "../include/Celda.h"
#include "../include/Lista_Doble_Circular.h"
#include "../include/Menu.h"
#include "../include/Nodo.h"
#include "../include/Parqueadero.h"
#include "../include/Persona.h"
#include "../include/Registro.h"
#include "../include/Validation.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <filesystem>

int main() {
    int opcion;
    Menu menu;
    Lista_Doble_Circular<Auto> lista_auto;
    Lista_Doble_Circular<Celda> lista_celda;
    Lista_Doble_Circular<Registro> lista_registro;
    menu.addTitle("\t\t  Sistema de gestion de parqueadero ");
    menu.addOption("Registrar ingreso ");
    menu.addOption("Registrar salida ");
    menu.addOption("Ver historial");
    menu.addOption("Buscar auto en el parqueadero");
    menu.addOption("Ver parqueadero");
    menu.addOption("Salir");

    do {
        menu.displayMenu();
        opcion = menu.getSelectedOption();
        Menu menu1;
        Menu menu2;
        Registro registro1;
        Auto nuevoAuto;
        std::string ruta_autos = std::filesystem::current_path().string() + "/output/Autos.txt";
        std::string ruta_clientes = std::filesystem::current_path().string() + "/output/Clientes.txt";
        std::string ruta_historial = std::filesystem::current_path().string() + "/output/Historial.txt";
        switch (opcion) {
        case 0:  // Opción "Registrar ingreso"
            {
                menu1.addTitle("Seleccione el tipo de ingreso:");
                menu1.addOption("Ya estoy registrado");
                menu1.addOption("Primera vez");
                menu1.addOption("Regresar");
                menu1.displayMenu();
                int opcion2 = menu1.getSelectedOption();
                if(opcion2 == 0) {
                    std::string placa;
                    std::cout << "Ingrese su placa registrada: ";
                    std::cin >> placa;
                    Auto autoTemporal;  // Para usar la función validarPlaca
                    if (!autoTemporal.validarPlaca(placa)) {
                        std::cout << "Formato no valido.Debe ser AAA-#### o AAA####." << std::endl;
                    break;
                    }
                    lista_auto.cargarDesdeArchivo(ruta_autos);  // Cargar los autos registrados

                    Nodo<Auto>* autoRegistrado = lista_auto.buscarPorPlaca(placa);
                    if (autoRegistrado) {
                    std::cout << "Placa encontrada: " << placa << std::endl;
                     // Registrar la entrada del auto
                    std::time_t ingreso = std::time(0);  // Hora actual de ingreso
                    std::tm* timeinfo = std::localtime(&ingreso);  // Convertir el timestamp a una estructura tm
                    char buffer[80];  // Para almacenar la fecha y hora en formato legible
                    std::strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);  // Formato de fecha: "AAAA-MM-DD HH:MM:SS"

                    // Crear el objeto Registro con el formato de fecha legible
                    Registro registro = Registro(placa, 1, autoRegistrado->getDato().getTipo(), autoRegistrado->getDato().getConductor(), ingreso);

                    // Insertar el registro en la lista
                    lista_registro.insertar(registro);

                    // Guardar en el historial con la fecha formateada
                    Archivo archivo;
                    archivo.guardarDatosEnArchivo(ruta_historial, "Ingreso: " + placa + " a las " + buffer);

                    std::cout << "Ingreso registrado para el vehículo con placa: " << placa << std::endl;
                } else {
                std::cout << "Placa no registrada. Por favor registre su auto por primera vez." << std::endl;
                }
                } else if(opcion2 == 1) {
                    nuevoAuto = registro1.registrar_por_primera_vez();
                    lista_auto.insertar(nuevoAuto);
                    Archivo archivo;
                    archivo.guardarDatosEnArchivo(ruta_autos, nuevoAuto.toString());
                    archivo.guardarDatosEnArchivo(ruta_clientes, nuevoAuto.getConductor().toString());
                    
                } else if(opcion2 == 2) {
                    printf("\nVolviendo");
                    break;  
                } else {
                    return 0;  
                }
            }
            break;
        case 1:
            printf("Registrando salida.\n");
            break;
        case 2:
            printf("Ver historial seleccionado.\n");
            break;
        case 3:
            printf("Buscar auto en el parqueadero seleccionado.\n");
            break;
        case 4:
            printf("Ver parqueadero seleccionado.\n");
            break;
        case 5:
            printf("\nHasta la vista.......\n");
            break;
        default:
            printf("Opción no valida. Intentalo de nuevo.\n");
            break;
        }

        if (opcion != 5) {
            printf("\nPresiona Enter para continuar...");
            std::cin.sync(); 
            std::cin.get();  
        }

    } while (opcion != 5);

    return 0;
}
