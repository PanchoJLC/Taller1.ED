
#include "../include/models/Respuesta.h"

Respuesta::Respuesta(int idRespuesta, int idAutor, const std::string& textoRespuesta) {
    id = idRespuesta;
    idUsuario = idAutor;
    contenido = textoRespuesta;
    siguiente = nullptr;
}

int Respuesta::getId() const {
    return id;
}

int Respuesta::getIdUsuario() const {
    return idUsuario;
}

std::string Respuesta::getContenido() const {
    return contenido;
}

Respuesta* Respuesta::getSiguiente() const {
    return siguiente;
}

void Respuesta::setSiguiente(Respuesta* nuevoSiguiente) {
    siguiente = nuevoSiguiente;
}
