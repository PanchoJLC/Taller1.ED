
#ifndef FORO_H
#define FORO_H


#include "../service/ArregloUsuarios.h"
#include "../service/ArregloTemas.h"
#include "../models/Usuario.h"
#include "../models/Tema.h"
#include <string>


class Foro {
    // Atributos de la clase FORO
    ArregloUsuarios usuarios;
    ArregloTemas temas;
    Usuario* usuarioActual;
    std::string rutaTemas;
    // Muestra el menu de acciones para el usuario en el programa
    void mostrarMenuPrincipal() const;
    // Revisa si el ID ingresado esta en registro para su ingreso al foro
    void autenticar();
    // Permite visualizar temas dependiendo del ID que se ingrese
    void revisarTema();
    // Muestra los temas mas recientes
    void mostrarTema(const Tema* tema) const;
    // Permite comentar temas
    void comentar(Tema* tema);
    // Permite elimianar un usuario dependiendo de su ID
    void eliminarUsuario();
    // Permite publicar un tema y agregarlo al arreglo
    void publicarTema();
    // Muestra las estadisticas del foro
    void mostrarEstadisticas() const;
    // Sale del foro y por ende del sistema
    void salir();
    // Genera un ID aleatorio para el tema
    std::string generarIdTema() const;
    // Permite visualizar el nombre del usuario dependiendo del ID que se ingrese
    std::string obtenerNombreUsuario(int id) const;
    // Permite saber cuantas respuestas tiene un tema
    int contarRespuestasDeUsuario(int id) const;

public:
    Foro();
    //Carga los datos de los archivos de texto para su uso en el programa
    bool cargarDatos(const std::string& rutaUsuarios, const std::string& rutaArchivoTemas);
    // Da inicio a la ejecucion del programa
    void ejecutar();
};



#endif
