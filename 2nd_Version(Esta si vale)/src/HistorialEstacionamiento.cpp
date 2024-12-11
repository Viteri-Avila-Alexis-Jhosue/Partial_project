/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Proyecto 1, Parcial 1                               *
 * Autor:                          Camila Amores, Alexander Benavidez, Alexis Viteri   *
 * Fecha de creacion:              06/12/2024                                          *
 * Fecha de modificacion:          11/12/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 ***************************************************************************************/
#include "../include/HistorialEstacionamiento.h"

// Constructor: carga el historial desde el archivo
HistorialEstacionamiento::HistorialEstacionamiento() {
    cargarDesdeArchivo();
}

// Obtener la fecha y hora actual como string
string HistorialEstacionamiento::obtenerFechaHoraActual() const {
    time_t now = time(nullptr);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&now));
    return string(buffer);
}

// Cargar historial desde el archivo
void HistorialEstacionamiento::cargarDesdeArchivo() {
    ifstream archivoEntrada(archivoHistorial);
    if (!archivoEntrada.is_open()) {
        cerr << "No se pudo abrir el archivo " << archivoHistorial << ". Creando uno nuevo." << endl;
        return;
    }

    string linea;
    while (getline(archivoEntrada, linea)) {
        stringstream ss(linea);
        string placa, espacioId, fechaHoraIngreso, fechaHoraSalida;

        getline(ss, placa, ',');
        getline(ss, espacioId, ',');
        getline(ss, fechaHoraIngreso, ',');
        getline(ss, fechaHoraSalida, ',');

        historial.emplace_back(placa, espacioId, fechaHoraIngreso, fechaHoraSalida);
    }
    archivoEntrada.close();
}

// Guardar historial en el archivo
void HistorialEstacionamiento::guardarEnArchivo() {
    ofstream archivoSalida(archivoHistorial, ios::trunc);
    if (!archivoSalida.is_open()) {
        cerr << "Error al abrir el archivo " << archivoHistorial << " para guardar." << endl;
        return;
    }

    for (const auto& registro : historial) {
        archivoSalida << registro.placa << ","
                      << registro.espacioId << ","
                      << registro.fechaHoraIngreso << ","
                      << registro.fechaHoraSalida << "\n";
    }
    archivoSalida.close();
}

// Registrar la entrada de un auto
void HistorialEstacionamiento::registrarEntrada(const string& placa, const string& espacioId) {
    string fechaHora = obtenerFechaHoraActual();
    historial.emplace_back(placa, espacioId, fechaHora);
    guardarEnArchivo();
    cout << "Acceso registrado: Placa " << placa << ", Lugar " << espacioId 
         << ", Fecha/Hora: " << fechaHora << endl;
}

// Registrar la salida de un auto
void HistorialEstacionamiento::registrarSalida(const string& placa) {
    for (auto& registro : historial) {
        if (registro.placa == placa && registro.fechaHoraSalida.empty()) {
            registro.fechaHoraSalida = obtenerFechaHoraActual();
            guardarEnArchivo();
            cout << "Salida registrada: Placa " << placa 
                 << ", Fecha/Hora Salida: " << registro.fechaHoraSalida << endl;
            return;
        }
    }
    cout << "No se hallo una entrada activa para la placa " << placa << "." << endl;
}

// Mostrar todo el historial
void HistorialEstacionamiento::mostrarHistorial() const {
    if (historial.empty()) {
        cout << "No tenemos la existencia de un registro con ese historial." << endl;
        return;
    }

    cout << "Historial del Estacionamiento:\n";
    for (const auto& registro : historial) {
        cout << "Placa: " << registro.placa 
             << ", Espacio: " << registro.espacioId 
             << ", Datos de Ingreso: " << registro.fechaHoraIngreso 
             << ", Datos de Salida: " << (registro.fechaHoraSalida.empty() ? "El vehiculo aun se encuentra en nuestro parqueadero" : registro.fechaHoraSalida)
             << endl;
    }
}

void HistorialEstacionamiento::mostrarHistorialPorFecha(const string& fecha) const {
    bool encontrado = false;
    cout << "Historial de estacionamiento para la fecha: " << fecha << "\n";
    cout << "------------------------------------------------------\n";

    for (const auto& registro : historial) {
        if (registro.fechaHoraIngreso.substr(0, 10) == fecha) { // Compara la parte de la fecha (YYYY-MM-DD)
            cout << "Placa: " << registro.placa 
                 << ", Espacio: " << registro.espacioId 
                 << ", Ingreso: " << registro.fechaHoraIngreso 
                 << ", Salida: " << (registro.fechaHoraSalida.empty() ? "Aún en el parqueadero" : registro.fechaHoraSalida) 
                 << "\n";
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontro ningun registro con dicha fecha: " << fecha << ".\n";
    }
}
void HistorialEstacionamiento::mostrarHistorialPorFechaYPlaca(const string& fecha, const string& placa) const {
    bool encontrado = false;
    cout << "Historial de estacionamiento segun la placa: " << placa 
         << " y fecha: " << fecha << "\n";
    cout << "------------------------------------------------------\n";

    for (const auto& registro : historial) {
        if (registro.placa == placa && registro.fechaHoraIngreso.substr(0, 10) == fecha) {
            cout << "Placa: " << registro.placa 
                 << ", Espacio: " << registro.espacioId 
                 << ", Ingreso: " << registro.fechaHoraIngreso 
                 << ", Salida: " << (registro.fechaHoraSalida.empty() ? "Aún se encuentra en nuestro parqueadero" : registro.fechaHoraSalida) 
                 << "\n";
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron registros con esa placa: " << placa 
             << " en la fecha: " << fecha << ".\n";
    }
}

// Buscar historial por placa
string HistorialEstacionamiento::buscarHistorial(const string& placa) const {
    string resultado;
    cout << "Buscando historial para la placa: " << placa << endl;
    for (const auto& registro : historial) {
        if (registro.placa == placa) {
            resultado += "Placa: " + registro.placa 
                       + ", Espacio: " + registro.espacioId 
                       + ", Ingreso: " + registro.fechaHoraIngreso 
                       + ", Salida: " + (registro.fechaHoraSalida.empty() ? "Aun en el parqueadero" : registro.fechaHoraSalida) 
                       + "\n";
        }
    }
    return resultado.empty() ? "No se encontró ningun historial con esa placa " + placa : resultado;
}