#include "../include/models/Tema.h"


Tema::Tema(const std::string& idTema, const std::string& tituloTema,
           const std::string& contenidoTema, int idAutor) {
    id = idTema;
    titulo = tituloTema;
    contenido = contenidoTema;
    idUsuario = idAutor;
    primeraRespuesta = nullptr;
}

Tema::~Tema() {
    Respuesta* actual = primeraRespuesta;
    while (actual != nullptr) {
        Respuesta* siguiente = actual->getSiguiente();
        delete actual;
        actual = siguiente;
    }
    primeraRespuesta = nullptr;
}

std::string Tema::getId() const {
    return id;
}

std::string Tema::getTitulo() const {
    return titulo;
}

std::string Tema::getContenido() const {
    return contenido;
}

int Tema::getIdUsuario() const {
    return idUsuario;
}

Respuesta* Tema::getPrimeraRespuesta() const {
    return primeraRespuesta;
}

void Tema::agregarRespuestaAlInicio(Respuesta* nueva) {
    nueva->setSiguiente(primeraRespuesta);
    primeraRespuesta = nueva;
}

void Tema::agregarRespuestaAlFinal(Respuesta* nueva) {
    nueva->setSiguiente(nullptr);
    if (primeraRespuesta == nullptr) {
        primeraRespuesta = nueva;
        return;
    }
    Respuesta* ultima = primeraRespuesta;
    while (ultima->getSiguiente() != nullptr) {
        ultima = ultima->getSiguiente();
    }
    ultima->setSiguiente(nueva);
}

int Tema::contarRespuestas() const {
    int cantidad = 0;
    Respuesta* actual = primeraRespuesta;
    while (actual != nullptr) {
        cantidad++;
        actual = actual->getSiguiente();
    }
    return cantidad;
}

int Tema::contarRespuestasDeUsuario(int idAutor) const {
    int cantidad = 0;
    Respuesta* actual = primeraRespuesta;
    while (actual != nullptr) {
        if (actual->getIdUsuario() == idAutor) {
            cantidad++;
        }
        actual = actual->getSiguiente();
    }
    return cantidad;
}

int Tema::eliminarRespuestasDeUsuario(int idAutor) {
    int eliminadas = 0;
    Respuesta* anterior = nullptr;
    Respuesta* actual = primeraRespuesta;
    while (actual != nullptr) {
        Respuesta* siguiente = actual->getSiguiente();
        if (actual->getIdUsuario() == idAutor) {
            if (anterior == nullptr) {
                primeraRespuesta = siguiente;
            } else {
                anterior->setSiguiente(siguiente);
            }
            delete actual;
            eliminadas++;
        } else {
            anterior = actual;
        }
        actual = siguiente;
    }
    return eliminadas;
}

int Tema::obtenerSiguienteIdRespuesta() const {
    int mayor = 0;
    Respuesta* actual = primeraRespuesta;
    while (actual != nullptr) {
        if (actual->getId() > mayor) {
            mayor = actual->getId();
        }
        actual = actual->getSiguiente();
    }
    return mayor + 1;
}
