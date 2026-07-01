/**********************************************************************/ /**
 *
 * @file tablaHash.h
 * 
 * @brief Practica 6 EDA-GIM
 * Interfaz de la clase TablaHash.
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

#ifndef _TABLA_HASH_
#define _TABLA_HASH_

#include "pr6_definiciones.h"
#include <vector>

using namespace std;

//Clave = indice de la particula en el catalogo que las contiene
typedef size_t TipoClave;

// Tabla Hash con dispersion Abierta con encadenamiento
class TablaHash
{
    public:       
        //Constructor con tamanyo y vector de particulas con la informacion
        TablaHash(size_t, TVector&); 
        
        //Buscar/Consultar existencia de Clave en la TablaHash: true/false
        bool Existe(const TipoClave&) const;
        
        //Insertar una Clave en la TablaHash
        void Insertar(const TipoClave&);

        //Numero de posiciones (buckets) en la tabla
        size_t Size() const;
        
        //Numero de claves que colisionan en una posicion de la tabla (bucket) 
        size_t BucketSize(size_t) const;
    
    	//Posicion de ubicacion de una clave en la tabla (indice/bucket) 
    	size_t Bucket(const TipoClave) const;
    	
    	//Obtener todas las particulas asociadas a una posicion de la tabla
    	const vector<TipoClave>& GetBucket(const size_t) const;
    	
    private:
        //Encadenamiento, cada posicion del vector t es un vector
        //que contiene las claves que colisionan en esa posicion
        vector< vector<TipoClave> > t; 
        
        //Informacion de las particulas almacenadas en la tabla
        //El constructor establecera la asociacion con el vector
        //que contiene informacion de las particulas
        TVector &info;

        //Funcion de dispersion: caso particular de hashing espacial
        //Solo tiene sentido en esta aplicacion
        size_t FHash(const TipoClave) const;
};

#endif
