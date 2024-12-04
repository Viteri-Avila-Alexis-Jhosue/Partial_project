#include <vector>
#include <iostream>
#include <conio.h>
#include "Ordenamientos.h"
#include "Hash.h"


using namespace std;

void shellSortPersonas(Nodo* cabeza, Nodo* cola, bool esCircular, int criterio) {
    if (!cabeza || cabeza == cola) return;

    int n = 0;
    Nodo* actual = cabeza;
    do {
        n++;
        actual = actual->siguiente;
    } while (actual != (esCircular ? cabeza : nullptr));

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            Nodo* temp = cabeza;
            for (int k = 0; k < i; k++) temp = temp->siguiente;

            Persona tempDato = temp->dato;
            Nodo* jNodo = temp;
            for (int j = i; j >= gap; j -= gap) {
                Nodo* jGapNodo = cabeza;
                for (int k = 0; k < j - gap; k++) jGapNodo = jGapNodo->siguiente;

                bool debeIntercambiar = false;
                switch (criterio) {
                case 1:
                    debeIntercambiar = jGapNodo->dato.nombre > tempDato.nombre;
                    break;
                case 2:
                    debeIntercambiar = jGapNodo->dato.apellido > tempDato.apellido;
                    break;
                case 3:
                    debeIntercambiar = jGapNodo->dato.cedula > tempDato.cedula;
                    break;
                }

                if (!debeIntercambiar) break;

                jNodo->dato = jGapNodo->dato;
                jNodo = jGapNodo;
            }
            jNodo->dato = tempDato;
        }
    }
}

void shellSort(std::string& str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);

    int n = str.length();

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            char temp = str[i];
            int j;
            for (j = i; j >= gap && str[j - gap] > temp; j -= gap) {
                str[j] = str[j - gap];
            }
            str[j] = temp;
        }
    }
}

void radixSort(std::string& str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);

    int n = str.length();
    int maxVal = *std::max_element(str.begin(), str.end());

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        std::vector<char> bucket(26, 0);
        std::vector<int> count(26, 0);

        for (int i = 0; i < n; i++) {
            int index = str[i] - 'a';
            count[index]++;
        }

        for (int i = 1; i < 26; i++) {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            int index = str[i] - 'a';
            bucket[count[index] - 1] = str[i];
            count[index]--;
        }

        for (int i = 0; i < n; i++) {
            str[i] = bucket[i];
        }
    }
}


void radixSortPersonas(Nodo*& cabeza, Nodo* cola, bool esCircular, int criterio) {
    if (!cabeza || cabeza == cola) return;

    // Obtener la longitud máxima de los strings en la lista
    int maxLongitud = 0;
    Nodo* actual = cabeza;
    do {
        string criterioStr;
        switch (criterio) {
        case 1:
            criterioStr = actual->dato.nombre;
            break;
        case 2:
            criterioStr = actual->dato.apellido;
            break;
        case 3:
            criterioStr = actual->dato.cedula;
            break;
        }
        int longitud = criterioStr.length();
        if (longitud > maxLongitud) maxLongitud = longitud;
        actual = actual->siguiente;
    } while (actual != (esCircular ? cabeza : nullptr));

    // Radix Sort
    for (int d = maxLongitud - 1; d >= 0; d--) {
        // Crear contenedores para los caracteres (ASCII 0-255)
        Nodo* buckets[256] = { nullptr };
        Nodo* last[256] = { nullptr };

        // Distribuir los nodos en los buckets según el carácter en la posición d
        actual = cabeza;
        do {
            string criterioStr;
            switch (criterio) {
            case 1:
                criterioStr = actual->dato.nombre;
                break;
            case 2:
                criterioStr = actual->dato.apellido;
                break;
            case 3:
                criterioStr = actual->dato.cedula;
                break;
            }
            char caracter = (d >= 0 && d < criterioStr.length()) ? criterioStr[d] : '\0';
            int indice = (int)caracter + 1; // Usar (int)caracter + 1 para manejar caracteres nulos correctamente
            if (!buckets[indice]) {
                buckets[indice] = actual;
            }
            else {
                last[indice]->siguiente = actual;
            }
            last[indice] = actual;
            actual = actual->siguiente;
        } while (actual != (esCircular ? cabeza : nullptr));

        // Concatenar los buckets en la lista original
        Nodo* nuevoCabeza = nullptr;
        Nodo* nuevoCola = nullptr;
        for (int i = 0; i < 256; i++) {
            if (buckets[i]) {
                if (!nuevoCabeza) {
                    nuevoCabeza = buckets[i];
                }
                else {
                    nuevoCola->siguiente = buckets[i];
                }
                nuevoCola = last[i];
            }
        }
        if (esCircular && nuevoCola) nuevoCola->siguiente = nuevoCabeza;

        cabeza = nuevoCabeza;
        cola = nuevoCola;
    }
}

