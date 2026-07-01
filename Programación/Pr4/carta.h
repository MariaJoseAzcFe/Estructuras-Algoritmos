
/******* carta.h *******************************************************/ /**
 *
 * @file carta.h
 *
 * Fichero de cabecera de la clase Carta
 *
 * @version 5.0
 * @author Pablo Arnau
 * @date 15/03/2024
 *  
 ***************************************************************************/
 
#ifndef _CARTA_H_
#define _CARTA_H_

#include <string>
using namespace std;

/**
 * @brief Clase para el de Cartas
 *
 * Clase para manejar la informacion de cartas.
  */
class Carta
{
	public:	
		Carta();
		void AsignarValores(string,string,string);
		string DevuelveNombre();
		string DevuelveTipo();
		string DevuelveIdentidadColor();
		bool TieneSubIdentidadColor(Carta &);
	

	private:
		string tipo;      ///< tipo de carta
		string nombre;    ///< nombre de la carta
		string identidad_color;  ///< indetificador de color de la carta
};

#endif
