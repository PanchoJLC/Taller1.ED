
#include "../include/service/Foro.h"
#include "../include/service/GestorArchivos.h"
#include "../include/struct/Utilidades.h"

#include <iostream>

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
        std::string entrada = (Utilidades::leerLinea("Seleccione una opcion: "));

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
        std::string id =
                Utilidades::leerLinea("Ingrese el Id del tema que desea revisar (0 para volver al menu): ");
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
        std::string opcion = Utilidades::leerLinea("Seleccione una opcion: ");
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
void Foro::comentar(Tema* tema) {
    std::string contenido;
    bool valido = false;

    while (!valido) {
        contenido = Utilidades::leerLinea("Ingrese su respuesta: ");
        if (contenido.find(',') != std::string::npos) {
            std::cout << "Error: la respuesta no puede contener comas. Corrija el texto." << std::endl;
        } else if (contenido.find('_') != std::string::npos) {
            std::cout << "Error: la respuesta no puede contener guion bajo. Corrija el texto." << std::endl;
        } else {
            valido = true;
        }
    }

    Respuesta* nueva = new Respuesta(tema->obtenerSiguienteIdRespuesta(), usuarioActual->getId(), contenido);
    tema->agregarRespuestaAlInicio(nueva);
    temas.moverAlInicio(temas.buscarIndicePorId(tema->getId()));
    std::cout << "Respuesta publicada." << std::endl;
}

void Foro::eliminarUsuario() {
    Utilidades::imprimirEncabezado();
    std::cout << "Usuarios activos:" << std::endl;
    for (int i = 0; i < usuarios.getCantidad(); i++) {
        Usuario* usuario = usuarios.obtener(i);
        std::cout << usuario->getId() << ". " << usuario->getNombre() << std::endl;
    }
    std::cout << std::endl;

    Usuario* aEliminar = nullptr;
    while (aEliminar == nullptr) {
        std::string entrada = Utilidades::leerLinea("Ingrese el ID del usuario que desea eliminar (0 para volver al menu): ");
        int id;
        if (!Utilidades::convertirAEntero(entrada, id)) {
            std::cout << "Error: el ID debe ser un numero entero positivo." << std::endl;
            continue;
        }
        if (id == 0) {
            return;
        }
        if (id == usuarioActual->getId()) {
            std::cout << "No puedes eliminarte a ti mismo" << std::endl;
            continue;
        }
        aEliminar = usuarios.buscarPorId(id);
        if (aEliminar == nullptr) {
            std::cout << "Error: usuario no encontrado" << std::endl;
        }
    }

    int idEliminar = aEliminar->getId();
    std::string nombre = aEliminar->getNombre();

    int temasCreados = 0;
    for (int i = 0; i < temas.getCantidad(); i++) {
        if (temas.obtener(i)->getIdUsuario() == idEliminar) {
            temasCreados++;
        }
    }
    int respuestasRealizadas = contarRespuestasDeUsuario(idEliminar);

    std::cout << "\nEl usuario " << nombre << " ha creado " << temasCreados << " tema(s) y ha realizado "
              << respuestasRealizadas << " respuesta(s)." << std::endl;

    bool respondido = false;
    while (!respondido) {
        std::string confirmacion =
                Utilidades::leerLinea("Se eliminaran todos sus registros. Desea continuar? (SI/NO): ");
        if (confirmacion == "NO") {
            std::cout << "Eliminacion cancelada." << std::endl;
            return;
        }
        if (confirmacion == "SI") {
            respondido = true;
        } else {
            std::cout << "Error: responda SI para confirmar o NO para cancelar." << std::endl;
        }
    }

    for (int i = temas.getCantidad() - 1; i >= 0; i--) {
        if (temas.obtener(i)->getIdUsuario() == idEliminar) {
            temas.eliminarEn(i);
        }
    }
    for (int i = 0; i < temas.getCantidad(); i++) {
        temas.obtener(i)->eliminarRespuestasDeUsuario(idEliminar);
    }
    usuarios.eliminarPorId(idEliminar);

    std::cout << "Usuario " << nombre << " eliminado con exito" << std::endl;
}