void invertirStringDesdeIndice(string& str, int indice) {
    if (indice < 0 || indice >= str.length()) {
        cout << "Indice fuera del rango" << endl;
        return;
    }
    string parte1 = str.substr(0, indice + 1);
    reverse(parte1.begin(), parte1.end());
    str = parte1;
}

void inversoString(Nodo* cabeza, Nodo* cola, bool esCircular, int criterio) {
    if (!cabeza || cabeza == cola)return;
    int indice;
    bool inverso;
    Nodo* actual;
    string cadena = "";
    Nodo* fin = nullptr;
    do {
        inverso = false;
        actual = cabeza;
        while (actual->siguiente != fin) {
            Nodo* siguiente = actual->siguiente;
            bool debeInverso = false;
            switch (criterio) {
            case 1:
                cout << "Digite el indice desde donde se desea invertir: " << endl;
                cin >> indice;
                invertirStringDesdeIndice(actual->dato.nombre, indice);
                cout << actual->dato.nombre;
                _getch();
                break;
            case 2:
                cout << "Digite el indice desde donde se desea invertir: " << endl;
                cin >> indice;
                invertirStringDesdeIndice(actual->dato.apellido, indice);
                cout << actual->dato.apellido;
                _getch();
                break;
            case 3:
                cout << "Digite el indice desde donde se desea invertir: " << endl;
                cin >> indice;
                invertirStringDesdeIndice(actual->dato.cedula, indice);
                cout << actual->dato.cedula;
                _getch();
                break;
            }

            actual = siguiente;
        }

    } while (inverso);
}

void bubbleSortPersonas(Nodo* cabeza, Nodo* cola, bool esCircular, int criterio) {
    if (!cabeza || cabeza == cola) return;

    bool intercambiado;
    Nodo* actual;
    Nodo* fin = nullptr;

    do {
        intercambiado = false;
        actual = cabeza;

        while (actual->siguiente != fin) {
            Nodo* siguiente = actual->siguiente;
            bool debeIntercambiar = false;

            switch (criterio) {
            case 1:
                debeIntercambiar = actual->dato.nombre > siguiente->dato.nombre;
                break;
            case 2:
                debeIntercambiar = actual->dato.apellido > siguiente->dato.apellido;
                break;
            case 3:
                debeIntercambiar = actual->dato.cedula > siguiente->dato.cedula;
                break;
            }

            if (debeIntercambiar) {
                Persona tempDato = actual->dato;
                actual->dato = siguiente->dato;
                siguiente->dato = tempDato;
                intercambiado = true;
            }

            actual = siguiente;
        }

        fin = actual;
    } while (intercambiado);
}



void bubbleSort(std::string& str) {
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    int n = str.length();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                std::swap(str[j], str[j + 1]);
            }
        }
    }
}

void quickSortPersonas(Nodo*& cabeza, Nodo*& cola, bool esCircular, int criterio) {
    if (cabeza == nullptr || cabeza == cola) return;

    Nodo* pivot = cola;
    Nodo* i = cabeza->anterior;
    for (Nodo* j = cabeza; j != cola; j = j->siguiente) {
        bool menor = false;
        switch (criterio) {
        case 1: menor = j->dato.nombre < pivot->dato.nombre; break;
        case 2: menor = j->dato.apellido < pivot->dato.apellido; break;
        case 3: menor = j->dato.cedula < pivot->dato.cedula; break;
        }
        if (menor) {
            if (i == nullptr) i = cabeza;
            else i = i->siguiente;
            std::swap(i->dato, j->dato);
        }
    }
    if (i == nullptr) i = cabeza;
    else i = i->siguiente;
    std::swap(i->dato, pivot->dato);

    Nodo* pi = (i == nullptr) ? cabeza : i;
    Nodo* ni = (i == nullptr || i->siguiente == nullptr) ? cola : i->siguiente;

    if (pi != cabeza) quickSortPersonas(cabeza, pi->anterior, esCircular, criterio);
    if (ni != cola) quickSortPersonas(ni, cola, esCircular, criterio);
}

