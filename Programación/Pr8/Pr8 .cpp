/**
 * @file Pr8.cpp
 *
 * @brief Programa para gestionar recetas
 *
 * Este programa permite al usuario gestionar recetas, incluyendo agregar, eliminar,
 * avanzar, retroceder, mostrar recetas por dificultad o tipo, guardar y recuperar
 * la lista de recetas desde un archivo.
 *
 * @version 1.0
 * @author María José Azcárate
 * @date 18/05/2024
 */

#include <iostream>
#include <string>
#include "ListaReceta.h"
#include "Receta.h"

using namespace std;

// Prototipos de funciones
void mostrarRecetaActiva(ListaReceta& listaRecetas);
void mostrarRecetasPorDificultad(ListaReceta& listaRecetas);
void mostrarRecetasPorTipo(ListaReceta& listaRecetas);

/**
 * @brief Muestra la receta activa de la lista
 * 
 * Muestra la receta activa si hay alguna en la lista.
 * Si no hay recetas en la lista, muestra un mensaje indicándolo.
 * 
 * @param listaRecetas Lista de recetas
 */
void mostrarRecetaActiva(ListaReceta& listaRecetas) 
{
    cout << "Receta activa:" << endl;
    if (listaRecetas.DevuelveCuantos() > 0) {
        listaRecetas.MostrarPantalla();
    } else {
        cout << "No hay recetas en la lista." << endl;
    }
}

/**
 * @brief Muestra recetas por dificultad
 * 
 * Pide al usuario un nivel de dificultad y muestra todas las recetas
 * de ese nivel de dificultad.
 * 
 * @param listaRecetas Lista de recetas
 */
void mostrarRecetasPorDificultad(ListaReceta& listaRecetas) 
{
    string dificultad;
    cout << "Ingrese la dificultad (fácil, medio o difícil): ";
    cin >> dificultad;
    cout << "Recetas con dificultad '" << dificultad << "':" << endl;
}

/**
 * @brief Muestra recetas por tipo
 * 
 * Pide al usuario un tipo de receta y muestra todas las recetas
 * de ese tipo.
 * 
 * @param listaRecetas Lista de recetas
 */
void mostrarRecetasPorTipo(ListaReceta& listaRecetas) 
{
    string tipo;
    cout << "Ingrese el tipo de receta (entrante, primero, segundo o postre): ";
    cin >> tipo;
    cout << "Recetas del tipo '" << tipo << "':" << endl;
}

/**
 * @brief Función principal
 * 
 * Crea una lista de recetas y permite al usuario gestionarlas a través de un menú interactivo.
 * 
 * @return 0
 */

int main() {
    ListaReceta listaRecetas;
    Receta nuevaReceta;
    int opcion;
    string nombreArchivo,titulo, informacion, url, dificultad, tipo;
    Tiempo duracion;

    do 
	{
        mostrarRecetaActiva(listaRecetas);

        cout << "\n--- Menú ---" << endl;
        cout << "1. Añadir nueva receta" << endl;
        cout << "2. Eliminar receta activa" << endl;
        cout << "3. Avanzar receta activa" << endl;
        cout << "4. Retroceder receta activa" << endl;
        cout << "5. Mostrar recetas por dificultad" << endl;
        cout << "6. Mostrar recetas por tipo" << endl;
        cout << "7. Guardar lista en archivo" << endl;
        cout << "8. Recuperar lista de archivo" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {

                cout << "Ingrese el título de la receta: ";
                cin.ignore();
                getline(cin, titulo);
                cout << "Ingrese la información de la receta: ";
                getline(cin, informacion);
                cout << "Ingrese la URL de la receta: ";
                getline(cin, url);
                cout << "Ingrese la dificultad de la receta: ";
                getline(cin, dificultad);
                cout << "Ingrese el tipo de la receta: ";
                getline(cin, tipo);
                cout << "Ingrese la duración de la receta (en horas y minutos separados por un espacio): ";
                cin >> duracion;

                nuevaReceta.EstablecerReceta(titulo, informacion, url, dificultad, tipo, duracion);
                listaRecetas.InsertarEnOrden(nuevaReceta);
                break;
            }
            	case 2: {
			    // Eliminar receta activa
			    if (listaRecetas.DevuelveCuantos() == 0) 
				    {
				        cout << "No hay recetas para eliminar." << endl;
			
				    }
				
				    // Eliminar la receta activa de la lista
				    listaRecetas.EliminarActivo();
				
				    cout << "Receta eliminada exitosamente." << endl;
			}
			case 3: {
			    // Avanzar receta activa
			      if (listaRecetas.DevuelveCuantos() == 0) 
				  	{
				        cout << "No hay recetas para avanzar." << endl;
				    }
				
				    // Avanzar al siguiente elemento de la lista
				    listaRecetas.Avanzar();
				
				    cout << "Receta avanzada exitosamente." << endl;
			}
			case 4: {
			    // Retroceder receta activa
			    if (listaRecetas.DevuelveCuantos() == 0) 
				{
			        cout << "No hay recetas para retroceder." << endl;
			    }
			
			    // Retroceder al elemento anterior de la lista
			    listaRecetas.Retroceder();
			
			    cout << "Receta retrocedida exitosamente." << endl;
			}

            case 5:
                mostrarRecetasPorDificultad(listaRecetas);
                break;
            case 6:
                mostrarRecetasPorTipo(listaRecetas);
                break;
            case 7: 
			    // Guardar lista en archivo
			    cout << "Ingrese el nombre del archivo para guardar la lista: ";
			    cin >> nombreArchivo;
			    if (listaRecetas.GuardarEnFichero(nombreArchivo)) 
				{
			        cout << "Lista guardada correctamente en el archivo '" << nombreArchivo << "'." << endl;
			    } else {
			        cout << "Error al guardar la lista en el archivo." << endl;
			    }
			    break;
			
			case 8: {
			    // Recuperar lista de archivo
			    cout << "Ingrese el nombre del archivo para recuperar la lista: ";
			    cin >> nombreArchivo;
			    if (listaRecetas.RecuperarDeFichero(nombreArchivo)) {
			        cout << "Lista recuperada correctamente desde el archivo '" << nombreArchivo << "'." << endl;
			    } else {
			        cout << "Error al recuperar la lista desde el archivo." << endl;
			    }
			    break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
                break;
      			}
      	
		}
    } while (opcion != 0);

    return 0;
}

