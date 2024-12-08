#include "../include/Registro.h"
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <string>
#include <fstream>
#include <sstream>
#include "../include/Validation.h"
#include "../include/Nodo.h"
#include "../include/Lista_Doble_Circular.h"
using namespace std;
// Constructor
Registro::Registro(std::string placa, int celda, std::string tipo, Persona propietario, std::time_t ingreso)
    : placa(placa), celda(celda), tipo(tipo), propietario(propietario), ingreso(ingreso), salida(0) {}
Registro::Registro()
    : placa(""), celda(-1), tipo(""), propietario(Persona()), ingreso(0), salida(0) {
    // Inicialización con valores por defecto
}
// Getters y Setters
std::string Registro::getPlaca() const { return placa; }
void Registro::setPlaca(std::string placa) { this->placa = placa; }

int Registro::getCelda() const { return celda; }
void Registro::setCelda(int celda) { this->celda = celda; }

std::string Registro::getTipo() const { return tipo; }
void Registro::setTipo(std::string tipo) { this->tipo = tipo; }

Persona Registro::getPropietario() const { return propietario; }
void Registro::setPropietario(Persona propietario) { this->propietario = propietario; }

std::time_t Registro::getIngreso() const { return ingreso; }
void Registro::setIngreso(std::time_t ingreso) { this->ingreso = ingreso; }

std::time_t Registro::getSalida() const { return salida; }
void Registro::setSalida(std::time_t salida) { this->salida = salida; }

Auto Registro::registrar_por_primera_vez(){
    Auto auto1;
    Validation validation1;
    string placa, tipo, color,nombre,correo,direccion,fecha_nacimiento, telefono;
    int cedula, edad,dian,mesn,anion;
    Persona persona1;
    do{
    printf("Ingrese una placa:\t");
    cin>>placa;
    if(!auto1.validarPlaca(placa)){
        printf("!!!!!!ERROR!!!!!! PLACA INCORRECA!!!!!!!!\n");
    }
    }while(!auto1.validarPlaca(placa));
    printf("Ingrese el tipo de vehiculo:\t");
    cin>>tipo;
    color=validation1.ingresarStringConEspacios("Ingrese el color de vehiculo:\t");
    printf("\n\t\tDatos del propietario:\t");
    nombre=validation1.ingresarStringConEspacios("\nNombre y Apellido:\t");
    do {
        cedula=validation1.ingresarInt("\nCedula:\t");
        try {
            validation1.validateId(cedula);  // Llama a la función de validación
            break;  // Si la cédula es válida, rompe el ciclo
        } catch (const invalid_argument& e) {
            cout << e.what() << endl;  // Imprime el mensaje de error si la cédula no es válida
        }
    } while (true);
    do {
        printf("\nCorreo electronico:\t");
        cin >> correo;
        fflush(stdin);
        try {
            validation1.validateEmail(correo);  // Llama a la función de validación de correo
            break;  // Si el correo es válido, rompe el ciclo
        } catch (const invalid_argument& e) {
            cout << e.what() << endl;  // Imprime el mensaje de error si el correo no es válido
        }
    } while (true);
    do {
    printf("Numero de telefono\t");
    cin >> telefono;  // Captura el número ingresado
    fflush(stdin);
    try {
        validation1.validateCellPhone(telefono);  // Validación del formato de teléfono
        break;  // Si el teléfono es válido, salimos del ciclo
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;  // Imprime el mensaje de error si el teléfono no es válido
    }
} while (true);


    printf("Direccion:\t");
    cin>>direccion;
    fflush(stdin);
    printf("Ingrese la fecha de nacimiento:");
    time_t t = time(0);
    struct tm *now = localtime(&t);
    int anioActual = (now->tm_year + 1900);
    do {
        anion = validation1.ingresarInt("\nAnio:\t");
        if (anion < anioActual - 200 || anion > anioActual) {
            cout << "Anio invalido.";
        } else {
            break;
        }
    } while (true);

    // Validar mes
    do {
        mesn = validation1.ingresarInt("\nMes:\t");
        if (mesn < 1 || mesn > 12) {
            cout << "Mes invalido.";
        } else {
            break;
        }
    } while (true);

    // Validar día
    do {
        dian = validation1.ingresarInt("\nDia:\t");
        bool esBisiesto = (anion % 4 == 0 && anion % 100 != 0) || (anion % 400 == 0);
        int maxDias;

        if (mesn == 2) {
            maxDias = esBisiesto ? 29 : 28;
        } else if (mesn == 4 || mesn == 6 || mesn == 9 || mesn == 11) {
            maxDias = 30;
        } else {
            maxDias = 31;
        }

        if (dian < 1 || dian > maxDias) {
            cout << "Dia invalido";
        } else {
            break;
        }
    } while (true);
    fecha_nacimiento = to_string(anion) + "-" + to_string(mesn) + "-" + to_string(dian);
    edad = persona1.calcularEdad(fecha_nacimiento);
    persona1 = Persona(nombre, cedula, correo, direccion, telefono, fecha_nacimiento);
    Auto auto2(placa,persona1,tipo,color);
    printf("\nAuto registrado correctamente");
    return auto2;

}
void Registro::registrar_ingreso(Auto auto1) {
    // Obtener la fecha y hora de ingreso
    std::time_t now = std::time(0);
    this->ingreso = now;

    // Guardar la información en un archivo Historial.txt
    std::ofstream archivo("/output/Historial.txt", std::ios::app);
    if (archivo.is_open()) {
        archivo << toString() << "\n\n";  // Llamamos a toString para obtener el formato adecuado
        archivo.close();
    } else {
        cout << "Error al abrir el archivo de historial." << endl;
    }
}
void Registro::registrar_salida(Auto auto1) {
    printf("Hola");
}


std::string Registro::toString() const {
    // Convertir las fechas a formato legible
    char bufferIngreso[100];
    char bufferSalida[100];
    strftime(bufferIngreso, sizeof(bufferIngreso), "%Y-%m-%d %H:%M:%S", localtime(&ingreso));
    strftime(bufferSalida, sizeof(bufferSalida), "%Y-%m-%d %H:%M:%S", localtime(&salida));

    std::ostringstream os;
    os << "Placa: " << placa << "\n"
       << "Celda: " << celda << "\n"
       << "Tipo: " << tipo << "\n"
       << "Propietario: " << propietario.toString() << "\n"  // Asumiendo que `Persona` tiene `toString()`
       << "Ingreso: " << bufferIngreso << "\n"
       << "Salida: " << (salida == 0 ? "No ha salido" : bufferSalida);
    
    return os.str();
}