void quickSort(std::string& str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);

    int n = str.length();

    if (n <= 1) return;

    char pivot = str[n / 2];
    str[n / 2] = str[0];
    str[0] = pivot;

    int i = 1;
    for (int j = 1; j < n; j++) {
        if (str[j] < pivot) {
            char temp = str[j];
            str[j] = str[i];
            str[i] = temp;
            i++;
        }
    }

    str[0] = str[i - 1];
    str[i - 1] = pivot;

    std::string left = str.substr(0, i - 1);
    std::string right = str.substr(i);

    quickSort(left);
    quickSort(right);

    str = left + pivot + right;
}

void intercambioPersonas(Nodo* cabeza, Nodo* cola, bool esCircular, int criterio) {
    if (!cabeza) return;
    bool swapped;
    Nodo* actual;
    Nodo* lastPtr = nullptr;

    if (esCircular) {
        do {
            swapped = false;
            actual = cabeza;

            do {
                Nodo* siguiente = actual->siguiente;
                if (siguiente == cabeza) break;

                bool condition = false;
                switch (criterio) {
                case 1:
                    condition = actual->dato.nombre > siguiente->dato.nombre;
                    break;
                case 2:
                    condition = actual->dato.apellido > siguiente->dato.cedula;
                    break;
                case 3:
                    condition = actual->dato.cedula > siguiente->dato.cedula;
                    break;
                }

                if (condition) {
                    std::swap(actual->dato, siguiente->dato);
                    swapped = true;
                }
                actual = siguiente;
            } while (actual != lastPtr);

            lastPtr = actual;
        } while (swapped);
    }
    else {
        do {
            swapped = false;
            actual = cabeza;

            while (actual->siguiente != lastPtr) {
                Nodo* siguiente = actual->siguiente;

                bool condition = false;
                switch (criterio) {
                case 1:
                    condition = actual->dato.nombre > siguiente->dato.nombre;
                    break;
                case 2:
                    condition = actual->dato.apellido > siguiente->dato.apellido;
                    break;
                case 3:
                    condition = actual->dato.cedula > siguiente->dato.cedula;
                    break;
                }

                if (condition) {
                    std::swap(actual->dato, siguiente->dato);
                    swapped = true;
                }
                actual = siguiente;
            }
            lastPtr = actual;
        } while (swapped);
    }
}

void intercambio(std::string& str) {
    bool swapped;
    for (size_t i = 0; i < str.size() - 1; ++i) {
        swapped = false;
        for (size_t j = 0; j < str.size() - i - 1; ++j) {
            if (str[j] > str[j + 1]) {
                std::swap(str[j], str[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void BucketSort(Nodo*& cabeza, Nodo*& cola, bool esCircular, int n) {
    if (!cabeza) return;

    int cant = 0;
    Nodo* actual = cabeza;
    do {
        cant++;
        actual = actual->siguiente;
    } while (actual != (esCircular ? cabeza : nullptr));

    Lista** listaB = new Lista * [cant];

    for (int i = 0; i < cant; i++) {
        listaB[i] = new Lista();
    }

    actual = cabeza;
    do {
        Persona valor = actual->dato;
        int indB;
        switch (n) {
        case 1:
            indB = calcularIndice(valor.cedula, cant);
            break;
        case 2:
            indB = calcularIndice(valor.nombre, cant);
            break;
        case 3:
            indB = calcularIndice(valor.apellido, cant);
            break;
        default:
            indB = 0; // Asignar a un bucket predeterminado en caso de valor inválido
            break;
        }
        listaB[indB]->insertarOrdenado(valor, n);
        actual = actual->siguiente;
    } while (actual != (esCircular ? cabeza : nullptr));

    while (cabeza != cola) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
    cabeza = nullptr;
    cola = nullptr;

    for (int i = 0; i < cant; i++) {
        while (listaB[i]->cantidad() > 0) {
            Persona valor = listaB[i]->eliminarPrimero();
            Nodo* nuevo = new Nodo(valor);
            if (!cabeza) {
                cabeza = nuevo;
                cola = nuevo;
                if (esCircular) {
                    cabeza->siguiente = cabeza;
                    cabeza->anterior = cabeza;
                }
            }
            else {
                cola->siguiente = nuevo;
                nuevo->anterior = cola;
                if (esCircular) {
                    nuevo->siguiente = cabeza;
                    cabeza->anterior = nuevo;
                }
                cola = nuevo;
            }
        }
        delete listaB[i];
    }
    delete[] listaB;
}