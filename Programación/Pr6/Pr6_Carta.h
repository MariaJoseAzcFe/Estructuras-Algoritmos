/******* Pr6_Carta.h ***************************************************/ /**
 *
 * @file Pr6_Carta.h
 *
 * Fichero de cabecera de la clase Carta
 *
 * @version 1.0
 * @author Jesús Albert
 * @author Miguel A. Gamón
 * @author Emiliano Torres
 * @date 19/03/2024
 *  
 ***************************************************************************/
#include <iostream>

using namespace std;

#ifndef _CARTA_H_
#define _CARTA_H_

/**
 * @brief Clase para el manejo de cartas
 *
 * Interfaz de la clase Carta, que representa cartas de la baraja española
 * identificadas por un palo (oros, copas, espadas y bastos) y por un número
 * en el rango 1 a 12.
 */

class Carta
{
    public:
        // Constructor por defecto
        Carta ();
        
        // Constructor indicando el palo (char) y el número (int) de la carta
        Carta (char, int);
        
        // Modificar el palo de la carta
        void EstablecePalo (char);
        
        // Modificar el número de la carta
        void EstableceNumero (int);
        
        // Obtener el palo de la carta
        char DevuelvePalo ();
        
        // Obtener el número de la carta
        int DevuelveNumero ();
        
        // Sobrecarga del operador de salida (<<)
        friend ostream& operator<< (ostream&, const Carta&);

    private:
        // El palo de la carta ('O', 'C', 'E', 'B')
        char palo;
        
        // El número de la carta (1 - 12)
        int numero;
};

#endif
