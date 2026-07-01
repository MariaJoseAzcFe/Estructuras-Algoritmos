
/******* persona.cpp *************************************************/ /**
 *
 * @file persona.cpp
 *
 * Implementacion de los metodos de la clase Persona
 *
 * @version 1.0
 * @author Jesus Albert
 * @date 03/03/2020
 *  
 ***************************************************************************/
#include <string>
#include <iostream>
#include "persona.h"

using namespace std;

/**********************************************************************/ /**
 *
 *  Constructor por defecto de la clase
 * 
 */ /**********************************************************************/
Persona::Persona()
{
    id = "Desconocido";
    apellidos = "Desconocido";
    nombre = "Desconocido";
    sexo = 'O';
    edad = 0;
    estatura = 0;
    peso = 0;  
}

/**********************************************************************/ /**
 *
 *  Asignar todos los campos de informacion de una persona
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
 *  @return  bool indicando si la asignacion ha sido completamente correcta
 *
 */ /**********************************************************************/
bool Persona::AsignarValores(string i, string a, string n, char s, int e, int h, int w)
{
    bool ok;
    //Realizar todas las validaciones previas
    ok = ( ValidarSexo(s) && ValidarEdad(e) && ValidarEstatura(h) && ValidarPeso(w) );
    if ( ok )
    //Solo si todas las validasciones son correctas se cambian los atributos
    {
        id = i;
        apellidos = a;
        nombre = n;
        sexo = s;
        edad = e;
        estatura = h;
        peso = w;
    }
    return ok;
}

/**********************************************************************/ /**
 *
 *  Establecer el identificador de una persona
 * 
 *  @param [in]  i  identificador
 *
 *  @return  true porque la asignacion de identificador siempre es correcta
 *
 */ /**********************************************************************/
bool Persona::SetId(string i)
{
    id = i;
    return true;
}

/**********************************************************************/ /**
 *
 *  Establecer los apellidos de una persona
 * 
 *  @param [in]  a  apellidos
 *
 *  @return  true porque la asignacion de apellidos siempre es correcta
 *
 */ /**********************************************************************/
bool Persona::SetApellidos(string a)
{
    apellidos = a;
    return true;
}

/**********************************************************************/ /**
 *
 *  Establecer el nombre de una persona
 * 
 *  @param [in]  n  nombre
 *
 *  @return  true porque la asignacion de nombre siempre es correcta
 *
 */ /**********************************************************************/
bool Persona::SetNombre(string n)
{
    nombre = n;
    return true;
}

/**********************************************************************/ /**
 *
 *  Establecer el sexo de una persona
 * 
 *  Solo se asignan sexos validos
 *
 *  @param [in]  s  sexo
 *
 *  @return  bool indicando si el sexo asignado es correcto
 *
 */ /**********************************************************************/
bool Persona::SetSexo(char s)
{
    bool ok;
    ok = ValidarSexo(s);
    if ( ok )
        sexo = s;
    return ok;
}

/**********************************************************************/ /**
 *
 *  Establecer la edad de una persona
 * 
 *  Solo se asignan edades validas
 *
 *  @param [in]  e  edad
 *
 *  @return  bool indicando si la edad asignada es correcta
 *
 */ /**********************************************************************/
bool Persona::SetEdad (int e)
{
    bool ok;
    ok = ValidarEdad(e);
    if ( ok )
        edad = e;
    return ok;    
}

/**********************************************************************/ /**
 *
 *  Establecer la estatura de una persona
 * 
 *  Solo se asignan estaturas validas
 *
 *  @param [in]  h  estatura
 *
 *  @return  bool indicando si la estatura asignada es correcta
 *
 */ /**********************************************************************/
bool Persona::SetEstatura (int h)
{
    bool ok;
    ok = ValidarEstatura(h);
    if ( ok )
        estatura = h;
    return ok;    
}

/**********************************************************************/ /**
 *
 *  Establecer el peso de una persona
 * 
 *  Solo se asignan pesos validos
 *
 *  @param [in]  w  peso
 *
 *  @return  bool indicando si el pesos asignado es correcto
 *
 */ /**********************************************************************/
