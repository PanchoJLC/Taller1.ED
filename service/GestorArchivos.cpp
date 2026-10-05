
#include "../include/service/GestorArchivos.h"
#include "../include/struct/Utilidades.h"
#include "../include/models/Tema.h"
#include "../include/models/Usuario.h"

#include <fstream>


static bool cargarRespuestas(const std::string& texto, Tema* tema, const ArregloUsuarios& usuarios,
                             int numeroLinea, std::string& error) {
    size_t inicio = 0;
    bool hayMas = true;
    int numeroMensaje = 0;

    while (hayMas) {
        numeroMensaje++;
        std::string mensaje;
        size_t posicionComa = texto.find(',', inicio);
        if (posicionComa == std::string::npos) {
            mensaje = texto.substr(inicio);
            hayMas = false;
        } else {
            mensaje = texto.substr(inicio, posicionComa - inicio);
            inicio = posicionComa + 1;
        }

        std::string campos[4];
        int cantidadCampos = Utilidades::dividir(mensaje, '_', campos, 4);
        std::string lugar = "temas.csv, linea " + std::to_string(numeroLinea) +
                            ", tema " + tema->getId() + ", respuesta " + std::to_string(numeroMensaje) + ": ";
        if (cantidadCampos != 3) {
            error = lugar + "formato incorrecto, se esperaba Id_IdUsuario_Contenido.";
            return false;
        }

        int idRespuesta;
        int idUsuario;
        if (!Utilidades::convertirAEntero(Utilidades::quitarEspacios(campos[0]), idRespuesta)) {
            error = lugar + "el Id de la respuesta no es un numero valido.";
            return false;
        }
        if (!Utilidades::convertirAEntero(Utilidades::quitarEspacios(campos[1]), idUsuario)) {
            error = lugar + "el IdUsuario de la respuesta no es un numero valido.";
            return false;
        }
        if (usuarios.buscarPorId(idUsuario) == nullptr) {
            error = lugar + "el usuario con Id " + std::to_string(idUsuario) + " no existe.";
            return false;
        }

        Respuesta* nueva = new Respuesta(idRespuesta, idUsuario, Utilidades::quitarEspacios(campos[2]));
        tema->agregarRespuestaAlFinal(nueva);
    }
    return true;
}

bool GestorArchivos::cargarUsuarios(const std::string& ruta, ArregloUsuarios& usuarios, std::string& error) {
    std::ifstream archivo(ruta.c_str());
    if (!archivo.is_open()) {
        error = "No se pudo abrir el archivo " + ruta + ".";
        return false;
    }

    std::string linea;
    int numeroLinea = 0;
    while (std::getline(archivo, linea)) {
        numeroLinea++;
        if (numeroLinea == 1) {
            linea = Utilidades::quitarMarcaBOM(linea);
        }
        linea = Utilidades::quitarEspacios(linea);
        if (linea.empty()) {
            continue;
        }

        std::string lugar = "usuarios.csv, linea " + std::to_string(numeroLinea) + ": ";
        std::string partes[3];
        if (Utilidades::dividir(linea, ';', partes, 3) != 2) {
            error = lugar + "se esperaban 2 campos (Id;Nombre).";
            return false;
        }

        int id;
        std::string nombre = Utilidades::quitarEspacios(partes[1]);
        if (!Utilidades::convertirAEntero(Utilidades::quitarEspacios(partes[0]), id) || id <= 0) {
            error = lugar + "el Id debe ser un numero entero positivo.";
            return false;
        }
        if (nombre.empty()) {
            error = lugar + "el nombre no puede estar vacio.";
            return false;
        }
        if (usuarios.buscarPorId(id) != nullptr) {
            error = lugar + "el Id " + std::to_string(id) + " esta repetido.";
            return false;
        }

        Usuario* nuevo = new Usuario(id, nombre);
        if (!usuarios.agregar(nuevo)) {
            delete nuevo;
            error = "No hay memoria suficiente para guardar los usuarios.";
            return false;
        }
    }
    return true;
}

