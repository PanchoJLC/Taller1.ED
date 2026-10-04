cmake_minimum_required(VERSION 4.1)
project(Taller1_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Taller1_1 main.cpp
        include/models/Usuario.h
        models/Usuario.cpp
        include/models/Tema.h
        models/Tema.cpp
        include/models/Respuesta.h
        models/Respuesta.cpp
        include/struct/Utilidades.h
        struct/Utilidades.cpp
        include/service/GestorArchivos.h
        service/GestorArchivos.cpp
        include/service/ArregloUsuarios.h
        service/ArregloUsuarios.cpp
        include/service/ArregloTemas.h
        service/ArregloTemas.cpp
        include/service/Foro.h
        service/Foro.cpp)