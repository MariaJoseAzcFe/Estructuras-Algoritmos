/*
 * @file Ubicacion.h
 * @brief Material de la Practica 4 de EDA (GIM).
 * 
 * Implementacion de la clase Ubicacion
 *
 * @author Jesus Albert
 * @date 13/11/2024
 * @version 1.1
 */

#include "ubicacion.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;

/**
 * @brief Constructor de Ubicacion, inicializando todos los atributos a cero.
 * 
 */
Ubicacion::Ubicacion():
x(0.0), y(0.0), angulo(0.0)
{}

/**
 * @brief Constructor de Ubicacion, inicializando a valores concretos.
 * 
 * @param a coord. x
 * @param b coord. y
 * @param c angulo en radianes
 */
Ubicacion::Ubicacion(double a, double b, double c)
:x(a), y(b), angulo(c) 
{}

/**
 * @brief Devuelve coordenada x 
 * 
 * @return double 
 */
double Ubicacion::GetX()
{
    return x;
}

/**
 * @brief Devuelve coordenada y 
 * 
 * @return double 
 */
double Ubicacion::GetY()
{
    return y;
}

/**
 * @brief Devuelve el angulo en radianes
 * 
 * @return double 
 */
double Ubicacion::GetAngulo()
{
    return angulo;    
}

/**
 * @brief Establece todos los atributos del ubicacion
 * 
 * @param a nueva coord. x
 * @param b nueva coord. y
 * @param c nuevo angulo en radianes
 */
void Ubicacion::SetUbicacion(double a, double b, double c)
{
    x = a;
    y = b;
    angulo = c;
}

/**
 * @brief Desplazar el punto una cierta distancia segun el angulo de orientacion
 * 
 * @param dist distancia a desplazar
 */
void Ubicacion::Desplazar(double dist)
{
    x += dist * cos(angulo);
    y += dist * sin(angulo);
}

/**
 * @brief Realizar un giro del angulo en radianes
 * 
 * @param giro rotacion a realizar
 */
void Ubicacion::Girar(double giro)
{
    angulo += giro;
}

/**
 * @brief Operador salida, muestra los datos del ubicacion
 * 
 * @param f flujo de salida
 * @param e ubicacion a mostrar
 */
ostream& operator<<(ostream& f, Ubicacion e)
{
    f << "(" << e.x << "," << e.y << ";" << e.angulo << ")";
    return f;
}
