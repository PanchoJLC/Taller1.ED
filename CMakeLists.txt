cmake_minimum_required(VERSION 4.1)
project(Taller1_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Taller1_1 main.cpp
        struct/ArregloDinamico.cpp
        include/struct/ArregloDinamico.h
        models/Usuario.cpp
        include/models/Usuario.h
        service/Sistema.cpp
        include/service/Sistema.h
        models/Tema.cpp
        include/models/Tema.h
        struct/ListaEnlazadaSimple.cpp
        include/struct/ListaEnlazadaSimple.h)
