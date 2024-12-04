#include "Lista.h"
#include <iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

Lista::Lista(bool circular, const std::string& nombreArchivo)
    : cabeza(nullptr), cola(nullptr), esCircular(circular), nombreArchivo(nombreArchivo) {
    cargarDesdeArchivo(nombreArchivo);
}


Lista::~Lista() {
    if (!esCircular) {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            Nodo* temp = actual;
            actual = actual->siguiente;
            delete temp;
        }
    }
    else {
        Nodo* actual = cabeza;
        if (actual) {
            do {
                Nodo* temp = actual;
                actual = actual->siguiente;
                delete temp;
            } while (actual != cabeza);
        }
    }
}


bool Lista::verificarCedula(const std::string& cedula) {
    return cedulasRegistradas.find(cedula) != cedulasRegistradas.end();
}

void Lista::insertar(Persona dato) {
    if (verificarCedula(dato.cedula)) {
        std::cout << "La cedula ya esta registrada" << std::endl;
        return;
    }

    dato.setCorreo(generarCorreo(cabeza, dato, esCircular));
    generarContrasena(dato);
    Nodo* nuevo = new Nodo(dato);
    if (!cabeza) {
        cabeza = nuevo;
        cola = nuevo;
        if (esCircular) {
            cabeza->siguiente = cabeza;
            cabeza->anterior = cabeza;
        }
    }
    else {
        if (esCircular) {
            nuevo->siguiente = cabeza;
            nuevo->anterior = cola;
            cola->siguiente = nuevo;
            cabeza->anterior = nuevo;
            cola = nuevo;
        }
        else {
            cola->siguiente = nuevo;
            nuevo->anterior = cola;
            cola = nuevo;
        }
    }

    cedulasRegistradas.insert(dato.cedula);

    // Agregar al archivo después de insertar
    agregarAlArchivo(dato);
}

void Lista::insertarEn(int indice, Persona dato) {
    if (indice < 1) return;
    Nodo* nuevo = new Nodo(dato);

    if (indice == 1) {
        nuevo->siguiente = cabeza;
        if (cabeza != nullptr) {
            cabeza->anterior = nuevo;
        }
        cabeza = nuevo;
        if (cola == nullptr) {
            cola = nuevo;
        }
        return;
    }

    Nodo* actual = cabeza;
    for (int i = 1; i < indice - 1 && actual != nullptr; i++) {
        actual = actual->siguiente;
    }
    if (actual == nullptr) return;

    nuevo->siguiente = actual->siguiente;
    if (actual->siguiente != nullptr) {
        actual->siguiente->anterior = nuevo;
    }
    actual->siguiente = nuevo;
    nuevo->anterior = actual;

    if (nuevo->siguiente == nullptr) {
        cola = nuevo;
    }
}

void Lista::ordenarRadix(int criterio) {
    if (criterio >= 1 && criterio <= 3) {
        radixSortPersonas(cabeza, cola, esCircular, criterio);
        guardarEnArchivo(nombreArchivo); // Guardar en el archivo original
    }
    else if (criterio == 4) {
        ordenarCaracteres();
    }
}

int getMaxLength(const std::string& name) {
    return name.length();
}




void Lista::ordenar(int criterio) {
    if (criterio >= 1 && criterio <= 3) {
        shellSortPersonas(cabeza, cola, esCircular, criterio);
        guardarEnArchivo(nombreArchivo); // Guardar en el archivo original
    }
    else if (criterio == 4) {
        ordenarCaracteres();
    }
}

void Lista::ordenarCaracteres() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        shellSort(actual->dato.nombre);
        shellSort(actual->dato.apellido);
        actual = actual->siguiente;
        if (esCircular && actual == cabeza) break;
    }

    std::string contenidoOrdenado = obtenerContenidoOrdenado();
    crearBackup(nombreArchivo, contenidoOrdenado); // Crear un backup con los datos ordenados
}

void Lista::ordenarBurbuja(int criterio) {
    if (criterio >= 1 && criterio <= 3) {
        bubbleSortPersonas(cabeza, cola, esCircular, criterio);
        guardarEnArchivo(nombreArchivo); // Guardar en el archivo original
    }
    else if (criterio == 4) {
        ordenarCaracteres();
    }
}

void Lista::ordenarInverso(int criterio) {
    if (criterio >= 1 && criterio <= 3) {
        inversoString(cabeza, cola, esCircular, criterio);
        guardarEnArchivo(nombreArchivo); // Guardar en el archivo original
    }
    else if (criterio == 4) {
        ordenarCaracteres();
    }
}

void Lista::ordenarQuicksort(int criterio) {
    if (criterio >= 1 && criterio <= 3) {
        quickSortPersonas(cabeza, cola, esCircular, criterio);
        guardarEnArchivo(nombreArchivo); // Guardar en el archivo original
    }
    else if (criterio == 4) {
        ordenarCaracteresQuicksort();
    }
}

