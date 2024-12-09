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
#include <fstream>
#include <ctime>  // Para el manejo de fechas y horas

int main() {
    int indice = 0; 
    int opcion;
    Menu menu;
    Lista_Doble_Circular<Auto> lista_auto;
    Lista_Doble_Circular<Celda> lista_celda;
    Lista_Doble_Circular<Registro> lista_registro;

    menu.addTitle("\t\t  Sistema de gestion de parqueadero ");
    menu.addOption("Registrar ingreso");
    menu.addOption("Registrar salida");
    menu.addOption("Ver historial");
    menu.addOption("Buscar auto en el parqueadero");
    menu.addOption("Ver parqueadero");
    menu.addOption("Salir");

    std::string ruta_autos = std::filesystem::current_path().string() + "/output/Autos.txt";
    std::string ruta_clientes = std::filesystem::current_path().string() + "/output/Clientes.txt";
    std::string ruta_historial = std::filesystem::current_path().string() + "/output/Historial.txt";

    // Crear un parqueadero con casillas
    Parqueadero parqueadero(10);  // 10 casillas por ejemplo

    do {
        menu.displayMenu();
        opcion = menu.getSelectedOption();

        switch (opcion) {
        case 0: {  // Registrar ingreso
            Menu menuIngreso;
            menuIngreso.addTitle("Seleccione el tipo de ingreso:");
            menuIngreso.addOption("Ya estoy registrado");
            menuIngreso.addOption("Primera vez");
            menuIngreso.addOption("Regresar");
            menuIngreso.displayMenu();

            int opcionIngreso = menuIngreso.getSelectedOption();
            switch (opcionIngreso) {
            case 0: {  // Ya estoy registrado
                std::string placa;
                std::cout << "Ingrese su placa registrada: ";
                std::cin >> placa;

                Auto autoTemporal;
                if (!autoTemporal.validarPlaca(placa)) {
                    std::cout << "Formato no valido. Debe ser AAA-#### o AAA####.\n";
                    break;
                }

                lista_auto.cargarDesdeArchivoAuto(ruta_autos);
                Nodo<Auto>* autoRegistrado = lista_auto.buscarPorPlaca(placa);

                if (autoRegistrado) {
                    std::cout << "Placa encontrada: " << placa << "\n";
                    
                    // Obtener la hora actual en formato de cadena
                    std::time_t ingreso = std::time(0);
                    std::tm* tiempoIngreso = std::localtime(&ingreso);
                    char bufferIngreso[80];
                    std::strftime(bufferIngreso, sizeof(bufferIngreso), "%Y-%m-%d %H:%M:%S", tiempoIngreso);
                    std::string fechaIngreso(bufferIngreso);

                    Registro registro(placa, 1, fechaIngreso, "");  // Usar string para la fecha
                    lista_registro.insertar(registro);

                    Archivo archivo;
                    archivo.guardarDatosEnArchivo(ruta_historial, placa + "," + fechaIngreso);
                    std::cout << "Ingreso registrado para el vehiculo con placa: " << placa << "\n";
                    
                    // Marcar la casilla ocupada en el parqueadero
                    parqueadero.marcarCasillaOcupada(indice);
                } else {
                    std::cout << "Placa no registrada. Por favor registre su auto por primera vez.\n";
                }
                break;
            }
            case 1: {  
                Registro registro1;
                Auto nuevoAuto;
                nuevoAuto = registro1.registrar_por_primera_vez();
                lista_auto.insertar(nuevoAuto);

                Archivo archivo;
                archivo.guardarDatosEnArchivo(ruta_autos, nuevoAuto.toString());
                archivo.guardarDatosEnArchivo(ruta_clientes, nuevoAuto.getConductor().toString());
                std::cout << "Auto registrado exitosamente.\n";
                break;
            }
            case 2:  // Regresar
                std::cout << "Volviendo al menu principal...\n";
                break;
            default:
                std::cout << "Opción no valida.\n";
                break;
            }
            break;
        }
        case 1: {  // Registrar salida
            std::cout << "Registrar salida seleccionado.\nIngrese la placa del vehiculo: ";
            std::string placa;
            std::cin >> placa;

            lista_registro.cargarDesdeArchivoRegistro(ruta_historial);
            Nodo<Registro>* registroNodo = lista_registro.buscarPorPlaca(placa);

            if (registroNodo) {
                if (!registroNodo->getDato().getSalida().empty()) {  // Ahora es una cadena
                    std::cout << "El vehiculo ya tiene una salida registrada.\n";
                } else {
                    // Obtener la hora de salida en formato de cadena
                    std::time_t salida = std::time(0);
                    std::tm* tiempoSalida = std::localtime(&salida);
                    char bufferSalida[80];
                    std::strftime(bufferSalida, sizeof(bufferSalida), "%Y-%m-%d %H:%M:%S", tiempoSalida);
                    std::string fechaSalida(bufferSalida);

                    registroNodo->getDato().setSalida(fechaSalida);  // Usar cadena para la fecha

                    Archivo archivo;
                    archivo.guardarDatosEnArchivo(ruta_historial, placa + ",SALIDA," + fechaSalida);
                    std::cout << "Salida registrada exitosamente.\n";
                    
                    // Marcar la casilla como libre
                    parqueadero.marcarCasillaLibre(indice);
                }
            } else {
                std::cout << "No se encontro un registro asociado a la placa ingresada.\n";
            }
            break;
        }
        case 2: {  // Ver historial
            Menu menuHistorial;
            menuHistorial.addTitle("Seleccione una opcion:");
            menuHistorial.addOption("Por rango de fechas");
            menuHistorial.addOption("Por auto");
            menuHistorial.addOption("Regresar");
            menuHistorial.displayMenu();

            int opcionHistorial = menuHistorial.getSelectedOption();
            if (opcionHistorial == 0) {
                // Historial por rango de fechas
                std::string fechaInicio, fechaFin;
                std::cout << "Ingrese fecha de inicio (YYYY-MM-DD): ";
                std::cin >> fechaInicio;
                std::cout << "Ingrese fecha de fin (YYYY-MM-DD): ";
                std::cin >> fechaFin;

                // Filtrar los registros en el rango de fechas
                lista_registro.cargarDesdeArchivoRegistro(ruta_historial);
                lista_registro.mostrarPorRangoFechas(fechaInicio, fechaFin);
            } else if (opcionHistorial == 1) {
                // Historial por auto
                std::string placa;
                std::cout << "Ingrese la placa del vehiculo: ";
                std::cin >> placa;

                lista_registro.cargarDesdeArchivoRegistro(ruta_historial);
                lista_registro.mostrarPorPlaca(placa);
            } else {
                std::cout << "Volviendo al menu principal...\n";
            }
            break;
        }
        case 3: {  // Buscar auto en el parqueadero
            std::string placa;
            std::cout << "Ingrese la placa del vehiculo: ";
            std::cin >> placa;

            lista_auto.cargarDesdeArchivoAuto(ruta_autos);
            Nodo<Auto>* autoBuscado = lista_auto.buscarPorPlaca(placa);

            if (autoBuscado) {
                std::cout << "El auto con placa " << placa << " esta en el parqueadero.\n";
            } else {
                std::cout << "El auto no esta registrado en el parqueadero.\n";
            }
            break;
        }
        case 4: {  // Ver parqueadero
            std::cout << "Estado actual del parqueadero:\n";
            parqueadero.mostrarEstado();  // Mostrar el estado del parqueadero
            break;
        }
        case 5:
            std::cout << "Saliendo del sistema...\n";
            break;
        default:
            std::cout << "Opción no valida. Intentelo de nuevo.\n";
            break;
        }

        if (opcion != 5) {
            std::cout << "\nPresiona Enter para continuar...";
            std::cin.ignore();
            std::cin.get();
        }
    } while (opcion != 5);

    return 0;
}
