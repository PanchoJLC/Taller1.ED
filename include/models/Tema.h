
#ifndef TEMA_H
#define TEMA_H

#include <string>
#include "Respuesta.h"

class Tema {

    std::string id;
    std::string titulo;
    std::string contenido;
    int idUsuario;
    Respuesta* primeraRespuesta;

public:

    Tema(const std::string& idTema, const std::string& tituloTema,
         const std::string& contenidoTema, int idAutor);

    ~Tema();

    std::string getId() const;

    std::string getTitulo() const;

    std::string getContenido() const;

    int getIdUsuario() const;

    Respuesta* getPrimeraRespuesta() const;

    void agregarRespuestaAlInicio(Respuesta* nueva);

    void agregarRespuestaAlFinal(Respuesta* nueva);


    int contarRespuestas() const;

    int contarRespuestasDeUsuario(int idAutor) const;

    int eliminarRespuestasDeUsuario(int idAutor);

    int obtenerSiguienteIdRespuesta() const;
};

#endif