void Lista::ordenarCaracteresQuicksort() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        quickSort(actual->dato.nombre);
        quickSort(actual->dato.apellido);
        actual = actual->siguiente;
        if (esCircular && actual == cabeza) break;
    }

    std::string contenidoOrdenado = obtenerContenidoOrdenado();
    crearBackup(nombreArchivo, contenidoOrdenado); // Crear un backup con los datos ordenados
}

void Lista::InertirPersonas(int criterio) {
    if (criterio >= 1 && criterio <= 3) {
        inversoString(cabeza, cola, esCircular, criterio);
        //guardarEnArchivo(nombreArchivo); // Guardar en el archivo original
    }
    std::string contenidoOrdenado = obtenerContenidoOrdenado();
    crearBackup(nombreArchivo, contenidoOrdenado);
}

void Lista::ordenarIntercambio(int criterio) {
    if (criterio >= 1 && criterio <= 3) {
        intercambioPersonas(cabeza, cola, esCircular, criterio);
        guardarEnArchivo(nombreArchivo); // Guardar en el archivo original
    }
    else if (criterio == 4) {
        ordenarCaracteresIntercambio();
    }
}

void Lista::ordenarCaracteresIntercambio() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        intercambio(actual->dato.nombre);
        intercambio(actual->dato.apellido);
        actual = actual->siguiente;
        if (esCircular && actual == cabeza) break;
    }

    std::string contenidoOrdenado = obtenerContenidoOrdenado();
    crearBackup(nombreArchivo, contenidoOrdenado); // Crear un backup con los datos ordenados
}

std::string Lista::obtenerContenidoOrdenado() const {
    std::stringstream ss;
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        ss << "Nombre: " << actual->dato.nombre << " " << actual->dato.segundoNombre
            << ", Apellido: " << actual->dato.apellido
            << ", Cedula: " << actual->dato.cedula << std::endl;

        ss << "Correo: " << actual->dato.getCorreo() << "@espe.edu.ec"
            << ", Contrasenia inicial: " << actual->dato.getContrasenaInicial()
            << ", Contrasenia: " << actual->dato.getContrasena() << std::endl;

        actual = actual->siguiente;
        if (esCircular && actual == cabeza) break;
    }
    return ss.str();
}


void Lista::imprimir() const {
    Nodo* actual = cabeza;
    do {
        std::cout << "Nombre: " << actual->dato.nombre << " " << actual->dato.segundoNombre
            << ", Apellido: " << actual->dato.apellido
            << ", Cedula: " << actual->dato.cedula << std::endl;

        std::cout << "Correo: " << actual->dato.getCorreo() << "@espe.edu.ec"
            << ", Contrasenia inicial: " << actual->dato.getContrasenaInicial()
            << ", Contrasenia: " << actual->dato.getContrasena() << std::endl;

        actual = actual->siguiente;
        if (esCircular && actual == cabeza) break;
    } while (actual != nullptr);
}

void Lista::guardarEnArchivo(const std::string& nombreArchivo) const {
    std::ofstream archivo(nombreArchivo);

    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo " << nombreArchivo << std::endl;
        return;
    }

    Nodo* actual = cabeza;
    while (actual != nullptr) {
        archivo << "Nombre: " << actual->dato.nombre << " " << actual->dato.segundoNombre
            << ", Apellido: " << actual->dato.apellido
            << ", Cedula: " << actual->dato.cedula << std::endl;

        archivo << "Correo: " << actual->dato.getCorreo() << "@espe.edu.ec"
            << ", Contrasenia inicial: " << actual->dato.getContrasenaInicial()
            << ", Contrasenia: " << actual->dato.getContrasena() << std::endl;

        actual = actual->siguiente;
        if (esCircular && actual == cabeza) break;
    }
}

void Lista::cargarDesdeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);

    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo " << nombreArchivo << std::endl;
        return;
    }

    std::string nombre, segundoNombre, apellido, cedula, correo, contrasenaInicial, contrasena;
    std::string dummy;
    while (archivo >> dummy >> nombre >> segundoNombre >> dummy >> apellido >> dummy >> cedula) {
        archivo >> dummy >> correo >> dummy >> dummy >> contrasenaInicial >> dummy >> contrasena;
        correo = correo.substr(0, correo.find('@'));
        Persona persona(nombre, segundoNombre == "null" ? "" : segundoNombre, apellido, cedula, correo);
        persona.setCorreo(correo);
        persona.setContrasena(contrasena);
        persona.setContrasenaInicial(contrasenaInicial);
        insertarDesdeArchivo(persona);
    }
}

