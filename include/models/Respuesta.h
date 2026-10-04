
#ifndef RESPUESTA_H
#define RESPUESTA_H

#include <string>

class Respuesta {

    int id;
    int idUsuario;
    std::string contenido;
    Respuesta* siguiente;

public:
    Respuesta(int idRespuesta, int idAutor, const std::string& textoRespuesta);


    int getId() const;

    int getIdUsuario() const;

    std::string getContenido() const;

    Respuesta* getSiguiente() const;

    void setSiguiente(Respuesta* nuevoSiguiente);
};

#endif
