#include "Menus.h"
#include "ArbolAA.h"
#include<conio.h>
#include<iostream>
#include"Persona.h"
#include "WindowArbolAA.h"

using namespace std;

enum Opciones {
    LISTA_SIMPLE,
    LISTA_DOBLE,
    LISTA_CIRCULAR,
    SALIR,
    NUM_OPCIONES
};

enum OpcionesSubMenu {
    INGRESAR_DATOS,
    ORDENAR_LISTA,
    IMPRIMIR_LISTA,
    ADICIONAL,
    REGRESAR,
    NUM_OPCIONES_SUBMENU
};

enum OpcionesSubMenu2 {
    INVERTIR_NOMBRE,
    INVERTIR_APELLIDO,
    INVERTIR_CEDULA,
    VOLVER,
    NUM_OPCIONES_SUBMENU2
};

enum OpcionesAdicionales {
    INVERTIR_CARACTERES,
    ENCRIPTAR_NOMBRE_APELLIDO,
    CONTAR_VOCALES_CONSONANTES,
    REEMPLAZAR_CEDULA,
    MEZCLA_NOMBRES,
    COMBINAR_LISTAS,
    BUSCAR,
    ENCRIPTAR_PALABRA_SHA1,
    INSERTAR_DATOS_ARBOL, //Quitarlo y ponerlo en un menu con todos los tipos de arboles
    RETROCEDER,
    NUM_OPCIONES_ADICIONALES
};

enum OpcionesBusqueda {
    BUSQUEDA_SECUENCIAL,
    BUSQUEDA_BINARIA,
    BUSQUEDA_HASH,
    BUSQUEDA_FIBONACCI,
    ATRAS,
    NUM_OPCIONES_BUSQUEDA
};

enum OpcionesSubMenuInsertar {
    INSERTAR_CEDULA,
    INSERTAR_CORREO,
    INSERTAR_NOMBRE1,
    INSERTAR_NOMBRE2,
    REGRESAR_INSERTAR,
    NUM_OPCIONES_SUMENU_INSERTAR
};

enum OpcionesSubMenuEliminar {
    ELIMINAR_CEDULA,
    ELIMINAR_CORREO,
    ELIMINAR_NOMBRE1,
    ELIMINAR_NOMBRE2,
    REGRESAR_ELIMINAR,
    NUM_OPCIONES_SUMENU_ELIMINAR
};

enum OpcionesArbolAA {
    INSERTAR,
    ELIMINAR,
    VER_ALTURA,
    VER_PROFUNDIDAD,
    CONTAR_HOJAS,
    IMPRIMIR_NIVELES,
    VER_BALANCE,
    RECORRIDO_INORDEN,
    RECORRIDO_PREORDEN,
    RECORRIDO_POSTORDEN,
    CONTAR_ABUELOS,
    VOLVER_ARBOL,
    NUM_OPCIONES_ARBOL_AA
};

void setConsoleColor(WORD color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void mostrarMenu(int opcion) {
    system("cls");
    const char* opciones[] = {
        "Lista Simple",
        "Lista Doble",
        "Lista Circular",
        "Salir"
    };

    std::cout << "******************************" << endl;
    std::cout << "En que lista deseas trabajar?" << endl;
    std::cout << "******************************" << endl;
    for (int i = 0; i < NUM_OPCIONES; ++i) {
        if (i == opcion) {
            setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE); // Cambiar color
            std::cout << " --> " << opciones[i] << "\n";
            setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Restaurar color
        }
        else {
            std::cout << "     " << opciones[i] << "\n";
        }
    }
    std::cout << "******************************" << endl;
}

void mostrarSubMenu(int opcion) {
    system("cls");
    const char* opciones[] = {
        "Ingresar datos",
        "Ordenar lista",
        "Imprimir lista",
        "Adicional",
        "Regresar"
    };

    std::cout << "******************************" << endl;
    for (int i = 0; i < NUM_OPCIONES_SUBMENU; ++i) {
        if (i == opcion) {
            setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE); // Cambiar color
            std::cout << " --> " << opciones[i] << "\n";
            setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Restaurar color
        }
        else {
            std::cout << "     " << opciones[i] << "\n";
        }
    }
    std::cout << "******************************" << endl;
}

