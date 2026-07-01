/**********************************************************************/ /**
 * @file pr2_funciones.h
 *
 * @brief Funciones de búsqueda para la Práctica nº2 de EDA-GIM
 *
 * Incluye 3 funciones típicas de búsqueda sobre vectores:
 * 1) BusquedaSecuencialParada
 * 2) BusquedaConCentinela
 * 3) BusquedaBinaria
 *
 * @version 1.2
 * @author María José Azcárate Ferrando
 * @author Juan Pablo Gómez Rodríguez
 * @date 25-10-2024
 */ /**********************************************************************/
 
#ifndef _PR2_FUNCIONES_H_
#define _PR2_FUNCIONES_H_

//#define NDEBUG
#include <assert.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>

using namespace std;

//Tipo de vectores utilizado
typedef vector<int> TVector;

//Prototipos de las funciones incluidas en el archivo
bool BusquedaSecuencialParada (TVector, int, size_t&);
bool BusquedaConCentinela (TVector, int, size_t&);
bool BusquedaBinaria (TVector, int, size_t&);
bool Ordenado (TVector);
void GenerarVectorOrdenado (TVector&, unsigned int);

/**********************************************************************/ /**
 *
 *  @brief Busqueda secuencial con parada
 *
 *  @param [in]  v   vector que contiene los datos
 *  @param [in]  x   elemento a buscar
 *  @param [in,out]  pasos   pasos realizados
 *  @retval true x encontrado
 *  @retval false x no encontrado
 *
 *  @post  (return True si existe i=0..n-1: v[i]=x) or (return False si v[i]!=x, para todo i=0..n-1)
 *
 */ /**********************************************************************/
bool BusquedaSecuencialParada (TVector v, int x, size_t& pasos)
{
    unsigned int i;
    bool enc;
       
    i = 0;
    pasos = 0;
    while ( (i < v.size()) && (v[i] != x) )
    {
        i = i + 1;
        pasos += 3;
    }
        
    if (i == v.size())
        enc = false;
    else
        enc = true;

    return enc;
}

/**********************************************************************/ /**
 *
 *  @brief Busqueda secuencial con centinela:
 *
 *  @param [in]  v   vector que contiene los datos
 *  @param [in]  x   elemento a buscar
 *  @param [in,out]  pasos   pasos realizados
 *  @retval true x encontrado
 *  @retval false x no encontrado
 *
 *  @post  (return True si existe i=0..n-1: v[i]=x) or (return False si v[i]!=x, para todo i=0..n-1)
 *
 */ /**********************************************************************/
bool BusquedaConCentinela (TVector v, int x, size_t& pasos)
{
    unsigned int i;
    bool enc;
    
    //fijar centinela antes de buscar
    v.push_back(x);

    i = 0;
    pasos = 0;
    while ( v[i] != x )
    {
        i = i + 1;
        pasos += 2;
    }

    if (i == v.size())
        enc = false;
    else
        enc = true;

    //retirar centinela antes de finalizar
    v.pop_back();

    return enc;
}

/**********************************************************************/ /**
 *
 *  @brief Busqueda binaria
 *
 *  @param [in]  v   vector que contiene los datos
 *  @param [in]  x   elemento a buscar
 *  @param [in,out]  pasos   pasos realizados
 *  @retval true x encontrado
 *  @retval false x no encontrado
 *
 *  @pre  v debe estar ordenado de menor a mayor
 *  @post  (return True si existe i=0..n-1: v[i]=x) or (return False si v[i]!=x, para todo i=0..n-1)
 *
 */ /**********************************************************************/
bool BusquedaBinaria (TVector v, int x, size_t& pasos)
{
    unsigned int izq, der, cen;
    bool enc = false;

    assert(Ordenado(v));
    
    izq = 0;
    der = v.size() - 1;
    cen = (izq + der) / 2;
    
    pasos = 0;
    while ( (izq <= der) && (v[cen] != x) )
    {
        if (x < v[cen])
            der = cen - 1;
        else
            izq = cen + 1;
            
        cen = (izq + der) / 2;
        pasos += 5;
    }

    if (izq > der)
        enc = false;
    else
        enc = true;
 
    return enc;
}

/**********************************************************************/ /**
 *
 *  @brief Comprobar si un vector esta ordenado de menor a mayor
 *
 *  @param [in]  v   vector que contiene los datos
 *  @retval true v ordenado
 *  @retval false v no ordenado
 *
 *  @post  (return True si v[i]>=v[i-1], para todo i=1..n-1) or (return False si existe i=1..n-1: v[i]<v[i-1])
 *
 */ /**********************************************************************/
bool Ordenado (TVector v)
{
    unsigned int i;
    bool orden = false;
    
    i = 1;
    while ( (i < v.size()) && (v[i] >= v[i-1]) )
        i++;
    if (i == v.size())
        orden = true;
    return orden;
}

/**********************************************************************/ /**
 *
 *  @brief Generar un vector ordenado de n elementos
 *
 *  @param [out]  v   vector que contendra los datos
 *  @param [in]  n   numero de elementos generados en el vector
 *
 *  @pre n>0
 *  @post  para todo i=0..n-1: v[i]=i
 *
 */ /**********************************************************************/
void GenerarVectorOrdenado (TVector& v, unsigned int n)
{
    assert(n>0);
    v.clear();
    for (size_t i = 0; i < n; i++)
        v.push_back(i);
}


#endif