void Lista::insertarDesdeArchivo(Persona dato) {
    Nodo* nuevo = new Nodo(dato);
    if (!cabeza) {
        cabeza = nuevo;
        cola = nuevo;
        if (esCircular) {
            cabeza->siguiente = cabeza;
            cabeza->anterior = cabeza;
        }
    }
    else {
        if (esCircular) {
            nuevo->siguiente = cabeza;
            nuevo->anterior = cola;
            cola->siguiente = nuevo;
            cabeza->anterior = nuevo;
            cola = nuevo;
        }
        else {
            cola->siguiente = nuevo;
            nuevo->anterior = cola;
            cola = nuevo;
        }
    }

    cedulasRegistradas.insert(dato.cedula);
}

void Lista::crearBackup(const std::string& nombreArchivo, const std::string& contenido) {
    std::string backupNombreArchivo = nombreArchivo + ".backup";
    std::ofstream backupArchivo(backupNombreArchivo);
    if (!backupArchivo) {
        std::cerr << "No se pudo crear el archivo de backup " << backupNombreArchivo << std::endl;
        return;
    }
    backupArchivo << contenido;
}

void Lista::agregarAlArchivo(const Persona& dato) const {
    std::ofstream archivo(nombreArchivo, std::ios::app);

    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo " << nombreArchivo << std::endl;
        return;
    }

    archivo << "Nombre: " << dato.nombre << " " << dato.segundoNombre
        << ", Apellido: " << dato.apellido
        << ", Cedula: " << dato.cedula << std::endl;

    archivo << "Correo: " << dato.getCorreo() << "@espe.edu.ec"
        << ", Contrasenia inicial: " << dato.getContrasenaInicial()
        << ", Contrasenia: " << dato.getContrasena() << std::endl;
}


int Lista::cantidad() {
    if (cabeza == nullptr) {
        return 0;
    }
    else {
        int cant = 0;
        Nodo* aux = cabeza;

        do {
            cant++;
            aux = aux->siguiente;
        } while (aux != nullptr);

        return cant;
    }
}

Persona Lista::datoEn(int posicion) {
    if (cantidad() == 0 || posicion > cantidad()) {
        std::cout << "No hay ningun nodo" << std::endl;
    }

    Nodo* aux = cabeza;

    for (int i = 1; i < posicion; i++) aux = aux->siguiente;

    return aux->dato;
}

Persona* Lista::nodoEn(int posicion) {
    if (cantidad() == 0 || posicion > cantidad()) {
        std::cout << "No hay ningun nodo" << std::endl;
        return nullptr;
    }
    Nodo* aux = cabeza;

    for (int i = 1; i < posicion; i++) aux = aux->siguiente;

    return &(aux->dato);
}

void Lista::eliminar(int posicion) {
    if (cantidad() >= posicion && posicion > 0) {
        Nodo* aux = cabeza;
        Nodo* anterior = cabeza;

        for (int i = 1; i < posicion - 1; i++) anterior = anterior->siguiente;
        if (posicion != 1) aux = anterior->siguiente;
        if (aux != cabeza) anterior->siguiente = aux->siguiente;
        if (aux == cabeza) cabeza = aux->siguiente;
    }
}

void Lista::recorrer(std::function<void(Persona)> callback) {
    Nodo* temp = cabeza;
    while (temp) {
        callback(temp->dato);
        temp = temp->siguiente;
    }
}

void Lista::insertarOrdenado(Persona valor, int criterio) {
    Nodo* nuevo = new Nodo(valor);
    if (!cabeza) {
        cabeza = nuevo;
        cola = nuevo;
        return;
    }
    Nodo* actual = cabeza;
    while (actual) {
        bool debeInsertar = false;
        switch (criterio) {
        case 1:
            debeInsertar = valor.cedula < actual->dato.cedula;
            break;
        case 2:
            debeInsertar = valor.nombre < actual->dato.nombre;
            break;
        case 3:
            debeInsertar = valor.apellido < actual->dato.apellido;
            break;
        }
        if (debeInsertar) {
            if (actual == cabeza) {
                nuevo->siguiente = cabeza;
                cabeza->anterior = nuevo;
                cabeza = nuevo;
            }
            else {
                nuevo->siguiente = actual;
                nuevo->anterior = actual->anterior;
                actual->anterior->siguiente = nuevo;
                actual->anterior = nuevo;
            }
            return;
        }
        if (!actual->siguiente) {
            actual->siguiente = nuevo;
            nuevo->anterior = actual;
            cola = nuevo;
            return;
        }
        actual = actual->siguiente;
    }
}

Persona Lista::eliminarPrimero() {
    Nodo* temp = cabeza;
    cabeza = cabeza->siguiente;
    if (cabeza) {
        cabeza->anterior = nullptr;
    }

    Persona dato = temp->dato;
    delete temp;
    return dato;
}

