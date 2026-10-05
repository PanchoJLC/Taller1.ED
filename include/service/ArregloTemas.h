
#ifndef ARREGLOTEMAS_H
#define ARREGLOTEMAS_H

#include "../models/Tema.h"
#include <string>

class ArregloTemas {
    //Atributos de la clase ARREGLO TEMAS
    Tema** temas;
    int cantidad;
    int capacidad;
    //Funciones de la clase ARREGLO TEMAS
    bool expandir();

public:
    //Constructor y Destructor de la clase ARREGLO TEMAS
    ArregloTemas();
    ~ArregloTemas();
    // Agrega temas al inicio del arreglo
    bool agregarAlInicio(Tema* tema);
    // Agrega tema al final del arreglo
    bool agregarAlFinal(Tema* tema);
    // Busca un tema dependiendo del ID ingresado
    int buscarIndicePorId(const std::string& id) const;
    // Funcion que mueve al inicio de los temas
    void moverAlInicio(int indice);
    // Elimina tema dependiendo del indice ingresado
    void eliminarEn(int indice);
    // Muestra en pantalla el tema dependiendo del indice ingresado
    Tema* obtener(int indice) const;
    // Muestra la cantidad de temas en el arreglo
    int getCantidad() const;
    // Libera memoria
    void liberar();
};

#endif
