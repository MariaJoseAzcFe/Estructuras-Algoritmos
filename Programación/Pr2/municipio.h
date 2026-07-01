
/******* municipio.h ***************************************************/ /**
 *
 * @file municipio.h
 *
 * Fichero de cabecera de la clase municipio
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
		// Operaciones para devolver información del municipio
		string DevuelveCodine();
		// Operaciones para modificar información del municipio
		void PonCodine(string);
        bool LeerDeFichero(ifstream &);
        void Mostrar();

    private:  
        // Definición del vector de datos de poblacion en distintos años     
        static const int N_ANYOS = 25;    ///< Num años sobre los que hay datos
        typedef int VecDatos[N_ANYOS];  ///< Tipo vector de datos (poblacion)
        
        static const int ANYO_INICIO = 2022;    ///< Ultimo año del que se tienen datos
        // Atributos propios del municipio:
        string codine;          ///< Código INE del municipio
        string nombre;          ///< Nombre del municipio
        unsigned int ndatos;    ///< num. de años para los que hay datos
        VecDatos datos;         ///< Datos de poblacion de los ultimos 25 años
                                //   datos[0] = 2022, datos[1] = 2021, ...
};

#endif
