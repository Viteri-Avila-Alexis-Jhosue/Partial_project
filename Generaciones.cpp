#include "Generaciones.h"
#include<sstream>
#include<iomanip>
#include<vector>

std::string generarCorreo(Nodo* cabeza, Persona& persona, bool esCircular) {
    Nodo* auxiliar = cabeza;
    std::string inicialesNombre = "";
    inicialesNombre.push_back(tolower(persona.nombre[0]));
    if (!persona.segundoNombre.empty()) {
        inicialesNombre.push_back(tolower(persona.segundoNombre[0]));
    }
    std::string correo = inicialesNombre + persona.apellido;
    std::string correoBase = correo;
    int contador = 0;

    while (auxiliar != nullptr) {
        if (auxiliar->dato.getCorreo() == correo) {
            contador++;
            correo = correoBase + std::to_string(contador);
        }
        auxiliar = auxiliar->siguiente;
        if (esCircular && auxiliar == cabeza) break;
    }

    return correo;
}

std::string generarContrasena(Persona& persona) {
    static bool primerUsuario = true;
    static int contador = 1;

    std::string apellido = persona.apellido;
    std::string primerNombre = persona.nombre;
    std::string segundoNombre = persona.segundoNombre;

    char ultimaLetraApellido = tolower(apellido.back());
    char primeraLetraPrimerNombre = tolower(primerNombre.front());
    char ultimaLetraSegundoNombre = !segundoNombre.empty() ? tolower(segundoNombre.back()) : '\0';

    std::string restoApellido = apellido.substr(0, apellido.size() - 1);
    std::reverse(restoApellido.begin(), restoApellido.end());
    std::transform(restoApellido.begin(), restoApellido.end(), restoApellido.begin(), ::tolower);

    std::string contrasenaBase = std::string(1, ultimaLetraApellido) + primeraLetraPrimerNombre;
    if (ultimaLetraSegundoNombre != '\0') {
        contrasenaBase += ultimaLetraSegundoNombre;
    }
    contrasenaBase += restoApellido;

    std::string contrasenaEncriptada = "";

    int shift = 2;
    for (char c : contrasenaBase) {
        if (isalnum(c)) {
            char base = (isdigit(c) ? '0' : (isupper(c) ? 'A' : 'a'));
            char encryptedChar = (c - base + shift) % 26 + base;
            contrasenaEncriptada += encryptedChar;
        }
        else {
            contrasenaEncriptada += c;
        }
    }

    if (!primerUsuario) {
        contrasenaBase += std::to_string(contador);
        contador++;
    }

    primerUsuario = false;

    persona.setContrasena(contrasenaEncriptada);
    persona.setContrasenaInicial(contrasenaBase);
    return contrasenaEncriptada;
}

std::string desencriptarContrasena(Persona& persona) {
    std::string contrasenaBase = persona.getContrasenaInicial();
    std::string contrasenaDesencriptada = "";

    int shift = 2;
    for (char c : persona.getContrasena()) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            char decryptedChar = (c - base - shift + 26) % 26 + base;
            contrasenaDesencriptada += decryptedChar;
        }
        else {
            contrasenaDesencriptada += c;
        }
    }

    return contrasenaDesencriptada;
}

void contarVocalesYConsonantesRec(Nodo* nodo, int& vocales, int& consonantes) {
    if (nodo == nullptr) return;


    std::string nombreCompleto = nodo->dato.nombre + nodo->dato.segundoNombre + nodo->dato.apellido;
    for (char c : nombreCompleto) {
        c = std::tolower(c);
        if (std::isalpha(c)) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vocales++;
            }
            else {
                consonantes++;
            }
        }
    }
    contarVocalesYConsonantesRec(nodo->siguiente, vocales, consonantes);
}

void contarVocalesYConsonantes(Nodo* nodo, int& vocales, int& consonantes) {
    vocales = 0;
    consonantes = 0;
    contarVocalesYConsonantesRec(nodo, vocales, consonantes);
}

// Definición de constantes para SHA-1
const unsigned int SHA1_K[4] = { 0x5A827999, 0x6ED9EBA1, 0x8F1BBCDC, 0xCA62C1D6 };

// Función auxiliar para la rotación de bits
unsigned int leftRotate(unsigned int value, unsigned int bits) {
    return (value << bits) | (value >> (32 - bits));
}

std::string encriptarSHA1(const std::string& input) {
    std::vector<unsigned int> hash = { 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0 };

    // Preparar el mensaje
    std::vector<unsigned char> paddedMessage(input.begin(), input.end());
    paddedMessage.push_back(0x80);
    while ((paddedMessage.size() % 64) != 56) {
        paddedMessage.push_back(0x00);
    }

    // Añadir longitud del mensaje original en bits
    unsigned long long originalLength = input.size() * 8;
    for (int i = 7; i >= 0; --i) {
        paddedMessage.push_back(static_cast<unsigned char>((originalLength >> (i * 8)) & 0xFF));
    }

    // Procesar en bloques de 512 bits (64 bytes)
    for (size_t i = 0; i < paddedMessage.size(); i += 64) {
        unsigned int w[80];
        for (int j = 0; j < 16; ++j) {
            w[j] = (paddedMessage[i + 4 * j] << 24) |
                (paddedMessage[i + 4 * j + 1] << 16) |
                (paddedMessage[i + 4 * j + 2] << 8) |
                (paddedMessage[i + 4 * j + 3]);
        }

        for (int j = 16; j < 80; ++j) {
            w[j] = leftRotate(w[j - 3] ^ w[j - 8] ^ w[j - 14] ^ w[j - 16], 1);
        }

        unsigned int a = hash[0];
        unsigned int b = hash[1];
        unsigned int c = hash[2];
        unsigned int d = hash[3];
        unsigned int e = hash[4];

        for (int j = 0; j < 80; ++j) {
            unsigned int f, k;
            if (j < 20) {
                f = (b & c) | ((~b) & d);
                k = SHA1_K[0];
            }
            else if (j < 40) {
                f = b ^ c ^ d;
                k = SHA1_K[1];
            }
            else if (j < 60) {
                f = (b & c) | (b & d) | (c & d);
                k = SHA1_K[2];
            }
            else {
                f = b ^ c ^ d;
                k = SHA1_K[3];
            }

            unsigned int temp = leftRotate(a, 5) + f + e + k + w[j];
            e = d;
            d = c;
            c = leftRotate(b, 30);
            b = a;
            a = temp;
        }

        hash[0] += a;
        hash[1] += b;
        hash[2] += c;
        hash[3] += d;
        hash[4] += e;
    }

    std::ostringstream result;
    for (unsigned int h : hash) {
        result << std::hex << std::setw(8) << std::setfill('0') << h;
    }
    return result.str();
}