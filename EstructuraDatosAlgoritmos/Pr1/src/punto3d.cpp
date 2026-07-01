/**
 * @file punto3d.cpp
 * @brief Implementacion de la clase Punto3d. Practica 1 de EDA (GIM).
 * 
 *
 * @author Jesus Albert
 * @date 08/10/2024
 * @version 1.0
 */

#include <iostream>
#include <math.h>
#include "punto3d.h"

using namespace std;

/** 
 * Diferencia maxima que se considera cero al comparar dos reales
 */
const float CERO = 0.0001;

/**
 * @brief Construir un Punto3d con un valor inicial para x,y,z
 * @param [in] a valor inicial de x
 * @param [in] b valor inicial de y
 * @param [in] c valor inicial de z
 */
Punto3d::Punto3d(float a, float b, float c) 
{
    this->x = a;
    this->y = b;
    this->z = c;
} 

/**
* @brief Asignar nuevos valores al Punto3d.
* @param [in] a Nuevo valor de x
* @param [in] b Nuevo valor de y
* @param [in] c Nuevo valor de z
*/
void Punto3d::Set(float a, float b, float c)
{
    this->x = a;
    this->y = b;  
    this->z = c;
}

/**
* @brief Obtener la coordenada x del Punto3d
* @return coordenada x
*/
float Punto3d::GetX() const 
{
    return this->x;
}

/**
* @brief Obtener la coordenada y del Punto3d
* @return coordenada y
*/
float Punto3d::GetY() const 
{
    return this->y;
}

/**
* @brief Obtener la coordenada z del Punto3d
* @return coordenada z
*/
float Punto3d::GetZ() const 
{
    return this->z;
}

/**
* @brief Desplazar un Punto3d.
* @param [in] dx Desplazamiento en X
* @param [in] dy Desplazamiento en Y
* @param [in] dz Desplazamiento en Z
*/
void Punto3d::Desplazar(float dx, float dy, float dz)
{
    this->x += dx;
    this->y += dy;
    this->z += dz;
}

/**
* @brief Rotar un Punto3d alrededor del eje X
* @param [in] a angulo de rotacion en radianes
*/
void Punto3d::RotarX(float a)
{
    float xb, yb, zb;
    xb = this->x;
    yb = this->y*cos(a) - this->z*sin(a);
    zb = this->y*sin(a) + this->z*cos(a);
    this->Set(xb,yb,zb);
}

/**
* @brief Rotar un Punto3d alrededor del eje Y
* @param [in] a angulo de rotacion en radianes
*/
void Punto3d::RotarY(float a)
{
    float xb, yb, zb;
    xb = this->x*cos(a) + this->z*sin(a);
    yb = this->y;
    zb = -this->x*sin(a) + this->z*cos(a);
    this->Set(xb,yb,zb);
}

/**
* @brief Rotar un Punto3d alrededor del eje Z
* @param [in] a angulo de rotacion en radianes
*/
void Punto3d::RotarZ(float a)
{
    float xb, yb, zb;
    xb = this->x*cos(a) - this->y*sin(a);
    yb = this->x*sin(a) + this->y*cos(a);
    zb = z;
    this->Set(xb,yb,zb);
}

/**
* @brief Comparar dos puntos e indicar si son iguales (estan en la misma ubicacion).
* @param [in] a Primer elemento de la comparación.
* @param [in] b Segundo elemento de la comparación.
* @retval true a y b son iguales
* @retval false a y b son diferentes
*/
bool operator==(const Punto3d a, const Punto3d b)
{
    bool eq = false;
    if ( (fabs(a.x - b.x) < CERO) && (fabs(a.y - b.y) < CERO) && (fabs(a.z - b.z) < CERO) )
        eq = true;
    return eq;
}

/**
* @brief Imprimir un Punto3d.
*/
ostream& operator<<(ostream& s, const Punto3d c)
{
    s << "(" << c.x << "," << c.y << "," << c.z << ")";
    return s;
} 

