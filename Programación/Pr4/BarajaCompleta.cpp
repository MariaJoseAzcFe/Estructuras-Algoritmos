
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

const string NOM_FICH = "cards.csv";

#include "carta.h"
#include "BarajaCompleta.h"

size_t BarajaCompleta::BuscarEnCabecera(string s)
{
    size_t pos, i = 0;
    
    while (i < cabecera.size() && cabecera[i] != s)
        i++;
        
    if (i < cabecera.size())
        pos = i;
    else
        pos = string::npos;
        
    return pos;
}

bool BarajaCompleta::ObtenerCartasAtributos(string s1, string s2, string s3,
                                                        vector<Carta> & cartas)
{
    bool ok;
    Carta c;
    size_t pos1, pos2, pos3;
    
    pos1 = BuscarEnCabecera(s1);
    pos2 = BuscarEnCabecera(s2);
    pos3 = BuscarEnCabecera(s3);
    
    if (pos1 != string::npos && pos2 != string::npos && pos3 != string::npos)
    {
        ok = true;
        
        for (size_t i = 0; i < cartas_completas.size(); i++)
        {
            c.AsignarValores(cartas_completas[i].contenidos[pos2],
                             cartas_completas[i].contenidos[pos1],
                             cartas_completas[i].contenidos[pos3]);
            cartas.push_back(c);
        }
    }
    else
        ok = false;

    return ok;
}

bool BarajaCompleta::LeerCartas(string nombre)
{
    bool ok;
    ifstream fich;
    string linea;
    CartaCompleta carta_completa;
    
    fich.open(nombre);
    
    if (!fich)
        ok = false;
    else
    {
        ok = true;
        
        // leemos la cabecera y la analizamos para sacar el vector cabeceras
        cout << "Analizando cabecera.\n";
        getline(fich, linea);
        AnalizaLineaCabecera(linea, cabecera);
        cout << "Cabecera analizada.\n";
        cout << cabecera.size() << " elementos en la cabecera.\n";
        
        // Para el resto de lineas las leemos, las analizamos para obtener la
        // carta y ponemos la carta en el vector de cartas
        cout << "Analizando cartas.\n";
        while (getline(fich, linea))
        {
            carta_completa = AnalizaLineaCarta(linea);
            if (carta_completa.contenidos.size() != cabecera.size())
            {
                cout << "Error en la lectura de atributos de una carta.\n";
                cout << "Elementos distintos: ";
                cout << carta_completa.contenidos.size() << " - ";
                cout <<  cabecera.size() << endl;
                cout << carta_completa.contenidos[0] << endl;
                cout << "Seguimos con el resto de cartas.\n";
                system("PAUSE");
            }
            else
                cartas_completas.push_back(carta_completa);
        }
        cout << '\n';
        cout << "Cartas analizadas -> " << cartas_completas.size() << ".\n";
        
        fich.close();
    }
    
    return ok;
}

void BarajaCompleta::AnalizaLineaCabecera(string linea,
                                                      vector<string> & cabecera)
{
    size_t pos, pos_ant = 0;
    
    pos = linea.find(",", pos_ant);
    while (pos != string::npos)
    {
        cabecera.push_back(linea.substr(pos_ant, pos - pos_ant));
        pos_ant = pos + 1;
        pos = linea.find(",", pos_ant);
    }
    cabecera.push_back(linea.substr(pos_ant, linea.length() - pos_ant));
    
    return;
}

BarajaCompleta::CartaCompleta BarajaCompleta::AnalizaLineaCarta(string linea)
{
    CartaCompleta carta_completa;
    size_t pos_coma, pos_comillas, pos_fin_comillas, pos_ant = 0;

    pos_coma = linea.find(",", pos_ant);
    pos_comillas = linea.find("\"", pos_ant);
    while (pos_coma != string::npos)
    {
        if (pos_coma < pos_comillas)
        {
            carta_completa.contenidos.push_back(linea.substr(pos_ant,
                                                           pos_coma - pos_ant));
            pos_ant = pos_coma + 1;
        }
        else
        {
            pos_fin_comillas = AnalizaLineaComillas(linea, pos_comillas);
            carta_completa.contenidos.push_back(linea.substr(pos_comillas + 1,
                                        pos_fin_comillas - (pos_comillas + 1)));
            pos_ant = pos_fin_comillas + 2;
        }
        pos_coma = linea.find(",", pos_ant);
        pos_comillas = linea.find("\"", pos_ant);
    }
    carta_completa.contenidos.push_back(linea.substr(pos_ant, linea.length() - pos_ant));
    
    return carta_completa;
}

// Damos por supuesto que la linea esta bien conformada y no hay errores de
// sintaxis
size_t BarajaCompleta::AnalizaLineaComillas(string linea, size_t pos)
{
    vector<char> pila;
    
    pila.push_back('\7');
    pos++;
    while (pila.size() != 0)
    {
        if (linea[pos] == '{')
        {
            pila.push_back(linea[pos]);
            pos++;
        }
        else if (linea[pos] == '}')
        {
            pila.pop_back();
            pos++;
        }
        else if (linea[pos] == '"' && linea[pos + 1] == '"')
        {
            if (pila[pila.size() - 1] == '"')
                pila.pop_back();
            else
                pila.push_back('"');
            pos += 2;
        }
        else if (linea[pos] == '"' && linea[pos + 1] == ',')
        {
            pila.pop_back();
        }
        else
            pos++;
    }
    
    return pos;
}
