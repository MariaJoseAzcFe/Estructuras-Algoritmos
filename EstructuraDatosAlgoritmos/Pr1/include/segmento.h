/**
 * @file segmento.h
 * @brief Archivo de cabecera de la clase Segmento. Practica 1 de EDA (GIM).
 * 
 *
 * @author María José Azcárate Ferrando
 * @author Juan Pablo Gómez Rodríguez
 * @date 16/10/2024
 * @version 2.0
 */
 
#ifndef _SEGMENTO_H_
#define _SEGMENTO_H_
#include <cassert>
//#define NDEBUG
#include <iostream>
#include "punto3d.h"
using namespace std;

const int MAX_X= 1920;
const int MAX_Y= 1080;
const int MAX_Z= 800;
const float CERO = 0.0001;

class Segmento
{
        public:
            // Constructor que cumple con la postcondición
            Segmento();
            void SetIni(const Punto3d &);
            void SetFin(const Punto3d &);
            void Desplazar(float,float, float);
            void RotarX(float);
            void RotarY(float);
            void RotarZ(float);
            float Longitud() const;
            friend bool operator==(const Segmento, const Segmento);
            friend ostream& operator<<(ostream&, const Segmento);
           
            
        private:
            Punto3d vertice[2];
            bool Invariante() const;
 
};

#endif