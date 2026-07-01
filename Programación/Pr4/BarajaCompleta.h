
#ifndef _LEER_CARTAS_H_
#define _LEER_CARTAS_H_

#include <string>
#include "carta.h"

class BarajaCompleta
{
    public:
        bool LeerCartas(string nombre);
        bool ObtenerCartasAtributos(string, string, string, vector<Carta> &);
    
    private:

        struct CartaCompleta
        {
            vector<string> contenidos;
        };

        vector<string> cabecera;
        vector<CartaCompleta> cartas_completas;
        
        void AnalizaLineaCabecera(string, vector<string> & cabecera);
        CartaCompleta AnalizaLineaCarta(string);
        size_t AnalizaLineaComillas(string, size_t);
        
        size_t BuscarEnCabecera(string);
};

#endif
