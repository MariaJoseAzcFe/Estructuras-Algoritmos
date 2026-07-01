/******* ColaC.h *******************************************************/ /**
 *
 * @file ColaC.h
 *
 * Fichero de cabecera de la clase Cola (representacion estatica circular)
 *
 * @version 1.1
 * @author Jesus Albert, Ricardo Ferris
 * @date 11/04/2024
 *  
 ***************************************************************************/

#ifndef _COLA_C_H_
#define _COLA_C_H_

typedef int Valor;  ///< Tipo de informacion que guardara la cola

/**
 * Clase para la representacion y manipulacion de colas
 * (representacion estatica circular).
 */
class Cola
{
    public:
        // Constructor por defecto de la cola
        Cola();
        // Funciones de manipulacion y consulta de la cola
        bool Encolar(Valor);
        bool Desencolar(void);
        bool PrimeroCola(Valor &) const;
        bool ColaVacia(void) const;
        
        // Funciones adicionales convenientes para la practica actual
        void MostrarCola(void) const;
        bool Buscar(Valor) const;

    private:
        /**
         * Valor maximo de elementos que se podran guardar en la cola
         * (+1 porque hay un elemento que va ha quedar vacio para poder
         * distinguir entre cola llena y cola vacia)
         */
        static const int MAX = 20 + 1;
        /**
         * Definicion del contenedor usado para guardar los elementos de 
         * la cola
         */
        typedef Valor Vector[MAX];
        
        Vector datos;   ///< Array donde guardaremos los elementos de la cola
        size_t inicio,  ///< Donde empiezan los elementos de la cola
               fin;     ///< Donde finalizan los elementos de la cola
        
        // Funcion auxiliar para conocer el indice siguiente de la cola circular
        size_t Siguiente(size_t) const;
};

#endif
