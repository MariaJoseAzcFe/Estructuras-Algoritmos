/**
 * @file main.cpp
 * @brief Pr7: Programa principal para explorar escenarios con grafos
 *
 * Implementa todas las funcionalidades requeridas por el guion de la Práctica 7.
 * Permite leer escenarios, construir grafos, explorar accesibilidad y detectar posiciones inaccesibles.
 *
 * @author: María José Azcárate y Juan Pablo Gómez
 * @date: 23/12/2024
 * @version: 1.0
 */
#include "grafo.h"
#include "pr7.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;
/**
 * @brief Realiza un recorrido en profundidad (DFS) desde un nodo origen
 * para determinar qué nodos son alcanzables.
 *
 * @param grafo El grafo a explorar.
 * @param origen El nodo origen desde el cual comienza la exploración.
 * @return vector<bool> Vector de booleanos donde `true` indica que el nodo
 *         es alcanzable desde el origen.
 */
vector<bool> ExplorarGrafo(const Grafo& grafo, size_t origen) 
{
    vector<bool> visitados(grafo.Size(), false); 
    stack<size_t> pila;  
    vector<size_t> adyacentes;                       
    size_t nodo;
    
    pila.push(origen);
    visitados[origen] = true;

    while (!pila.empty()) 
    {
        nodo = pila.top();
        pila.pop();


        adyacentes = grafo.NodosAdyacentes(nodo);

        for (const auto& vecino : adyacentes) 
        {
            if (!visitados[vecino]) 
            { 
                visitados[vecino] = true;
                pila.push(vecino);
            }
        }
    }

    return visitados;
}
/**
 * @brief Carga un escenario desde un archivo.
 * 
 * Esta función lee un archivo que contiene un escenario en formato de texto. 
 * El archivo debe comenzar con las dimensiones del escenario (alto y ancho),
 * seguidas por líneas de caracteres donde cada posición está representada por:
 * - '.' para posiciones transitables.
 * - 'X' para posiciones no transitables (obstáculos).
 * 
 * @param filename Nombre del archivo que contiene la descripción del escenario.
 * @return Escenario Objeto que representa el escenario cargado, con sus dimensiones
 *         y el estado de cada posición (transitable o no).
 * 
 * @throws runtime_error Si el archivo no se puede abrir.
 */
Escenario CargarEscenario(const string& filename) 
{
    size_t index;
    string linea;
    ifstream file(filename);
    Escenario escenario;
    size_t alto, ancho;
    if (!file.is_open()) {
        throw runtime_error("No se pudo abrir el archivo: " + filename);
    }
    file >> alto >> ancho; 

    escenario.alto = alto;
    escenario.ancho = ancho;
    escenario.posiciones.resize(alto * ancho);

    index = 0;
    while (getline(file, linea)) 
    {
        for (char c : linea) 
        {
            if (c == '.') {
                escenario.posiciones[index++] = true;
            } else if (c == 'X') {
                escenario.posiciones[index++] = false;
            }
        }
    }

    file.close();
    return escenario;
}

/**
 * @brief Determinar las posiciones inaccesibles desde un nodo origen.
 * 
 * @param escenario El escenario cargado.
 * @param grafo El grafo generado a partir del escenario.
 * @param origen Nodo origen desde el cual explorar.
 */
void DeterminarInaccesibles(const Escenario& escenario, const Grafo& grafo, size_t origen) 
{
    vector<bool> visitados = ExplorarGrafo(grafo, origen);
    vector<size_t> inaccesibles;
    size_t transitables = 0, visitados_count = 0;

    for (size_t i = 0; i < escenario.posiciones.size(); i++) 
    {
        if (escenario.posiciones[i]) 
        {
            transitables++; 
            if (!visitados[i]) 
            {
                inaccesibles.push_back(i); 
            } else 
            {
                visitados_count++; 
            }
        }
    }

    cout << "=== Resultados para el nodo origen " << origen << " ===" << endl;
    cout << "Total posiciones transitables: " << transitables << endl;
    cout << "Total posiciones alcanzadas: " << visitados_count << endl;
    cout << "Total posiciones inaccesibles: " << inaccesibles.size() << endl;

    if (!inaccesibles.empty()) 
    {
        cout << "Posiciones inaccesibles: ";
        for (size_t id : inaccesibles) 
        {
            cout << id << " ";
        }
        cout << endl;
    }
}
/**
 * @brief funcion principal
 */
int main() 
{
    try {

        Escenario escenario = CargarEscenario("data/escenario_small.dat");
        Grafo grafo(escenario.alto * escenario.ancho);
        Escenario escenario_grande;

        for (size_t i = 0; i < escenario.posiciones.size(); i++) 
        {
            if (escenario.posiciones[i]) {
                for (size_t vecino : Vecinos(i, escenario)) 
                {
                    if (escenario.posiciones[vecino]) 
                    {
                        grafo.AsignarArco(i, vecino, 1); 
                    }
                }
            }
        }

        // Pruebas con dos nodos origen
        DeterminarInaccesibles(escenario, grafo, 11); 
        DeterminarInaccesibles(escenario, grafo, 28); 

        escenario_grande = CargarEscenario("data/escenario.dat");
        Grafo grafo_grande(escenario_grande.alto * escenario_grande.ancho);

        for (size_t i = 0; i < escenario_grande.posiciones.size(); i++) 
        {
            if (escenario_grande.posiciones[i]) 
            {
                for (size_t vecino : Vecinos(i, escenario_grande)) 
                {
                    if (escenario_grande.posiciones[vecino]) 
                    {
                        grafo_grande.AsignarArco(i, vecino, 1); 
                    }
                }
            }
        }

        DeterminarInaccesibles(escenario_grande, grafo_grande, 101);  
        DeterminarInaccesibles(escenario_grande, grafo_grande, 1279); 

    } catch (const exception& e) 
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
