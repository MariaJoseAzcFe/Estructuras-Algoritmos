/**
 * @file ubicacion.h
 * @brief Material de la Practica 4 de EDA (GIM).
 * 
 * Archivo de cabecera de la clase Ubicacion
 * Representa un ubicacion con una ubicación espacial 2D (x,y) + un ángulo de orientación
 *
 * @author Jesus Albert
 * @date 13/11/2024
 * @version 1.1
 */

#ifndef _UBICACION_H_
#define _UBICACION_H_

#include <iostream>
using namespace std;

/**
 * @brief Clase Ubicacion que define el ubicacion del punto (coordenadas y angulo de orientacion):
 * Donde estamos ubicados en el espacio (x,y) y con que orientacion.
 * 
 */
class Ubicacion
{

    public:   
        //Crea un ubicacion inicializando todos los atributos a cero.
        Ubicacion();
        //Crea un ubicacion inicializando a valores concretos.
        Ubicacion(double,double,double);
        //Obtiene la coordenada x.
        double GetX();
        //Obtiene la coordenada y.
        double GetY();
        //Obtiene el angulo.
        double GetAngulo();
        //Establece la posición y orientación 
        void SetUbicacion(double,double,double);
        //Desplazar punto una determinada distancia, en función del ángulo
        void Desplazar(double);
        //Girar ángulo de orientación
        void Girar(double);
        //Operador salida
        friend ostream& operator<<(ostream&, Ubicacion);
    
    private:
        double x,y; ///< Coordenadas actuales
        double angulo;  ///< Ángulo en radianes
};

#endif
