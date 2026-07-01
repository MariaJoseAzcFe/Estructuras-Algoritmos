/****** Pr6_Prueba.cpp *****************************************************/ /**
 *
 * @file Pr6_JuegoCartas.cpp
 *
 * @brief Prácticas de Programación.
 *
 * Programa que implementa una baraja de cartas.
 *
 * @version 2
<<<<<<< HEAD
 * @author Hern?ndez P?rez Alejandro, Azcarate Ferrando Mar?aJos?
 * @author Jesús Albert
 * @author Miguel A. Gamón
=======
 * @author Hernández Pérez Alejandro, Azcarate Ferrando MaríaJosé
 * @author JesÃºs Albert
 * @author Miguel A. GamÃ³n
>>>>>>> 859c8b953fcbd989fe49a7522498541b8c738133
 * @author Emiliano Torres
 * @date 25/03/2024
 *
 */ /***************************************************************************/


#include <iostream>
#include <fstream>
#include <vector>
#include "Pr6_Carta.h"
#include "Pr6_Pila.h"
#include <stdlib.h> 
#include <ctime>

using namespace std;

/*
 * Una baraja es un vector de cartas
 */
typedef vector<Carta> Baraja;

//Funciones
void IniciarBaraja (Baraja &);
void Barajar (Baraja &);
void TransferirMazo (Baraja, Pila<Carta>&);
void RepartirCartas (Pila<Carta>&, Pila<Carta>&, Pila<Carta> &);
void MostrarBaraja (Baraja b);
bool sePuedeMoverCarta(Pila<Carta>&);
int Puntuacion (vector<Carta>);
void MoverParaPunt (Pila<Carta>&, Baraja&);
void LeerGanador (string&, int &);
void GuardarGanador (string, int);
int main()
{
	
	Baraja final;
	int punt;
	ifstream fi;
	ofstream fo;
	string nombre;
	Carta cartaMovida;
	Pila<Carta> centro, jugadas, mano;	
	Baraja d;
	char opcion;
	
	cout << "Bienvenido a este juego de cartas" << endl;
	cout << "A continuacion, vamos a crear una baraja, y vamos a mezclarla bien" << endl;
	IniciarBaraja (d);
	Barajar (d);
	MostrarBaraja(d);
	TransferirMazo (d, centro);

    cout << "Mazo Central:" << endl;
    cout << "--------------" << endl;
    cout << centro;
   	
    RepartirCartas (centro, jugadas, mano);
		
    	if (!sePuedeMoverCarta(centro))
		{
        	cout << "No puedes mover ninguna carta. Fin del juego!" << endl;
         
    	}
	        do
	        {
	        	cout << "Quieres jugar otra carta ? (s/n): ";
	        	cin >> opcion;
				if (opcion == 's' || opcion == 'S')
				{
				   mano.CimaPila(cartaMovida);
				   jugadas.Apilar(cartaMovida);
				   mano.Desapilar();
      		   
		           cout << "Cartas Jugadas:" << endl;
	        	   cout << jugadas;
		        } 
				else
				{
		            cout << "Dejaste de mover cartas" << endl;
		        }
			}while (opcion == 's' || opcion == 'S');


    MoverParaPunt (jugadas, final);
    punt = Puntuacion (final);
    MostrarBaraja (final);
    GuardarGanador(nombre, punt);
    LeerGanador (nombre, punt);
    
	
    cout << "Centro: ";
    cout << centro;
    cout << "Jugadas: ";
    cout << jugadas;
        
    	if (!sePuedeMoverCarta(jugadas))
		{
        	cout << "No puedes mover ninguna carta. ¡Fin del juego!" << endl;
         
    	}
        
	        cout << "¿Quieres mover una carta al mazo central? (s/n): ";
	        cin >> opcion;
	        if (opcion == 's' || opcion == 'S')
			{
	            // Mover carta al mazo central
	            if (jugadas.Desapilar()) 
				{
	                centro.Apilar(cartaMovida);
	            } 
				else 
				{
	                cout << "No hay cartas en tu jugada." << endl;
	            }
	        } 
			else
			{
	            cout << "Dejaste de mover cartas" << endl;
	        }
     


    return 0;
}


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


void TransferirMazo (Baraja bar, Pila<Carta>& p)
{
	unsigned int i;
	
	for (i = 0; i < bar.size(); i++)
	{
		p.Apilar(bar[i]);
	}
}


void RepartirCartas (Pila<Carta>& cent, Pila<Carta>& jug, Pila<Carta>& mano)
{
	unsigned int i;
	Carta c;
	
	if (cent.CimaPila(c))
    {
    	jug.Apilar(c);
		cent.Desapilar();	
	}
	
	for (i = 0; i < 7; i++)
		 
 		 cent.CimaPila(c);
 		 mano.Apilar(c);
 		 cent.Desapilar();
}

void MostrarBaraja (Baraja b)
{
	if (b.empty ())
		cout << "La baraja esta vacia.";
	else
		for (unsigned int i = 0; i < b.size (); i++)
			cout << b[i] << " ";
		
	cout << endl;
}
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
bool sePuedeMoverCarta(Pila<Carta>& mano) 
{
	bool mover;
	mover = !mano.PilaVacia();
    return mover;
}


void MoverParaPunt (Pila<Carta>& Pil, Baraja& final)
{
 	 vector<Carta> vec;
 	 int i = 0;
	  
	  while (!Pil.PilaVacia())	
 	 {
 	 	Pil.CimaPila(vec[i]);
 	 	final.push_back(vec[i]);
 	 	Pil.Desapilar();
	 	i++;
	 }
}

int Puntuacion (vector<Carta> punt)
{
	unsigned int i, total;
	for (i = 0; i < punt.size(); i++)
	{
		total += punt[i].DevuelveNumero();
	}
	
	return total;
}

void LeerGanador (string & nom, int & valor)
{
	ifstream fich;
	
	fich.open("Puntuaciones.txt");
 	if (fich.fail())
  	{
  		cerr << "El fichero no se puedo abrir" << endl;
 	}
 	else
 	{
 		fich >> nom;
 		fich >> valor;
 	}	
 	fich.close();
}

void GuardarGanador (string nom, int puntaje)
{
	ofstream sal;
	sal.open ("Puntuaciones.txt");
	if (sal.fail())
	{
		cerr << "El fichero no se puede abrir" << endl;
	}
	else 
	{
		sal << nom << endl;
		sal << puntaje << endl;
	}
	sal.close();
}
