/****** Pr6_Prueba.cpp *****************************************************/ /**
 *
 * @file Pr6_Prueba.cpp
 *
 * @brief PrÃ¡cticas de ProgramaciÃ³n.
 *
 * Programa que implementa una baraja de cartas.
 *
 * @version 1.0
 * @author María José Azcárate Ferrando
 * @author Alejandro Hernández Pérez
 * @author Emiliano Torres
 * @date 19/03/2024
 *
 */ /***************************************************************************/

#include <stdlib.h> 
#include <time.h>
#include <iostream>
#include <vector>
#include "Pr6_Carta.h"

using namespace std;

/*
 * Una baraja es un vector de cartas
 */
typedef vector<Carta> Baraja;

//Funciones
void IniciarBaraja (Baraja&);
void Barajar (Baraja&);
void MostrarBaraja (Baraja b);

/*
 * Programa principal
 */
int main()
{
	/**
	 * Declaraciones
	 */
    int i;
    Baraja b;
    Carta c;
    char opcion;
    
    cout << "*** Programa de pruebas de una baraja de cartas." << endl;
    cout << endl;
 
 	// Crea la baraja
    IniciarBaraja (b);
    
    // Muestra la baraja antes de barajar
    cout << "*** Cartas de la baraja (ANTES de barajar):" << endl;
    cout << endl;
    MostrarBaraja (b);
	cout << endl;
	
	// Baraja las cartas de la baraja
	cout << "*** Barajando..." << endl;
	cout << endl; 	
	Barajar (b);
	cout << endl;
		
	 // Muestra la baraja despuÃ©s de barajar
	cout << "*** Cartas de la baraja (DESPUES de barajar):" << endl;
	cout << endl;	
    MostrarBaraja (b);
    cout << endl;
    
    // Coger una carta random   
    do
    {
    	i = rand() % b.size();
	    cout << "La carta de la posicion: " << i  << " es: " << b[i] << endl;
    	cout << "Desea continuar (s/n)? ";
    	cin >> opcion;    	    	
    	cout << endl;
	}
	while (opcion == 's');
}

/**********************************************************************/ /**
 *
 *  Iniciar la baraja antes de empezar a jugar
 *  Se introducen todas las cartas en la baraja b, en el siguiente orden:
 *  12 cartas de oros, copas, espadas y bastos
 *
 *  @param  [in,out]  b  Baraja que se inicia
 *
 *  @return  No devuelve nada
 *
 */ /**********************************************************************/
void IniciarBaraja (Baraja& b)
{
	int i;
	Carta c;
	
	c.EstablecePalo('O');
	for(i=1;i<=12;i++)
	{
		c.EstableceNumero(i);
		b.push_back(c);
	}
	
    c.EstablecePalo('C');
	for(i=1;i<=12;i++)
	{
		c.EstableceNumero(i);
		b.push_back(c);
	}
	c.EstablecePalo('E');
	for(i=1;i<=12;i++)
	{
		c.EstableceNumero(i);
		b.push_back(c);
	}
	c.EstablecePalo('B');
	for(i=1;i<=12;i++)
	{
		c.EstableceNumero(i);
		b.push_back(c);
	}
}

/**********************************************************************/ /**
 *
 *  Barajar las cartas de la baraja
 *
 *  @param  [in,out]  b  Baraja
 *
 *  @return  No devuelve nada
 *
 */ /**********************************************************************/
void Barajar (Baraja& b)
{
    Carta temp;
    int i, m;
    
    if (b.empty ())
		cout << "No hay cartas para barajar." << endl;
	else
	{    
	    srand (time (NULL) );
	    //Barajando, Intercambiando 1000 cartas
	    for (int k = 0; k < 1000; k++) 
		{
	        i = rand() % b.size ();
	        m = rand() % b.size ();
	        temp = b[i];
	        b[i] = b[m];
	        b[m] = temp;
	    }
	}
}

/**********************************************************************/ /**
 *
 *  Muestra la baraja por pantalla
 *
 *  @param  [in]  b  Baraja a mostrar
 *
 *  @return  No devuelve nada
 *
 */ /**********************************************************************/
void MostrarBaraja (Baraja b)
{
	if (b.empty ())
		cout << "La baraja esta vacia.";
	else
		for (unsigned int i = 0; i < b.size (); i++)
			cout << b[i] << " ";
		
	cout << endl;
}


