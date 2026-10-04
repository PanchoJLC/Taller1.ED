
#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
    int id;
    std::string nombre;

public:

    Usuario(int idUsuario, const std::string& nombreUsuario);

    int getId() const;

    std::string getNombre() const;

    void setNombre(const std::string& nuevoNombre);
};

#endif
