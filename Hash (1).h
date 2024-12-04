#pragma once
#include<iostream>

#ifndef HASH_H
#define HASH_H

//Esto es del grupo por el emtodo de distribucion
template<typename U>
typename std::enable_if<std::is_same<U, std::string>::value, int>::type
calcularIndice(U valor, int cant) {
    std::hash<std::string> hash_fn;
    size_t hash = hash_fn(valor);
    int index = hash % cant;
    std::cout << "Hash " << valor << ":" << index << std::endl;
    return index;
}

#endif // HASH_H