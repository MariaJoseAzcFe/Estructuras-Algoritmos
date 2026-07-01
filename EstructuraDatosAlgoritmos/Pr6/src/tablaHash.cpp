/**********************************************************************/ /**
 *
 * @file tablaHash.cpp
 * 
 * @brief Practica 6 EDA-GIM
 * Implementacion de la clase TablaHash.
 * Implementacion de dispersion abierta con encadenamiento mediante vectores.
 * Funcion de dispersión adaptada al caso de hashing espacial
 * de particulas en una simulacion grafica.
 * Caso simplificado de TablaHash en el que solo interesa almacenar
 * la clave, NO HAY VALOR ASOCIADO.
 * Cumple el esquema de un tipo Conjunto (set).
 *
 * @version 1.1
 * @author Jesús Albert
 * @date 25/11/2020
 * 
 */ /**********************************************************************/

#include "tablaHash.h"
#include <vector>
#include <string>
#include <iostream>
#include <cmath>	//floor

using namespace std;

/**********************************************************************/ /**
 *
 *  @brief Constructor de la tabla, que establece:
 *  1) Tamaño de la TablaHash (numero de indices = numero de buckets)
 *  2) Asocia el vector que contiene la informacion de posiciones de las particulas.
 *
 *  @param [in]  tam tamaño de la tabla
 *  @param [in]  v  vector que contiene las posiciones de las particulas
 *                  pasado por referencia para no duplicar memoria
 *
 */ /**********************************************************************/
TablaHash::TablaHash(size_t tam, TVector& v)
:info(v) //Asocia el vector de posiciones de las particulas
{
    t.resize(tam); //Crea todas las posiciones = todos los indices
}

/**********************************************************************/ /**
 *
 *  @brief Determina la existencia de una clave en la tabla.
 *
 *  @param [in]  cl Clave
 *  @retval true: La clave cl ya existe en la tabla
 *  @retval false: La clave cl no existe en la tabla
 *
 */ /**********************************************************************/
bool TablaHash::Existe(const TipoClave& cl) const
{
    size_t ind, j;
    bool enc = false;
    
    ind = FHash(cl);
    j = 0;
    //Busqueda secuencial en el vector t[ind] 
    while ( j < this->t[ind].size() && ! enc ) 
        if ( this->t[ind][j] == cl ) 
            enc = true;
        else 
			j++;
    return enc;
}

/**********************************************************************/ /**
 *
 *  @brief Insertar una Clave en la TablaHash
 *
 *  @param [in]  cl Clave
 *  @retval true cl existe en la tabla
 *  @retval false cl no existe en la tabla
 *
 */ /**********************************************************************/
void TablaHash::Insertar(const TipoClave& cl)
{
    if ( ! Existe(cl) ) 
        //Añadir al final del vector correspondiente
        t[FHash(cl)].push_back(cl); 
}

/**********************************************************************/ /**
 *
 *  @brief Tamaño de la tabla.
 *
 *  @return Numero de posiciones definidas (buckets)
 *
 */ /**********************************************************************/
size_t TablaHash::Size() const
{
	return t.size();
}

/**********************************************************************/ /**
 *
 *  @brief Numero de claves almacenadas en una posicion (bucket) de la tabla.
 *
 *  @param [in]  i indice de la tabla
 *  @return Tamaño del vector asociado con la posicion i de la tabla
 *
 */ /**********************************************************************/
size_t TablaHash::BucketSize(size_t i) const
{
	return t[i].size();
}

/**********************************************************************/ /**
 *
 *  @brief Posicion (indice) de ubicacion de una clave en la tabla.
 *  No asegura que la clave exista en la tabla.
 *
 *  @param [in]  cl Clave
 *  @return Posicion de la tabla donde deberia encontrarse cl
 *
 */ /**********************************************************************/
size_t TablaHash::Bucket(const TipoClave cl) const
{
	return FHash(cl);
}

/**********************************************************************/ /**
 *
 *  @brief Conjunto de claves almacenadas en una posicion (bucket) de la tabla.
 *  
 *  @param [in]  i indice de la tabla
 *  @return Vector con todas las claves almacenadas en la posicion i
 *
 */ /**********************************************************************/
const vector<TipoClave>& TablaHash::GetBucket(const size_t i) const
{
	return t[i];
}

/**********************************************************************/ /**
 *
 *  @brief Funcion de dispersion de la tabla.
 *  Caso particular adaptado al hashing espacial de particulas en una simulacion.
 *  Calcula en que celda se encuentra la particula con indice cl en el vector de particulas.
 *  Las celdas estan numeradas en la rejilla definida sobre el espacio de representacion.
 *  Las celdas se numeran de izquierda a derecha y de abajo a arriba.
 *  Fila inferior de la rejilla = Celdas numeradas de 0 a NCELDAS_X-1
 *  
 *  @param [in]  cl Clave
 *  @return Indice de la tabla resultado de la dispersion
 *
 */ /**********************************************************************/
size_t TablaHash::FHash(const TipoClave cl) const
{
	TParticula p;
    float dx, dy;
    size_t nx, ny;
    size_t celda;
    
	p = info[cl];                   //Posicion (x,y) de la particula cl
    dx = p.first - MIN_X;           //Distancia al origen de X
    dy = p.second - MIN_Y;          //Distancia al origen de Y
    nx = floor(dx/TAM_GRID);        //Reducir al grid en X
    ny = floor(dy/TAM_GRID);        //Reducir al grid en Y
    celda = nx + ny * NCELDAS_X;    //Calcular numero de celda
    return celda;
}
