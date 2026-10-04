
#ifndef ARREGLOUSUARIOS_H
#define ARREGLOUSUARIOS_H

#include "../models/Usuario.h"


class ArregloUsuarios {

    Usuario** usuarios;
    int cantidad;
    int capacidad;
    int expansiones;


    bool expandir();
    void reducir();

public:

    ArregloUsuarios();
    ~ArregloUsuarios();

    bool agregar(Usuario* usuario);

    Usuario* buscarPorId(int id) const;

    bool eliminarPorId(int id);

    Usuario* obtener(int indice) const;

    int getCantidad() const;

    int getExpansiones() const;

    void liberar();
};

#endif
