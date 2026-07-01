/******* ColaP.cpp ********************************************************/ /**
 *
 * @file ColaP.cpp
 *
 * Implementación de los métodos de la Cola (representacion dinamica mediante
 * punteros)
 *
 * @version 1.1
 * @author Ricardo Ferris
 * @date 11/04/2024
 *  
 ******************************************************************************/

#include <iostream>
using namespace std;

#include "ColaP.h"

/*** Cola::Cola(void) *************************************************/ /**
 *
 *  Constructor por defecto.
 *  Asigna valores iniciales 'coherentes' a los distintos atributos de la
 *  clase:
 *     inicio = fin = nullptr
 *
 */ /**********************************************************************/
Cola::Cola(void)
{
    inicio = nullptr;
    fin = nullptr;
}

/*** Cola::Cola(const Cola &) *****************************************/ /**
 *
 *  Constructor de copia.
 *  Genera una copia de la cola pasada como parametro
 *
 */ /**********************************************************************/
Cola::Cola(const Cola & c_orig)
{
    inicio = nullptr;
    fin = nullptr;
    Copiar(c_orig);
}

/*** Cola::~Cola() ****************************************************/ /**
 *
 *  Destructor de la clase cola.
 *  Elimina la cola una vez deja de existir el objeto.
 *
 */ /**********************************************************************/
Cola::~Cola()
{
    Vaciar();
}

/*** const Cola & Cola::operator=(const Cola & c) *********************/ /**
 *
 * Sobrecarga del operador asignacion. Permite asignar objetos dinamicos
 * representadas mediante punteros.
 *
 * @param  [in]  c  Cola asignada
 *
 * @return Copia de la cola asignada
 *
 */ /**********************************************************************/
const Cola & Cola::operator=(const Cola & c)
{
    Vaciar();
    Copiar(c);
    
    return *this;
}

/*** bool Cola::ColaVacia(void) ***************************************/ /**
 *
 *  Comprueba si hay o no elementos en la cola.
 *  No hay elementos en la cola si la marca de inicio esta a nullptr.
 *
 */ /**********************************************************************/
bool Cola::ColaVacia(void) const
{
    return inicio == nullptr;   
}

/*** bool Cola::Encolar(Valor) ****************************************/ /**
 *
 * Reserva un espacio nuevo para el nuevo elemento, lo enlaza con la 
 * estructura dinamica y coloca la nueva informacion en ese espacio.
 * Consideraremos que SIEMPRE se puede reservar el espacio, por lo que
 * SIEMPRE devolveremos true (se mantiene el tipo 'bool' del metodo por
 * compatibilidad con otras implementaciones de la clase Cola).
 *
 * @param  [in]  x  Valor a encolar
 *
 * @retval  true  SIEMPRE es posible encolar
 *
 */ /**********************************************************************/
bool Cola::Encolar(Valor x)
{
    bool b_aux = true;
    Puntero p_aux;

    p_aux = new Nodo;
    p_aux->info = x;
    p_aux->sig = nullptr;
    if (inicio == nullptr)  // Cola vacia
    {
        inicio = p_aux;
        fin = p_aux;
    }
    else
    {
        fin->sig = p_aux;
        fin = p_aux;
    }

    return b_aux;
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
    Puntero p_aux;

    if (inicio == nullptr)  // Cola vacia
        ok = false;
    else
    {
        ok = true;
        p_aux = inicio;
        inicio = inicio->sig;
        delete p_aux;
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

    if (inicio == nullptr)  // Cola vacia
        ok = false;
    else
    {
        ok = true;
        x = inicio->info;
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
    Puntero p_aux;
    
    if (inicio == nullptr && fin == nullptr)
    {
       cerr << "La cola no tiene valores en su interior" << endl;
    }
	else
	{
	
	 	p_aux = inicio;
		while (p_aux != nullptr)
		{
  		 	  cout << p_aux -> info << " ";
  		 	  p_aux = p_aux -> sig;
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
    Puntero p_aux = inicio;
    
	while (inicio != nullptr && res == false)
	{
		if (p_aux -> info == x)
			res = true;
		else
			p_aux = p_aux -> sig;
	}
	
    return true;  // Modificar adecuadamente
}

/*** void Cola::Copiar(const Cola &) **********************************/ /**
 *
 * Crea una copia de la cola pasada como parametro en la cola que realiza
 * la llamada.
 *
 * @param  [in]  c  Cola original a copiar
 *
 */ /**********************************************************************/
void Cola::Copiar(const Cola & c)
{
    Puntero p_aux, dup;
    
    p_aux = c.inicio;
    while (p_aux != nullptr)
    {
        dup = new Nodo;
        dup->info = p_aux->info;
        dup->sig = nullptr;
        if (inicio == nullptr)
            inicio = dup;
        else
            fin->sig = dup;
        fin = dup;
        p_aux = p_aux->sig;
    }
    
    return;
}

/*** void Cola::Vaciar(void) ******************************************/ /**
 *
 * Crea una copia de la cola pasada como parametro en la cola que realiza
 * la llamada.
 *
 * @param  [in]  c  Cola original a copiar
 *
 */ /**********************************************************************/
void Cola::Vaciar(void)
{
    Puntero p_aux;

    while (inicio != nullptr)
    {
        p_aux = inicio;
        inicio = inicio->sig;
        delete p_aux;
    }
    fin = nullptr;
    
    return;
}
