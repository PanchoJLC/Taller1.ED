//
// Created by fraco on 30-09-2026.
//

#include "../include/service/LecturaTema.h"
#include "../include/models/Tema.h"

#include <fstream>
#include <sstream>

using namespace std;

LecturaTema::LecturaTema() = default;

void LecturaTema::leerTema() {
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

        Tema tema = Tema(id,titulo,idUsuario,respuestas);

        temas.agregar(tema);
    }
    file.close();
}
void LecturaTema::mostrarTema() {
    for (int i = 0; i < temas.getTamanio(); i++) {
        std::cout << "Tema " << i+1 << ":" << std::endl;
        temas.obtener(i).mostrarInformacion();
        std::cout << std::endl;
    }
}

