/****** Tiempo.cpp ************************************************/ /**
 *
 * @file Tiempo.cpp
 *
 * @brief Implementacion de los metodos de la clase Tiempo
 *
 * @version 1.0
 * @author José García
 * @date 05-05-2024
 */ /**************************************************************************/

#include <iomanip>
#include "Tiempo.h"

/**** Tiempo::Tiempo () ***************************************************/ /**
 *
 * Constructor por defecto de la clase Tiempo.
 *
 */ /**************************************************************************/
Tiempo::Tiempo()
{
    horas = 0;
    minutos = 0;
}

/**** Tiempo::Tiempo (int hh, int mm) ************************************/ /**
 *
 * Constructor con un argumentos de la clase Tiempo.
 * Asigna los valores de horas, minutos y segundos
 * 
 * @param[in]  hh     horas
 * @param[in]  mm     minutos
 *
 */ /*************************************************************************/
Tiempo::Tiempo(int hh, int mm)
{   
    if (hh >= 0 && mm >= 0 && mm < 60)
    {
        horas = hh;
        minutos = mm;
    }      
}

/**** bool Tiempo::SetTiempo (int hh, int mm) **********************************/ /**
 *
 * Asigna los valores de horas, minutos y segundos y devuelve si se ha podido asignar
 * 
 * @param[in]  hh     horas
 * @param[in]  mm     minutos
 *
 */ /********************************************************************************/
bool Tiempo::SetTiempo(int hh, int mm)
{   
    bool correcto;
    
    if(hh >= 0 && mm >= 0 && mm < 60)
    {
        horas = hh;
        minutos = mm;
        correcto = true;
    }      
    else
        correcto = false;
        
    return correcto;    
}

/****  int Tiempo::GetHoras () ******************************************/ /**
 *
 * Devuelve las horas
 *
 * @return     horas
 */ /**************************************************************************/
int Tiempo::GetHoras()
{
    return horas;
}
              
/****  int Tiempo::GetMinutos () ******************************************/ /**
 *
 * Devuelve los minutos
 *
 * @return     minutos
 */ /**************************************************************************/
int Tiempo::GetMinutos()
{
    return minutos;
}
              
/*** istream & operator>> (istream & in, Tiempo & t) ************************/ /**
 *
 *  Sobrecarga del operador '>>' para asignar la información de un Tiempo 
 *  desde un stream (fichero, teclado, ...).
 *
 *  @param [in, out]  in  stream del que vamos a obtener la informacion.
 *  @param [out]     t        objeto Tiempo que queremos rellenar con la
 *                            informacion obtenida del stream.
 *
 *  @return  El stream modificado tras su utilizacion
 *
 */ /**********************************************************************/
istream& operator>> (istream & in, Tiempo & t)
{
    in >> t.horas;
    in.ignore();
    in >> t.minutos;
    
    return in;
}

/*** ostream & operator<< (ostream &, Tiempo& ) ******************/ /**
 *
 *  Sobrecarga del operador '<<' para sacar la información de un Tiempo 
 *  por un stream (fichero, consola, ...).
 *
 *  @param [in, out]  out    stream por el que vamos a sacar la informacion.
 *  @param [in]      t      objeto Tiempo que queremos sacar por el stream.
 *
 *  @return  El stream modificado tras su utilizacion
 *
 */ /**********************************************************************/
ostream& operator<< (ostream& out, Tiempo t)
{
    out << setw(2) << setfill('0') << t.horas << ":" << setw(2) << setfill('0') << t.minutos;

    return out;
}

/*** void operator+=(Tiempo& t, Tiempo t2) ******************/ /**
 *
 *  Sobrecarga del operador '+=' para sumar a un tiempo otro tiempo dado
 *
 *  @param [in, out]  t       Tiempo que queremos modificar.
 *  @param [in]      t2      Tiempo que queremos añadir.
 *
 */ /**********************************************************************/
void operator+=(Tiempo &t, Tiempo t2)
{
    t.horas += t2.horas;
    t.minutos += t2.minutos;
    
    if(t.minutos >= 60)
    {
        t.horas ++;
        t.minutos -= 60;
    }
}

/*** void operator-=(Tiempo& t, Tiempo t2) ******************/ /**
 *
 *  Sobrecarga del operador '-=' para restar a un tiempo otro tiempo dado
 *
 *  @param [in, out]  t       Tiempo que queremos modificar.
 *  @param [in]      t2      Tiempo que queremos restar.
 *
 */ /**********************************************************************/
void operator-=(Tiempo &t, Tiempo t2)
{
    t.horas -= t2.horas;
    t.minutos -= t2.minutos;
    
    if(t.minutos < 0)
    {
        t.horas --;
        t.minutos += 60;
    }
}
