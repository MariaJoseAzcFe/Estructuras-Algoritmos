
/******* municipio.cpp ****************************************************/ /**
 *
 * @file municipio.cpp
 *
 * Implementación de los métodos de la clase Municipio
 *
 * @version 1.0
 * @author Jose Fco. Garcia, Jesus V. Albert
 * @date 22/02/2023
 *  
 ***************************************************************************/

#include "municipio.h"

/*** Municipio::Municipio() **************************************************/ /**
 *
 *  Asigna valores iniciales 'coherentes' a los distintos atributos de la
 *  clase
 *
 */ /**********************************************************************/
Municipio::Municipio ()
{
    /*
       No seria necesario iniciar los 'string' porque se inician de forma
       automatica a vacíos en cuanto se declaran, como p.e. nombre = "";
    
        Si se quiere, podríamos iniciarlos a valores 'por defecto'
    */
    
    codine = "unknown";
    nombre = "unknown";
    ndatos = 0;
}

/*** void Municipio::Mostrar () ***********************/ /**
 *
 *  Muestra por la salida estandar los datos del municipio
 *
 */ /****************************************************/
void Municipio::Mostrar ()
{
    string sep = "    ";
    
    cout << "*** Datos del municipio:" << endl;
    cout << sep << "- Cod. INE: " << codine << endl;
    cout << sep << "- Nombre  : " << nombre << endl;
    cout << sep << "- Datos de poblacion ( " << ndatos << " anyos ):" << endl;
        
    for (unsigned int i = 0; i < ndatos; i++)
    {
        cout << sep << "Datos del año " << ANYO_INICIO - i << ": ";
        cout << datos[i] << " habitantes" << endl;
    }
}

/*** bool LeerDeFichero (ifstream &) ***********************************/ /**
 *
 *  @param [in/out]  fich_in  fstream del que vamos a obtener la informacion.
 *
 *  @retval  true   La informacion ha podido ser leida de forma correcta.
 *  @retval  false  La informacion no ha podido ser leida de forma correcta
 *                  (probablemente porque se ha terminado el fichero).
 *
 */ /**********************************************************************/
bool Municipio::LeerDeFichero (ifstream & fich_in)
{
    bool ok, quedan;
    string dato_ine;

    //código del municipio
    if ( getline (fich_in, codine,';') ) 
    {
        //nombre del municipio
        getline (fich_in, nombre,';');    
        ndatos = 0;
        quedan = true;
        while ( ndatos < N_ANYOS-1 && quedan)
        {
            //cogemos datos de población de cada año 
            //mientas haya, si no hay más aparece una 'x'.
            getline (fich_in, dato_ine,';');  
            if (dato_ine != "x")              
            {
                datos[ndatos] = stoi(dato_ine);   
                ndatos++;
            }
            else
                // es una 'x' ya no hay más registros de población.
                quedan = false;     
        }
        // cargamos lo que queda hasta el final de la línea
        getline (fich_in, dato_ine);   
        //comprobamos si es un dato de población para insertarlo  
        if (quedan && dato_ine != "x") 
        {
            datos[ndatos] = stoi(dato_ine); 
            ndatos++;
        }
        ok = true;
    }
    else
        ok = false;
        
    return ok;
}


/*** string Persona::DevuelveIdentificador () *************************/ /**
 *
 *  Devuelve el nombre del municipio.
 *
 *  @return  el string con el nombre del municipio.
 *
 */ /**********************************************************************/
 string Municipio::DevuelveCodine ()
 {
    return codine;
 }
   
/**********************************************************************/ /**
 *
 *  Modifica el nombre del municipio recibido como parámetro.
 *
 *  @param[in]  nomb    nuevo nombre del municipio.
 *
 */ /**********************************************************************/
 void Municipio::PonCodine (string cod)
 {
    codine = cod;
 }

