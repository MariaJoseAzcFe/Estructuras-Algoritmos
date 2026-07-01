/****** Tiempo.h **************************************************/ /**
 *
 * @file Tiempo.h
 *
 * @brief Fichero de cabecera de la clase Tiempo
 *
 * @version 1.0
 * @author Jose García
 * @date 05-05-2024
 */ /**************************************************************************/

#ifndef _TIEMPO_H_
#define _TIEMPO_H_

#include <iostream>

using namespace std;

/** Clase Tiempo para la gestión de tiempos */
class Tiempo
{
    public:
        Tiempo ();
        Tiempo (int, int);
        bool SetTiempo(int, int);
        int GetHoras();
        int GetMinutos();
        int GetSegundos();
        
        //sobrecargas
        friend istream& operator>> (istream&, Tiempo&); 
        friend ostream& operator<< (ostream&, Tiempo);
        friend void operator+=(Tiempo&, Tiempo);
        friend void operator-=(Tiempo&, Tiempo); 
        
    private:
        int horas;      ///< horas 
        int minutos;    ///< minutos
};

#endif
