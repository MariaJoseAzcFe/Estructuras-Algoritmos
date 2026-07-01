#ifndef PARTIDA_H
#define PARTIDA_H

#include <iostream>
#include "buffer.h"
#include <vector>
#include <string>

using namespace std;
class Partida
{
    public:
        Partida();
        void agregarJugador(const string& nombre);
        string abandonarPartida(const char& numeroPartida);
        string moverDesdeSalaEspera(const char& numeroPartida);
        void mostrarEstado() const;

    private:
        vector <string> jugadores; 
        Buffer<string> salaEspera; 
    
};

#endif
