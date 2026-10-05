
#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <string>

namespace Utilidades {

    // Elimina espacios, tabulaciones y saltos de linea al inicio y al final.
    std::string quitarEspacios(const std::string& texto);
     // Divide un texto segun un separador y guarda las partes en un arreglo.
    int dividir(const std::string& texto, char separador, std::string partes[], int maximo);
    // Convierte un texto formado solo por digitos en un numero entero.
    bool convertirAEntero(const std::string& texto, int& resultado);
    // Revisa que un Id de tema tenga dos letras mayusculas y tres digitos.
    bool esIdTemaValido(const std::string& id);
    // Muestra un mensaje y lee una linea completa desde el teclado.
    std::string leerLinea(const std::string& mensaje);
    //Imprime el encabezado del foro.
    void imprimirEncabezado();
}

#endif
