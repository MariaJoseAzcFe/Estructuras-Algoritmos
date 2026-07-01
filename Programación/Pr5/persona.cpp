/******* persona.cpp*******************************************************/ /**
 *
 * @file persona.cpp
 *  
 * Fichero de Implementación de la clase persona
 *
 * @version 1.0
 * @author Alejandro Hernández Pérez, María José Azcarate Ferrando
 * @date 18/04/2024
 *
 ***************************************************************************/
 #include "persona.h"
 #include <iostream>
 #include <string>
 /**
 * Constructor de la clase Persona.
 * @param nom Nombre de la persona.
 * @param n Edad de la persona.
 */
 Persona::Persona(string nom,unsigned int n)
 {
 	nombre = nom;
 	edad = n;
 }
 /**
 * Asigna una nueva edad a la persona.
 * @param n Nueva edad a asignar.
 */
 void Persona::AsignaEdad(unsigned int n)
 {
 	edad = n;
 }
 
/**
 * Asigna un nuevo nombre a la persona.
 * @param nom Nuevo nombre a asignar.
 */
 void Persona::AsignaNombre(string nom)
 {
 	nombre = nom;
 }
 /**
 * Método que indica que la persona está asistiendo a clase.
 */
void Persona::AsistirAClase()
{
	cout << nombre << "va a clase" << endl;
}
/**
 * Devuelve la edad de la persona.
 * @return Edad de la persona.
 */
unsigned int Persona::DevuelveEdad()
{
	return (edad);
}
/**
 * Devuelve el nombre de la persona.
 * @return Nombre de la persona.
 */
string Persona::DevuelveNombre()
{
	return (nombre);
}

