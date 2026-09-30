//
// Created by fraco on 30-09-2026.
//

#include "../include/service/LecturaTema.h"
#include "../include/models/Tema.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void lecturaTema() {
    std::fstream file("temas.csv");

    if (file.is_open()) {
        std::cout << "Error al abrir el archivo";
        exit(1);
    }
    std::string linea;

    while (std::getline(file, linea)) {
        std::stringstream ss(linea);
        std::string id,titulo,idUsuario,respuestas;

        std::getline(ss,id,';');
        std::getline(ss,titulo,';');
        std::getline(ss,idUsuario,';');
        std::getline(ss,respuestas,';');
    }
    file.close();
}
