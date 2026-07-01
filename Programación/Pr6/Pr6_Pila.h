/*****************************************************************/ /**
 * @file pila_vector_template.h
 *
 * @brief template clase Pila construida con vector
 * Programación (1º Gr. Ing. Informática / Multimedia)
 *
 * @author  Jesus Albert
 * @author Emiliano Torres
 * @date    19/03/2024
 *
**********************************************************************/
#ifndef _PILA_VECTOR_H_
#define _PILA_VECTOR_H_

#include <iostream>
#include <vector>

using namespace std;

template <class Valor>
class Pila
{
    public:
        Pila ();
        void Apilar (Valor);
        bool Desapilar ();
        bool CimaPila (Valor &);
        bool PilaVacia ();
		// Sobrecarga del operador de salida
		//Obligatoriamente se debe implementar aqui
        friend std::ostream& operator<< (std::ostream& o, const Pila<Valor>& p)
        {
       		for (unsigned int i = 0; i < p.datos.size(); i++)
				o << p.datos[i] << " ";
			o << endl;
			return o;
		}
    private:
        static const int MAX_INI = 100; ///< Tamanyo inicial del vector
        vector<Valor> datos; ///< Los datos de la pila
};

/**********************************************************************/ /**
 *  Constructor por defecto
 *
 *  Establece un tamanyo inicial para el vector
 *  La pila esta vacia 
 */ /**********************************************************************/
template <class Valor>
Pila<Valor>::Pila ()
{
    datos.reserve(MAX_INI);
}

/**********************************************************************/ /**
 *  Almacenar el valor x en la pila
 *
 *  @param [in]  x valor almacenado
 */ /**********************************************************************/
template <class Valor>
void Pila<Valor>::Apilar (Valor x)
{
    datos.push_back(x);
}

/**********************************************************************/ /**
 *  Indica si la pila esta vacia (sin elementos)
 *
 *  @retval true si pila vacia
 *  @retval false si pila no vacia
 */ /**********************************************************************/
template <class Valor>
bool Pila<Valor>::PilaVacia ()
{
   return datos.size() == 0;
}

/**********************************************************************/ /**
 *  Elimina un elemento de la pila
 *
 *  @retval true ha sido posible eliminar elemento
 *  @retval false error, la pila esta vacia
 */ /**********************************************************************/
template <class Valor>
bool Pila<Valor>::Desapilar ()
{
   bool ok;

   if ( datos.size() == 0 )
      ok = false;
   else
   {
      datos.pop_back();
      ok = true;
   }
   return (ok);
}

/**********************************************************************/ /**
 *  Consulta la cima de la pila
 *
 *  @param [out]  x variable en la que se deposita el resultado de la consulta
 *
 *  @retval true ha sido posible realizar la consulta, resultado en x
 *  @retval false error, la pila esta vacia
 */ /**********************************************************************/
template <class Valor>
bool Pila<Valor>::CimaPila (Valor & x)
{
   bool ok;

   if ( datos.size() == 0 )
      ok = false;
   else
   {
      x = datos.back();
      ok = true;
   }
   return (ok);
}

#endif
