/******* ListaReceta.h ****************************************************/ /**
 *
 * @file ListaReceta.h
 *
 * Fichero de cabecera de la clase ListaReceta
 *
 * @version 3.0
 * @author María José Azcárate Ferrando, Alejandro Hernández
 * @date 15/05/2024
 *  
 ***************************************************************************/
#ifndef _LISTARECETA_H_
#define _LISTARECETA_H_

#include <iostream>
#include <string>
#include "Receta.h"

using namespace std;

typedef Receta Valor;

struct Nodo {
    Valor dato;
    Nodo* siguiente;
    Nodo* anterior;
};
// clase ListaReceta, usa datos de la clase Receta
class ListaReceta
{
	public:
	
		ListaReceta();
		void InsertarEnOrden(Valor);
		bool Retroceder();
		int DevuelveCuantos();
		void MostrarPantalla();
		bool GuardarEnFichero(const string&);
		bool RecuperarDeFichero(const string&);
		bool Avanzar();
		void EliminarActivo();
		
	private:
		Nodo* cabeza;
		Nodo* activo;
		int cuantos;
};

#endif

