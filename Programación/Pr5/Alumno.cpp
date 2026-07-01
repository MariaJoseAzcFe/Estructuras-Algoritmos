/******* alumno.cpp***************************************************/ /**
 *
 * @file alumno.cpp
 *
 * Fichero de implementacion de la clase alumno
 *
 * @version 1.0
 * @author Hernández Pérez Alejandro, Azcarate Ferrando María José
 * @date 17/04/2024
 *  
 ***************************************************************************/
 #include "Alumno.h"
 #include "persona.h"
 #include <iostream>
 #include <string>
 
 /*** Alumno::Alumno() *******************************************/ /**
 *
 *  Constructor por defecto:
 *  @param [in] nom cadena con el nombre del alumno
 *  @param [in] gr cadena con el grado al que pertenece el alumno
 *  @param [in] prom cadena con la promocion a la que pertenece el alumno
 *  @param [in] ed numero que se corresponde con la edad del alumno
 *
 */ /**********************************************************************/
 
 Alumno::Alumno(string nom, string gr, string pr, unsigned int ed)
 :Persona(nom, ed)
 {
 	prom = pr;
 	grado = gr;
 }
 /**********************************************************************/ /**
 *
 *  Modifica el grado del alumno con el recibido como parametro.
 *
 *  @param [in]  s  nuevo nombre del grado al que pertenezca el alumno
 
 */ /**********************************************************************/
 
 void Alumno::AsignarGrado(string s)
 {
 	grado = s;	
 }
  /**********************************************************************/ /**
 *
 *  Devuelve el grado al que pertenece el alumno.
 *
 *  @return  grado del alumno
 
 */ /**********************************************************************/
 
 string Alumno::DevuelveGrado()
 {
 	return grado;
 }
  /**********************************************************************/ /**
 *
 *  Devuelve la promocio a la que pertenece el alumno.
 *
 *  @return promocion del alumno
 
 */ /**********************************************************************/
 
 string Alumno::DevuelvePromocion()
 {
 	return prom;
 }
  /**********************************************************************/ /**
 *
 *  Modifica la promocion del alumno con el recibido como parametro.
 *
 *  @param [in]  s  nuevo nombre de la promocion a la que pertenezca el alumno
 
 */ /**********************************************************************/
 
 void Alumno::AsignarPromocion(string s)
 {
 	prom = s;
 }
 
  /**********************************************************************/ /**
 *
 *  Muestra el nombre del alumno por pantalla junto a un texto dice que el 
 *  alumno va a la universidad utilizando el metro.
 *
 */ /**********************************************************************/
 
 void Alumno::IrALaUniversidad()
 {
 	
	 cout << DevuelveNombre() << " va a la universidad en metro" <<endl;
 }

