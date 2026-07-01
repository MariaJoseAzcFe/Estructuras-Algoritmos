#include "partida.h"
#include "buffer.h"
#include <iostream>
#include <string>



using namespace std;

/**
 * @brief Construye una nueva partida
 * 
 */
Partida::Partida()
{
    /*
    for (int i = 0; i < 5; i++) 
    { 
        jugadores.push_back("");
        
    }
    */
}
/**
 * @brief Agrega un jugador a la partida
 * @pre Que se pueda incorparar un jugador a la sala de espera
 * @exception te imprime que es imposible conectar
 * @param nombre 
 */

void Partida::agregarJugador(const string& nombre) 
{
    string nombreTemporal;
    char numeroPartida;
    bool jugadorAgregado = false;

    nombreTemporal = nombre;
    numeroPartida=nombreTemporal[0];
  

    nombreTemporal.erase(0,2);
   

    if(jugadores.size()<5)
    {
        jugadores.push_back(nombreTemporal);
        cout << nombreTemporal <<": Entra a jugar en "<< numeroPartida<< endl;
        jugadorAgregado = true;
    }
    /*
    for (int i = 0; i < 5 && !jugadorAgregado; i++) 
    {
        if (jugadores[i].empty()) 
        {
            jugadores[i] = nombreTemporal;
            cout << nombreTemporal <<": Entra a jugar en "<< numeroPartida<< endl;
            jugadorAgregado = true;
        }
    }
    */
    if(jugadorAgregado == false)
    {   


            try 
            {
                salaEspera.Incorporar(nombreTemporal);  
                cout << nombreTemporal << ": Espera turno en la sala de espera " <<numeroPartida<< endl;
               
            } 
            catch (const exception& e) 
            {
                
                cout << nombre << ": Imposible conectar, inténtelo más tarde" << endl;
                
            }

    }

}
/**
 * @brief El jugador abandona la partida e intenta llamar a la función moverDesdeSalaEspera
 * 
 * @param numeroPartida 
 * @return string 
 */

string Partida::abandonarPartida(const char& numeroPartida) 
{
   
    
    string jugadorqueAbandona;

   
    if(!jugadores[0].empty())
    {
        jugadorqueAbandona = jugadores[0];
        cout<<jugadorqueAbandona<<": Ha finalizado su partida en "<<numeroPartida<<endl; 
        jugadores.erase (jugadores.begin()); 
        moverDesdeSalaEspera(numeroPartida);
    }
   
    return jugadorqueAbandona;
}

/**
 * @brief Intenta mover usuario a la partida
 * @pre Que haya minimo un jugador en la sala de espera
 * @exception imprime las plazas disponibles
 * @param numeroPartida 
 * @return string 
 */

string Partida::moverDesdeSalaEspera(const char& numeroPartida)
{

    string jugador;

    try
    {
        jugador = salaEspera.Primero();
        salaEspera.Eliminar();
        jugadores.push_back(jugador);
        cout<< jugador<<": Asignado a la partida  "<<numeroPartida<<endl;
        
    
       
    }
    catch (const exception& e) 
    {
                
        cout <<"Hay plazas disponibles en " <<numeroPartida<< endl;
                
    }

    return jugador;
   

}

