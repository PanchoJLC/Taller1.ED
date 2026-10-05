
#ifndef ARREGLOUSUARIOS_H
#define ARREGLOUSUARIOS_H

#include "../models/Usuario.h"


class ArregloUsuarios {
    //Atributos de la clase ARREGLO DE USUARIOS
    Usuario** usuarios;
    int cantidad;
    int capacidad;
    int expansiones;

    //Funciones de la clase ARREGLO DE USUARIOS
    bool expandir();
    void reducir();

public:
    //Constructor y Destructor de la clase ARREGLO DE USUARIOS
    ArregloUsuarios();
    ~ArregloUsuarios();
    //Agrega un usuario
    bool agregar(Usuario* usuario);
    //Busca usuario por ID
    Usuario* buscarPorId(int id) const;
    //Elimina usuario dependiendo del ID que se ingrese
    bool eliminarPorId(int id);
    //Se obtiene el usuario dependiendo del indice ingresado
    Usuario* obtener(int indice) const;
    //Se obtiene la cantidad de usuarios en el arreglo
    int getCantidad() const;
    //Se obtiene las expansiones requeridas
    int getExpansiones() const;
    //Se libera memoria
    void liberar();
};

#endif
