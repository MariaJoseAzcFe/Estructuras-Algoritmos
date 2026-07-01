
#define CSV_IO_NO_THREAD

#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
using namespace std;
#include "BarajaCompleta.h"
#include "carta.h"

const string CARD_CSV = "cards.csv";

int CargarCartas(string filename, vector<Carta> & cartas);

int main()
{
    vector<Carta> vector;
    int error;

    SetConsoleOutputCP(CP_UTF8);

    error = CargarCartas(CARD_CSV, vector);
    
    if (error == 0)
    {
        system("PAUSE");
    }
    else if (error == 1)
        cout << "Se ha producido un error creando el vector de cartas.\n";
    else if (error == 2)
        cout << "Error en la lectura del fichero " << CARD_CSV << endl;
    else
        cout << "Codigo de error desconocido.\n";
    
    return 0;
}

/**
 * Carga todas las cartas existentes contenidas en el fichero pasado como
 * parametro y crea un vector de Carta con las cartas del fichero pero con
 * solo los atributos "name", "type" y "colorIdentity"
 *
 * @param  filename  el nombre del fichero donde esta la informacion
 *                   completa de todas las cartas
 * @param [out] cartas  vector que contiene todas las cartas posibles
 *                      pero solo con los atributos "name", "type",
 *                      "colorIdentity"
 *
 * @retval  0  La lectura y analisis de las cartas ha sido correcto
 * @retval  1  Se ha producido un error en el analisis de los atributos de
 *             las cartas y no se ha creado correctamente el vector de Carta
 * @retval  2  Se ha producido un error en la lectura del fichero 'filename'
 */
int CargarCartas(string filename, vector<Carta> & cartas) 
{
    int cod_error;
    BarajaCompleta baraja_completa;
    
    if (baraja_completa.LeerCartas(filename))
    {
        if (baraja_completa.ObtenerCartasAtributos("name", "type",
                                                   "colorIdentity", cartas))
            cod_error = 0;
        else
            cod_error = 1;
    }
    else
        cod_error = 2;
    
    return cod_error;
}