void Lista::insertarUltimo(Persona persona) {
    Nodo* nuevo = new Nodo(persona);
    if (cabeza == nullptr) {
        cabeza = nuevo;
    }
    else {
        Nodo* aux = cabeza;
        while (aux->siguiente) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
        nuevo->anterior = aux;
    }
}

void Lista::ordenarDistribucion(int criterio) {
    if (criterio >= 1 && criterio <= 3) {
        BucketSort(cabeza, cola, esCircular, criterio);
        guardarEnArchivo(nombreArchivo); // Guardar en el archivo original
    }
    else if (criterio == 4) {
        ordenarCaracteres();
    }
}

Nodo* Lista::getCabeza() {
    return cabeza;
}

Nodo* Lista::getCola() {
    return cola;
}

void Lista::setCabeza(Nodo* newCabeza) {
    cabeza = newCabeza;
}

void Lista::setCola(Nodo* newCola) {
    cola = newCola;
}

void Lista::contarVocalesYConsonantes(int& vocales, int& consonantes) {
    ::contarVocalesYConsonantes(cabeza, vocales, consonantes);
}

void Lista::contarVocalesYConsonantes(const std::string& texto, int index, int& vocales, int& consonantes) const {
    if (index == texto.length()) {//Esto es hasta que el indice sea igual al tamaño del string
        return;
    }

    char caracter = std::tolower(texto[index]);
    if (std::isalpha(caracter)) {
        if (caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u') {
            ++vocales;
        }
        else {
            ++consonantes;
        }
    }
    contarVocalesYConsonantes(texto, index + 1, vocales, consonantes);
}

void Lista::MezclaPares() {
    Nodo* actual = cabeza;
    while (actual != nullptr && actual->siguiente != nullptr) {
        std::string nombre1 = actual->dato.nombre;
        std::string nombre2 = actual->siguiente->dato.nombre;
        std::string resultado;

        auto it1 = nombre1.begin();
        auto it2 = nombre2.begin();

        // Intercalar caracteres usando iteradores
        while (it1 != nombre1.end() && it2 != nombre2.end()) {
            resultado += *it1++;
            resultado += *it2++;
        }

        // Agregar los caracteres restantes de nombre1, si los hay
        while (it1 != nombre1.end()) {
            resultado += *it1++;
        }

        // Agregar los caracteres restantes de nombre2, si los hay
        while (it2 != nombre2.end()) {
            resultado += *it2++;
        }

        // Imprimir el resultado
        std::cout << "Par: " << nombre1 << "-" << nombre2 << " -> " << resultado << std::endl;

        // Avanzar al siguiente par de nodos
        actual = actual->siguiente->siguiente;
        if (esCircular && actual == cabeza) break;
    }
}

Nodo* Lista::combinarListas(Nodo* cabeza1, Nodo* cabeza2, int criterio) {
    if (cabeza1 == nullptr) {
        return cabeza2;
    }
    if (cabeza2 == nullptr) {
        return cabeza1;
    }

    string dato1, dato2;

    switch (criterio) {
    case 1:
        dato1 = cabeza1->dato.cedula;
        dato2 = cabeza2->dato.cedula;
        break;
    case 2:
        dato1 = cabeza1->dato.nombre;
        dato2 = cabeza2->dato.nombre;
        break;
    case 3:
        dato1 = cabeza1->dato.apellido;
        dato2 = cabeza2->dato.apellido;
        break;
    }

    if (dato1 < dato2) {
        cabeza1->siguiente = combinarListas(cabeza1->siguiente, cabeza2, criterio);
        return cabeza1;
    }
    else {
        cabeza2->siguiente = combinarListas(cabeza1, cabeza2->siguiente, criterio);
        return cabeza2;
    }
}

vector<Persona> Lista::leerArchivo() {
    ifstream archivo(nombreArchivo);
    vector<Persona> personas;
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo " << nombreArchivo << std::endl;
        return personas;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::istringstream ss(linea);
        std::string dummy, nombre, segundoNombre, apellido, cedula, correo, contrasenaInicial, contrasena;

        // Leer la línea con los nombres y apellidos
        ss >> dummy >> nombre >> segundoNombre >> dummy >> apellido >> dummy >> cedula;

        // Leer la línea con el correo y contraseñas
        std::getline(archivo, linea);
        std::istringstream ss2(linea);
        ss2 >> dummy >> correo >> dummy >> dummy >> contrasenaInicial >> dummy >> contrasena;

        correo = correo.substr(0, correo.find('@')); // Eliminar el dominio del correo

        Persona persona(nombre, segundoNombre == "null" ? "" : segundoNombre, apellido, cedula, correo);
        persona.setCorreo(correo);
        persona.setContrasena(contrasena);
        persona.setContrasenaInicial(contrasenaInicial);

        personas.push_back(persona);
    }

    return personas;
}