void mostrarMenuArbolAA(int opcion) {
    system("cls");
    const char* opciones[] = {
        "Insertar",
        "Eliminar",
        "Ver altura",
        "Ver profundidad",
        "Contar hojas",
        "Imprimir niveles",
        "Ver balance",
        "Recorrido inorden",
        "Recorrido preorden",
        "Recorrido postorden",
        "Contar Abuelos",
        "Volver"
    };

    std::cout << "******************************" << endl;
    for (int i = 0; i < NUM_OPCIONES_ARBOL_AA; ++i) {
        if (i == opcion) {
            setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
            std:: cout << "--> " << opciones[i] << "\n";
            setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        else {
            std::cout << "    " << opciones[i] << "\n";
        }
    }
    std::cout << "******************************" << endl;
}

void MostrarMenuInsertar(ArbolAA& arbol) {
    int opcion = 0;
    bool continuar = true;
    Persona persona;
    string cedula, correo, nombre1, nombre2;
    while (opcion != REGRESAR_INSERTAR) {
        cout << "\nSeleccione una opcion para insertar: " << endl;
        cout << "1. Insertar cedula" << endl;
        //cout << "2. Insertar correo" << endl;
        //cout << "3. Insertar Primer Nombre" << endl;
        //cout << "4. Insertar Segundo Nombre" << endl;
        //cout << "5. Regresar" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case INSERTAR_CEDULA:
            cout << "Ingrese la cedula: ";
            cin >> cedula;
            persona.setCedula(cedula);
            arbol.insert(persona);


            //_getch();
            break;
        //case INSERTAR_CORREO:
            //cout << "Ingrese el correo: ";
			//cin >> correo;
            //persona.setCorreo(correo);
            //arbol.insert(persona);


			//_getch();
			//break;
        //case INSERTAR_NOMBRE1:
            //cout << "Ingrese el primer nombre: ";
            //cin >> nombre1;
            //persona.setNombre(nombre1);
            //arbol.insert(persona);


            //_getch();
            //break;
        //case INSERTAR_NOMBRE2:
            //cout << "Ingrese el segundo nombre: ";
            //cin >> nombre2;
            //persona.setSegundoNombre(nombre2);
            //arbol.insert(persona);


            //_getch();
            //break;
        case REGRESAR_INSERTAR:
            cout << "Regresando al menu principal..." << endl;
            continuar = false;
            break;
        }
    }
    arbol.printLevels();
    //arbol.checkAndBalance();
}

void MostarMenuEliminar(ArbolAA& arbol) {
    int opcion = 0;
    bool continuar = true;
    string key, field;
    while (opcion != REGRESAR_ELIMINAR) {
        cout << "\nSeleccione una opcion para eliminar: " << endl;
        cout << "1. Eliminar por cedula" << endl;
        cout << "2. Eliminar por correo" << endl;
        cout << "3. Eliminar por primer nombre" << endl;
        cout << "4. Eliminar por segundo nombre" << endl;
        cout << "5. Regresar" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case ELIMINAR_CEDULA:
            cout << "Ingrese la cedula: ";
            cin >> key;
            field = "cedula";
            arbol.remove(key, field);


            _getch();
            break;
        //case ELIMINAR_CORREO:
            //cout << "Ingrese el correo: ";
            //cin >> key;
            //field = "correo";
            //arbol.remove(key, field);


            //_getch();
            //break;
        //case ELIMINAR_NOMBRE1:
            //cout << "Ingrese el primer nombre: ";
			//cin >> key;
			//field = "nombre";
			//arbol.remove(key, field);


			//_getch();
			//break;
        //case ELIMINAR_NOMBRE2:
            //cout << "Ingrese el segundo nombre: ";
            //cin >> key;
            //field = "segundoNombre";
            //arbol.remove(key, field);


            //_getch();
             //break;
        case REGRESAR_ELIMINAR:
            cout << "Regresando al menu principal..." << endl;
            continuar = false;
            //_getch();
            break;
        default:
            cout << "Opcion no valida" << endl;
			break;
        }
    }
    arbol.printLevels();
    //arbol.checkAndBalance();
}

void menuArbolAA(ArbolAA& arbol) {
    int subopcion = 0;
    bool continuar = true;
    while (continuar) {
        mostrarMenuArbolAA(subopcion);
        int tecla = _getch();
        switch (tecla) {
        case 72: // Flecha arriba
            subopcion = (subopcion - 1 + NUM_OPCIONES_ARBOL_AA) % NUM_OPCIONES_ARBOL_AA;
            break;
        case 80: // Flecha abajo
            subopcion = (subopcion + 1) % NUM_OPCIONES_ARBOL_AA;
            break;
        case 13: // Enter
            switch (subopcion) {
            case INSERTAR: {
                MostrarMenuInsertar(arbol);
                _getch();
                break;
            }
            case ELIMINAR: {
                string cedula;
                MostarMenuEliminar(arbol);
                _getch();
                break;
            }
            case VER_ALTURA:
                //cout << "Altura del arbol: " << arbol.getHeight() << endl;
                _getch();
                break;
            case VER_PROFUNDIDAD: {
                string cedula;
                cout << "Ingrese la cedula para ver la profundidad: ";
                cin >> cedula;
                cout << "Profundidad: " << arbol.getDepth(cedula, "cedula") << endl;
                _getch();
                break;
            }
            case CONTAR_HOJAS:
                cout << "Numero de hojas: " << arbol.countLeaves() << endl;
                _getch();
                break;
            case IMPRIMIR_NIVELES:
                arbol.printLevels();
                _getch();
                break;
            case VER_BALANCE:
                //cout << "El arbol " << (arbol.isBalanced() ? "esta" : "no esta") << " balanceado." << endl;
                _getch();
                break;
            case RECORRIDO_INORDEN:
                arbol.traverseInOrder();
                _getch();
                break;
            case RECORRIDO_PREORDEN:
                arbol.traversePreOrder();
                _getch();
                break;
            case RECORRIDO_POSTORDEN:
                arbol.traversePostOrder();
                _getch();
                break;
            case CONTAR_ABUELOS:
                arbol.contarAbuelosUnicos();
                lanzarInterfazGraficaConArbolAA(&arbol);
                _getch();
                break;
            case VOLVER_ARBOL:
                continuar = false;
                break;

            default:
                cout << "Opcion no valida" << endl;
                break;
            }
            break;
        default:
            break;
        }
    }
}

