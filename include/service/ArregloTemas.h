
#ifndef ARREGLOTEMAS_H
#define ARREGLOTEMAS_H

#include "../models/Tema.h"
#include <string>

class ArregloTemas {

    Tema** temas;
    int cantidad;
    int capacidad;

    bool expandir();

public:

    ArregloTemas();
    ~ArregloTemas();

    bool agregarAlInicio(Tema* tema);
    bool agregarAlFinal(Tema* tema);
    int buscarIndicePorId(const std::string& id) const;
    void moverAlInicio(int indice);
    void eliminarEn(int indice);
    Tema* obtener(int indice) const;
    int getCantidad() const;
    void liberar();
};

#endif
