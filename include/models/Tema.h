//
// Created by fraco on 13-09-2026.
//

#ifndef TALLER1_1_TEMA_H
#define TALLER1_1_TEMA_H
#include <iostream>
using namespace std;
class Tema {
    string id;
    string titulo;
    string idUsuario;
    string respuestas;
    public:
    Tema();
    Tema(string id,string titulo, string idUsuario, string respuestas);
    ~Tema();

    string getId() {
        return this->id;
    }
    string getTitulo() {
        return this->titulo;
    }
    string getIdUsuario() {
        return this->idUsuario;
    }
    string getRespuestas() {
        return this->respuestas;
    }

    void setId(string id) {
        this->id = id;
    }
    void setTitulo(string titulo) {
        this->titulo = titulo;
    }
    void setIdUsuario(string idUsuario) {
        this->idUsuario = idUsuario;
    }
    void setRespuestas(string respuestas) {
        this->respuestas = respuestas;
    }
};


#endif //TALLER1_1_TEMA_H