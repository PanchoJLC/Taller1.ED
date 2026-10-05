
#ifndef GESTORARCHIVOS_H
#define GESTORARCHIVOS_H

#include <string>
#include "ArregloUsuarios.h"
#include "ArregloTemas.h"

class GestorArchivos {
public:
    // Carga los USUARIOS del archivo de texto usuarios.csv
    static bool cargarUsuarios(const std::string& ruta, ArregloUsuarios& usuarios, std::string& error);
    // Carga los TEMAS del archivo de texto temas.csv
    static bool cargarTemas(const std::string& ruta, const ArregloUsuarios& usuarios,
                            ArregloTemas& temas, std::string& error);
    // Guarda los TEMAS agregados en el programa
    static bool guardarTemas(const std::string& ruta, const ArregloTemas& temas);
};

#endif
