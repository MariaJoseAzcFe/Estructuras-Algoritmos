/**
 * @file punto3d.h
 * @brief Archivo de cabecera de la clase Punto3d. Practica 1 de EDA (GIM).
 * 
 *
 * @author Jesus Albert
 * @date 08/10/2024
 * @version 1.0
 */
 
#ifndef _PUNTO3D_H
#define _PUNTO3D_H

#include <iostream>
using namespace std;

/**
 * Clase Punto3d
 * @brief Representacion de puntos en un espacio 3D
 * 
 */
class Punto3d
{
    public:
    
        /**
         * @brief Crear un Punto3d inicializandolo a (0,0,0)
         * @post x=0 and y=0 and z=0
         * 
         */
        Punto3d()
        :x(0),y(0),z(0)
        {}
    
        /*
        * Crear un Punto3d con un valor inicial para las coordenadas x,y,z
        */
        Punto3d(float, float, float);
    
        /*
        * Establecer nuevos valores para las coordenadas del Punto3d.
        */
        void Set(float, float, float);
    
        /*
        * Obtener la coordenada x del Punto3d.
        */
        float GetX() const;
    
        /*
        * Obtener la coordenada y del Punto3d.
        */
        float GetY() const;
    
        /*
        * Obtener la coordenada z del Punto3d.
        */
        float GetZ() const;

        /*
        * Desplazar un Punto3d, indicando:
        * desplazamiento en X
        * desplazamiento en Y
        * desplazamiento en Z
        */
        void Desplazar(float, float, float);
    
        /*
        * Rotar (alrededor del eje X) un Punto3d un angulo en radianes
        */
        void RotarX(float);
    
        /*
        * Rotar (alrededor del eje Y) un Punto3d un angulo en radianes
        */
        void RotarY(float);
    
        /*
        * Rotar (alrededor del eje Z) un Punto3d un angulo en radianes
        */
        void RotarZ(float);
    
        /*
        * Comparar dos puntos e indicar si son iguales (estan en la misma ubicacion).
        */
        friend bool operator==(const Punto3d, const Punto3d);
        
        /*
        * Imprimir los datos del Punto3d
        */
        friend ostream& operator<<(ostream&, const Punto3d);
        
    private:
        float x; // Coordenada x del Punto3d
        float y; // Coordenada y del Punto3d
        float z; // Coordenada z del Punto3d
};

#endif
