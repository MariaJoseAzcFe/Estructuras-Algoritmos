/******* Mazo.cpp ********************************************************/ /**
 *
 * @file Mazo.cpp
 *
 * ImplementaciÃ³n de los mÃ©todos de la clase Mazo
 *
 * @version 5.0
 * @author Alejandro Hernandez Perez
 * @author Maria Jose Azcarate Ferrando
 * @date 13/03/2024
 *  
 ******************************************************************************/
#include <iostream>

#include "Mazo.h"
#include <regex>
#include "carta.h"
using namespace std;
/*** Mazo::Mazo() *******************************************/ /**
 *
 *  Constructor por defecto:
 *  Asigna valores iniciales 'coherentes' al atributo del nombre de la clase
 *
 */ /**********************************************************************/
Mazo::Mazo()
{
 	nombreMazo = "<sin asignar>";	
}

/**********************************************************************/ /**
 *
 *  Añade una carta recibida como parametro de entrada al mazo.
 *
 *  @param [in]  c parametro de la carta que se va a añadir al conjunto.
 *
 */ /**********************************************************************/
void Mazo::AnadirCarta(Carta c)
{
	vec_cards.push_back(c);
}

/**********************************************************************/ /**
 *
 *  Asigna un nuevo nombre introducido como parametro de entrada al nombre del Mazo.
 *
 *  @param [in]  new_nom nuevo nombre con el que se va a sustituir el nombre del Mazo.
 *
 */ /**********************************************************************/
void Mazo::AsignarNombreMazo (string new_nom)
{
	nombreMazo = new_nom;
}

/**********************************************************************/ /**
 *
 *  Añade una carta recibida como parametro de entrada al mazo.
 *
 *  @return el string del nombre que le corresponde al mazo
 *
 */ /**********************************************************************/
string Mazo::DevuelveNombreMazo()
{
	return nombreMazo;
}

/**********************************************************************/ /**
 *
 *  Esta función Muestra las propiedades del mazo, que vienen a ser su nombre
 *  y el nombre de las cartas que tiene dentro (si tiene).
 *
 */ /**********************************************************************/
void Mazo::MostrarMazo()
{
	unsigned int i;
	
	cout << "Nombre del mazo: " << nombreMazo << endl;
	cout << "Cantidad de cartas: " << vec_cards.size() << endl;
	
	cout << "Las cartas en su interior son: ";
	for (i = 0; i < vec_cards.size(); i++)
		cout << vec_cards[i].DevuelveNombre() << endl;
	
}

void Mazo::CargarMazoDeFichero(string nombreFichero, const vector<Carta>& cartas)
{
    ifstream fichero(nombreFichero);
    if (!fichero.is_open()) {
        cerr << "Error al abrir el fichero: " << nombreFichero << endl;
        return;
    }

    // Leer el nombre del mazo desde el fichero
    string nombreMazo;
    getline(fichero, nombreMazo);
    AsignarNombreMazo(nombreMazo);

    // Ignorar la línea de separación
    string lineaSeparacion;
    getline(fichero, lineaSeparacion);

    // Leer las cartas del fichero y añadirlas al mazo
    string nombreCarta;
    int cantidad;
    while (fichero >> cantidad >> nombreCarta) {
        // Buscar la carta en el vector de cartas
        Carta cartaEncontrada;
        if (BuscarCartaPorNombre(cartas, nombreCarta, cartaEncontrada)) {
            // Añadir la cantidad correcta de la carta al mazo
            for (int i = 0; i < cantidad; ++i) {
                AnadirCarta(cartaEncontrada);
            }
        } else {
            cerr << "Carta no encontrada: " << nombreCarta << endl;
        }
    }

    fichero.close();
}


