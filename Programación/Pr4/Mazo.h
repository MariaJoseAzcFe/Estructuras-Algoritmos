
/******* Mazo.h *******************************************************/ /**
 *
 * @file Mazo.h
 *
 * Fichero de cabecera de la clase Mazo
 *
 * @version 5.0
 * @author Alejandro Hernandez Perez
 * @author Maria Jose Azcarate Ferrando 
 * @date 15/03/2024
 *  
 ***************************************************************************/
#ifndef _MAZO_H_
#define _MAZO_H_

#include <string>
#include <vector>
#include <regex>
#include "carta.h"
using namespace std;
template < class Mazo, class Carta = allocator<Mazo> > class Vector;
/**
 * @brief Clase para el de Mazo
 *
 * Clase para agrupar cartas.
  */
  class Mazo
{
	public:	
	    //constructor por defecto de la clase Mazo//
	    Mazo();
	    
	    //funciones para modificar el contenido del mazo//
	    void AnadirCarta(Carta);
		void AsignarNombreMazo(string);
		
		//funciones para mostrar el contenido del mazo//
		string DevuelveNombreMazo();
		void MostrarMazo();

    
  		// Método para cargar un mazo desde un archivo
  		void CargarMazoDeFichero(string nombreFichero, const vector<Carta>& cartas);


		
	private:
		  
		  vector<Carta> vec_cards; //< Vector de las STL que guarda las cartas que pertenecen al mazo
		  string nombreMazo; //< string con el Nombre que tiene el mazo
};

#endif

