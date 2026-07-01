/******* main.cpp *******************************************************/ /**
 *
 * @file main.cpp
 *
 * Fichero principal de la pr5
 *
 * @version 5
 * @author Alejandro Hernández Pérez, María José Azcarate Ferrando
 * @author Pablo Arnau
 * @date 18/04/2024
 *  
 ***************************************************************************/
 
#include <iostream>
#include <vector>
#include <string>
#include "persona.h"
#include "alumno.h"
//#include "profesor.h"

using namespace std;
/**
 * Función para cargar un alumno.
 * @return El alumno cargado.
 */
Alumno CargarAlumno();

/**
 * Metodo principal de la pr5
 */
int main() 
{
	Alumno a("Alberto","Ingenieria","Cuarta" ,24);
	
	a = CargarAlumno();
	a.IrALaUniversidad();
	a.AsistirAClase();
	
	system("pause");
	return 0;
}
/**
 * Función para cargar los datos de un alumno desde la consola
 * @return El alumno creado con los datos ingresados.
 */
 Alumno CargarAlumno()
 {
 	Alumno al ("alberto","Ingenieria","Cuarta" ,24);
 	unsigned int ed;
 	string nom,gra,pr;
 	
 	cout << "Introduce los datos del alumno: " << endl;
 	cout << "Edad: ";
 	cin >> ed;
 	al.AsignaEdad(ed);
 	cout << "Nombre: ";
 	cin >> nom;
 	al.AsignaNombre(nom);
 	cout << "Promocion: ";
 	cin >> pr;
 	al.AsignarPromocion(pr);
 	cout << "Grado: ";
 	cin >> gra;
 	al.AsignarGrado(gra);
 	
	 return al;		
 }
