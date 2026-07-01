
#include <iostream>
using namespace std;
#include <conio.h>
#include "FuncAux.h"
#include "Ascensor.h"
#include "ColaP.h"


const int NUM_PLANTAS = 5;
//Programa principal

int main (void)
{
    char tecla = 's';
    Ascensor a(NUM_PLANTAS);
    Cola ColaInt,ColaExt;
	int piso;
	
	gotoxy(1,0);
    cout<<"Pulsa la tecla del piso al que quieres subir" <<endl;
    cout<<"Para ejecutar la orden y que el ascensor sube pulse la tecla m" <<endl;
    cout<<"Para salir del programa pulse s" << endl;
    gotoxy(1,4);
    cout<<"Pisos en la cola interior: ";
    gotoxy(1,7);
    cout<<"Pisos en la cola exterior: ";

    // Aqui se incluira el bucle que atiende la simulacion
    do
    {
		do	
		{
	    	tecla = getch();
	    	if (tecla >= '0' && tecla <= '4') {
	        	if (!ColaInt.Buscar(tecla - '0') && !ColaExt.Buscar(tecla - '0')) {
	            	ColaInt.Encolar(tecla - '0');
	            	gotoxy(1, 1);
	            	cout << "Encolando en la cola interior. Piso: " << tecla << endl;
	        	}
	    	}
	    	if (tecla >= 'A' && tecla <= 'E') {
	        	if (!ColaInt.Buscar(tecla - 'A') && !ColaExt.Buscar(tecla - 'A')) {
	            	ColaExt.Encolar(tecla - 'A');
	            	gotoxy(1, 1);
	            	cout << "Encolando en la cola exterior. Piso:  " << tecla << endl;
	        	}
	    	}
	    	else 
	    	{
	    		cout << "Has introducido un valor incorrecto de tecla" << endl;
			}
	    gotoxy(1, 5);
	    cout << "Cola interior: ";
	    ColaInt.MostrarCola();
	    gotoxy(1, 8);
	    cout << "Cola exterior: ";
	    ColaExt.MostrarCola();
	}
		while (tecla != 'm' && tecla != 'M' && tecla != 's' && tecla != 'S');
	
			
				if(tecla== 'm' || tecla == 'M')
				{
					if(!ColaInt.ColaVacia())
					{
						piso = tecla-'0';
						ColaInt.PrimeroCola(piso);
						ColaInt.Desencolar();
						a.MoverAscensor(piso);
					}
					else
					{
						if(!ColaExt.ColaVacia())
						{
						piso = tecla-'A';
						ColaExt.PrimeroCola(piso);
						ColaExt.Desencolar();
						a.MoverAscensor(piso);
						}
					}
				}
			
	    
	}while ((tecla != 's') && (tecla != 'S'));
    gotoxy(0, ALTO - 3); 			
    
    return 0;
}
