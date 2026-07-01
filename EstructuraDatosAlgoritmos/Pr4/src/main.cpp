#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <cmath>
#include "Ubicacion.h"

using namespace std;

/**
 * @brief Funcion que genera la curva de Peano de un tamaño y nivel
 *
 * @param nivel [in] escala de detalle
 * @param d [in] tamaño de la forma
 * @param e [in] ubicacion espacial
 * @param f [out] archivo de salida
 * @return número de segmentos generados por la curva
 */
size_t GeneraCurvaPeano(unsigned int, double, Ubicacion&, ofstream&);
/**
 * @brief funcion principal
 */
int main() 
{
    Ubicacion u;
    size_t segmentos;
    ofstream f;
    string fichero;
   
        for(int i = 0; i < 6; i++)
        {
            fichero = to_string(i);
            f.open("data/curva_peano"+fichero+".txt" );
             if (!f.is_open()) 
             {
                cerr << "Error al abrir el archivo de salida." << endl;
       
            }
            else
            {

                // Configurar la ubicación inicial
                u.SetUbicacion(75,100, 0);

    
                segmentos = GeneraCurvaPeano(i, 100, u, f);

        
                cout << "Curva de Peano generada con " << segmentos << " segmentos." << endl;
                f.close();
            }
        }
        
    

    return 0;

    
}


size_t GeneraCurvaPeano(unsigned int nivel, double d, Ubicacion& e, ofstream& f) 
{
    size_t numeroSegmentos=0;

    if (nivel == 0) 
    {
        
        double dx = d * cos(e.GetAngulo());
        double dy = d * sin(e.GetAngulo());
        
        f << e.GetX() << "\t" << e.GetY() << "\t" << dx << "\t" << dy << endl;
        e.Desplazar(d);
        numeroSegmentos++;
        
       
    } 

    else
    {
       
        double distanciaRecursiva = d / 3.0;

        // 1. Subcurva 1
        numeroSegmentos+=GeneraCurvaPeano(nivel - 1, distanciaRecursiva, e, f);
        e.Girar(-M_PI / 2); // Girar -π/2

        
        numeroSegmentos+=GeneraCurvaPeano(nivel - 1, distanciaRecursiva, e, f);
        e.Girar(M_PI / 2); 

       
        numeroSegmentos+=GeneraCurvaPeano(nivel - 1, distanciaRecursiva, e, f);
        e.Girar(M_PI / 2); 

      
        numeroSegmentos+=GeneraCurvaPeano(nivel - 1, distanciaRecursiva, e, f);

       
        numeroSegmentos+=GeneraCurvaPeano(nivel - 1, distanciaRecursiva, e, f);
        e.Girar(M_PI / 2); 

     
        numeroSegmentos+=GeneraCurvaPeano(nivel - 1, distanciaRecursiva, e, f);
        e.Girar(M_PI / 2); 

    
        numeroSegmentos+=GeneraCurvaPeano(nivel - 1,distanciaRecursiva, e, f);
        e.Girar(M_PI / 2); 

   
        numeroSegmentos+=GeneraCurvaPeano(nivel - 1,distanciaRecursiva, e, f);

       
        numeroSegmentos+=GeneraCurvaPeano(nivel - 1, distanciaRecursiva, e, f);
    
    }
    return numeroSegmentos;
}

