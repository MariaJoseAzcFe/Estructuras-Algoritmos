/******* ColaC.cpp ********************************************************/ /**
 *
 * @file ColaC.cpp
 *
 * Implementación de los métodos de la Cola (representacion estatica circular)
 *
 * @version 1.1
 * @author Ricardo Ferris
 * @date 11/04/2024
 *  
 ******************************************************************************/

#include <iostream>
using namespace std;

#include "ColaC.h"

/*** Cola::Cola(void) *************************************************/ /**
 *
 *  Constructor por defecto.
 *  Asigna valores iniciales 'coherentes' a los distintos atributos de la
 *  clase:
 *     inicio = fin = 0
 *
 */ /**********************************************************************/
Cola::Cola(void)
{
    inicio = 0;
    fin = 0;
}

/*** bool Cola::ColaVacia(void) ***************************************/ /**
 *
 *  Comprueba si hay o no elementos en la cola.
 *  No hay elementos en la cola si la marcas de inicio y fin coinciden.
 *
 */ /**********************************************************************/
bool Cola::ColaVacia(void) const
{
    return inicio == fin;   
}

/*** bool Cola::Encolar(Valor) ****************************************/ /**
 *
 * Comprueba si hay espacio para nuevos elementos en la cola.
 * Si hay espacio encola el elemento.
 * Si no lo hay el elementos no se encola.
 *
 * @param  [in]  x  Valor a encolar
 *
 * @retval  true  Hay espacio en la cola y el elemento se ha encolado
 * @retval  false  No queda espacio en la cola y el elemento NO se ha
 *                 encolado
 *
 */ /**********************************************************************/
bool Cola::Encolar(Valor x)
{
    bool ok = true;
    
    if (inicio == Siguiente(fin))
        ok = false; //Cola llena
    else
    {
        fin = Siguiente(fin);
        datos[fin] = x;
    }
    return ok;
}

/*** bool Cola::Desencolar(void) **************************************/ /**
 *
 * Comprueba si hay elementos en la cola.
 * Si los hay, elimina de la cola el primero de ellos.
 * Si no los hay, no se hace nada.
 *
 * @retval  true  Hay elementos en la cola y se ha eliminado el primero
 *                de ellos
 * @retval  false  No habia elementos en la cola y NO se ha podido
 *                 eliminar
 * 
 */ /**********************************************************************/
bool Cola::Desencolar(void)
{
    bool ok;
    
    if (inicio == fin)
        ok = false; //Cola vacía
    else
    {
        ok = true;
        inicio = Siguiente (inicio);
    }
    
    return ok;
}

/*** bool Cola::PrimeroCola(Valor &) **********************************/ /**
 *
 * Comprueba si hay elementos en la cola.
 * Si los hay, devuelve el primero de ellos.
 * Si no los hay no se hace nada.
 *
 * @param  [out]  x  Primer valor de la cola
 *
 * @retval  true  Hay elementos en la cola y se ha consultado el primero
 *                de ellos
 * @retval  false  No habia elementos en la cola y NO se ha podido
 *                 consultar
 *
 */ /**********************************************************************/
bool Cola::PrimeroCola(Valor & x) const
{
    bool ok;
    
    if (inicio == fin)
        ok = false; //Cola vacía
    else
    {
        ok = true;
        x = datos[Siguiente (inicio)];
    }

    return ok;
}

/*** void Cola::MostrarCola(void) *************************************/ /**
 *
 * Muestra por pantalla los elementos contenidos en la cola empezando por
 * el primero de ellos y terminando por el ultimo.
 * Si la cola esta vacia se muestra el mensaje "Cola Vacia".
 *
 */ /**********************************************************************/
void Cola::MostrarCola(void) const
{
  	int i = inicio;
  	
  	if (inicio == fin)
  	{
  		cerr << "La cola no cuenta con valores en su interior" << endl;
	}
	else
	{
		while (i != fin)
   		{
   			cout << datos[Siguiente(i)] << endl;
   			i++;
   		}     
  
	}
    return;
}

/*** bool Cola::Buscar(Valor) *****************************************/ /**
 *
 * Determina si un cierto valor esta o no contenido en la cola.
 *
 * @param  [in]  x  Valor a encontrar en la cola
 *
 * @retval  true  El valor se encuentra encolado en la cola
 * @retval  false  El valor NO se encuentra encolado en la cola
 *
 */ /**********************************************************************/
bool Cola::Buscar(Valor x) const
{
    bool res = false;
    int i = inicio;
    
	while (i != fin && res == false)
	{
		if (datos[Siguiente(i)] == x)
			res = true;
		else
			i = Siguiente(i);
	}
	
    return res;  // Modificar adecuadamente
}

/*** size_t Cola::Siguiente(size_t) ***********************************/ /**
 *
 * Determina el siguiente indice en la cola circular a partir del indice
 * pasado como parametro.
 *
 * @param  [in]  i  Valor a encontrar en la cola
 *
 * @return  Indice siguiente en la cola circular al indicado como parametro
 *
 */ /**********************************************************************/
size_t Cola::Siguiente(size_t i) const
{
    return (i + 1) % MAX;
}
