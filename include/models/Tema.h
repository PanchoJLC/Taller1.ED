//
// Created by fraco on 13-09-2026.
//

#ifndef TALLER1_1_TEMA_H
#define TALLER1_1_TEMA_H
#include <iostream>
//Clase "TEMA" donde se guardan los datos para los atributos, constructor y GET and SET.
using namespace std;
class Tema {
    std::string id;
    std::string titulo;
    std::string idUsuario;
    std::string respuestas;
    public:
    Tema();
    Tema(string id,string titulo, string idUsuario, string respuestas);

    string getId();
    string getTitulo();
    string getIdUsuario();
    string getRespuestas();

    void setId(std::string id);
    void setTitulo(std::string titulo);
    void setIdUsuario(std::string idUsuario);
    void setRespuestas(std::string respuestas);

    void mostrarInformacion();
};


#endif //TALLER1_1_TEMA_H