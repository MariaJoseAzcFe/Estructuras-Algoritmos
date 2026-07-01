/******* alumno.h ***************************************************/ /**
 *
 * @file alumno.h
 *
 * Fichero de cabecera de la clase alumno
 *
 * @version 1.0
 * @author Hernández Pérez Alejandro, Azcarate Ferrando María José
 * @date 16/04/2024
 *  
 ***************************************************************************/
#ifndef _ALUMNO_H_
#define _ALUMNO_H_

#include "Persona.h"
#include <iostream>
#include <string>

using namespace std;

class Alumno: public Persona
{
	public:
		   Alumno(string, string, string, unsigned int);
		   void AsignarGrado(string);
		   string DevuelveGrado();
		   string DevuelvePromocion();
		   void AsignarPromocion(string);
		   void IrALaUniversidad();
		   
    private:
    		string grado;
    		string prom;
};

#endif
