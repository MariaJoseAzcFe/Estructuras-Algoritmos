/****** Receta.cpp ************************************************/ /**
 *
 * @file Receta.cpp
 *
 * @brief Implementacion de los metodos de la clase Receta
 *
 * @version 1.0
 * @author José García
 * @date 05-05-2024
 */ /**************************************************************************/

#include <iomanip>
#include <string>
#include "Receta.h"
#include "Tiempo.h"
using namespace std;
/**** Receta::Receta () ***************************************************/ /**
 *
 * Constructor por defecto de la clase Receta.
 *
 */ /**************************************************************************/
Receta::Receta()
{}
/****  void Receta::EstablecerReceta() ******************************************/ /**
 *
 * Establece los parametros de la receta
 *
 * @param [in] t, el titulo
 * @param [in] i, la informacion
 * @param [in] u, el url
 * @param [in] d, la dificultad
 * @param [in] tp, el tipo
 * @param [in] du, el tiempo de preparacion
 *
 */ /**************************************************************************/
void Receta::EstablecerReceta (string t, string i, string u, string d, string tp, Tiempo du)
{
	titulo = t;
    info = i;
    url = u;
    dificultad = d;
    tipo = tp;
    duracion = du;
    
}
/****  void Receta::EstablecerTitulo() ******************************************/ /**
 *
 * Establece el titulo/nombre de la receta
 *
 * @param [in] t, el titulo
 *
 */ /**************************************************************************/
void Receta::EstablecerTitulo(string tit)
{
	titulo = tit;
}
/****  void Receta::EstablecerInformacion() ******************************************/ /**
 *
 * Establece la informacion complementaria de la receta
 *
 * @param [in] i, la informacion
 *
 */ /**************************************************************************/
void Receta::EstablecerInformacion(string inf)
{
	info = inf;
}
/****  void Receta::EstablecerUrl() ******************************************/ /**
 *
 * Establece la url de la receta 
 *
 * @param [in] u, el url
 *
 */ /**************************************************************************/
void Receta::EstablecerUrl(string ur)
{
	url = ur;
}
/****  void Receta::EstablecerDificultad() ******************************************/ /**
 *
 * Establece la dificultad de la preparacion
 *
 * @param [in] d, la dificultad
 *
 */ /**************************************************************************/
void Receta::EstablecerDificultad(string dif)
{
	dificultad = dif;
}
/****  void Receta::EstablecerTipo() ******************************************/ /**
 *
 * Establece el tipo de receta
 *
 * @param [in] tp, el tipo
 *
 */ /**************************************************************************/
void Receta::EstablecerTipo(string tip)
{
	tipo = tip;
}
/****  void Receta::EstablecerTiempo() ******************************************/ /**
 *
 * Devuelve las horas
 *
 * @return     horas
 */ /**************************************************************************/
void Receta::EstablecerTiempo (Tiempo dur)
{
	duracion = dur;	
}
/****  string Receta::DevuelveTitulo() ******************************************/ /**
 *
 * Devuelve las horas
 *
 * @return     horas
 */ /**************************************************************************/
string Receta::DevuelveTitulo()
{
	return titulo;
}
/****  string Receta::DevuelveInformacion() ******************************************/ /**
 *
 * Devuelve las horas
 *
 * @return     horas
 */ /**************************************************************************/
string Receta::DevuelveInformacion()
{
	return info;
}
/****  string Receta::DevuelveUrl() ******************************************/ /**
 *
 * Devuelve las horas
 *
 * @return     horas
 */ /**************************************************************************/
string Receta::DevuelveUrl()
{
	return url;
}
/****  string Receta::DevuelveDificultad() ******************************************/ /**
 *
 * Devuelve las horas
 *
 * @return     horas
 */ /**************************************************************************/
string Receta::DevuelveDificultad()
{
	return dificultad;
}
/****  string Receta::DevuelveTipo() ******************************************/ /**
 *
 * Devuelve las horas
 *
 * @return     horas
 */ /**************************************************************************/
string Receta::DevuelveTipo()
{
	return tipo;
}
/****  Tiempo Receta::DevuelveTiempo() ******************************************/ /**
 *
 * Devuelve las horas
 *
 * @return     horas
 */ /**************************************************************************/
Tiempo Receta::DevuelveTiempo()
{
	return duracion;
}
/****  friend istream& operator>> () ******************************************/ /**
 *
 * Devuelve las horas
 *
 * @return     horas
 */ /**************************************************************************/
istream& operator>> (istream& in, Receta r)
{
	getline(in, r.titulo);
	getline(in, r.info);
	getline(in, r.url);
	getline(in, r.dificultad);
	getline(in, r.tipo);
	in >> r.duracion;
}
/****  friend ostream& operator<<() ******************************************/ /**
 *
 * Devuelve las horas
 *
 * @return     horas
 */ /**************************************************************************/
ostream& operator<< (ostream& out, Receta r)
{
	out << r.titulo;
	out << r.info;
	out << r.url;
	out << r.dificultad;
	out << r.tipo;
	out << r.duracion;
}
/****  friend void operator<() ******************************************/ /**
 *
 * Devuelve las horas
 *
 * @return     horas
 */ /**************************************************************************/
bool operator< (Receta r1, Receta r2)
{
	bool ok = false;
	
	if(r1.DevuelveTitulo() < r2.DevuelveTitulo())
		ok = true;
	else
		ok = false;
		
	return ok;
}

