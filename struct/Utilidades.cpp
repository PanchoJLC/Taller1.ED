
#include "../include/struct/Utilidades.h"

#include <cstdlib>
#include <iostream>

namespace Utilidades {

    std::string quitarEspacios(const std::string& texto) {
        size_t inicio = 0;
        size_t fin = texto.size();
        while (inicio < fin && (texto[inicio] == ' ' || texto[inicio] == '\t' ||
                                texto[inicio] == '\r' || texto[inicio] == '\n')) {
            inicio++;
        }
        while (fin > inicio && (texto[fin - 1] == ' ' || texto[fin - 1] == '\t' ||
                                texto[fin - 1] == '\r' || texto[fin - 1] == '\n')) {
            fin--;
        }
        return texto.substr(inicio, fin - inicio);
    }

    std::string quitarMarcaBOM(const std::string& texto) {
        if (texto.size() >= 3 && (unsigned char)texto[0] == 0xEF &&
            (unsigned char)texto[1] == 0xBB && (unsigned char)texto[2] == 0xBF) {
            return texto.substr(3);
        }
        return texto;
    }

    std::string aMayusculas(const std::string& texto) {
        std::string resultado = texto;
        for (size_t i = 0; i < resultado.size(); i++) {
            if (resultado[i] >= 'a' && resultado[i] <= 'z') {
                resultado[i] = resultado[i] - 'a' + 'A';
            }
        }
        return resultado;
    }

    int dividir(const std::string& texto, char separador, std::string partes[], int maximo) {
        int cantidad = 0;
        std::string actual = "";
        for (size_t i = 0; i <= texto.size(); i++) {
            if (i == texto.size() || texto[i] == separador) {
                if (cantidad < maximo) {
                    partes[cantidad] = actual;
                }
                cantidad++;
                actual = "";
            } else {
                actual += texto[i];
            }
        }
        return cantidad;
    }

    bool convertirAEntero(const std::string& texto, int& resultado) {
        if (texto.empty() || texto.size() > 9) {
            return false;
        }
        int numero = 0;
        for (size_t i = 0; i < texto.size(); i++) {
            if (texto[i] < '0' || texto[i] > '9') {
                return false;
            }
            numero = numero * 10 + (texto[i] - '0');
        }
        resultado = numero;
        return true;
    }

    bool esIdTemaValido(const std::string& id) {
        if (id.size() != 5) {
            return false;
        }
        for (int i = 0; i < 2; i++) {
            if (id[i] < 'A' || id[i] > 'Z') {
                return false;
            }
        }
        for (int i = 2; i < 5; i++) {
            if (id[i] < '0' || id[i] > '9') {
                return false;
            }
        }
        return true;
    }

    std::string leerLinea(const std::string& mensaje) {
        std::cout << mensaje;
        std::string linea;
        if (!std::getline(std::cin, linea)) {
            std::cout << "\nEntrada finalizada. Cerrando el programa." << std::endl;
            std::exit(0);
        }
        return quitarEspacios(linea);
    }

    void imprimirEncabezado() {
        std::cout << "\n[---------- Foro Comunitario ----------]\n" << std::endl;
    }
}
