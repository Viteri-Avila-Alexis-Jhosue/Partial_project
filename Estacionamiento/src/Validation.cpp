/*
Universidad de las Fuerzas Armadas ESPE
Libreria para la validacion del ingreso de datos
Alexis Viteri
Fecha de creacion:  20/11/2024
Ultima fecha de modificacion:   05/12/2024
Estructura de Datos
NRC:  1978
*/
#include <iostream>
#include <conio.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stdexcept>
#include <regex>
#include <cmath>
#include <vector> 
#include "../include/Validation.h"

using namespace std;

char Validation::ingresarChar(const char* msj) {
    char c;
    printf("%s", msj);
    while (true) {
        c = getch();
        if (isalpha(c)) {
            printf("%c", c);
            return c;
        } else if (c == 8) {
            printf("\b \b");
        }
    }
}

int Validation::ingresarInt(const char* msj) {
    char* cad = new char[1]; 
    char c;
    int i = 0;
    int valor = 0;
    printf("%s", msj);
    while((c = getch()) != 13) {  
        if (c >= '0' && c <= '9') {
            printf("%c", c);
            cad[i++] = c;  
            cad = (char*)realloc(cad, (i + 1) * sizeof(char)); 
        } else if (c == 8) {  
            if (i > 0) {
                printf("\b \b");
                i--;
            }
        }
    }
    cad[i] = '\0';
    valor = atoi(cad);  
    delete[] cad;  
    return valor;
}

float Validation::ingresarFloat(const char* msj) {
    char* cad = new char[1];  
    char c;
    int i = 0;
    float valor = 0;
    printf("%s", msj);
    while((c = getch()) != 13) {  
        if (c >= '0' && c <= '9') {
            printf("%c", c);
            cad[i++] = c;  
            cad = (char*)realloc(cad, (i + 1) * sizeof(char));  
        } else if (c == 8) {  
            if (i > 0) {
                printf("\b \b");
                i--;
            }
        } else if (c == 46) {  
            bool aux = false;
            for (int j = 0; cad[j] != '\0'; j++) {
                if (cad[j] == 46) {
                    aux = true;
                    break;
                }
            }
            if(aux == false) {
                printf("%c", c);
                cad[i++] = c;
                cad = (char*)realloc(cad, (i + 1) * sizeof(char));  
            }
        }
    }
    cad[i++] = '\0';
    valor = atof(cad);  
    delete[] cad;  
    return valor;
}

double Validation::ingresarDouble(const char* msj) {
    char* cad = new char[1];  
    char c;
    int i = 0;
    double valor = 0;
    bool puntoDecimal = false;
    printf("%s", msj);
    while((c = getch()) != 13) {  
        if (c >= '0' && c <= '9') {
            printf("%c", c);
            cad[i++] = c;  
            cad = (char*)realloc(cad, (i + 1) * sizeof(char));  
        } else if (c == 8) {  
            if (i > 0) {
                printf("\b \b");
                i--;
            }
        } else if (c == '.' && !puntoDecimal) {
            puntoDecimal = true;
            printf("%c", c);
            cad[i++] = c;
            cad = (char*)realloc(cad, (i + 1) * sizeof(char));  
        }
    }
    cad[i] = '\0';
    valor = atof(cad);  
    delete[] cad;  
    return valor;
}

string Validation::ingresarString(const char *msj) {
    char* cad = new char[1];  
    char c;
    int i = 0;
    string cadena1;
    printf("%s", msj);
    while ((c = getch()) != 13) {  
        if (isalpha(c)) {
            printf("%c", c);
            cad[i++] = c;  
            cad = (char*)realloc(cad, (i + 1) * sizeof(char));  
        } else if (c == 8) {  
            if (i > 0) {
                printf("\b \b");
                i--;
            }
        }
    }
    cad[i] = '\0';
    cadena1 = cad;  
    delete[] cad;  
    return cadena1;
}