void mostrarSubMenu2(int opcion) {
    system("cls");
    const char* opciones[] = {
        "Invertir nombre",
        "Invertir apellido",
        "Invertir cedula",
        "Volver"
    };

    std::cout << "******************************" << endl;
    for (int i = 0; i < NUM_OPCIONES_SUBMENU2; ++i) {
        if (i == opcion) {
            setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE); // Cambiar color
            std::cout << " --> " << opciones[i] << "\n";
            setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Restaurar color
        }
        else {
            std::cout << "     " << opciones[i] << "\n";
        }
    }
    std::cout << "******************************" << endl;
}

void mostrarMenuOrden(int opcion) {
    system("cls");
    const char* opciones[] = {
        "Ordenar por Nombre",
        "Ordenar por Apellido",
        "Ordenar por Cedula",
        "Ordenar por Caracteres de Nombre",
        "Retroceder"
    };

    std::cout << "******************************" << endl;
    std::cout << "Seleccione un criterio de ordenacion:" << endl;
    std::cout << "******************************" << endl;
    for (int i = 0; i < 5; ++i) { // 4 opciones + "Regresar"
        if (i == opcion) {
            setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE); // Cambiar color
            std::cout << " --> " << opciones[i] << "\n";
            setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Restaurar color
        }
        else {
            std::cout << "     " << opciones[i] << "\n";
        }
    }
    std::cout << "******************************" << endl;
}

void mostrarAdicional(int opcion) {
    system("cls");
    const char* opciones[] = {
        "Invertir caracteres",
        "Encriptar nombres y apellidos",
        "Contar vocales y consonantes",
        "Reemplazar cedula",
        "Mezclar nombres",
        "Combinar listas",
        "Buscar",
        "Encriptar palabra con SHA-1",
        "Insertar datos en un arbol e imprimirlos",//Quitarlo y ponerlo en un menu para los arboles
        "Volver"
    };

    std::cout << "******************************" << endl;
    for (int i = 0; i < NUM_OPCIONES_ADICIONALES; ++i) {
        if (i == opcion) {
            setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE); // Cambiar color
            std::cout << " --> " << opciones[i] << "\n";
            setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Restaurar color
        }
        else {
            std::cout << "     " << opciones[i] << "\n";
        }
    }
    std::cout << "******************************" << endl;
}

void mostrarSubMenuCombinarListas(int opcion) {
    system("cls");
    const char* opciones[] = {
        "Ordenadas por nombre",
        "Ordenadas por apellido",
        "Ordenadas por cedula",
        "Volver"
    };

    std::cout << "******************************" << endl;
    std::cout << "Seleccione el criterio por el cual estan ordenadas las listas:" << endl;
    for (int i = 0; i < NUM_OPCIONES_SUBMENU2; ++i) {
        if (i == opcion) {
            setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE); // Cambiar color
            std::cout << " --> " << opciones[i] << "\n";
            setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Restaurar color
        }
        else {
            std::cout << "     " << opciones[i] << "\n";
        }
    }
    std::cout << "******************************" << endl;
}

void mostrarMenuBusqueda(int opcion) {
    system("cls");
    const char* opciones[] = {
        "Busqueda Secuencial",
        "Busqueda Binaria",
        "Busqueda Hash",
        "Busqueda Fibonacci",
        "Atras"
    };

    std::cout << "******************************" << endl;
    std::cout << "Seleccione un criterio de busqueda:" << endl;
    std::cout << "******************************" << endl;
    for (int i = 0; i < NUM_OPCIONES_BUSQUEDA; ++i) { // 4 opciones + "Regresar"
        if (i == opcion) {
            setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE); // Cambiar color
            std::cout << " --> " << opciones[i] << "\n";
            setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Restaurar color
        }
        else {
            std::cout << "     " << opciones[i] << "\n";
        }
    }
    cout << "******************************" << endl;
}


void ingresarDatos(Lista& lista) {
    string cedula = ingresarCedula();

    if (lista.verificarCedula(cedula)) {
        cout << "La cedula ya esta registrada. Intente con otra. " << endl;
        return;
    }
    else if (cedulaRegistradaEnArchivo(cedula)) {
        cout << "La cedula ya esta registrada. Intente con otra. " << endl;
        return;
    }

    string nombre, segundoNombre, apellido, correo;
    cout << "Ingrese el primer nombre: ";
    nombre = ingresarLetra();
    cout << "Ingrese el segundo nombre: ";
    segundoNombre = ingresarStringValidado();
    cout << "Ingrese el apellido: ";
    apellido = ingresarLetra();

    Persona p(nombre, segundoNombre, apellido, cedula, correo);
    lista.insertar(p);
}

