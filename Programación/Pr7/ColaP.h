/******* ColaP.h *******************************************************/ /**
 *
 * @file ColaP.h
 *
 * Fichero de cabecera de la clase Cola (representacion dinamica mediante
 * punteros)
 *
 * @version 1.1
 * @author Jesus Albert, Ricardo Ferris
 * @date 11/04/2024
 *  
 ***************************************************************************/

#ifndef _COLA_P_H_
#define _COLA_P_H_

typedef int Valor;  ///< Tipo de informacion que guardara la cola

/**
 * Definicion del tipo puntero
 */
typedef struct Nodo * Puntero;

/**
 * Definicion del tipo basico para la realizacion de estructuras dinamicas
 * mediante la utilizacion de punteros
 */
struct Nodo
{
    /**
     * Informacion contenida en cada elemento de la estuctura dinamica
     */
    Valor info;
    Puntero sig;  ///< Enlace al siguiente elemento de la estructura dinamica
};

/**
 * Clase para la representacion y manipulacion de colas
 * (representacion estatica circular).
 */
class Cola
{
    public:
        // Constructor por defecto de la cola
        Cola(void);
        // Constructor de copia. Necesario al ser una representación dinámica
        // usando punteros
        Cola(const Cola &);
        // Destructor. Necesario al ser una representación dinámica usando
        // punteros
        ~Cola();
        // Sobrecarga del operador asignacion
        const Cola & operator=(const Cola &);

        // Funciones de manipulacion y consulta de la cola
        bool ColaVacia(void) const;
        bool Encolar(Valor);
        bool Desencolar(void);
        bool PrimeroCola(Valor &) const;

        // Funciones adicionales convenientes para la practica actual        
        bool Buscar(Valor) const;
        void MostrarCola(void) const;

    private:
        Puntero inicio, ///< Enlace donde empieza la estructura dinamica
                fin;    ///< Enlace al ultimo elemento de la estructura dinamica
    
        // Funcion auxiliar para facilitar la implementacion de los
        // metodos constructor de copia, destructor y sobrecarga de la
        // asignacion
        void Copiar(const Cola &);
        void Vaciar(void);
};

#endif