string Validation::ingresarStringConEspacios(const char* msj) {
    char* cad = new char[1]; 
    char c;
    int i = 0;
    string cadena1;
    printf("%s", msj);
    
    while ((c = getch()) != 13) {  // 13 es el código de enter
        if (isalpha(c) || isspace(c)) {  // Permitir letras y espacios
            printf("%c", c);
            cad[i++] = c;  
            cad = (char*)realloc(cad, (i + 1) * sizeof(char));  
        } else if (c == 8) {  // 8 es el código para la tecla backspace
            if (i > 0) {
                printf("\b \b");
                i--;
            }
        }
    }
    
    cad[i] = '\0';  
    cadena1 = cad;  
    delete[] cad;  
    return cadena1;  
}
void Validation::validateId(int id) {
    string idStr = to_string(id);

    while (idStr.length() < 10) idStr = "0" + idStr; // Agregar ceros iniciales si faltan

    if (idStr.length() != 10) {
        throw invalid_argument("Cedula Invalida");
    }

    int provincia = stoi(idStr.substr(0, 2));
    if (provincia < 1 || provincia > 24) {
        throw invalid_argument("Cedula Invalida");
    }

    int total = 0;
    for (int i = 0; i < 9; i++) {
        int digit = idStr[i] - '0';
        if (i % 2 == 0) { // Posiciones impares
            digit *= 2;
            if (digit > 9) digit -= 9;
        }
        total += digit;
    }

    int verificador = idStr[9] - '0';
    int residuo = total % 10;
    int resultado = residuo == 0 ? 0 : 10 - residuo;

    if (verificador != resultado) {
        throw invalid_argument("Cedula Invalida");
    }
}

void Validation::validateEmail(const string& email) {
    regex emailPattern(R"((\w+)(\.\w+)*@(\w+\.)+\w{2,})");
    if (!regex_match(email, emailPattern)) {
        throw invalid_argument("Correo no valido");
    }
}
void Validation::validateCellPhone(const string& cellPhone) {
    // Verifica que el número tenga 10 dígitos y que comience con '0'
    if (cellPhone.length() != 10 || cellPhone[0] != '0') {
        throw invalid_argument("Numero no valido");
    }
    // Validación con expresión regular para asegurarse de que el formato es correcto
    regex phonePattern(R"(^0\d{9}$)");
    if (!regex_match(cellPhone, phonePattern)) {
        throw invalid_argument("Numero no valido");
    }
}

void Validation::validateCellPhone(int cellPhone) {
    // Convierte el número entero a una cadena de texto
    string phoneStr = to_string(cellPhone);

    // Si el número tiene menos de 10 dígitos, lo completamos con ceros a la izquierda
    while (phoneStr.length() < 10) {
        phoneStr = "0" + phoneStr; // Agrega ceros a la izquierda
    }

    // Llamamos a la validación de string, que ya no pierde los ceros
    validateCellPhone(phoneStr);
}
void Validation::ingresarTelefono(string& telefono) {
    char c;
    telefono.clear();  // Limpiar el teléfono al comenzar

    while (telefono.length() < 10) {
        c = getch();  // Lee un carácter desde la entrada (sin necesidad de presionar Enter)
        
        // Aceptamos solo números del 0 al 9
        if (c >= '0' && c <= '9') {
            cout << c;  // Imprime el carácter
            telefono += c;  // Añade el número a la cadena
        }
        // Permitir retroceso (eliminar el último carácter ingresado)
        else if (c == 8 && telefono.length() > 0) {
            cout << "\b \b";  // Elimina el carácter en pantalla
            telefono.pop_back();  // Elimina el último carácter de la cadena
        }
    }

    // Una vez completados 10 caracteres, verificamos si es válido
    if (telefono.length() != 10 || telefono[0] != '0') {
        throw invalid_argument("");
    }
    
    cout << endl;  // Nueva línea después de completar la entrada
}
