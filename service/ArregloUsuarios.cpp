
#include "../include/service/ArregloUsuarios.h"

#include <cstdlib>



ArregloUsuarios::ArregloUsuarios() {
    cantidad = 0;
    expansiones = 0;
    capacidad = 2;
    usuarios = (Usuario**) malloc(capacidad * sizeof(Usuario*));
    if (usuarios == nullptr) {
        capacidad = 0;
    }
}

ArregloUsuarios::~ArregloUsuarios() {
    liberar();
}

bool ArregloUsuarios::expandir() {
    int nuevaCapacidad = (capacidad == 0) ? 2 : capacidad * 2;
    Usuario** nuevoArreglo = (Usuario**) realloc(usuarios, nuevaCapacidad * sizeof(Usuario*));
    if (nuevoArreglo == nullptr) {
        return false;
    }
    usuarios = nuevoArreglo;
    capacidad = nuevaCapacidad;
    expansiones++;
    return true;
}

void ArregloUsuarios::reducir() {
    if (capacidad > 2 && cantidad <= capacidad / 4) {
        int nuevaCapacidad = capacidad / 2;
        Usuario** nuevoArreglo = (Usuario**) realloc(usuarios, nuevaCapacidad * sizeof(Usuario*));
        if (nuevoArreglo != nullptr) {
            usuarios = nuevoArreglo;
            capacidad = nuevaCapacidad;
        }
    }
}

bool ArregloUsuarios::agregar(Usuario* usuario) {
    if (cantidad == capacidad) {
        if (!expandir()) {
            return false;
        }
    }
    usuarios[cantidad] = usuario;
    cantidad++;
    return true;
}

Usuario* ArregloUsuarios::buscarPorId(int id) const {
    for (int i = 0; i < cantidad; i++) {
        if (usuarios[i]->getId() == id) {
            return usuarios[i];
        }
    }
    return nullptr;
}

bool ArregloUsuarios::eliminarPorId(int id) {
    for (int i = 0; i < cantidad; i++) {
        if (usuarios[i]->getId() == id) {
            delete usuarios[i];
            for (int j = i; j < cantidad - 1; j++) {
                usuarios[j] = usuarios[j + 1];
            }
            cantidad--;
            reducir();
            return true;
        }
    }
    return false;
}

Usuario* ArregloUsuarios::obtener(int indice) const {
    if (indice < 0 || indice >= cantidad) {
        return nullptr;
    }
    return usuarios[indice];
}

int ArregloUsuarios::getCantidad() const {
    return cantidad;
}

int ArregloUsuarios::getExpansiones() const {
    return expansiones;
}

void ArregloUsuarios::liberar() {
    for (int i = 0; i < cantidad; i++) {
        delete usuarios[i];
    }
    free(usuarios);
    usuarios = nullptr;
    cantidad = 0;
    capacidad = 0;
}
