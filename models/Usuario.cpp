#include "../include/models/Usuario.h"

Usuario::Usuario(int idUsuario, const std::string& nombreUsuario) {
    id = idUsuario;
    nombre = nombreUsuario;
}

int Usuario::getId() const {
    return id;
}

std::string Usuario::getNombre() const {
    return nombre;
}

void Usuario::setNombre(const std::string& nuevoNombre) {
    nombre = nuevoNombre;
}
