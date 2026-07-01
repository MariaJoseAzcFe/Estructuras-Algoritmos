/******* ListaReceta.cpp ****************************************************/
/**
 *
 * @file ListaReceta.cpp
 *
 * Implementación de la clase ListaReceta
 *
 * @version 3.0
 * @date 15/05/2024
 *  
 ***************************************************************************/
#include "ListaReceta.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Receta.h"
using namespace std;

/**
 * @brief Constructor de la clase ListaReceta.
 */
ListaReceta::ListaReceta() 
{
    this->cabeza = NULL;
    this->activo = NULL;
    cuantos = 0;
}
/**
 * @brief Inserta una receta en orden en la lista.
 *
 * @param r Receta a insertar.
 */
void ListaReceta::InsertarEnOrden(Valor r) 
{
    Nodo* nuevo = new Nodo;
    nuevo->dato = r; 

    if (this->cabeza == NULL) 
    {
        this->cabeza = nuevo; 
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
        this->activo = nuevo;
        this->cuantos++;
        return;
    }

    Nodo* actual = this->cabeza;
    do {
        if (actual->dato.DevuelveTitulo() >= r.DevuelveTitulo()) 
            break;
        actual = actual->siguiente;
    } while (actual != this->cabeza);

    nuevo->siguiente = actual;
    nuevo->anterior = actual->anterior;
    actual->anterior->siguiente = nuevo;
    actual->anterior = nuevo;

    if (actual == this->cabeza && nuevo->dato.DevuelveTitulo() < actual->dato.DevuelveTitulo())
        this->cabeza = nuevo;

    this->cuantos++;
}
/**
 * @brief Retrocede el puntero activo a la receta anterior.
 *
 * @return true si se pudo retroceder, false si no hay recetas en la lista.
 */
bool ListaReceta::Retroceder() 
{
	bool retrocede;
    if (cuantos == 0) 
        retrocede = false;
    activo = activo->anterior;
    retrocede = true;
    
    return retrocede;
}
/**
 * @brief Avanza el puntero activo a la siguiente receta.
 *
 * @return true si se pudo avanzar, false si no hay recetas en la lista.
 */
bool ListaReceta::Avanzar() 
{
	bool avanza;
    if (activo->siguiente != cabeza) { 
        activo = activo->siguiente; 
        avanza = true; 
    } else {
        avanza = false; 
    }
    return avanza;
}
/**
 * @brief Elimina la receta activa de la lista.
 */
void ListaReceta::EliminarActivo() 
{
	Nodo* nodoEliminar = activo;
    if (cuantos == 0) 
	{ 
        cout << "No hay nada que eliminar"; 
    }
    nodoEliminar->anterior->siguiente = nodoEliminar->siguiente;
    nodoEliminar->siguiente->anterior = nodoEliminar->anterior;
    activo = nodoEliminar->siguiente;
    delete nodoEliminar;

    cuantos--;
}
/**
 * @brief Devuelve la cantidad de recetas en la lista.
 *
 * @return Número de recetas en la lista.
 */
int ListaReceta::DevuelveCuantos()
{
    return cuantos;
}
/**
 * @brief Muestra por pantalla todas las recetas en la lista.
 */
void ListaReceta::MostrarPantalla()
{
    if (cabeza == NULL)
        cout << "No hay elementos "<< endl;
        
    Nodo* actual = cabeza;
    do {
        cout << actual->dato << endl;
        actual = actual->siguiente;
    } while (actual != cabeza);
}

/**
 * @brief Guarda la lista de recetas en un archivo.
 *
 * @param nombreFichero Nombre del archivo donde se guardará la lista.
 * @return true si se pudo guardar correctamente, false si hubo algún error.
 */
bool ListaReceta::GuardarEnFichero(const string& nombreFichero)
{
	bool guardar = false;
    ofstream archivo(nombreFichero.c_str());
    Nodo* actual = cabeza;

    if (cabeza == NULL) {
        archivo.close();
        guardar = true;
    }

    do {
        archivo << actual->dato << endl;
        actual = actual->siguiente;
    } while (actual != cabeza);

    archivo.close();
    guardar = true;
    
    return guardar;
}
/**
* @brief Recupera la lista de recetas desde un archivo.
* 
* @param nombreFichero Nombre del archivo desde donde se recuperará la lista.
* @return true si se pudo recuperar correctamente, false en caso contrario.
*/
bool ListaReceta::RecuperarDeFichero(const string& nombreFichero) 
{
	bool f;
    ifstream archivo(nombreFichero.c_str());
    if (!archivo.is_open()) 
        f = false;

    Valor receta;
    while (archivo >> receta) {
        InsertarEnOrden(receta);
    }
    archivo.close();
    f = true;
    
    return f;
}

