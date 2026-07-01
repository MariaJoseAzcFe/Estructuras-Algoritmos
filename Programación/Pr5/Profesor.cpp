/******* profesor.cpp ***************************************************/ /**
 *
 * @file profesor.cpp
 *
 * Fichero de implementacion de la clase profesor
 *
 * @version 1.0
 * @author Hernández Pérez Alejandro, Azcarate Ferrando María José
 * @date 17/04/2024
 *  
 ***************************************************************************/
 #include "Profesor.h"
 #include "persona.h"
 #include <iostream>
 #include <string>
 
 /*** Profesor::Profesor() *******************************************/ /**
 *
 *  Constructor por defecto:
 *  @param [in] nom cadena con el nombre del profesor
 *  @param [in] depart cadena con el departamento al que pertenece el profesor
 *  @param [in] area numero que se corresponde con el area de conocimiento del profesor
 *  @param [in] ed numero que se corresponde con la edad del profesor
 *
 */ /**********************************************************************/
 Profesor::Profesor(string nom, unsigned int edad, string depart, int area)
 :Persona(nom,edad)
 {
 	departamento = depart;
 	area_con = area;
 	
 }
 /**********************************************************************/ /**
 *
 *  Devuelve el departamento al que pertenece el profesor.
 *
 *  @return el departamento correspondiente
 *
 */ /**********************************************************************/
 string Profesor::DevuleveDepartamento()
 {
 	return departamento;
 }
 /**********************************************************************/ /**
 *
 *  Devuelve el area de conocimiento a la que pertenece el profesor.
 *
 *  @return el area de conocimiento correspondiente
 *
 */ /**********************************************************************/
 int Profesor::DevuelveAreaConocimiento()
 {
 	return area_con;
 }
 /**********************************************************************/ /**
 *
 *  Modifica el departamento del profesor con el recibido como parametro.
 *
 *  @param [in]  s  nuevo nombre del departamento al que pertenezca el profesor
 
 */ /**********************************************************************/
 void Profesor::AsignarDepartamento(string s)
 {
 	departamento = s;
 }
 /**********************************************************************/ /**
 *
 *  Modifica el area de conocimiento del profesor con el recibido como parametro.
 *
 *  @param [in]  n  numero entero que guarda el area de conocimiento
 
 */ /**********************************************************************/
 void Profesor::AsignarAreaConocimiento(int n)
 {
 	area_con = n;
 }
 /**********************************************************************/ /**
 *
 *  Muestra el nombre del Profesor por pantalla junto a un texto dice que el 
 *  alumno va a la universidad utilizando el metro.
 *
 */ /**********************************************************************/
 
 void Profesor::IrALaUniversidad()
 {
 	cout << DevuelveNombre() << "va a a la universidad a la pata coja" << endl;
 }
 /**********************************************************************/ /**
 *
 *  Muestra por pantalla el nombre del profesor y tambien un mensaje de que ha fichado
 *  para a continuacion llamar al metodo AsistirAClase() de la clase Persona.
 *
 */ /**********************************************************************/
 void Profesor::AsistirAClase()
 {
 	cout << DevuelveNombre() << "ha fichado" << endl;
 	Persona::AsistirAClase();
 }
