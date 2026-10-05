#include "../include/models/Usuario.h"

Usuario::Usuario(int idUsuario, const std::string& nombreUsuario) {
    id = idUsuario;
    nombre = nombreUsuario;
}
// Arroja el ID del usuario
int Usuario::getId() const {
    return id;
}
//  Arroja el nombre del usuario
std::string Usuario::getNombre() const {
    return nombre;
}
// Coloca el nombre al usuario
void Usuario::setNombre(const std::string& nuevoNombre) {
    nombre = nuevoNombre;
}
