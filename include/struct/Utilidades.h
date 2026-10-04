/**
 * @file Utilidades.h
 * @brief Funciones de apoyo para leer datos, validar texto y dividir cadenas.
 */
#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <string>

/**
 * @namespace Utilidades
 * @brief Agrupa funciones generales que usan varias clases del programa.
 */
namespace Utilidades {

    /**
     * @brief Elimina espacios, tabulaciones y saltos de linea al inicio y al final.
     * @param texto Texto original.
     * @return Texto sin espacios en los extremos.
     */
    std::string quitarEspacios(const std::string& texto);

    /**
     * @brief Elimina la marca BOM (EF BB BF) si el texto comienza con ella.
     * @param texto Texto original.
     * @return Texto sin la marca BOM.
     */
    std::string quitarMarcaBOM(const std::string& texto);

    /**
     * @brief Convierte todas las letras del texto a mayusculas.
     * @param texto Texto original.
     * @return Texto en mayusculas.
     */
    std::string aMayusculas(const std::string& texto);

    /**
     * @brief Divide un texto segun un separador y guarda las partes en un arreglo.
     * @param texto Texto a dividir.
     * @param separador Caracter que separa las partes.
     * @param partes Arreglo donde se guardan las partes (solo las primeras "maximo").
     * @param maximo Tamano del arreglo "partes".
     * @return Cantidad total de partes encontradas (puede ser mayor que "maximo").
     */
    int dividir(const std::string& texto, char separador, std::string partes[], int maximo);

    /**
     * @brief Convierte un texto formado solo por digitos en un numero entero.
     * @param texto Texto a convertir.
     * @param resultado Variable donde se guarda el numero obtenido.
     * @return true si el texto es un entero valido (hasta 9 digitos), false en caso contrario.
     */
    bool convertirAEntero(const std::string& texto, int& resultado);

    /**
     * @brief Revisa que un Id de tema tenga dos letras mayusculas y tres digitos.
     * @param id Id a validar.
     * @return true si cumple el formato, false en caso contrario.
     */
    bool esIdTemaValido(const std::string& id);

    /**
     * @brief Muestra un mensaje y lee una linea completa desde el teclado.
     *
     * Si la entrada se cierra (fin de archivo), el programa termina.
     * @param mensaje Texto que se muestra antes de leer.
     * @return Linea leida sin el salto de linea.
     */
    std::string leerLinea(const std::string& mensaje);

    /**
     * @brief Imprime el encabezado del foro.
     */
    void imprimirEncabezado();
}

#endif
