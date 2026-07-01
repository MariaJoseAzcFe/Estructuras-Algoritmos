
/******* persona.h ***************************************************/ /**
 *
 * @file persona.h
 *
 * Fichero de cabecera de la clase Persona
 *
 * @version 1.0
 * @author Jesus Albert
 * @date 03/03/2020
 *  
 ***************************************************************************/

#ifndef _PERSONA_H_
#define _PERSONA_H_

#include <string>
#include <iostream>

using namespace std;

/**
 * @brief Clase para el manejo de Personas
 *
  */

class Persona
{
    public:
        Persona();
        //Modificadores
        bool AsignarValores(string, string, string, char, int, int, int);
        bool SetId(string);
        bool SetApellidos(string);
        bool SetNombre(string);
        bool SetSexo(char);
        bool SetEdad (int);
        bool SetEstatura (int);
        bool SetPeso (int);
        //Consultores
        string GetId();
        string GetApellidos();
        string GetNombre();
        char GetSexo();
        int GetEdad ();
        int GetEstatura();
        int GetPeso();
        //Imprimir
        friend ostream& operator<<(ostream&,Persona);
    private:
        string id, apellidos, nombre;
        char sexo;
        int edad, estatura, peso;
        //Funciones de validacion
        bool ValidarSexo (char);
        bool ValidarEdad (int);
        bool ValidarEstatura (int);
        bool ValidarPeso (int);
};

#endif
