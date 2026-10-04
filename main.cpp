#include <iostream>
#include "include/service/Foro.h"
int main() {
    Foro foro;
    if (!foro.cargarDatos("usuarios.csv", "temas.csv")) {
        return 1;
    }
    foro.ejecutar();
    return 0;
return 0;
}