void Foro::publicarTema() {
    Utilidades::imprimirEncabezado();
    std::string titulo;
    std::string contenido;

    bool valido = false;
    while (!valido) {
        titulo = Utilidades::leerLinea("Ingrese el titulo: ");
        if (titulo.empty()) {
            std::cout << "Error: el titulo no puede estar vacio." << std::endl;
        } else if (titulo.find(';') != std::string::npos) {
            std::cout << "Error: el titulo no puede contener punto y coma (;)." << std::endl;
        } else {
            valido = true;
        }
    }

    valido = false;
    while (!valido) {
        contenido = Utilidades::leerLinea("Ingrese el contenido: ");
        if (contenido.empty()) {
            std::cout << "Error: el contenido no puede estar vacio." << std::endl;
        } else if (contenido.find(';') != std::string::npos) {
            std::cout << "Error: el contenido no puede contener punto y coma (;)." << std::endl;
        } else {
            valido = true;
        }
    }

    std::string id = generarIdTema();
    Tema* nuevo = new Tema(id, titulo, contenido, usuarioActual->getId());
    if (!temas.agregarAlInicio(nuevo)) {
        delete nuevo;
        std::cout << "Error: no hay memoria suficiente para publicar el tema." << std::endl;
        return;
    }
    std::cout << "\nTema publicado con ID " << id << std::endl;
}

void Foro::mostrarEstadisticas() const {
    Utilidades::imprimirEncabezado();
    // a) Usuario(s) con mas respuestas
    std::cout << "Usuario con mas respuestas:" << std::endl;
    int maximoUsuario = 0;
    for (int i = 0; i < usuarios.getCantidad(); i++) {
        int cantidad = contarRespuestasDeUsuario(usuarios.obtener(i)->getId());
        if (cantidad > maximoUsuario) {
            maximoUsuario = cantidad;
        }
    }
    if (maximoUsuario == 0) {
        std::cout << "  Aun no hay respuestas publicadas." << std::endl;
    } else {
        for (int i = 0; i < usuarios.getCantidad(); i++) {
            Usuario* usuario = usuarios.obtener(i);
            if (contarRespuestasDeUsuario(usuario->getId()) == maximoUsuario) {
                std::cout << "  Id: " << usuario->getId() << " | Nombre: " << usuario->getNombre()
                          << " | Respuestas: " << maximoUsuario << std::endl;
            }
        }
    }

    // b) Tema(s) con mayor cantidad de respuestas
    std::cout << "\nTema con mayor cantidad de respuestas:" << std::endl;
    int maximoTema = 0;
    for (int i = 0; i < temas.getCantidad(); i++) {
        int cantidad = temas.obtener(i)->contarRespuestas();
        if (cantidad > maximoTema) {
            maximoTema = cantidad;
        }
    }
    if (maximoTema == 0) {
        std::cout << "  Aun no hay respuestas publicadas." << std::endl;
    } else {
        for (int i = 0; i < temas.getCantidad(); i++) {
            Tema* tema = temas.obtener(i);
            if (tema->contarRespuestas() == maximoTema) {
                std::cout << "  Id: " << tema->getId() << " | Titulo: " << tema->getTitulo()
                          << " | Autor: " << obtenerNombreUsuario(tema->getIdUsuario())
                          << " | Respuestas: " << maximoTema << std::endl;
            }
        }
    }

    // c) Numero de expansiones
    std::cout << "\nNumero de expansiones del arreglo de usuarios: " << usuarios.getExpansiones() << std::endl;
}

void Foro::salir() {
    if (GestorArchivos::guardarTemas(rutaTemas, temas)) {
        std::cout << "\nInformacion guardada en " << rutaTemas << std::endl;
    } else {
        std::cout << "\nError: no se pudo guardar el archivo " << rutaTemas << std::endl;
    }
    usuarioActual = nullptr;
    temas.liberar();
    usuarios.liberar();
    std::cout << "Hasta pronto." << std::endl;
}

std::string Foro::generarIdTema() const {
    std::string id;
    do {
        id = "";
        id += (char) ('A' + std::rand() % 26);
        id += (char) ('A' + std::rand() % 26);
        for (int i = 0; i < 3; i++) {
            id += (char) ('0' + std::rand() % 10);
        }
    } while (temas.buscarIndicePorId(id) != -1);
    return id;
}

std::string Foro::obtenerNombreUsuario(int id) const {
    Usuario* usuario = usuarios.buscarPorId(id);
    if (usuario == nullptr) {
        return "Desconocido";
    }
    return usuario->getNombre();
}

int Foro::contarRespuestasDeUsuario(int id) const {
    int total = 0;
    for (int i = 0; i < temas.getCantidad(); i++) {
        total += temas.obtener(i)->contarRespuestasDeUsuario(id);
    }
    return total;
}

