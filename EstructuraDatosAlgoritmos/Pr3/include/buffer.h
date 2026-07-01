/**
 * @file buffer.h
 * @brief Material de la Practica 3 de EDA (GIM).
 * 
 * template class Buffer
 *
 * @author Jesus Albert
 * @date 29/10/2024
 * @version 1.0
 */
 
#ifndef _BUFFER_H_
#define _BUFFER_H_

#include <queue>
#include <stdexcept>
#include <iostream>

using namespace std;

/**
 * Clase Buffer (template)
 * @class Buffer
 * @brief Plantilla para clases Buffer de cualquier tipo
 * 
 */
template <class E>
class Buffer
{
	public:
		Buffer();
		void Incorporar(E);
		void Eliminar();
		E Primero();
		bool Vacio();
		
	private:
        queue<E> datos;
		
};

/**
 * Constructor de un buffer vacio
 */
template <class E>
Buffer<E>::Buffer()
:datos()
{}

/**
 * Guardar un nuevo elemento en el buffer
 * @pre hay espacio disponible en memoria
 * @exception bad_alloc fallo al reservar memoria
 * @param[in] x elemento añadido
 */
 template <class E>
void Buffer<E>::Incorporar(E x)
{
	
	try
	{
		datos.push(x);
	}
	catch(exception& e)
	{
		cerr << e.what() << endl;
		throw bad_alloc();
	}
}

/**
 * Eliminar un elemento del buffer
 * @pre buffer no vacio
 * @exception runtime_error buffer vacio
 */
template <class E>
void Buffer<E>::Eliminar()
{
	if ( this->Vacio() )
		throw runtime_error("Buffer::Eliminar()");
	else
		datos.pop();
}

/**
 * Consultar el primer elemento del buffer
 * @pre buffer no vacio
 * @exception runtime_error buffer vacio
 * @return E
 */
template <class E>
E Buffer<E>::Primero()
{
	if ( this->Vacio() )
		throw runtime_error("Buffer::Primero()");
	else 
		return datos.front();
}

/**
 * Comprobar si el buffer esta vacio
 * @retval true buffer vacio
 * @retval false no vacio
 */
template <class E>
bool Buffer<E>::Vacio()
{
   return datos.empty();
}

#endif