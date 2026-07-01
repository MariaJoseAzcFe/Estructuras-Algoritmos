
/****** Pr3_prueba.cpp ****************************************************/ /**
 *
 * @file Pr3_prueba.cpp
 *
 * @brief Practicas de Programacion 3_ Iniciacion a las clases
 *
 * Este programa comprueba la correcta implementacion de los metodos de la
 * clase municipio.
 *
 * @version 1
 * @author Jose Fco. Garcia, Jesus Albert, Ricardo Ferris
 * @date 22/02/2024
 *
 */ /**************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "municipio.h"

/*
 * Prototipos de las funciones empleadas,
 * implementadas despues de main()
 */
void Presentacion(void);
void ComprobarConstructorConParametrosMunicipio(string, string, int, VecDatos);

/*
 * Programa principal
 */
int main()
{
    Municipio municipio;
    string codine,
           nombre;
    int ultimo_anyo;
    VecDatos v,
             datos;
    unsigned int num,
                 i;

    Presentacion();
    
    cout << "Municipio 'por defecto':\n";
    cout << "========================\n";
    municipio.Mostrar();
    
    // Comprobacion del metodo 'Asignar'
    cout << "Comprobacion del metodo 'Asignar'\n";
    cout << "=================================\n";
    for (i = 0; i < N_ANYOS; i++)
        v[i] = N_ANYOS - i;
        
    municipio.AsignarValores("00000", "Municipio de prueba", N_ANYOS, v);
    
    municipio.Mostrar();
   
    // Comprobacion de los metodos 'Setters' y 'Getters'
    cout << "Comprobacion de los metodos 'Setters' y 'Getters'\n";
    cout << "=================================================\n";

    municipio.AsignarNombre("Municipio cambiado");
    
    nombre = municipio.ObtenerNombre();
    cout << "Nombre: " << nombre << endl;

    municipio.AsignarCodine("11111");

    codine = municipio.ObtenerCodine();
    cout << "Codine: " << codine << endl;
    
    ultimo_anyo = municipio.ObtenerUltimoAnyo();
    cout << "Ultimo anyo: " << ultimo_anyo << endl;

    for (i = 0; i < N_ANYOS; i++)
        v[i] = 2 * (N_ANYOS - i);
    municipio.AsignarDatos(N_ANYOS, v);

    num = municipio.ObtenerDatos(datos);
    
    cout << "Num anyos: " << num << endl;
    for (i = 0; i < num - 1; i++)
    {
        cout << datos[i] << ", ";
    }
    cout << datos[i] << ".";

    cout << endl;

    return 0;
}

/**********************************************************************/ /**
 *
 *  Muestra por pantalla que realiza el programa.
 *
 */ /**********************************************************************/
void Presentacion(void)
{
    cout << "Este programa se encarga de comprobar la correcta ";
    cout << "implementacion de la clase municipio llamando a los diferentes ";
    cout << "metodos y comprobando su correcta ejecucion.";
    cout << endl << endl;
    
    return;
}
