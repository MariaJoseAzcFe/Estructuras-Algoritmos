/**
 * @file grafo.h
 * @brief Pr7: Interfaz de la clase Grafo
 * Implementado como listas de adyacencia con tablas hash
 *
 * @author: Jesús Albert
 * @date: 11/12/2024
 * @version 1.0
 */
 
#ifndef _GRAFO_H_
#define _GRAFO_H_

#include <unordered_map>
#include <vector>

using namespace std;

//Tipo para el peso asociado a los arcos
typedef size_t TipoPeso;

/**
 * @brief Clase Grafo
 * Especificación genérica usando unordered_map para construir la
 * lista de adyacencia de cada nodo
 */
class Grafo
{
    public:     
        /// @brief Constructor con numero de nodos      
        Grafo(size_t); 
        /// @brief Asignar arco entre dos nodos con un peso
        void AsignarArco(size_t, size_t, TipoPeso);
        /// @brief Obtener peso del arco entre dos nodos
        TipoPeso PesoArco(size_t, size_t) const;
        /// @brief Obtener la lista de adyacencia de un nodo
        vector<size_t> NodosAdyacentes(size_t) const;
        /// @brief Numero de nodos del grafo
        size_t Size() const;
        /// @brief Imprimir arcos de un nodo
        void Print(size_t) const;
    private:
        /// @brief Vector de nodos con sus arcos como listas de adyacencia en forma de unordered_map: clave=destino, valor=peso
        std::vector< std::unordered_map<size_t,TipoPeso> > arcos;
};

#endif

