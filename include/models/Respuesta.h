
#ifndef RESPUESTA_H
#define RESPUESTA_H

#include <string>

class Respuesta {
    // Atributos de la clase RESPUESTA
    int id;
    int idUsuario;
    std::string contenido;
    Respuesta* siguiente;

public:
    // Constructor de la clase RESPUESTA
    Respuesta(int idRespuesta, int idAutor, const std::string& textoRespuesta);

    // Obtiene el id de la RESPUESTA
    int getId() const;
    // Obtiene el usuario de la RESPUESTA
    int getIdUsuario() const;
    // Obtiene el contenido de la RESPUESTA
    std::string getContenido() const;
    // Obtiene (si es que hay) una siguiente respuesta a traves de punteros
    Respuesta* getSiguiente() const;
    // Coloca una respuesta nueva
    void setSiguiente(Respuesta* nuevoSiguiente);
};

#endif
