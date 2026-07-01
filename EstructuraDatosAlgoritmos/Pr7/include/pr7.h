/**
 * @file pr7.h
 * @brief Pr7: Funciones y declaraciones auxiliares para realizar la practica
 *
 * @author: Jesús Albert
 * @date: 11/12/2024
 * @version 1.0
 */
 
#ifndef _PR7_H_
#define _PR7_H_

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

using namespace std;

/**
 * @brief Tipo para definir un escenario
 * 
 */
struct Escenario
{
    //dimensiones del escenario
    size_t alto; ///< altura del escenario
    size_t ancho; ///< anchura del escenario
    //vector de posiciones
    vector<bool> posiciones; ///< true = posicion transitable, false = no transitable/obstaculo
};

/**
 *  @brief Indica el tipo de posicion en funcion de la zona del escenario 
 *  en la que se ubica
 *  @param [in] i Identificador numerico de la celda
 *  @param [in] e Escenario
 *  @retval 0 Posicion interior con 4 potenciales posiciones vecinas
 *  @retval 1 Celda situada en el lateral izquierdo, no tiene vecino a la izquierda
 *  @retval 2 Celda situada en el lateral derecho, no tiene vecino a la derecha
 * 
 * @pre 0 <= i < e.alto*e.ancho
 * @exception out_of_range si no cumple precondicion
 */
unsigned int TipoPosicion(size_t i, const Escenario& e)
{
    unsigned int tipo;

    if ( i < 0 || i >= (e.alto * e.ancho) )
        throw out_of_range("TipoPosicion: posicion fuera de rango");

    if ( i % e.ancho == 0 ) //lateral izq.
        tipo = 1;
    else if ( (i+1) % e.ancho == 0 ) //lateral der.
        tipo = 2;
    else //interior, todos los vecinos
        tipo = 0;
        
    return tipo;
}

/**
 * @brief Obtener los indices de los vecinos de la celda i en el escenario e
 * 
 * @param i Identificador numerico de la celda
 * @param e Escenario
 * @return vector<size_t> vector con los indices de los vecinos
 * 
 * @pre 0 <= i < e.alto*e.ancho
 * @exception out_of_range si no cumple precondicion
 */
vector<size_t> Vecinos(size_t i, const Escenario& e)
{
    vector<size_t> vecinos;
    unsigned int tipo;

    if ( i < 0 || i >= (e.alto * e.ancho) )
        throw out_of_range("Vecinos: posicion fuera de rango");

    tipo = TipoPosicion(i,e);
    //Seleccionar el vector de vecinos correspondiente al tipo de celda
    switch(tipo)
    {
        case 0: //Celda estandar, con 4 posibles vecinos (puede tener 3)
            if ( int(i - e.ancho) < 0 ) //fila superior, no vecino arriba
                vecinos = {i-1, i+e.ancho, i+1};
            else if ( int(i + e.ancho) >= int(e.alto * e.ancho) ) //fila inferior, no vecino abajo
                vecinos = {i-1, i+1, i-e.ancho};
            else
                vecinos = {i-1, i+e.ancho, i+1, i-e.ancho};
            break;
        case 1: //Celda del lateral izquierdo, no vecino izquierda
            if ( int(i - e.ancho) < 0 ) //esquina superior, no vecino arriba
                vecinos = {i+e.ancho, i+1};
            else if ( int(i + e.ancho) >= int(e.alto * e.ancho) ) //esquina inferior, no vecino abajo
                vecinos = {i+1, i-e.ancho};
            else
                vecinos = {i+e.ancho, i+1, i-e.ancho};
            break;
        case 2: //Celda del lateral derecho, no vecino derecho
            if ( int(i - e.ancho) < 0 ) //esquina superior, no vecino arriba
                vecinos = {i-1, i+e.ancho};
            else if ( int(i + e.ancho) >= int(e.alto * e.ancho) ) //esquina inferior, no vecino abajo
                vecinos = {i-1, i-e.ancho};
            else
                vecinos = {i-1, i+e.ancho, i-e.ancho};
            break;
    }    

    return vecinos;
}

/**
 * @brief Contar el numero de posiciones transitables en el escenario
 * Util para depuracion
 * 
 * @param e Escenario
 * @return int 
 */
int ContarTransitables(const Escenario& e)
{
    return count(e.posiciones.begin(),e.posiciones.end(),true);
}

/**
 * @brief Representar en pantalla el escenario (2D)
 * Obstaculo(X), Transitable(.)
 * 
 * @param e Escenario
 */
void  PintarEscenario(const Escenario& e)
{
    for (size_t i=0; i < e.posiciones.size(); i++)
    {
        if ( i%e.ancho == 0 )
            cout << endl;
        if ( e.posiciones[i] ) //transitable
            cout << " ";
        else
            cout << "X";
    }
    cout << endl << endl;
}

#endif