bool cedulaRegistradaEnArchivo(const string& cedula) {
    ifstream archivo("Datos_Personas.txt");
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return false;
    }

    string linea;
    while (getline(archivo, linea)) {
        size_t pos = linea.find("Cedula: ");
        if (pos != string::npos) {
            size_t start = pos + 8; // 8 es la longitud de "Cedula: "
            size_t end = linea.find('\n', start);
            string cedulaEnArchivo = linea.substr(start, end - start);
            if (cedula == cedulaEnArchivo) {
                return true;
            }
        }
    }
    return false;
}

void encriptador(Nodo* act, int nume) {
    if (act == nullptr) {
        return;
    }
    string pass = "", pass2 = "";
    string alfabetom = "abcdefghijklmnopqrstuvwxyz";
    bool mayuscula = true;
    for (char aux : act->dato.nombre) {
        char letra = alfabetom[(tolower(aux) - 'a' + nume) % 26];
        pass += mayuscula ? toupper(letra) : tolower(letra);
        mayuscula = !mayuscula;
    }
    mayuscula = true;
    for (char aux : act->dato.apellido) {
        char letra = alfabetom[(tolower(aux) - 'a' + nume) % 26];
        pass2 += mayuscula ? toupper(letra) : tolower(letra);
        mayuscula = !mayuscula;
    }
    pass2.pop_back();
    std::cout << "Encriptado: " << pass << " " << pass2 << std::endl;

    act = act->siguiente;
    encriptador(act, nume);
}

void encriptado(Lista& lista, int num) {
    Nodo* actual = lista.getCabeza();
    encriptador(actual, num);
}

void contarVocalesYConsonantes(Lista& lista) {
    int vocales = 0;
    int consonantes = 0;
    lista.contarVocalesYConsonantes(vocales, consonantes);
    cout << "En la lista hay " << vocales << " vocales y " << consonantes << " consonantes en total." << endl;

    system("pause");
}

void reemplazarEnCedula() {
    string cedula = ingresarCedula();
    if (!validarCedula(cedula)) {
        cout << "Cedula invalida:" << endl;
        return;
    }

    Pila pila = convertirCedulaAPila(cedula);
    int viejo, nuevo;

    cout << "Ingrese el valor a reemplazar: ";
    cin >> viejo;
    cout << "Ingrese el nuevo valor: ";
    cin >> nuevo;

    pila.reemplazar(viejo, nuevo);

    cout << "Cedula modificada: ";
    pila.imprimir();
}

void menuBusqueda(Lista& lista) {
    int subopcion = 0;
    bool continuar = true;
    ArbolAA arbol;
    arbol.cargarDesdeArchivo("Datos_Personas.txt");
    while (continuar) {
        mostrarMenuBusqueda(subopcion);
        int tecla = _getch();
        switch (tecla) {
        case 72: // Flecha arriba
            subopcion = (subopcion - 1 + NUM_OPCIONES_BUSQUEDA) % NUM_OPCIONES_BUSQUEDA;
            break;
        case 80: // Flecha abajo
            subopcion = (subopcion + 1) % NUM_OPCIONES_BUSQUEDA;
            break;
        case 13: // Enter
            switch (subopcion) {
            case BUSQUEDA_SECUENCIAL: {
                Busquedas busquedas;
                string cedula;
                cout << "Ingrese la cedula a buscar: ";
                cin >> cedula;
                Persona* persona = busquedas.busquedaSecuencial("Datos_Personas.txt", cedula);
                busquedas.imprimirPersona(persona);
                _getch();
            }
                                    break;
            case BUSQUEDA_BINARIA:
                cout << "Busqueda binaria" << endl;
                break;
            case BUSQUEDA_HASH:
                cout << "Busqueda hash" << endl;
                break;
            case BUSQUEDA_FIBONACCI: {
                string cedula;
                cout << "Ingrese la cedula a buscar: ";
                cin >> cedula;
                Persona* persona = arbol.buscarCedulaFibonacci(cedula);
                if (persona) {
                    cout << "Persona encontrada: " << endl;
                }
                else {
                    cout << "Cedula no encontrada" << endl;
                }
                _getch();
                break;
            }
            case ATRAS:
                continuar = false;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
            }
            break;
        default:
            break;
        }
    }
}

