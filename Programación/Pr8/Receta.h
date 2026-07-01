/****** Receta.h **************************************************/ /**
 *
 * @file Receta.h
 *
 * @brief Fichero de cabecera de la clase Tiempo
 *
 * @version 1.0
 * @author Jose García
 * @date 05-05-2024
 */ /**************************************************************************/

#ifndef _RECETA_H_
#define _RECETA_H_
#include "Tiempo.h"
#include <iostream>

using namespace std;

/** Clase Receta para la gestión de recetas */
class Receta
{
    public:
    	Receta();
    	void EstablecerReceta (string, string, string, string, string, Tiempo);
    	void EstablecerTitulo (string);
    	void EstablecerInformacion (string);
    	void EstablecerUrl (string);
    	void EstablecerDificultad (string);
    	void EstablecerTipo (string);
    	void EstablecerTiempo (Tiempo);
    	string DevuelveTitulo();
    	string DevuelveInformacion ();
    	string DevuelveUrl ();
    	string DevuelveDificultad ();
    	string DevuelveTipo ();
    	Tiempo DevuelveTiempo ();
    	friend istream& operator>> (istream&, Receta);
    	friend ostream& operator<< (ostream&, Receta);
    	friend bool operator< (Receta, Receta);
    	
    private:
    	string titulo;
    	string info;
    	string url;
    	string dificultad;
    	string tipo;
    	Tiempo duracion;
};
    
#endif	
