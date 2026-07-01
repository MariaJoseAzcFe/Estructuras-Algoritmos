/**
 * @file grafo.cpp
 * @brief Pr7: Implementacion de la clase Grafo (Solucion)
 *
 * @author: Jesus Albert
 * @date: 11/12/2024
 * @version 1.0
 */
 
#include "grafo.h"
#include <unordered_map>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

/**
 *  @brief Constructor de Grafo
 *
 *  @param [in]  tam Numero de nodos del grafo
 * 
 *  @pre tam > 0
 *  @exception out_of_range si no cumple precondicion
 */
Grafo::Grafo(size_t tam)
{
    if (tam <= 0)
        throw out_of_range("Grafo: tamanyo <= 0");
    arcos.resize(tam);
}

/**
 *  @brief Asignar un arco (dirigido) entre nodos del Grafo
 *
 *  @param [in]  orig nodo origen del arco
 *  @param [in]  dest nodo destino del arco
 *  @param [in]  p  peso asignado al arco
 * 
 *  @pre 0 <= orig <= Size() y 0 <= dest <= Size() 
 *  @exception out_of_range si no cumple precondicion
 */
void Grafo::AsignarArco(size_t orig, size_t dest, TipoPeso p)
{
    if ( orig < 0 || orig > this->Size() )
            throw out_of_range("AsignarArco: origen fuera de rango");
    else if ( dest < 0 || dest > this->Size() )
            throw out_of_range("AsignarArco: destino fuera de rango");
    else
        arcos[orig][dest] = p;
}

/**
 *  @brief Obtener el peso de un arco (dirigido) entre nodos del Grafo
 *
 *  @param [in]  orig nodo origen del arco
 *  @param [in]  dest nodo destino del arco
 *  @return peso del arco
 *  @retval 0 si no existe el arco
 * 
 *  @pre 0 <= orig <= Size() y 0 <= dest <= Size() 
 *  @exception out_of_range si no cumple precondicion
 */
TipoPeso Grafo::PesoArco(size_t orig, size_t dest) const
{
    if ( orig < 0 || orig > this->Size() )
            throw out_of_range("PesoArco: orig fuera de rango");
    else if ( dest < 0 || dest > this->Size() )
            throw out_of_range("PesoArco: dest fuera de rango");
    else
    {
        TipoPeso p;
        
        try //puede no existir el arco
        {
            p = arcos.at(orig).at(dest);
        }
        catch(const std::exception& e)
        {
            p = 0; //No existe arco
        }
        return p;
    }
}

/**
 * @brief Devolver la lista de nodos adyacentes a un nodo
 * 
 * @param i nodo del que se desean obtener los adyacentes
 * @return list<size_t> lista de nodos destino de los arcos
 *
 *  @pre 0 <= i <= Size()
 *  @exception out_of_range si no cumple precondicion
 */
vector<size_t> Grafo::NodosAdyacentes(size_t i) const
{
    if ( i < 0 || i > this->Size() )
        throw out_of_range("ListaAdyacencia: indice fuera de rango");
    else
    {
        vector<size_t> nodos;

        for (auto a : arcos[i])
            nodos.push_back(a.first);
        return nodos;
    }
}

/**
 *  @brief Numero de nodos del Grafo
 *
 *  @return numero de nodos
 */
size_t Grafo::Size() const
{
    return arcos.size();
}

/**
 * @brief Imprimir en pantalla los arcos de un nodo del Grafo
 * 
 * @param [in]  orig nodo cuyos arcos se muestran
 * 
 *  @pre 0 <= orig <= Size()
 *  @exception out_of_range si  no cumple precondicion
*/
void Grafo::Print(size_t orig) const
{
    unordered_map<size_t,TipoPeso>::const_iterator it;

    if ( orig < 0 || orig > this->Size() )
            throw out_of_range("Print: orig fuera de rango");

    else
    {
        cout << "Nodo " << orig << " (num.arcos=" << arcos[orig].size() << ")" << endl;
        cout << string(60,'-') << endl;
        for (it = arcos[orig].begin(); it != arcos[orig].end();  it++)
            cout << "<" << orig << "," << it->first << ">:" << it->second << " ";
        cout << endl;
        cout << string(60,'-') << endl;
    }
}