void menuAdicional(Lista& lista) {
    int subopcion = 0;
    bool continuar = true;
    while (continuar) {
        mostrarAdicional(subopcion);
        int tecla = _getch();
        switch (tecla) {
        case 72: // Flecha arriba
            subopcion = (subopcion - 1 + NUM_OPCIONES_ADICIONALES) % NUM_OPCIONES_ADICIONALES;
            break;
        case 80: // Flecha abajo
            subopcion = (subopcion + 1) % NUM_OPCIONES_ADICIONALES;
            break;
        case 13: // Enter
            switch (subopcion) {
            case INVERTIR_CARACTERES: {
                int criteri = 0;
                bool continuarOrden = true;
                while (continuarOrden) {
                    mostrarSubMenu2(criteri);
                    int teclaOrden = _getch();
                    switch (teclaOrden) {
                    case 72: // Flecha arriba
                        criteri = (criteri - 1 + 4) % 4; // 4 opciones en el menú de ordenación
                        break;
                    case 80: // Flecha abajo
                        criteri = (criteri + 1) % 4;
                        break;
                    case 13: // Enter
                        if (criteri == 3) {
                            continuarOrden = false;
                        }
                        else {
                            lista.InertirPersonas(criteri + 1); // Ajustar criterio según implementación
                        }
                        break;
                    }
                }
                break;
            }
            case ENCRIPTAR_NOMBRE_APELLIDO: {
                int num;
                cout << "Ingrese el valor de desplazamiento: ";
                num = ingresarEntero();
                encriptado(lista, num);
                cout << "Presione cualquier tecla para continuar...";
                _getch(); // Espera una tecla antes de continuar
                break;
            }
            case CONTAR_VOCALES_CONSONANTES:
                contarVocalesYConsonantes(lista);
                break;
            case REEMPLAZAR_CEDULA:
                reemplazarEnCedula();
                _getch();
                break;
            case MEZCLA_NOMBRES:
                lista.MezclaPares();
                cout << "Presione cualquier tecla para continuar...";
                _getch(); // Espera una tecla antes de continuar
                break;
            case COMBINAR_LISTAS: {
                int criter = 0;
                bool continuarOrde = true;
                while (continuarOrde) {
                    mostrarSubMenuCombinarListas(criter);
                    int teclaOrde = _getch();
                    switch (teclaOrde) {
                    case 72: // Flecha arriba
                        criter = (criter - 1 + 4) % 4; // 4 opciones en el menú de ordenación
                        break;
                    case 80: // Flecha abajo
                        criter = (criter + 1) % 4;
                        break;
                    case 13: // Enter
                        if (criter == 3) {
                            continuarOrde = false;
                        }
                        else {
                            Lista lista2(false, "Datos_Personas.txt");
                            Lista listaCombinada(false);
                            listaCombinada.setCabeza(lista.combinarListas(lista.getCabeza(), lista2.getCabeza(), criter + 1));
                            cout << "Lista combinada: " << endl;
                            listaCombinada.imprimir();
                            cout << "Presione cualquier tecla para continuar...";
                            _getch();

                        }
                        break;
                    }
                }
                break;
            }
            case BUSCAR:
                menuBusqueda(lista);
                break;
            case ENCRIPTAR_PALABRA_SHA1: {
                    std::string palabra;
                    std::cout << "Ingrese la palbra a encriptar con SHA-1: ";
                    std::cin >> palabra;
                    std::string resultado = encriptarSHA1(palabra);
                    std::cout << "Resultado encriptado: " << resultado << endl;
                    _getch();
                    break;
                }
            case INSERTAR_DATOS_ARBOL: { //Esto hay que quitarlo
                int arbolopcion;
                cout << "Seleccione el tipo de arbol: " << endl;
                cout << "1. Arbol B" << endl;
                cout << "2. Arbol Rojo-Negro" << endl;
                cout << "3. Arbol AA" << endl;
                cin >> arbolopcion;

                switch (arbolopcion) {
                case 1: {

                    cout << "No hay nada aqui" << endl;
                    _getch();
                    break;
                };
                case 2: {

                    cout << "No hay nada aqui" << endl;
                    _getch();

                }
                case 3: {
                    ArbolAA arbol;
                    menuArbolAA(arbol);
                    _getch();
                    break;
                }
                default: {
                    cout << "Opción inválida" << endl;
                }
                }
                break;
            }
            case RETROCEDER:
                continuar = false;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
            }
            break;
        default:
            break;
        }
    }
}


void subMenuListaShell(Lista& lista) {
    int subopcion = 0;
    bool continuar = true;
    while (continuar) {
        mostrarSubMenu(subopcion);
        int tecla = _getch();
        switch (tecla) {
        case 72: // Flecha arriba
            subopcion = (subopcion - 1 + NUM_OPCIONES_SUBMENU) % NUM_OPCIONES_SUBMENU;
            break;
        case 80: // Flecha abajo
            subopcion = (subopcion + 1) % NUM_OPCIONES_SUBMENU;
            break;
        case 13: // Enter
            switch (subopcion) {
            case INGRESAR_DATOS:
                ingresarDatos(lista);
                break;
            case ORDENAR_LISTA: {
                int criterio = 0;
                bool continuarOrden = true;
                while (continuarOrden) {
                    mostrarMenuOrden(criterio);
                    int teclaOrden = _getch();
                    switch (teclaOrden) {
                    case 72: // Flecha arriba
                        criterio = (criterio - 1 + 5) % 5; // 5 opciones en el menú de ordenación
                        break;
                    case 80: // Flecha abajo
                        criterio = (criterio + 1) % 5;
                        break;
                    case 13: // Enter
                        if (criterio == 4) {
                            continuarOrden = false;
                        }
                        else {
                            lista.ordenar(criterio + 1); // Ajustar criterio según implementación
                        }
                        break;
                    }
                }
                break;
            }
            case IMPRIMIR_LISTA:
                lista.imprimir();
                cout << "Presione cualquier tecla para continuar...";
                _getch(); // Espera una tecla antes de continuar
                break;
            case ADICIONAL:
                menuAdicional(lista);
                break;
            case REGRESAR:
                continuar = false;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
            }
        }
    }
}


