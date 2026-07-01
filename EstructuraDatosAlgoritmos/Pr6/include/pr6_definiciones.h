/**********************************************************************/ /**
 *
 * @file pr6_definiciones.h
 * 
 * @brief Practica 6 EDA-GIM
 * Definiciones de constantes y tipos para establecer
 * el contexto del problema
 *
 * @version 1.0
 * @author Jesús Albert
 * @date 04/12/2024
 * 
 */ /**********************************************************************/

#ifndef _PR6_DEFINICIONES_
#define _PR6_DEFINICIONES_

#include <utility>	//pair
#include <vector>
#include <string>
#include <cmath>	//ceil

/*** CONSTANTES ***/

//Limite de separacion entre particulas (en metros)
const float UMBRAL = 0.25;

//Tamanyo de la rejilla en la que se divide el escenario
// = limite de separacion entre particulas
const float TAM_GRID = UMBRAL;

//Dimensiones del escenario 4 x 7 metros
const size_t MIN_X = 0;
const size_t MAX_X = 4;
const size_t MIN_Y = 0;
const size_t MAX_Y = 7;
//Numero de celdas horizantales de la rejilla
const std::size_t NCELDAS_X = ceil((MAX_X - MIN_X)/TAM_GRID);
//Numero de celdas verticales de la rejilla
const std::size_t NCELDAS_Y = ceil((MAX_Y - MIN_Y)/TAM_GRID);
//Numero total de celdas de la rejilla
const std::size_t NCELDAS_TOTAL = NCELDAS_X * NCELDAS_Y;

//Celdas vecinas de una celda i de la rejilla
//El vector almacena los valores a sumar al indice de la celda para acceder a los vecinos
//Se debe verificar que el indice del vecino esta en el rango [0..NCELDAS_TOTAL-1]
//Si el indice no esta en ese rango NO existe el vecino (1a. fila o ultima fila)
//Para celdas estandar, con 8 posibles vecinos
const int NX = (int) NCELDAS_X; //Simple cambio de tipo para los siguientes calculos
const std::vector<int> VECINOS_STD = {NX-1, NX, NX+1, -1, +1, -NX-1, -NX, -NX+1};
//Para celdas de la primera columna (izquierda), no hay vecinos a la izquierda, 5 vecinos
const std::vector<int> VECINOS_IZQ = {NX, NX+1, +1, -NX, -NX+1};
//Para celdas de la ultima columna (derecha), no hay vecinos a la derecha, 5 vecinos
const std::vector<int> VECINOS_DER = {NX-1, NX, -1, -NX-1, -NX};

//Numero de archivos de entrada a procesar (frames de la simulacion)
const size_t NUM_FRAMES = 4;
//Prefijo de todos los nombres de los archivos de entrada
//Los archivos estaran numerados de 1 a NUM_FRAMES y tendran extension ".dat"
//Ejemplo: "datos_2D_frame_1.dat"
const std::string PRE_NOM_IN = "datos_2D_frame_";
//Prefijo de todos los nombres de los archivos de resultados
//Los archivos estaran numerados de 1 a NUM_FRAMES y tendran extension ".dat"
//Ejemplo: "result_frame_1.dat"
const std::string PRE_NOM_OUT = "result_frame_";

/*** TIPOS DE DATOS ***/

//Definicion de 1 particula
typedef std::pair<float,float> TParticula;

//Definicion de vector de posiciones de particulas
typedef std::vector<TParticula> TVector;

//Definicion de vector de colisiones entre particulas
//Lista de indices de particulas que colisionan con cada una de ellas
typedef std::vector<std::vector<size_t>> TVectorColisiones;

#endif
