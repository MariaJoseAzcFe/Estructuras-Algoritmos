/******* Pr6_Carta.cpp *************************************************/ /**
 *
 * @file Pr6_Carta.cp
 *
 * Implementación de los métodos de la clase Carta
 *
 * @version 1.0
 * @author Jesús Albert
 * @author Miguel A. Gamón
 * @date 19/04/2022
 *  
 ************* **************************************************************/

#include "Pr6_Carta.h"

/**************************************************************************/ /**
 *
 *  Construye una carta y asigna valores iniciales a los atributos:
 *  1 de Oros ('O').
 *
 */ /*************************************************************************/
using namespace std;

Carta::Carta ()
:palo ('O'), numero (1)
{}

/**************************************************************************/ /**
 *
 *  Construye una carta y asigna valores a los atributos a partir de los
 *  parámetros.
 *  @param  [in]	p	palo de la carta
 *  @param  [in]	n	número de la carta
 *
 */ /*************************************************************************/
Carta::Carta (char p, int n)
{
    switch ( p )
    {
        case 'O': case 'C':
        case 'E': case 'B':
            palo = p;
        default:
            cerr << "Carta mal inicializada. Id. palo incorrecto." << endl;
    }
    if ( ( n>=1 ) && ( n <= 12 ) )
        numero = n;
    else
        cerr << "Carta mal inicializada. Numero incorrecto." << endl;
}

/**********************************************************************/ /**
 *
 *  Asigna el palo de la carta. Los valores correctos para asignar el
 *  palo deben ser ('O', 'C', 'E', 'B').
 *
 *  @param  [in]	p	palo de la carta
 *
 */ /**********************************************************************/
void Carta::EstablecePalo (char p)
{
    switch ( p )
    {
        case 'O': case 'C':
        case 'E': case 'B':
            palo = p;
            break;
        default:
            cerr << "Id. palo incorrecto." << endl;
    }
}

/**********************************************************************/ /**
 *
 *  Asigna el número de la carta. Los valores correctas para asignar el
 *  número deben del 1 al 12.
 *
 *  @param  [in]	n	número de la carta
 *
 */ /**********************************************************************/
void Carta::EstableceNumero (int n)
{
    if ( ( n>=1 ) && ( n <= 12 ) )
        numero = n;
    else
        cerr << "Numero incorrecto." << endl;
}

/**********************************************************************/ /**
 *
 *  Devuelve el palo de la carta.
 *
 *  @return  Palo de la carta
 *
 */ /**********************************************************************/
char Carta::DevuelvePalo ()
{
    return palo;
}

/**********************************************************************/ /**
 *
 *  Devuelve el número de la carta.
 *
 *  @return  Número de la carta
 *
 */ /**********************************************************************/
int Carta::DevuelveNumero ()
{
    return numero;
}
/**********************************************************************/ /**
 *
 *  Sobrecarga del operador <<.
 *
 *  @return  el operador de salida sobrecargado (sal)
 *
 */ /**********************************************************************/
ostream& operator<< (ostream& sal, const Carta& c)
{
	sal << c.numero << " de " << c.palo << endl;
	return sal;
}