void MenuShellMain() {
    Lista listaSimple(false, "Datos_Personas.txt");
    Lista listaDoble(false, "Datos_Personas.txt");
    Lista listaCircular(true, "Datos_Personas.txt");
    int opcion = 0;
    bool continuar = true;

    while (continuar) {
        mostrarMenu(opcion);

        int tecla = _getch();
        switch (tecla) {
        case 72: // Flecha arriba
            opcion = (opcion - 1 + NUM_OPCIONES) % NUM_OPCIONES;
            break;
        case 80: // Flecha abajo
            opcion = (opcion + 1) % NUM_OPCIONES;
            break;
        case 13: // Enter
            switch (opcion) {
            case LISTA_SIMPLE:
                subMenuListaShell(listaSimple);
                break;
            case LISTA_DOBLE:
                subMenuListaShell(listaDoble);
                break;
            case LISTA_CIRCULAR:
                subMenuListaShell(listaCircular);
                break;
            case SALIR:
                continuar = false;
                cout << "Saliendo..." << endl;
                break;
            }
        }
    }
}

void subMenuListaRadix(Lista& lista) {
    int subopcion = 0;
    bool continuar = true;

    while (continuar) {
        mostrarSubMenu(subopcion);

        int tecla = _getch();
        switch (tecla) {
        case 72: // Flecha arriba
            subopcion = (subopcion - 1 + 4) % 4;
            break;
        case 80: // Flecha abajo
            subopcion = (subopcion + 1) % 4;
            break;
        case 13: // Enter
            switch (subopcion) {
            case 0:
                ingresarDatos(lista);
                break;
            case 1: {
                int criterio = 0;
                bool continuarOrden = true;
                while (continuarOrden) {
                    mostrarMenuOrden(criterio);

                    int teclaOrden = _getch();
                    switch (teclaOrden) {
                    case 72: // Flecha arriba
                        criterio = (criterio - 1 + 5) % 5; // 5 opciones en el menú de ordenación
                        break;
                    case 80: // Flecha abajo
                        criterio = (criterio + 1) % 5;
                        break;
                    case 13: // Enter
                        if (criterio == 4) {
                            continuarOrden = false;
                        }
                        else {
                            lista.ordenarRadix(criterio + 1); // Ajustar criterio según implementación
                        }
                        break;
                    }
                }
                break;
            }
            case 2:
                lista.imprimir();
                std::cout << "Presione cualquier tecla para continuar...";
                _getch(); // Espera una tecla antes de continuar
                break;
            case 3:
                menuAdicional(lista);
                break;
            case 4:
                continuar = false;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
            }
        }
    }
}

void MenuRadixMain() {
    Lista listaSimple(false, "Datos_Personas.txt");
    Lista listaDoble(false, "Datos_Personas.txt");
    Lista listaCircular(true, "Datos_Personas.txt");
    int opcion = 0;
    bool continuar = true;

    while (continuar) {
        mostrarMenu(opcion);

        int tecla = _getch();
        switch (tecla) {
        case 72: // Flecha arriba
            opcion = (opcion - 1 + 4) % 4;
            break;
        case 80: // Flecha abajo
            opcion = (opcion + 1) % 4;
            break;
        case 13: // Enter
            switch (opcion) {
            case 0:
                subMenuListaRadix(listaSimple);
                break;
            case 1:
                subMenuListaRadix(listaDoble);
                break;
            case 2:
                subMenuListaRadix(listaCircular);
                break;
            case 3:
                continuar = false;
                std::cout << "Saliendo..." << endl;
                break;
            }
        }
    }
}


void subMenuListaIntercambio(Lista& lista) {
    int subopcion = 0;
    bool continuar = true;
    while (continuar) {
        mostrarSubMenu(subopcion);
        int tecla = _getch();
        switch (tecla) {
        case 72: // Flecha arriba
            subopcion = (subopcion - 1 + NUM_OPCIONES_SUBMENU) % NUM_OPCIONES_SUBMENU;
            break;
        case 80: // Flecha abajo
            subopcion = (subopcion + 1) % NUM_OPCIONES_SUBMENU;
            break;
        case 13: // Enter
            switch (subopcion) {
            case INGRESAR_DATOS:
                ingresarDatos(lista);
                break;
            case ORDENAR_LISTA: {
                int criterio = 0;
                bool continuarOrden = true;
                while (continuarOrden) {
                    mostrarMenuOrden(criterio);
                    int teclaOrden = _getch();
                    switch (teclaOrden) {
                    case 72: // Flecha arriba
                        criterio = (criterio - 1 + 5) % 5; // 5 opciones en el menú de ordenación
                        break;
                    case 80: // Flecha abajo
                        criterio = (criterio + 1) % 5;
                        break;
                    case 13: // Enter
                        if (criterio == 4) {
                            continuarOrden = false;
                        }
                        else {
                            lista.ordenarIntercambio(criterio + 1); // Ajustar criterio según implementación
                        }
                        break;
                    }
                }
                break;
            }
            case IMPRIMIR_LISTA:
                lista.imprimir();
                cout << "Presione cualquier tecla para continuar...";
                _getch(); // Espera una tecla antes de continuar
                break;
            case ADICIONAL:
                menuAdicional(lista);
                break;
            case REGRESAR:
                continuar = false;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
            }
        }
    }
}

