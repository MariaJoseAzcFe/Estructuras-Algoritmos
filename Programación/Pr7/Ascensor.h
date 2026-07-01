/******* Ascensor.h ****************************************************/ /**
 *
 * @file Ascensor.h
 *
 * Fichero de cabecera de la clase Ascensor
 *
 * @version 1.0
 * @author Ricardo Ferris
 * @date 11/04/2024
 *  
 ***************************************************************************/

#ifndef _ASCENSOR_H_
#define _ASCENSOR_H_

// Definiciones del alto y ancho de la pantalla en la que vamos a dibujar
const unsigned short ALTO = 29;   ///< Alto de la pantalla
const unsigned short ANCHO = 120; ///< Ancho de la pantalla

/**
 * Numero maximo de plantas del edificio del ascensor
 */
const unsigned short MAX_PLANTAS = 6;
/**
 * Numero minimo de plantas del edificio del ascensor
 */
const unsigned short MIN_PLANTAS = 2;

/**
 * @brief Clase para la representacion del ascensor
 *
 * Clase para representar y mover el ascensor por la pantalla.
 */
class Ascensor
{
    public:
        // Constructor
        /**
         * Hace una primera representacion del edificio con 'num_plantas_'
         * y el ascensor detenido en la planta cero del edificio
         */
        Ascensor(int num_plantas_);
        /**
         * Mueve el ascensor desde la planta en la que esta hasta la planta
         * indicada por el parametro
         */
        void MoverAscensor(int);

    private:
        // Funciones auxiliares para la representacion grafica del ascensor       
        void Esperar(int retardo);
        void DespintarAscensor(int piso, int incr);
        void PintarPuertas1(int piso);
        void PintarPuertas2(int piso);
        void PintarPuertas3(int piso);
        void PintarPuertas4(int piso);
        void AbrirPuertas(int piso);
        void CerrarPuertas(int piso);
        void PintarAscensor(int piso, int incr);
        void DibujarPisos(void);
        void LimpiarPantalla(void);
        
        int donde;         ///< Planta en la que esta actualmente el ascensor
        int num_plantas;   ///< Numero de plantas del edificio
};

#endif
