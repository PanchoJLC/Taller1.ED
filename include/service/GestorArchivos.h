
#ifndef GESTORARCHIVOS_H
#define GESTORARCHIVOS_H

#include <string>
#include "ArregloUsuarios.h"
#include "ArregloTemas.h"

class GestorArchivos {
public:

    static bool cargarUsuarios(const std::string& ruta, ArregloUsuarios& usuarios, std::string& error);

    static bool cargarTemas(const std::string& ruta, const ArregloUsuarios& usuarios,
                            ArregloTemas& temas, std::string& error);

    static bool guardarTemas(const std::string& ruta, const ArregloTemas& temas);
};

#endif
