
#ifndef TEMA_H
#define TEMA_H

#include <string>
#include "Respuesta.h"

class Tema {
    //  Atributos de la clase TEMA
    std::string id;
    std::string titulo;
    std::string contenido;
    int idUsuario;
    Respuesta* primeraRespuesta;

public:
    //  Constructor y Destructor de TEMA
    Tema(const std::string& idTema, const std::string& tituloTema,
         const std::string& contenidoTema, int idAutor);

    ~Tema();
    // Obtiene el ID del TEMA
    std::string getId() const;
    // Obtiene el titulo del TEMA
    std::string getTitulo() const;
    // Obtiene el contenido de TEMA
    std::string getContenido() const;
    // Obtiene el ID del usuario
    int getIdUsuario() const;
    // Obtiene la primera respuesta del TEMA a traves de punteros
    Respuesta* getPrimeraRespuesta() const;
    // Agrega la respuesta al tema de los primeros lugares
    void agregarRespuestaAlInicio(Respuesta* nueva);
    // Agrega la respuesta al tema de los ultimos lugares
    void agregarRespuestaAlFinal(Respuesta* nueva);
    // Cuenta cuantas respuesta hay para poder entregar la cantidad
    int contarRespuestas() const;
    // Cuenta cuantas respuestas hay en el TEMA dependiendo del ID del autor
    int contarRespuestasDeUsuario(int idAutor) const;
    // Elimina respuesta del usuario dependiendo del ID del usuario que lo hizo
    int eliminarRespuestasDeUsuario(int idAutor);
    // Obtienes la siguiente respuesta del TEMA
    int obtenerSiguienteIdRespuesta() const;
};

#endif
