/******* municipio.h ***************************************************/ /**
 *
 * @file municipio.h
 *
 * Fichero de cabecera de la clase municipio
 *
 * Anyadidos algunos 'putters' y 'getters' a la clase en la version 1.1
 *
 * @version 1.1
 * @author Ricardo Ferris
 * @date 21/02/2024
 *
 * @version 1.0
 * @author Jose Fco. Garcia, Jesus Albert
 * @date 19/02/2024
 *  
 ***************************************************************************/

#ifndef _MUNICIPIO_H_
#define _MUNICIPIO_H_

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Definicion del vector de datos de poblacion en distintos anyos     
static const int N_ANYOS = 25;    ///< Num anyos sobre los que hay datos

typedef int VecDatos[N_ANYOS];    ///< Tipo vector de datos (poblacion)

/**
 * @brief Clase para el manejo de municipio
 *
 * Clase para manejar la informacion de municipioes.
  */
class Municipio
{
    public:
        // Constructor por defecto
        Municipio();
        
        // Operaciones para modificar información del municipio
        void AsignarValores(string, string, int, const VecDatos);
        
		void AsignarCodine(string);
        void AsignarNombre(string);
        void AsignarDatos(int, const VecDatos);

		// Operaciones para devolver información del municipio
		string ObtenerCodine() const;
        string ObtenerNombre() const;
        int ObtenerDatos(VecDatos) const;
        int ObtenerUltimoAnyo() const;
        
        // Operaciones adicionales        
        bool LeerDeFichero(ifstream &);
        void Mostrar() const;

    private:  
        /** Ultimo anyo del que se tienen datos */
        static const int ANYO_INICIO = 2022;

        // Atributos propios del municipio:
        string codine;          ///< Codigo INE del municipio
        string nombre;          ///< Nombre del municipio
        unsigned int n_datos;   ///< num. de anyos para los que hay datos
        VecDatos datos;         ///< Datos de poblacion de los ultimos N_ANYOS
                                //   datos[0] = 2022, datos[1] = 2021, ...
};

#endif
