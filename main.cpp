#include <iostream>
#include "include/service/Foro.h"
int main() {
    //Clase main que pone en marcha el programa
    Foro foro;
    if (!foro.cargarDatos("usuarios.csv", "temas.csv")) {
        return 1;
    }
    foro.ejecutar();
    return 0;
}