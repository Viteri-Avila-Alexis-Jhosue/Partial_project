#include "ArbolAA.h"
#include <iostream>
#include<vector>
#include<unordered_set>
#include<string>
#include<Windows.h>
#include<algorithm>
#undef min;

ArbolAA::ArbolAA() : root(nullptr) {}

ArbolAA::~ArbolAA() {
    destroyTree(root);
}

void ArbolAA::destroyTree(NodoArbolAA* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

NodoArbolAA* ArbolAA::skew(NodoArbolAA* node) {
    if (!node || !node->left) return node;
    if (node->left->level == node->level) {
        NodoArbolAA* left = node->left;
        node->left = left->right;
        left->right = node;
        return left;
    }
    return node;
}

NodoArbolAA* ArbolAA::split(NodoArbolAA* node) {
    if (!node || !node->right || !node->right->right) return node;
    if (node->right->right->level == node->level) {
        NodoArbolAA* right = node->right;
        node->right = right->left;
        right->left = node;
        right->level++;
        return right;
    }
    return node;
}

std::string ArbolAA::getFieldValue(const Persona& persona, const std::string& field) {
    if (field == "nombre") {
        return persona.getNombre();
    }
    else if (field == "segundoNombre") {
        return persona.getSegundoNombre();
    }
    else if (field == "apellido") {
        return persona.getApellido();
    }
    else if (field == "cedula") {
        return persona.getCedula();
    }
    else if (field == "correo") {
        return persona.getCorreo();
    }
    else if (field == "contrasenaInicial") {
        return persona.getContrasenaInicial();
    }
    else if (field == "contrasena") {
        return persona.getContrasena();
    }
    return "";
}

NodoArbolAA* ArbolAA::insert(NodoArbolAA* node, const Persona& data) {
    if (!node) return new NodoArbolAA(data);
    if (data.getCedula() < node->data.getCedula()) {
        node->left = insert(node->left, data);
    }
    else if (data.getCedula() > node->data.getCedula()) {
        node->right = insert(node->right, data);
    }
    node = skew(node);
    node = split(node);
    return node;
}

void ArbolAA::insert(const Persona& data) {
    root = insert(root, data);
    balanceTree(root);
}

NodoArbolAA* ArbolAA::remove(NodoArbolAA* node, const std::string& key, const std::string& field) {
    if (!node) return nullptr;

    std::string nodeValue;
    if (field == "nombre") {
        nodeValue = node->data.getNombre();
    }
    else if (field == "segundoNombre") {
        nodeValue = node->data.getSegundoNombre();
    }
    else if (field == "apellido") {
        nodeValue = node->data.getApellido();
    }
    else if (field == "cedula") {
        nodeValue = node->data.getCedula();
    }
    else if (field == "correo") {
        nodeValue = node->data.getCorreo();
    }
    else if (field == "contrasenaInicial") {
        nodeValue = node->data.getContrasenaInicial();
    }
    else if (field == "contrasena") {
        nodeValue = node->data.getContrasena();
    }

    if (key < nodeValue) {
        node->left = remove(node->left, key, field);
    }
    else if (key > nodeValue) {
        node->right = remove(node->right, key, field);
    }
    else {
        if (!node->left || !node->right) {
            NodoArbolAA* temp = node->left ? node->left : node->right;
            delete node;
            return temp;
        }
        else {
            NodoArbolAA* temp = node->right;
            while (temp->left) temp = temp->left;
            node->data = temp->data;
            node->right = remove(node->right, temp->data.getCedula(), "cedula");
        }
    }

    node = skew(node);
    node = split(node);
    return node;
}

void ArbolAA::remove(const std::string& key, const std::string& field) {
    root = remove(root, key, field);
    balanceTree(root);
}

void ArbolAA::printInOrder(NodoArbolAA* node) {
    if (!node) return;
    printInOrder(node->left);
    std::cout << node->data << " ";
    printInOrder(node->right);
}

void ArbolAA::printInOrder() {
    printInOrder(root);
    std::cout << std::endl;
}

int ArbolAA::calculateHeight(NodoArbolAA* node) {
    if (!node) return 0;
    int leftHeight = calculateHeight(node->left);
    int rightHeight = calculateHeight(node->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int ArbolAA::getHeight() {
    return calculateHeight(root);
}

int ArbolAA::calculateDepth(NodoArbolAA* node, const std::string& key, int depth, const std::string& field) {
    if (!node) return -1;

    std::string nodeValue;
    if (field == "nombre") {
        nodeValue = node->data.getNombre();
    }
    else if (field == "segundoNombre") {
        nodeValue = node->data.getSegundoNombre();
    }
    else if (field == "apellido") {
        nodeValue = node->data.getApellido();
    }
    else if (field == "cedula") {
        nodeValue = node->data.getCedula();
    }
    else if (field == "correo") {
        nodeValue = node->data.getCorreo();
    }
    else if (field == "contrasenaInicial") {
        nodeValue = node->data.getContrasenaInicial();
    }
    else if (field == "contrasena") {
        nodeValue = node->data.getContrasena();
    }

    if (nodeValue == key) return depth;
    int leftDepth = calculateDepth(node->left, key, depth + 1, field);
    if (leftDepth != -1) return leftDepth;
    return calculateDepth(node->right, key, depth + 1, field);
}

int ArbolAA::getDepth(const std::string& key, const std::string& field) {
    return calculateDepth(root, key, 0, field);
}

void ArbolAA::printLevels(NodoArbolAA* node, int level) {
    if (node) {
        std::cout << "Nivel " << level << ": " << node->data << std::endl;
        printLevels(node->left, level + 1);
        printLevels(node->right, level + 1);
    }
}

void ArbolAA::printLevels() {
    printLevels(root, 0);
}

int ArbolAA::countLeaves(NodoArbolAA* node) {
    if (!node) return 0;
    if (!node->left && !node->right) return 1;
    return countLeaves(node->left) + countLeaves(node->right);
}

int ArbolAA::countLeaves() {
    return countLeaves(root);
}

bool ArbolAA::isBalanced(NodoArbolAA* node) {
    if (!node) return true;
    int leftHeight = calculateHeight(node->left);
    int rightHeight = calculateHeight(node->right);
    return abs(leftHeight - rightHeight) <= 1 && isBalanced(node->left) && isBalanced(node->right);
}

bool ArbolAA::isBalanced() {
    return isBalanced(root);
}

void ArbolAA::traversePreOrder(NodoArbolAA* node) {
    if (node) {
        std::cout << node->data << " ";
        traversePreOrder(node->left);
        traversePreOrder(node->right);
    }
}

void ArbolAA::traversePreOrder() {
    traversePreOrder(root);
    std::cout << std::endl;
}

void ArbolAA::traverseInOrder(NodoArbolAA* node) {
    if (node) {
        traverseInOrder(node->left);
        std::cout << node->data << " ";
        traverseInOrder(node->right);
    }
}

void ArbolAA::traverseInOrder() {
    traverseInOrder(root);
    std::cout << std::endl;
}

void ArbolAA::traversePostOrder(NodoArbolAA* node) {
    if (node) {
        traversePostOrder(node->left);
        traversePostOrder(node->right);
        std::cout << node->data << " ";
    }
}

void ArbolAA::traversePostOrder() {
    traversePostOrder(root);
    std::cout << std::endl;
}

void ArbolAA::cargarDesdeArchivo(const std::string& nombreArchivo) {
    Lista lista(false, nombreArchivo);
    vector<Persona> personas = lista.leerArchivo();

    for (const auto& persona : personas) {
        insert(persona);
    }
}

void ArbolAA::printWithRelations(NodoArbolAA* node, const std::string& field, const std::string& relation) {
    if (node) {
        std::cout << relation << ": " << getFieldValue(node->data, field) << std::endl;
        printWithRelations(node->left, field, "Hijo izquierdo de " + getFieldValue(node->data, field));
        printWithRelations(node->right, field, "Hijo derecho de " + getFieldValue(node->data, field));
    }
}

void ArbolAA::printTreeWithRelations(const std::string& field) {
    printWithRelations(root, field, "Raíz");
}

void ArbolAA::contarAbuelos(NodoArbolAA* node, std::unordered_set<std::string>& abuelos) {
    if (!node) return;

    if ((node->left && (node->left->left || node->left->right)) ||
        (node->right && (node->right->left || node->right->right))) {
        abuelos.insert(node->data.getCedula());
        std::cout << "Abuelo encontrado: " << node->data.getCedula() << std::endl; // Imprime el abuelo encontrado
    }

    contarAbuelos(node->left, abuelos);
    contarAbuelos(node->right, abuelos);
}

int ArbolAA::contarAbuelosUnicos() {
    std::unordered_set<std::string> abuelos;
    contarAbuelos(root, abuelos);
    std::cout << "Número de abuelos únicos: " << abuelos.size() << std::endl;
    return abuelos.size();
}

void ArbolAA::balanceTree(NodoArbolAA*& node) {
    if (!node) return;
    node = skew(node);
    node = split(node);
    balanceTree(node->left);
    balanceTree(node->right);
}

void ArbolAA::checkAndBalance() {
    if (!isBalanced()) {
        balanceTree(root);
        std::cout << "El árbol se ha balanceado automáticamente." << std::endl;
    }
    else {
        std::cout << "El árbol ya está balanceado." << std::endl;
    }
}

std::wstring convertStringToWString(const std::string& str) {
    return std::wstring(str.begin(), str.end());
}

void ArbolAA::Dibujar(HDC hdc, NodoArbolAA* nodo, int x, int y, int offsetX, int offsetY, int depth) {
    if (nodo == nullptr) return;

    HFONT hFont = CreateFont(20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
        CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Arial"));
    HFONT oldFont = (HFONT)SelectObject(hdc, hFont);

    std::wstring texto = L"[";
    texto += convertStringToWString(nodo->data.getCedula());
    texto += L"]";

    SIZE textSize;
    GetTextExtentPoint32W(hdc, texto.c_str(), texto.length(), &textSize);

    int nodoAncho = textSize.cx + 20;
    int nodoAlto = textSize.cy + 10;

    RECT rect;
    rect.left = x - nodoAncho / 2; // Centrando el nodo en la coordenada x
    rect.top = y;
    rect.right = rect.left + nodoAncho;
    rect.bottom = y + nodoAlto;

    Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
    DrawTextW(hdc, texto.c_str(), -1, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    int childY = y + offsetY;

    // Calcular las posiciones de los hijos equitativamente
    int totalChildren = (nodo->left ? 1 : 0) + (nodo->right ? 1 : 0);
    int childStartX = x - (totalChildren - 1) * (offsetX / 2);

    if (nodo->left) {
        int childX = childStartX;
        MoveToEx(hdc, rect.left + nodoAncho / 2, rect.bottom, NULL);
        LineTo(hdc, childX, childY);
        Dibujar(hdc, nodo->left, childX, childY, offsetX / 2, offsetY, depth + 1);
    }

    if (nodo->right) {
        int childX = childStartX + offsetX;
        MoveToEx(hdc, rect.left + nodoAncho / 2, rect.bottom, NULL);
        LineTo(hdc, childX, childY);
        Dibujar(hdc, nodo->right, childX, childY, offsetX / 2, offsetY, depth + 1);
    }

    SelectObject(hdc, oldFont);
    DeleteObject(hFont);
}

void ArbolAA::DibujarArbolAA(HDC hdc, int offsetX, int offsetY, double zoomFactor) {
    if (root != nullptr) {
        int startX = static_cast<int>(800 * zoomFactor) + offsetX; // Coordenada X inicial con zoom y offset
        int startY = static_cast<int>(50 * zoomFactor) + offsetY;  // Coordenada Y inicial con zoom y offset
        int nodeOffsetX = static_cast<int>(300 * zoomFactor); // Espaciado inicial más amplio con zoom
        int nodeOffsetY = static_cast<int>(100 * zoomFactor); // Espaciado vertical con zoom

        Dibujar(hdc, root, startX, startY, nodeOffsetX, nodeOffsetY, 0);
    }
}

Persona* ArbolAA::buscarCedulaFibonacci(const std::string& cedula) {
    if (!root) return nullptr;

    std::vector<NodoArbolAA*> nodes;
    std::function<void(NodoArbolAA*)> inorder = [&](NodoArbolAA* node) {
        if (!node) return;
        inorder(node->left);
        nodes.push_back(node);
        inorder(node->right);
        };
    inorder(root);

    int n = nodes.size();
    int fibMm2 = 0;  // (m-2)'th Fibonacci No.
    int fibMm1 = 1;  // (m-1)'th Fibonacci No.
    int fibM = fibMm2 + fibMm1;  // m'th Fibonacci

    while (fibM < n) {
        fibMm2 = fibMm1;
        fibMm1 = fibM;
        fibM = fibMm2 + fibMm1;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = std::min(offset + fibMm2, n - 1);

        if (nodes[i]->data.getCedula() < cedula) {
            fibM = fibMm1;
            fibMm1 = fibMm2;
            fibMm2 = fibM - fibMm1;
            offset = i;
        }
        else if (nodes[i]->data.getCedula() > cedula) {
            fibM = fibMm2;
            fibMm1 = fibMm1 - fibMm2;
            fibMm2 = fibM - fibMm1;
        }
        else {
            return &(nodes[i]->data);
        }
    }

    if (fibMm1 && nodes[offset + 1]->data.getCedula() == cedula) {
        return &(nodes[offset + 1]->data);
    }

    return nullptr;
}