bool GestorArchivos::cargarTemas(const std::string& ruta, const ArregloUsuarios& usuarios,
                                 ArregloTemas& temas, std::string& error) {
    std::ifstream archivo(ruta.c_str());
    if (!archivo.is_open()) {
        error = "No se pudo abrir el archivo " + ruta + ".";
        return false;
    }

    std::string linea;
    int numeroLinea = 0;
    while (std::getline(archivo, linea)) {
        numeroLinea++;
        if (numeroLinea == 1) {
            linea = Utilidades::quitarMarcaBOM(linea);
        }
        linea = Utilidades::quitarEspacios(linea);
        if (linea.empty()) {
            continue;
        }

        std::string lugar = "temas.csv, linea " + std::to_string(numeroLinea) + ": ";
        std::string partes[6];
        int cantidadPartes = Utilidades::dividir(linea, ';', partes, 6);
        if (cantidadPartes < 4 || cantidadPartes > 5) {
            error = lugar + "se esperaban 5 campos (Id;Titulo;Contenido;IdUsuario;Respuestas).";
            return false;
        }

        std::string id = Utilidades::quitarEspacios(partes[0]);
        std::string titulo = Utilidades::quitarEspacios(partes[1]);
        std::string contenido = Utilidades::quitarEspacios(partes[2]);
        std::string textoIdUsuario = Utilidades::quitarEspacios(partes[3]);

        if (!Utilidades::esIdTemaValido(id)) {
            error = lugar + "el Id del tema" + id + " debe tener dos letras mayusculas y tres digitos.";
            return false;
        }
        if (temas.buscarIndicePorId(id) != -1) {
            error = lugar + "el Id de tema " + id + " esta repetido.";
            return false;
        }
        if (titulo.empty()) {
            error = lugar + "el titulo del tema " + id + " no puede estar vacio.";
            return false;
        }
        if (contenido.empty()) {
            error = lugar + "el contenido del tema " + id + " no puede estar vacio.";
            return false;
        }

        int idUsuario;
        if (!Utilidades::convertirAEntero(textoIdUsuario, idUsuario)) {
            error = lugar + "el IdUsuario del tema " + id + " no es un numero valido.";
            return false;
        }
        if (usuarios.buscarPorId(idUsuario) == nullptr) {
            error = lugar + "el tema " + id + " fue creado por el usuario con Id " +
                    std::to_string(idUsuario) + ", que no existe en usuarios.csv.";
            return false;
        }

        Tema* nuevo = new Tema(id, titulo, contenido, idUsuario);

        if (cantidadPartes == 5) {
            std::string textoRespuestas = Utilidades::quitarEspacios(partes[4]);
            if (!textoRespuestas.empty()) {
                if (!cargarRespuestas(textoRespuestas, nuevo, usuarios, numeroLinea, error)) {
                    delete nuevo;
                    return false;
                }
            }
        }

        if (!temas.agregarAlFinal(nuevo)) {
            delete nuevo;
            error = "No hay memoria suficiente para guardar los temas.";
            return false;
        }
    }
    return true;
}

bool GestorArchivos::guardarTemas(const std::string& ruta, const ArregloTemas& temas) {
    std::ofstream archivo(ruta.c_str());
    if (!archivo.is_open()) {
        return false;
    }

    for (int i = 0; i < temas.getCantidad(); i++) {
        Tema* tema = temas.obtener(i);
        archivo << tema->getId() << ";" << tema->getTitulo() << ";" << tema->getContenido()
                << ";" << tema->getIdUsuario() << ";";

        Respuesta* actual = tema->getPrimeraRespuesta();
        while (actual != nullptr) {
            archivo << actual->getId() << "_" << actual->getIdUsuario() << "_" << actual->getContenido();
            if (actual->getSiguiente() != nullptr) {
                archivo << ",";
            }
            actual = actual->getSiguiente();
        }
        archivo << "\n";
    }
    return true;
}
