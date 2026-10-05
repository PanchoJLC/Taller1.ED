
#ifndef FORO_H
#define FORO_H


#include "../service/ArregloUsuarios.h"
#include "../service/ArregloTemas.h"
#include "../models/Usuario.h"
#include "../models/Tema.h"
#include <string>


class Foro {
    ArregloUsuarios usuarios;
    ArregloTemas temas;
    Usuario* usuarioActual;
    std::string rutaTemas;

    void mostrarMenuPrincipal() const;
    void autenticar();
    void revisarTema();
    void mostrarTema(const Tema* tema) const;
    void comentar(Tema* tema);
    void eliminarUsuario();
    void publicarTema();
    void mostrarEstadisticas() const;
    void salir();
    std::string generarIdTema() const;
    std::string obtenerNombreUsuario(int id) const;
    int contarRespuestasDeUsuario(int id) const;

public:
    Foro();
    bool cargarDatos(const std::string& rutaUsuarios, const std::string& rutaArchivoTemas);
    void ejecutar();
};



#endif
