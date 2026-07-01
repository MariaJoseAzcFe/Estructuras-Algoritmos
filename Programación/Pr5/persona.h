/******* persona.h*******************************************************/ /**
 *
 * @file persona.h
 *
 * Fichero de 
 * @author Alejandro Hernández Pérez, María José Azcarate Ferrando
 * @date 15/04/2024
 *  la clase persona
 *
 * @version 1.0
 ***************************************************************************/
#ifndef _PERSONA_H_
#define _PERSONA_H_

#include <string>

using namespace std;

class Persona
{
	public:
	    Persona (string, unsigned int);
	    string DevuelveNombre();
	    unsigned int DevuelveEdad();
	    void AsignaNombre(string);
	    void AsignaEdad(unsigned int);
	    void AsistirAClase();
	    //virtual void IrALaUniversidad() = 0; 
	    
	private:
	    string nombre;
	    unsigned int edad;
};
#endif

