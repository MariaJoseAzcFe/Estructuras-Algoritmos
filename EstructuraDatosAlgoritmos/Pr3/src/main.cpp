#include "buffer.h"
#include "partida.h"
#include <iostream>
#include <fstream>

using namespace std;
/**
 * @brief Función principal. Crea una simulación de 5 partidas y una sala de espera para gestionar conexiones y desconexiones.
 * 
 */
int main() 
{
   string linea;
   string nombreJugador;
   char numeroPartida;
   Partida partidas[5];
   
    //Actividad 1
    /*
    Buffer<int> buffer;

    cout << "Prueba de agregar y eliminar elementos en el buffer:" << endl;

    // Añadimos algunos elementos al buffer
    try
    {
        for (int i = 1; i < 10; i++)
        {
            buffer.Incorporar(i);
            cout << "Elemento anadido al buffer: " << i << endl;
        }

        // Consultar y eliminar los elementos
        for (int i = 1; i < 10; i++) 
        {
            cout << "Primer elemento en el buffer: " << buffer.Primero() << endl;
            buffer.Eliminar();
            cout << "Elemento eliminado del buffer." << endl;
        }

        // Intentar eliminar de un buffer vacío para forzar una excepción
        cout << "Intentando eliminar un elemento de un buffer vacio..." << endl;
        buffer.Eliminar();
    }
    catch (const runtime_error& e)
    {
        cout << "Excepcion capturada: " << e.what() << endl;
    }

    // Intentar consultar el primer elemento de un buffer vacío para forzar otra excepción
    try 
    {
        cout << "Intentando acceder al primer elemento de un buffer vacio..." << endl;
        cout << "Primer elemento en el buffer: " << buffer.Primero() << endl;
    }
    catch (const runtime_error& e) 
    {
        cout << "Excepcion capturada: " << e.what() << endl;
    }
    */
    //Actividad 2
    ifstream archivoEntrada("data/datos.txt"); 
    ofstream archivoSalida("data/resultados.txt");

    if (!archivoEntrada.is_open())
    { 
        cerr << "No se pudo abrir el archivo 'datos.txt'";
        return 1;
    }

    if (!archivoSalida.is_open())
    { 
        cerr << "No se pudo abrir el archivo 'resultados.txt'";
        return 1;
    }

     
    cout.rdbuf(archivoSalida.rdbuf());


    

    while (getline(archivoEntrada, linea)) 
    { 
        numeroPartida = linea[2];
        ////////nombreJugador= linea.substr(2,12);

        if(linea[0] == 'C')
        {
            nombreJugador= linea.substr(2,12);
            switch (numeroPartida)  
            {
                case '1':  
                     partidas[0].agregarJugador(nombreJugador);
                     break;

                case '2':  
                     partidas[1].agregarJugador(nombreJugador);
                     break;

                case '3':  
                     partidas[2].agregarJugador(nombreJugador);
                     break;

                case '4':  
                     partidas[3].agregarJugador(nombreJugador);
                     break;

                case '5':  
                     partidas[4].agregarJugador(nombreJugador);
                     break;

                default: 
                     cout << "Número de partida inválido." << endl;
                     break;
            }

        }

        else if(linea[0] == 'D')
        {
            nombreJugador= linea.substr(2,1);
            switch (numeroPartida)  
            {
                case '1':  
                     partidas[0].abandonarPartida(numeroPartida);
                     break;

                case '2':  
                     partidas[1].abandonarPartida(numeroPartida);
                     break;

                case '3':  
                     partidas[2].abandonarPartida(numeroPartida);
                     break;

                case '4':  
                     partidas[3].abandonarPartida(numeroPartida);
                     break;

                case '5':  
                     partidas[4].abandonarPartida(numeroPartida);
                     break;

                default: 
                     cout << "Número de partida inválido." << endl;
                     break;
            }

        }

        //cout << linea << endl;

    }

    archivoEntrada.close(); 
    return 0;



}