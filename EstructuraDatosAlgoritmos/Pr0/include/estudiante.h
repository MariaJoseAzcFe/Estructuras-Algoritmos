
/******* estudiante.h ***************************************************/ /**
 *
 * @file estudiante.h
 *
 * Fichero de cabecera de la clase Estudiante
 *
 * @version 1.0
 * @author Jesus Albert
 * @date 16/03/2020
 *  
 ***************************************************************************/

#ifndef _ESTUDIANTE_H_
#define _ESTUDIANTE_H_


#include <string>
#include <iostream>
#include "persona.h"

using namespace std;

/**
 * @brief Clase para el manejo de Estudiantes
 *
  */

class Estudiante: public Persona
{
	public:
    	Estudiante();
	    //Modificadores
        bool AsignarValores(string, string, string, char, int, int, int, string, int);
        bool SetTitulacion(string);
		bool SetCurso(int);
		bool SetId(string);
		string GetTitulacion();
		int GetCurso();
		//Imprimir
        friend ostream& operator<<(ostream&,Estudiante);
	private:
		string titulacion;
		int curso;
		bool ValidarCurso(int);
		bool ValidarId(string);
};

#endif
