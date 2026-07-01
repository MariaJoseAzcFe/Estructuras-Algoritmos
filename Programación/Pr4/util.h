
#ifndef _UTILS_H_
#define _UTILS_H_

#include <vector>
#include <algorithm>
using namespace std;
#include "carta.h"

/**
 * Busca una carta por nombre a partir de una posicion, devuelve true si existe
 * esa carta
 *
 * @param cartas El vector de cartas en el que buscar
 * @param nombre El nombre de la carta buscada
 * @param[out] La carta encontrada (si se encontro)
 * @param offset Posicion de inicio desde la que buscar. Opcional. Por defecto 0
 *
 * @retval  true  Hemos encontrado el nombre entre las cartas del vector
 * @retval  false  No se encontro el nombre entre las cartas del vector
 */
bool BuscarCartaPorNombre(vector<Carta> cartas, const string & nombre,
                                                        Carta & c, int offset=0) 
{
    vector<Carta>::iterator it = find(cartas.begin() + offset,
                                      cartas.end(), nombre);
    bool encontrado;

    if (it != cartas.end())
    {
        encontrado = true;
        c = *it;
    }
    else
        encontrado = false;

    return encontrado;
}

/**
 * Busca una carta a partir de una posicion
 *
 * @param cartas El vector de cartas en el que buscar
 * @param carta La carta buscada
 * @param[out] La carta encontrada (si se encontro)
 * @param offset Posicion de inicio desde la que buscar. Opcional. Por defecto 0
 *
 * @retval  true  Hemos encontrado la carta entre las cartas del vector
 * @retval  false  No se encontro la carta entre las cartas del vector
 */
bool BuscarCarta(vector<Carta> cartas, Carta & carta, Carta & c, int offset=0) 
{
	vector<Carta>::iterator it = find(cartas.begin() + offset, cartas.end(),
                                                                         carta);
    bool encontrado;

    if (it == cartas.end())
        encontrado = false;
    else
    {
        encontrado = true;
        c = *it;
    }

	return encontrado;
}

#endif
