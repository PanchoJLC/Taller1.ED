
#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
    // Atributos de la clase USUARIO
    int id;
    std::string nombre;

public:
    // Constructor de la clase USUARIO
    Usuario(int idUsuario, const std::string& nombreUsuario);
    // Obtienes el ID del USUARIO
    int getId() const;
    // Obtienes el nombre del USUARIO
    std::string getNombre() const;
    // Colocas el nombre al USUARIO
    void setNombre(const std::string& nuevoNombre);
};

#endif
