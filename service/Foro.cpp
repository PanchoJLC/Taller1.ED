
#include "../include/service/Foro.h"
#include "../include/service/GestorArchivos.h"
#include "../include/struct/Utilidades.h"

#include <iostream>
#include <cstdlib>

Foro::Foro() {
    usuarioActual = nullptr;
    rutaTemas = "";
}

bool Foro::cargarDatos(const std::string& rutaUsuarios, const std::string& rutaArchivoTemas) {
    std::string error;
    rutaTemas = rutaArchivoTemas;

    if (!GestorArchivos::cargarUsuarios(rutaUsuarios, usuarios, error)) {
        std::cout << "Error al cargar los datos: " << error << std::endl;
        return false;
    }
    if (!GestorArchivos::cargarTemas(rutaArchivoTemas, usuarios, temas, error)) {
        std::cout << "Error al cargar los datos: " << error << std::endl;
        return false;
    }
    return true;
}

void Foro::ejecutar() {
    autenticar();

    bool continuar = true;
    while (continuar) {
        mostrarMenuPrincipal();
        std::string entrada = Utilidades::aMayusculas(Utilidades::leerLinea("Seleccione una opcion: "));

        if (entrada == "A") {
            revisarTema();
        } else if (entrada == "B") {
            eliminarUsuario();
        } else if (entrada == "C") {
            publicarTema();
        } else if (entrada == "D") {
            mostrarEstadisticas();
        } else if (entrada == "E") {
            salir();
            continuar = false;
        } else {
            std::cout << "\nError: opcion invalida. Elija una letra entre A y E." << std::endl;
        }
    }
}

void Foro::autenticar() {
    Utilidades::imprimirEncabezado();
    while (usuarioActual == nullptr) {
        std::string entrada = Utilidades::leerLinea("Ingrese su ID: ");
        int id;
        if (!Utilidades::convertirAEntero(entrada, id)) {
            std::cout << "Error: el ID debe ser un numero entero positivo." << std::endl;
            continue;
        }
        Usuario* encontrado = usuarios.buscarPorId(id);
        if (encontrado == nullptr) {
            std::cout << "Error: usuario no encontrado" << std::endl;
        } else {
            usuarioActual = encontrado;
            std::cout << "Bienvenido/a " << usuarioActual->getNombre() << std::endl;
        }
    }
}

void Foro::mostrarMenuPrincipal() const {
    Utilidades::imprimirEncabezado();
    std::cout << "Temas:" << std::endl;
    if (temas.getCantidad() == 0) {
        std::cout << "(no hay temas publicados)" << std::endl;
    }
    for (int i = 0; i < temas.getCantidad(); i++) {
        Tema* tema = temas.obtener(i);
        std::cout << tema->getId() << ". " << tema->getTitulo() << std::endl;
    }
    std::cout << "A) Revisar un tema" << std::endl;
    std::cout << "B) Eliminar usuario" << std::endl;
    std::cout << "C) Publicar" << std::endl;
    std::cout << "D) Estadisticas" << std::endl;
    std::cout << "E) Salir" << std::endl;
}

void Foro::revisarTema() {
    Utilidades::imprimirEncabezado();
    Tema* tema = nullptr;

    while (tema == nullptr) {
        std::string id = Utilidades::aMayusculas(
                Utilidades::leerLinea("Ingrese el Id del tema que desea revisar (0 para volver al menu): "));
        if (id == "0") {
            return;
        }
        int indice = temas.buscarIndicePorId(id);
        if (indice == -1) {
            std::cout << "Error: el tema '" << id << "' no existe. Revise la lista de temas e intente de nuevo." << std::endl;
        } else {
            tema = temas.obtener(indice);
        }
    }

    mostrarTema(tema);

    bool volver = false;
    while (!volver) {
        std::cout << "A) Comentar" << std::endl;
        std::cout << "B) Atras" << std::endl;
        std::string opcion = Utilidades::aMayusculas(Utilidades::leerLinea("Seleccione una opcion: "));
        if (opcion == "A") {
            comentar(tema);
            mostrarTema(tema);
        } else if (opcion == "B") {
            volver = true;
        } else {
            std::cout << "Error: opcion invalida. Elija A o B." << std::endl;
        }
    }
}

void Foro::mostrarTema(const Tema* tema) const {
    Utilidades::imprimirEncabezado();
    std::cout << "Titulo: " << tema->getTitulo() << std::endl;
    std::cout << "Usuario: " << obtenerNombreUsuario(tema->getIdUsuario()) << std::endl;
    std::cout << "\n" << tema->getContenido() << std::endl;

    Respuesta* actual = tema->getPrimeraRespuesta();
    while (actual != nullptr) {
        std::cout << "\nUsuario " << obtenerNombreUsuario(actual->getIdUsuario()) << " responde:" << std::endl;
        std::cout << actual->getContenido() << std::endl;
        actual = actual->getSiguiente();
    }
}

