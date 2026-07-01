/******* municipio.cpp ****************************************************/ /**
 *
 * @file municipio.cpp
 *
 * Implementación de los métodos de la clase Municipio
 *
 * @version 1.1
 * @author Ricardo Ferris
 * @date 21/02/2024
 *
 * Anyadidos algunos 'putters' y 'getters' a la clase
 *
 * @version 1.0
 * @author Alejandro Hern�ndez P�rez, Mar�a Jos� Azcarate Ferrando
 * @author Jose Fco. Garcia, Jesus V. Albert
 * @date 22/02/2023
 *  
 ******************************************************************************/

#include "municipio.h"

/*** Municipio::Municipio() *******************************************/ /**
 *
 *  Constructor por defecto:
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
    n_datos = 0;
}

////////////////////////////////////////////////////////////////////////////
// Operaciones para modificar información del municipio ////////////////////
////////////////////////////////////////////////////////////////////////////

/**********************************************************************/ /**
 *
 *  Modifica la informacion del municipio con la recibida como parametros.
 *
 *  @param [in]  codine_  nuevo codigo INE del municipio.
 *  @param [in]  nom_  nuevo nombre del municipio.
 *  @param [in]  n_datos_  nuevo numero de datos de censo del municipio.
 *  @param [in]  datos_  Vector con los valores de censo de los ultimos
 *                       anyos del municipio.
 *
 */ /**********************************************************************/
void Municipio::AsignarValores(string codine_, string nom_, int n_datos_,
                                                          const VecDatos datos_)
{
    codine = codine_;
    nombre = nom_;
    n_datos = n_datos_;
    for (unsigned int i = 0; i < N_ANYOS; i++)
	{
	 	datos[i] = datos_[i];
	}
    
    return;
}

/**********************************************************************/ /**
 *
 *  Modifica el codigo INE del municipio con el recibido como parametro.
 *
 *  @param [in]  cod  nuevo codigo INE del municipio.
 *
 */ /**********************************************************************/
void Municipio::AsignarCodine(string cod)
{
    codine = cod;
    
    return;
}

/**********************************************************************/ /**
 *
 *  Modifica el codigo INE del municipio con el recibido como parametro.
 *
 *  @param [in]  nom_  nuevo nombre del municipio.
 *
 */ /**********************************************************************/
void Municipio::AsignarNombre(string nombre_)
{
    nombre = nombre_;

    
    return;
}

/**********************************************************************/ /**
 *
 *  Modifica el codigo numero de datos de censo y los valores de censo
 *  del municipio con los valores recibidos como parametro.
 *
 *  @param [in]  n_datos_  nuevo numero de datos de censo del municipio.
 *  @param [in]  datos_  Vector con los valores de censo de los ultimos
 *                       anyos del municipio.
 *
 */ /**********************************************************************/
void Municipio::AsignarDatos(int n_datos_, const VecDatos datos_)
{
    n_datos = n_datos_;
    for (int i = 0; i < N_ANYOS; i++)
	{
	 	datos[i] = datos_[i];
	}
    
    
    return;
}

////////////////////////////////////////////////////////////////////////////
// Operaciones para devolver información del municipio /////////////////////
////////////////////////////////////////////////////////////////////////////

/**********************************************************************/ /**
 *
 *  Devuelve el codigo INE del municipio.
 *
 *  @return el string con el codigo INE del municipio.
 *
 */ /**********************************************************************/
string Municipio::ObtenerCodine() const
{
    return codine;
}

/**********************************************************************/ /**
 *
 *  Devuelve el codigo INE del municipio.
 *
 *  @return el string con el nombre del municipio.
 *
 */ /**********************************************************************/
string Municipio::ObtenerNombre() const
{
    return nombre;
}

/**********************************************************************/ /**
 *
 *  Devuelve el codigo los datos de censo del municipio.
 *
 *  @param  [out]  v_datos  Vector con los valores de censo de los ultimos
 *                          anyos del municipio.
 *
 *  @return el numero de datos del censo del municipio.
 *
 */ /**********************************************************************/
int Municipio::ObtenerDatos(VecDatos v_datos) const
{
	for (unsigned int i = 0; i < n_datos; i++)
	{
	 	v_datos[i] = datos[i];
	}
    
	
    return n_datos;
}

/**********************************************************************/ /**
 *
 *  Devuelve el anyo del que se tiene elultimo valor de censo.
 *
 *  @return el anyo del ultimo censo del municipio.
 *
 */ /**********************************************************************/
int Municipio::ObtenerUltimoAnyo() const
{
    return ANYO_INICIO;
}

////////////////////////////////////////////////////////////////////////////
// Operaciones adicionales /////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

/**********************************************************************/ /**
 *
 *  @param [in/out]  fich_in  fstream del que vamos a obtener la informacion.
 *
 *  @retval  true   La informacion ha podido ser leida de forma correcta.
 *  @retval  false  La informacion no ha podido ser leida de forma correcta
 *                  (probablemente porque se ha terminado el fichero).
 *
 */ /**********************************************************************/
bool Municipio::LeerDeFichero(ifstream & fich_in)
{
    bool ok, quedan;
    string dato_ine;

    //código del municipio
    if (getline(fich_in, codine,';')) 
    {
        //nombre del municipio
        getline(fich_in, nombre, ';');    
        n_datos = 0;
        quedan = true;
        while (n_datos < N_ANYOS - 1 && quedan)
        {
            //cogemos datos de población de cada año 
            //mientas haya, si no hay más aparece una 'x'.
            getline(fich_in, dato_ine, ';');  
            if (dato_ine != "x")              
            {
                datos[n_datos] = stoi(dato_ine);   
                n_datos++;
            }
            else
                // es una 'x' ya no hay más registros de población.
                quedan = false;     
        }
        // cargamos lo que queda hasta el final de la línea
        getline(fich_in, dato_ine);   
        //comprobamos si es un dato de población para insertarlo  
        if (quedan && dato_ine != "x") 
        {
            datos[n_datos] = stoi(dato_ine); 
            n_datos++;
        }
        ok = true;
    }
    else
        ok = false;
        
    return ok;
}

/**********************************************************************/ /**
 *
 *  Muestra por la salida estandar los datos del municipio
 *
 */ /**********************************************************************/
void Municipio::Mostrar() const
{
    unsigned int i;
    
    cout << "***\nDatos del municipio:" << endl;
    cout << "- Nombre  : " << nombre << endl;
    cout << "- Cod. INE: " << codine << endl;
    cout << "- Datos de poblacion (" << n_datos << " anyos):" << endl;

    if (n_datos > 0)
    {
        cout << "  Datos desde el anyo " << ANYO_INICIO << ": ";        
        for (i = 0; i < n_datos - 1; i++)
        {
            cout << datos[i] << ", ";
        }
        cout << datos[i] << ".";
    }
    else
        cout << "No hay datos de censo.";

    cout << "\n***\n\n";
    
    return;
}