void MenuIntercambio() {
    Lista listaSimple(false, "Datos_Personas.txt");
    Lista listaDoble(false, "Datos_Personas.txt");
    Lista listaCircular(true, "Datos_Personas.txt");
    int opcion = 0;
    bool continuar = true;

    while (continuar) {
        mostrarMenu(opcion);

        int tecla = _getch();
        switch (tecla) {
        case 72: // Flecha arriba
            opcion = (opcion - 1 + NUM_OPCIONES) % NUM_OPCIONES;
            break;
        case 80: // Flecha abajo
            opcion = (opcion + 1) % NUM_OPCIONES;
            break;
        case 13: // Enter
            switch (opcion) {
            case LISTA_SIMPLE:
                subMenuListaIntercambio(listaSimple);
                break;
            case LISTA_DOBLE:
                subMenuListaIntercambio(listaDoble);
                break;
            case LISTA_CIRCULAR:
                subMenuListaIntercambio(listaCircular);
                break;
            case SALIR:
                continuar = false;
                cout << "Saliendo..." << endl;
                break;
            }
        }
    }
}

void subMenuListaQuicksort(Lista& lista) {
    int subopcion = 0;
    bool continuar = true;

    while (continuar) {
        mostrarSubMenu(subopcion);

        int tecla = _getch();
        switch (tecla) {
        case 72: // Flecha arriba
            subopcion = (subopcion - 1 + NUM_OPCIONES_SUBMENU) % NUM_OPCIONES_SUBMENU;
            break;
        case 80: // Flecha abajo
            subopcion = (subopcion + 1) % NUM_OPCIONES_SUBMENU;
            break;
        case 13: // Enter
            switch (subopcion) {
            case INGRESAR_DATOS:
                ingresarDatos(lista);
                break;
            case ORDENAR_LISTA: {
                int criterio = 0;
                bool continuarOrden = true;
                while (continuarOrden) {
                    mostrarMenuOrden(criterio);

                    int teclaOrden = _getch();
                    switch (teclaOrden) {
                    case 72: // Flecha arriba
                        criterio = (criterio - 1 + 5) % 5; // 5 opciones en el men� de ordenaci�n
                        break;
                    case 80: // Flecha abajo
                        criterio = (criterio + 1) % 5;
                        break;
                    case 13: // Enter
                        if (criterio == 4) {
                            continuarOrden = false;
                        }
                        else {
                            lista.ordenarQuicksort(criterio + 1); // Ajustar criterio seg�n implementaci�n
                        }
                        break;
                    }
                }
                break;
            }
            case IMPRIMIR_LISTA:
                lista.imprimir();
                cout << "Presione cualquier tecla para continuar...";
                _getch(); // Espera una tecla antes de continuar
                break;
            case ADICIONAL:
                menuAdicional(lista);
                break;
            case REGRESAR:
                continuar = false;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
            }
        }
    }
}

void MenuQuicksortMain() {
    Lista listaSimple(false, "Datos_Personas.txt");
    Lista listaDoble(false, "Datos_Personas.txt");
    Lista listaCircular(true, "Datos_Personas.txt");
    int opcion = 0;
    bool continuar = true;

    while (continuar) {
        mostrarMenu(opcion);

        int tecla = _getch();
        switch (tecla) {
        case 72: // Flecha arriba
            opcion = (opcion - 1 + NUM_OPCIONES) % NUM_OPCIONES;
            break;
        case 80: // Flecha abajo
            opcion = (opcion + 1) % NUM_OPCIONES;
            break;
        case 13: // Enter
            switch (opcion) {
            case LISTA_SIMPLE:
                subMenuListaQuicksort(listaSimple);
                break;
            case LISTA_DOBLE:
                subMenuListaQuicksort(listaDoble);
                break;
            case LISTA_CIRCULAR:
                subMenuListaQuicksort(listaCircular);
                break;
            case SALIR:
                continuar = false;
                cout << "Saliendo..." << endl;
                break;
            }
        }
    }
}

