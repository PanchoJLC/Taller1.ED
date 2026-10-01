//
// Created by fraco on 13-09-2026.
//

#include "../include/models/Tema.h"
#include <iostream>
#include <string>

Tema::Tema() {
    this->getId() = "";
    this->getTitulo() = "";
    this->getIdUsuario() = "";
    this->getRespuestas() = "";
}

Tema::Tema(std::string id, std::string titulo, std::string idUsuario, std::string respuestas):
id(id),titulo(titulo),idUsuario(idUsuario),respuestas(respuestas) {}

std::string Tema::getId() {
    return this->id;
}
std::string Tema::getTitulo() {
    return this->titulo;
}
std::string Tema::getIdUsuario() {
    return this->idUsuario;
}
std::string Tema::getRespuestas() {
    return this->respuestas;
}
void Tema::setId(std::string id) {
    this->id = id;
}
void Tema::setTitulo(std::string titulo) {
    this->titulo = titulo;
}
void Tema::setIdUsuario(std::string idUsuario) {
    this->idUsuario = idUsuario;
}
void Tema::setRespuestas(std::string respuestas) {
    this->getRespuestas() = respuestas;
}

void Tema::mostrarInformacion() {
    std::cout <<"id Comentario: " << this->getId() << std::endl;
    std::cout <<"Titulo: " << this->getTitulo() << std::endl;
    std::cout <<"Id Usuario: " << this->getIdUsuario() << std::endl;
    std::cout <<"Respuestas: " << this->getRespuestas() << std::endl;
}
