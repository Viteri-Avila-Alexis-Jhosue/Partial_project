#include "../include/Registro.h"
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <string>
#include <fstream>
#include <direct.h>
#include <sstream>
#include <iomanip> 
#include "../include/Validation.h"
#include "../include/Nodo.h"
#include "../include/Lista_Doble_Circular.h"
using namespace std;

Registro::Registro(std::string placa, int celda, std::string ingreso, std::string salida)
    : placa(placa), celda(celda), ingreso(ingreso.empty() ? "00:00:00" : ingreso), salida(salida.empty() ? "00:00:00" : salida) {
    // Validación de placa
    if (placa.empty()) {
        throw std::invalid_argument("La placa no puede estar vacía.");
    }

    // Validación de celda
    if (celda < 0) {
        throw std::invalid_argument("El número de celda debe ser un valor positivo.");
    }

    // Validación de tiempos
    if (ingreso.empty()) {
        throw std::invalid_argument("El tiempo de ingreso no puede estar vacío.");
    }
    if (!salida.empty() && salida < ingreso) { // Si la salida es no vacío, no puede ser anterior al ingreso
        throw std::invalid_argument("El tiempo de salida no puede ser anterior al de ingreso.");
    }
}

Registro::Registro()
    : placa("UNKNOWN"), celda(-1), ingreso("00:00:00"), salida("00:00:00") {
    // En este caso, la placa predeterminada es "UNKNOWN" y las fechas son "00:00:00".
}


// Getters y Setters
string Registro::getPlaca() const { return placa; }
void Registro::setPlaca(std::string placa) {
    if (placa.empty()) {
        throw std::logic_error("La placa no puede estar vacía");
    }
    this->placa = placa;
}

int Registro::getCelda() const { return celda; }
void Registro::setCelda(int celda) { this->celda = celda; }

string Registro::getIngreso() const { return ingreso; }
void Registro::setIngreso(std::string ingreso) { this->ingreso = ingreso; }

string Registro::getSalida() const { return salida; }
void Registro::setSalida(std::string salida) { this->salida = salida; }

Auto Registro::registrar_por_primera_vez() {
    Auto auto1;
    Validation validation1;
    string placa, tipo, color, nombre, correo, direccion, fecha_nacimiento, telefono, cedula;
    int edad, dian, mesn, anion;
    Persona persona1;
    Lista_Doble_Circular<Auto> lista_auto;  // Lista para cargar autos registrados

    // Obtener la ruta del archivo sin usar std::filesystem
    char buffer[FILENAME_MAX];
    string ruta_autos;
    if (_getcwd(buffer, FILENAME_MAX)) { // Obtiene el directorio actual
        ruta_autos = string(buffer) + "\\output\\Autos.txt"; // Ruta para Windows
    } else {
        ruta_autos = "output/Autos.txt"; // Ruta por defecto en caso de error
    }

    lista_auto.cargarDesdeArchivoAuto(ruta_autos);

    do {
        cout << "Ingrese una placa: ";
        cin >> placa;
        if (!auto1.validarPlaca(placa)) {
            cout << "!!!!!!ERROR!!!!!! PLACA INCORRECTA!!!!!!!!" << endl;
        } else {
            // Verificar si la placa ya está registrada
            Nodo<Auto>* autoExistente = lista_auto.buscarPorPlaca(placa);
            if (autoExistente) {
                cout << "!!!!!!ERROR!!!!!! LA PLACA YA ESTA REGISTRADA!!!!!!!!" << endl;
                continue;  // Solicitar nuevamente la placa
            } else {
                break;  // Placa válida y no registrada
            }
        }
    } while (true);

    cout << "Ingrese el tipo de vehiculo: ";
    cin >> tipo;
    color = validation1.ingresarStringConEspacios("Ingrese el color de vehiculo: ");
    
    cout << "\n\t\tDatos del propietario:\t";
    nombre = validation1.ingresarStringConEspacios("\nNombre y Apellido: ");
    
        cedula = validation1.ingresarInt("\nCedula: ");
    do {
        cout << "\nCorreo electronico: ";
        cin >> correo;
        try {
            validation1.validateEmail(correo);  // Llama a la función de validación de correo
            break;
        } catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    } while (true);

    do {
        cout << "Numero de telefono: ";
        cin >> telefono;
        try {
            validation1.validateCellPhone(telefono);  // Validación del formato de teléfono
            break;
        } catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    } while (true);

    cout << "Direccion: ";
    cin >> direccion;
    
    cout << "Ingrese la fecha de nacimiento: ";
    time_t t = time(0);
    struct tm *now = localtime(&t);
    int anioActual = (now->tm_year + 1900);

    do {
        anion = validation1.ingresarInt("\nAnio: ");
        if (anion < anioActual - 200 || anion > anioActual) {
            cout << "Anio invalido." << endl;
        } else {
            break;
        }
    } while (true);

    do {
        mesn = validation1.ingresarInt("\nMes: ");
        if (mesn < 1 || mesn > 12) {
            cout << "Mes invalido." << endl;
        } else {
            break;
        }
    } while (true);

    do {
        dian = validation1.ingresarInt("\nDia: ");
        bool esBisiesto = (anion % 4 == 0 && anion % 100 != 0) || (anion % 400 == 0);
        int maxDias = (mesn == 2) ? (esBisiesto ? 29 : 28) :
                      ((mesn == 4 || mesn == 6 || mesn == 9 || mesn == 11) ? 30 : 31);
        
        if (dian < 1 || dian > maxDias) {
            cout << "Dia invalido" << endl;
        } else {
            break;
        }
    } while (true);

    fecha_nacimiento = to_string(anion) + "-" + to_string(mesn) + "-" + to_string(dian);
    edad = persona1.calcularEdad(fecha_nacimiento);
    persona1 = Persona(nombre, cedula, correo, direccion, telefono, fecha_nacimiento);
    Auto auto2(placa, persona1, tipo, color);
    
    cout << "\nAuto registrado correctamente." << endl;
    return auto2;
}

void Registro::registrar_ingreso(Auto auto1) {
    // Obtener la fecha y hora de ingreso
    time_t now = time(0);
    struct tm* now_tm = localtime(&now);
    char buffer[100];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", now_tm);
    this->ingreso = std::string(buffer);

    // Guardar la información en un archivo Historial.txt
    std::ofstream archivo("output/Historial.txt", std::ios::app);
    if (archivo.is_open()) {
        archivo << toString() << "\n\n";  // Llamamos a toString para obtener el formato adecuado
        archivo.close();
    } else {
        cout << "Error al abrir el archivo de historial." << endl;
    }
}

void Registro::registrar_salida(Auto auto1) {
    // Obtener la fecha y hora de salida
    time_t now = time(0);
    struct tm* now_tm = localtime(&now);
    char buffer[100];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", now_tm);
    this->salida = std::string(buffer);

    // Actualizar el historial con la salida
    std::ofstream archivo("output/Historial.txt", std::ios::app);
    if (archivo.is_open()) {
        archivo << toString() << "\n\n";  // Llamamos a toString para obtener el formato adecuado
        archivo.close();
    } else {
        cout << "Error al abrir el archivo de historial." << endl;
    }
}

string Registro::toString() const {
    // Mostrar las fechas de ingreso y salida (ya son cadenas)
    std::ostringstream os;
    os << "Placa: " << placa << "\n"
       << "Celda: " << celda << "\n"
       << "Ingreso: " << ingreso << "\n"
       << "Salida: " << (salida.empty() ? "No ha salido" : salida);

    return os.str();
}
