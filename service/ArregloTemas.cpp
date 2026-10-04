
#include "../include/service/ArregloTemas.h"
#include <cstdlib>

ArregloTemas::ArregloTemas() {
    cantidad = 0;
    capacidad = 5;
    temas = (Tema**) malloc(capacidad * sizeof(Tema*));
    if (temas == nullptr) {
        capacidad = 0;
    }
}

ArregloTemas::~ArregloTemas() {
    liberar();
}

bool ArregloTemas::expandir() {
    int nuevaCapacidad = (capacidad == 0) ? 5 : capacidad * 2;
    Tema** nuevoArreglo = (Tema**) realloc(temas, nuevaCapacidad * sizeof(Tema*));
    if (nuevoArreglo == nullptr) {
        return false;
    }
    temas = nuevoArreglo;
    capacidad = nuevaCapacidad;
    return true;
}

bool ArregloTemas::agregarAlInicio(Tema* tema) {
    if (cantidad == capacidad) {
        if (!expandir()) {
            return false;
        }
    }
    for (int i = cantidad; i > 0; i--) {
        temas[i] = temas[i - 1];
    }
    temas[0] = tema;
    cantidad++;
    return true;
}

bool ArregloTemas::agregarAlFinal(Tema* tema) {
    if (cantidad == capacidad) {
        if (!expandir()) {
            return false;
        }
    }
    temas[cantidad] = tema;
    cantidad++;
    return true;
}

int ArregloTemas::buscarIndicePorId(const std::string& id) const {
    for (int i = 0; i < cantidad; i++) {
        if (temas[i]->getId() == id) {
            return i;
        }
    }
    return -1;
}

void ArregloTemas::moverAlInicio(int indice) {
    if (indice <= 0 || indice >= cantidad) {
        return;
    }
    Tema* tema = temas[indice];
    for (int i = indice; i > 0; i--) {
        temas[i] = temas[i - 1];
    }
    temas[0] = tema;
}

void ArregloTemas::eliminarEn(int indice) {
    if (indice < 0 || indice >= cantidad) {
        return;
    }
    delete temas[indice];
    for (int i = indice; i < cantidad - 1; i++) {
        temas[i] = temas[i + 1];
    }
    cantidad--;
}

Tema* ArregloTemas::obtener(int indice) const {
    if (indice < 0 || indice >= cantidad) {
        return nullptr;
    }
    return temas[indice];
}

int ArregloTemas::getCantidad() const {
    return cantidad;
}

void ArregloTemas::liberar() {
    for (int i = 0; i < cantidad; i++) {
        delete temas[i];
    }
    free(temas);
    temas = nullptr;
    cantidad = 0;
    capacidad = 0;
}