bool Persona::SetPeso (int w)
{
    bool ok;
    ok = ValidarPeso(w);
    if ( ok )
        peso = w;
    return ok;    
}

/**********************************************************************/ /**
 *
 *  Recuperar el identificador de una persona
 * 
 *  @return  string identificador
 *
 */ /**********************************************************************/
string Persona::GetId()
{
    return id;
}

/**********************************************************************/ /**
 *
 *  Recuperar los apellidos de una persona
 * 
 *  @return  string apellidos
 *
 */ /**********************************************************************/
string Persona::GetApellidos()
{
    return apellidos;
}

/**********************************************************************/ /**
 *
 *  Recuperar el nombre de una persona
 * 
 *  @return  string nombre
 *
 */ /**********************************************************************/
string Persona::GetNombre()
{
    return nombre;
}

/**********************************************************************/ /**
 *
 *  Recuperar el sexo de una persona
 * 
 *  @return  char sexo
 *
 */ /**********************************************************************/
char Persona::GetSexo()
{
    return sexo;
}

/**********************************************************************/ /**
 *
 *  Recuperar la edad de una persona
 * 
 *  @return  int edad
 *
 */ /**********************************************************************/
int Persona::GetEdad ()
{
    return edad;
}

/**********************************************************************/ /**
 *
 *  Recuperar la estatura de una persona
 * 
 *  @return  int estatura
 *
 */ /**********************************************************************/
int Persona::GetEstatura()
{
    return estatura;
}

/**********************************************************************/ /**
 *
 *  Recuperar el peso de una persona
 * 
 *  @return  int peso
 *
 */ /**********************************************************************/
int Persona::GetPeso()
{
    return peso;
}

/**********************************************************************/ /**
 *
 *  Operador salida (<<)
 * 
 *  @param [in,out]  sal  flujo de salida
 *
 *  @param [in]  p  persona
 *
 *  @return  ostream flujo de salida modificado
 *
 */ /**********************************************************************/
ostream& operator<<(ostream& sal,Persona p)
{
    sal << p.id << ";" ;
    sal << p.apellidos << ";" ;
    sal << p.nombre << ";";
    sal << p.sexo << ";" ;
    sal << p.edad << ";" ;
    sal << p.estatura << ";" ;
    sal << p.peso;
    return sal;
}

/**********************************************************************/ /**
 *
 *  Validar un valor de sexo: 'H', 'M', 'O'
 * 
 *  @param [in]  s  valor
 *
 *  @return  bool indicando si s corresponde a un sexo valido 
 *
 */ /**********************************************************************/
bool Persona::ValidarSexo (char s)
{
    bool ok;
    ok = ( (s=='H') || (s=='M') || (s=='O') );
    return ok;
}

/**********************************************************************/ /**
 *
 *  Validar un valor de edad (>=15, <=100)
 * 
 *  @param [in]  e  valor
 *
 *  @return  bool indicando si e corresponde a una edad valida 
 *
 */ /**********************************************************************/
bool Persona::ValidarEdad (int e)
{
    bool ok;
    ok = ( (e>=15) && (e<=100) );
    return ok;
}

/**********************************************************************/ /**
 *
 *  Validar un valor de estatura (>=30, <=250 cm)
 * 
 *  @param [in]  h  valor
 *
 *  @return  bool indicando si h corresponde a una estatura valida 
 *
 */ /**********************************************************************/
bool Persona::ValidarEstatura (int h)
{
    bool ok;
    ok = ( (h>=30) && (h<=250) );
    return ok;
}

/**********************************************************************/ /**
 *
 *  Validar un valor de peso (>=25, <=300 kg)
 * 
 *  @param [in]  w  valor
 *
 *  @return  bool indicando si w corresponde a un peso valido 
 *
 */ /**********************************************************************/
bool Persona::ValidarPeso (int w)
{
    bool ok;
    ok = ( (w>=25) && (w<=300) );
    return ok;
}