void subMenuListaDistribucion(Lista& lista) {
    int subopcion = 0;
    bool continuar = true;

    while (continuar) {
        mostrarSubMenu(subopcion);

        int tecla = _getch();
        switch (tecla) {
        case 72: // Flecha arriba
            subopcion = (subopcion - 1 + NUM_OPCIONES_SUBMENU) % NUM_OPCIONES_SUBMENU;
            break;
        case 80: // Flecha abajo
            subopcion = (subopcion + 1) % NUM_OPCIONES_SUBMENU;
            break;
        case 13: // Enter
            switch (subopcion) {
            case INGRESAR_DATOS:
                ingresarDatos(lista);
                break;
            case ORDENAR_LISTA: {
                int criterio = 0;
                bool continuarOrden = true;
                while (continuarOrden) {
                    mostrarMenuOrden(criterio);

                    int teclaOrden = _getch();
                    switch (teclaOrden) {
                    case 72: // Flecha arriba
                        criterio = (criterio - 1 + 5) % 5; // 5 opciones en el menú de ordenación
                        break;
                    case 80: // Flecha abajo
                        criterio = (criterio + 1) % 5;
                        break;
                    case 13: // Enter
                        if (criterio == 4) {
                            continuarOrden = false;
                        }
                        else {
                            lista.ordenarDistribucion(criterio + 1); // Ajustar criterio según implementación
                        }
                        break;
                    }
                }
                break;
            }
            case IMPRIMIR_LISTA:
                lista.imprimir();
                cout << "Presione cualquier tecla para continuar...";
                _getch(); // Espera una tecla antes de continuar
                break;
            case ADICIONAL:
                menuAdicional(lista);
                break;
            case REGRESAR:
                continuar = false;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
            }
        }
    }
}

void MenuDistribucion() {
    Lista listaSimple(false, "Datos_Personas.txt");
    Lista listaDoble(false, "Datos_Personas.txt");
    Lista listaCircular(true, "Datos_Personas.txt");
    int opcion = 0;
    bool continuar = true;

    while (continuar) {
        mostrarMenu(opcion);

        int tecla = _getch();
        switch (tecla) {
        case 72: // Flecha arriba
            opcion = (opcion - 1 + NUM_OPCIONES) % NUM_OPCIONES;
            break;
        case 80: // Flecha abajo
            opcion = (opcion + 1) % NUM_OPCIONES;
            break;
        case 13: // Enter
            switch (opcion) {
            case LISTA_SIMPLE:
                subMenuListaDistribucion(listaSimple);
                break;
            case LISTA_DOBLE:
                subMenuListaDistribucion(listaDoble);
                break;
            case LISTA_CIRCULAR:
                subMenuListaDistribucion(listaCircular);
                break;
            case SALIR:
                continuar = false;
                cout << "Saliendo..." << endl;
                break;
            }
        }
    }
}

void subMenuListaBurbuja(Lista& lista) {
    int subopcion = 0;
    bool continuar = true;

    while (continuar) {
        mostrarSubMenu(subopcion);

        int tecla = _getch();
        switch (tecla) {
        case 72: // Flecha arriba
            subopcion = (subopcion - 1 + NUM_OPCIONES_SUBMENU) % NUM_OPCIONES_SUBMENU;
            break;
        case 80: // Flecha abajo
            subopcion = (subopcion + 1) % NUM_OPCIONES_SUBMENU;
            break;
        case 13: // Enter
            switch (subopcion) {
            case INGRESAR_DATOS:
                ingresarDatos(lista);
                break;
            case ORDENAR_LISTA: {
                int criterio = 0;
                bool continuarOrden = true;
                while (continuarOrden) {
                    mostrarMenuOrden(criterio);

                    int teclaOrden = _getch();
                    switch (teclaOrden) {
                    case 72: // Flecha arriba
                        criterio = (criterio - 1 + 5) % 5; // 5 opciones en el men? de ordenaci?n
                        break;
                    case 80: // Flecha abajo
                        criterio = (criterio + 1) % 5;
                        break;
                    case 13: // Enter
                        if (criterio == 4) {
                            continuarOrden = false;
                        }
                        else {
                            lista.ordenarBurbuja(criterio + 1); // Ajustar criterio seg?n implementaci?n
                        }
                        break;
                    }
                }
                break;
            }
            case IMPRIMIR_LISTA:
                lista.imprimir();
                cout << "Presione cualquier tecla para continuar...";
                _getch(); // Espera una tecla antes de continuar
                break;
            case ADICIONAL:
                menuAdicional(lista);
                break;
            case REGRESAR:
                continuar = false;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
            }
        }
    }
}

void MenuBurbujaMain() {
    Lista listaSimple(false, "Datos_Personas.txt");
    Lista listaDoble(false, "Datos_Personas.txt");
    Lista listaCircular(true, "Datos_Personas.txt");
    int opcion = 0;
    bool continuar = true;

    while (continuar) {
        mostrarMenu(opcion);

        int tecla = _getch();
        switch (tecla) {
        case 72: // Flecha arriba
            opcion = (opcion - 1 + NUM_OPCIONES) % NUM_OPCIONES;
            break;
        case 80: // Flecha abajo
            opcion = (opcion + 1) % NUM_OPCIONES;
            break;
        case 13: // Enter
            switch (opcion) {
            case LISTA_SIMPLE:
                subMenuListaBurbuja(listaSimple);
                break;
            case LISTA_DOBLE:
                subMenuListaBurbuja(listaDoble);
                break;
            case LISTA_CIRCULAR:
                subMenuListaBurbuja(listaCircular);
                break;
            case SALIR:
                continuar = false;
                cout << "Saliendo..." << endl;
                break;
            }
        }
    }
}