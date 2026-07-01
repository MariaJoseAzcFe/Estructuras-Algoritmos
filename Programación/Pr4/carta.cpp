
/******* carta.cpp ********************************************************/ /**
 *
 * @file carta.cpp
 *
 * ImplementaciÃ³n de los mÃ©todos de la clase Carta
 *
 * @version 5.0
 * @author María José Azcárate, Alejandro Hernández
 * @date 15/03/2024
 *  
 ******************************************************************************/

#include <regex>
#include "carta.h"

Carta::Carta()
{
	string tipo;    
	string nombre;    
	string identidad_color;  
}
/**
* Asigna valores a la información de la cadena c
* 
*/
void Carta::AsignarValores(string tipo_, string nombre_, string identidad_color_)
{
	tipo = tipo_;
	nombre = nombre_;
	identidad_color = identidad_color_;
}
/**
* Devuelve el nombre de la carta c
* @retval nombre carta
*/
string Carta::DevuelveNombre()
{
	return nombre;
	
}
/**
* Devuelve el tipo de la carta c
* @retval tipo carta
*/
string Carta::DevuelveTipo()
{
	return tipo;
	
}
/**
* Devuelve los colores de mana de la carta c
* @retval color carta
*/
string Carta::DevuelveIdentidadColor()
{
	return identidad_color;
	
}
/**
 * Nos dice si la carta tiene o no sub identidad de color
 *
 * @retval true Si es tiene sub-identidad de color
 * @retval false Si NO tiene sub-identidad de color
 */
bool Carta::TieneSubIdentidadColor(Carta & c) 
{
	string id_color_otro = c.identidad_color;
	size_t pos;
	size_t prev_pos = 0;
    string color;
	bool compatible = true;
	bool more_comparisons = true;
	
	if (id_color_otro == identidad_color) 
	{
		compatible = true;
		more_comparisons = false;
	}
	else if (id_color_otro.size() == 0) 
	{
		compatible =  false;
		more_comparisons = false;
	}
	else if (identidad_color.size() == 0)
	{
		compatible =  true;
		more_comparisons = false;
	}
	else if (id_color_otro.size() == 1) 
	{
		compatible = this->identidad_color.find(id_color_otro) != string::npos;
		more_comparisons = false;
	}
    
	if (more_comparisons) 
	{
		do
        {
			pos = identidad_color.substr(prev_pos).find(", ");
			color = identidad_color.substr(prev_pos, prev_pos + pos);
			if (id_color_otro.find(color) == string::npos)
            {
				compatible = false;
			}
			prev_pos = pos + 2;
			
		}
        while (pos != string::npos && compatible); 
	}
    
	return compatible;	
}
