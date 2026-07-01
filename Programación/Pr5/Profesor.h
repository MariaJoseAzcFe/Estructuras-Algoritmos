/******* profesor.h ***************************************************/ /**
 *
 * @file profesor.h
 *
 * Fichero de cabecera de la clase profesor
 *
 * @version 1.0
 * @author Hernández Pérez Alejandro, Azcarate Ferrando María José
 * @date 17/04/2024
 *  
 ***************************************************************************/
#ifndef _PROFESOR_H_
#define _PROFESOR_H_

#include "Persona.h"
#include <iostream>
#include <string>

using namespace std;

class Profesor: public Persona
{
	public:
		   Profesor(string, unsigned int, string, int);
		   string DevuleveDepartamento();
		   int DevuelveAreaConocimiento();
		   void AsignarDepartamento(string);
		   void AsignarAreaConocimiento(int);
		   void IrALaUniversidad();
		   void AsistirAClase();
		   
 	private:
	 		string departamento;
			int area_con;	   
};
#endif
