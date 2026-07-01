
/******* estudiante.cpp *************************************************/ /**
 *
 * @file estudiante.cpp
 *
 * Implementacion de los metodos de la clase Estudiante
 *
 * @version 1.0
 * @author Jesus Albert
 * @date 16/03/2020
 *  
 ***************************************************************************/
#include <string>
#include <iostream>
#include "estudiante.h"
#include "persona.h"

using namespace std;

/**********************************************************************/ /**
 *
 *  Constructor por defecto de la clase
 * 
 */ /**********************************************************************/
Estudiante::Estudiante()
:Persona(),titulacion("Desconocido"),curso(0)
{}

/**********************************************************************/ /**
 *
 *  Asignar todos los campos de informacion de un estudiante
 *
 *  @param [in]  i  identificador
 *
 *  @param [in]  a  apellidos
 *
 *  @param [in]  n  nombre
 *
 *  @param [in]  s  sexo
 *
 *  @param [in]  e  edad
 *
 *  @param [in]  h  estatura
 *
 *  @param [in]  w  peso
 *
 *  @param [in]  tit  titulacion
 *
 *  @param [in]  curs  curso
 *
 *  @return  bool indicando si la asignacion ha sido completamente correcta
 *
 */ /**********************************************************************/
bool Estudiante::AsignarValores(string i, string a, string n, char s, int e, int h, int w, string tit, int curs)
{
	bool ok;
	
	ok = ValidarId(i) && ValidarCurso(curs);
	
	if ( ok )
	{
		ok = Persona::AsignarValores(i,a,n,s,e,h,w);
		if ( ok )
		{
			titulacion = tit;
			curso = curs;
			ok = true;
		}
	}
	return ok;
}

/**********************************************************************/ /**
 *
 *  Establecer la titulacion de un estudiante
 *
 *  @param [in]  tit  titulacion
 *
 *  @return  true porque la asignacion de titulacion siempre es posible
 *
 */ /**********************************************************************/
bool Estudiante::SetTitulacion(string tit)
{
	titulacion = tit;
	return true;
}

/**********************************************************************/ /**
 *
 *  Establecer el curso de un estudiante
 * 
 *  Solo se asignan cursos validos
 *
 *  @param [in]  c  curso
 *
 *  @return  bool indicando si el curso asignado es correcto
 *
 */ /**********************************************************************/
bool Estudiante::SetCurso(int c)
{
    bool ok;
    ok = ValidarCurso(c);
    if ( ok )
        curso = c;
    return ok;
}

/**********************************************************************/ /**
 *
 *  Establecer el identificador de un estudiante
 * 
 *  Solo se asignan identificadores validos
 *
 *  @param [in]  i  identificador
 *
 *  @return  bool indicando si el identificador asignado es correcto
 *
 */ /**********************************************************************/
bool Estudiante::SetId(string i)
{
    bool ok;
    ok = ValidarId(i);
    if ( ok )
        Persona::SetId(i);
    return ok;
}

/**********************************************************************/ /**
 *
 *  Recuperar la titulacion de un estudiante
 * 
 *  @return  string titulacion
 *
 */ /**********************************************************************/
string Estudiante::GetTitulacion()
{
	return titulacion;
}

/**********************************************************************/ /**
 *
 *  Recuperar el curso de un estudiante
 * 
 *  @return  int curso
 *
 */ /**********************************************************************/
int Estudiante::GetCurso()
{
	return curso;
}

/**********************************************************************/ /**
 *
 *  Operador salida (<<)
 * 
 *  @param [in,out]  sal  flujo de salida
 *
 *  @param [in]  e  estudiante
 *
 *  @return  ostream flujo de salida modificado
 *
 */ /**********************************************************************/
ostream& operator<<(ostream& sal,Estudiante e)
{
	sal << Persona(e);
	sal << ";" << e.titulacion << ";";
	sal << e.curso;
	return sal;
}

/**********************************************************************/ /**
 *
 *  Validar un valor de curso (1<=c<=4)
 * 
 *  @param [in]  c  valor
 *
 *  @return  bool indicando si c corresponde a un curso valido 
 *
 */ /**********************************************************************/
bool Estudiante::ValidarCurso(int c)
{
	bool ok;
	if ( c >= 1 && c <= 4 )
		ok = true;
	else
		ok = false;
	return ok;
}

/**********************************************************************/ /**
 *
 *  Validar un valor de identificador: 
 *  8 caracteres y los 2 primeros son letras mayusculas
 * 
 *  @param [in]  i  valor
 *
 *  @return  bool indicando si i corresponde a un identificador valido
 *
 */ /**********************************************************************/
bool Estudiante::ValidarId(string i)
{
	bool ok;
	ok = false;
	if ( i.length() == 8 )
		if ( i[0] >= 'A' && i[0] <= 'Z')
			if ( i[1] >= 'A' && i[1] <= 'Z')
				ok = true;
	return ok;
}

