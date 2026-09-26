//
// Created by fraco on 13-09-2026.
//

#ifndef TALLER1_1_USUARIO_H
#define TALLER1_1_USUARIO_H
#include <iostream>
using namespace std;
//Clase "USUARIO" la cual contiene los atributos "ID" y "NOMBRE", atributos que identifican,
//Al usuario y ademas sus funciones "GET" y "SET"
class Usuario {
    string id;
    string nombre;
    public:
    Usuario();
    Usuario(string id, string nombre);
    ~Usuario();

    string getId() {
        return this->id;
    }
    string getNombre() {
        return this->nombre;
    }
    void setId(string id) {
        this->id = id;
    }
    void setNombre(string nombre) {
        this->nombre = nombre;
    }


};


#endif //TALLER1_1_USUARIO_H