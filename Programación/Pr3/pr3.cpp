
/****** Pr3.cpp ***********************************************************/ /**
 *
 * @file Pr3.cpp
 *
 * @brief Practicas de Programacion 3. Iniciacion a las clases
 *
 * Lee la informacion de los municipios guardada en un fichero, los pone
 * en una estructura de datos adecuada y permite diferentes opciones de 
 * tratamiento de la informacion a traves de un menu.
 *
 *
 * @version 6
 * @version María José Azcárate, Alejandro Hernández
 * @author Jose Fco. Garcia, Jesus Albert, Ricardo Ferris
 * @date 06/03/2024
 *
 */ /**************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "municipio.h"

/**
 * Maximo numero de municipios que es posible guardar en la estructura
 */
const int MAX = 8200;

//const string NOM_FICH = "EvolMunicipios_small.csv"; ///< Nombre del fichero a leer
const string NOM_FICH = "EvolMunicipios2022.csv"; ///< Nombre del fichero a leer

/*
 * Usaremos la clase Municipio para guardar la informacion relativa a cada uno
 * de los municipios.
 */
   
/**
 * Tipo vector de municipios: Estructura auxiliar para construir el registro
 * Municipios
 */ 
typedef Municipio VecMunicipios[MAX + 1];
// Dimensionamos con MAX + 1 el vector porque vamos a utilizar la busqueda
// con centinela sobre el vector

/**
 * Registro Municipios donde guardar toda la informacion de los municipios
 * (la informacion de cada municipio, asi como el numero de municipios)
 */
struct Municipios
{
    VecMunicipios info; ///< Vector donde guardar la informacion de cada municipio
    unsigned int num;   ///< Numero de municipios guardados
};

/*
 * Prototipos de las funciones empleadas,
 * implementadas despues de main()
 */
bool LeerFichero(string, Municipios &);
void MostrarMunicipios(Municipios);
void MostrarCodineYNombresDeTodosLosMunicipios(const Municipios &);
int BusquedaBinaria(VecMunicipios, int, string);
int BusquedaConCentinela(VecMunicipios, int, string);
void CambiarNombreMunicipio(Municipio &);
Municipio MenorIncremento(const Municipios &);
Municipio MayorIncrementoRelativo(const Municipios &);
void Presentacion(void);
int Menu(void);

/*
 * Programa principal
 */
int main()
{
    Municipios municipios;
    Municipio municipio;
    int opcion,
        pos;
    VecDatos datos;
    string codine,
           nombre;
    
    Presentacion();
        
    // Leemos la informacion del conjunto de municipios
    if (LeerFichero (NOM_FICH, municipios))
        cout << "Leidos " << municipios.num << " municipios." << endl;
    else
    {
        cout << "Error al abrir el fichero de municipios." << endl;
        cout << "Empezaremos sin municipios." << endl;
    }
    
    do
    {
        opcion = Menu();
        
        switch(opcion)
        {
            case 1:
                MostrarCodineYNombresDeTodosLosMunicipios(municipios);
                break;
            
			case 2:
                
				cout << "Dame el codigo INE del municipio: ";
                cin >> nombre;
                cin.ignore();
                pos = BusquedaBinaria(municipios.info, municipios.num, nombre);
                if (pos == -1)
                {
                	cerr << "No se ha encontrado el municipio buscado" << endl;	
				}
				else
				{
					municipios.info[pos].Mostrar();
				}
                 
                
                break;
            case 3:
                 
				 cout << "Dame el nombre del municipio: ";
                cin >> nombre;
                cin.ignore();
                pos = BusquedaConCentinela(municipios.info, municipios.num, nombre);
                if (pos == -1)
                {
                	cerr << "No se ha encontrado el municipio buscado" << endl;	
				}
				else
				{
					municipios.info[pos].Mostrar();
				}
                 

                                                    
                break;
            case 4:
                cout << "Dame codigo INE a buscar: ";
                cin >> codine;
                cin.ignore();
                pos = BusquedaBinaria(municipios.info, municipios.num, codine);
                
                if (pos == -1)
                {
                	cerr << "No se ha encontrado el municipio buscado" << endl;	
				}
				else
				{
					municipios.info[pos].Mostrar();
					CambiarNombreMunicipio(municipios.info[pos]);
				}
                 


                break;
            case 5:
                if (municipios.num > 0)
                {
                    municipio = MenorIncremento(municipios);
                    cout << "El municipio con menor incremento de poblacion es:\n";
                    municipio.Mostrar();
                    municipio.ObtenerDatos(datos);
                    cout << "Incremento: ";
                    cout << datos[0] - datos[N_ANYOS - 1] << endl << endl;
    
                    municipio = MayorIncrementoRelativo(municipios);
                    cout << "El municipio con mayor incremento relativo de ";
                    cout << "poblacion es:\n";
                    municipio.Mostrar();
                    municipio.ObtenerDatos(datos);
                    cout << "Incremento relativo: ";
                    cout << float(datos[0] - datos[N_ANYOS - 1]) / datos[0] << endl;
                }
                else
                    cout << "No hay municipios que evaluar.\n";

                break;
            case 0:
                break;
            default:
                cout << "Opcion incorrecta.\n";
        }
    }
    while (opcion != 0);

    return 0;
}

/**********************************************************************/ /**
 *
 *  Muestra por pantalla que realiza el programa.
 *
 */ /**********************************************************************/
void Presentacion(void)
{
    cout << "Este programa se encarga de la gestion de los datos de censo ";
    cout << "de las ciudades espanyolas.";
    cout << endl;
    cout << "Puede consultarse la informacion de una poblacion concreta ";
    cout << "mediante su codigo INE o por su nombre, asi como modificar ";
    cout << "la informacion de cada uno de los elementos de su informacion.";
    cout << endl << endl;
    
    return;
}

/**********************************************************************/ /**
 *
 *  Muestra por pantalla las opciones del menu y devuelve la opcion elegida
 *  por el usuario.
 * 
 *  @return Opcion elegida por el usuario.
 *
 */ /**********************************************************************/
int Menu(void)
{
    int opcion;

    cout << endl;
    cout << "Elige una de las opciones:\n";
    cout << " 1. Mostrar el codigo INE y el nombre de TODOS los municipios.\n";
    cout << " 2. Buscar un municipio por codigo INE y mostrar su informacion ";
    cout << "completa por pantalla.\n";
    cout << " 3. Buscar un municipio por su nombre y mostrar su informacion ";
    cout << "completa por pantalla.\n";
    cout << " 4. Buscar un municipio por codigo INE y modificar su nombre.\n";
    cout << " 5. Buscar el municipio con mayor incremento de poblacion de los ";
    cout << "guardados en memoria.\n";
    cout << endl;
    cout << " 0. Salir.\n";
    cout << endl;
    cout << "Opcion: ";
    
    cin >> opcion;
    cout << endl;
    
    return opcion;
}

/**********************************************************************/ /**
 *
 *  Lee la informacion de los municipios contenidos en el fichero del que se
 *  nos pasa el nombre y la guarda en el registro Municipios de forma
 *  adecuada.
 *  La funcion devolvera si se abrio con exito el fichero, o si no se pudo
 *  abrir en cuyo caso el numero de municipios leidos sera 0.
 *
 *  @param [in]  nom_fich   Nombre del fichero donde esta la informacion de
 *                          los municipios.
 *  @param [out]  municipios Registro a rellenar con informacion de todos
 *                           los municipios.
 
 *  @retval true  Se han leido los registros del fichero.
 *  @retval false No se ha podido abrir el fichero.
 *
 */ /**********************************************************************/
bool LeerFichero (string nom_fich, Municipios & municipios)
{
    ifstream fich_in;
    string cab;
    bool ok;
    
    fich_in.open (nom_fich);
    
    municipios.num = 0;
    
    if (fich_in)
    {
        getline(fich_in,cab); //Leer la linea de cabecera
        
        while (municipios.num < MAX
               && municipios.info[municipios.num].LeerDeFichero(fich_in))
            municipios.num++;
            
        fich_in.close();
        ok = true;
    }
    else
        ok = false;

    return ok;
}

/**********************************************************************/ /**
 *
 *  Muestra por pantalla el numero de municipios asi como el codigo INE
 *  y el nombre de los municipios pasados como parametros.
 *
 *  @param [in]  municipios  registro que contiene la informacion de los
 *                           municipios ha mostrar
 *
 */ /**********************************************************************/
void MostrarCodineYNombresDeTodosLosMunicipios(const Municipios & municipios)
{
    unsigned int i;
    
    cout << "Municipios leidos: " << municipios.num << endl;
    cout << "-------------------------------------" << endl;
    for (i = 0; i < municipios.num; i++)
    {
        cout << municipios.info[i].ObtenerCodine() << " - ";
        cout << municipios.info[i].ObtenerNombre() << endl;
    }
    
    return;
}

/**********************************************************************/ /**
 *
 *  Implementa el metodo de busqueda binaria:
 *
 *  @pre  n debe ser un valor entero positivo
 *
 *  @param [in]  v    vector que contiene los datos
 *  @param [in]  n    numero de elementos 'validos' en el vector
 *  @param [in]  cod  clave del elemento a buscar
 *
 *  @retval  >= 1   Posicion donde se ha encontrado el municipio buscado
 *  @retval   -1    Devolvemos -1 si no hemos conseguido encontrar el
 *                  municipio buscado
 *
 */ /**********************************************************************/
int BusquedaBinaria(VecMunicipios v, int n, string cod)
{
 	
    int izq, der, cen, posicion;
    
    // izq y der delimitan la zona del vector donde se busca
    // cen es la posicion del elemento central de esta zona
     
    izq = 0;
    der = n - 1;
    cen = (izq + der) / 2;
    
 // 3 asignaciones iniciales
    
    // Mientras no se encuentre el elemento
    // y existan mas de un elemento en el subvector continua
    // la busqueda
    while ((izq <= der) && (v[cen].ObtenerCodine() != cod))
    {
	 // doble comparacion del while (izq <= der) && (v[cen].codine != cod)
        if (cod < v[cen].ObtenerCodine())
            der = cen - 1;
        else
            izq = cen + 1;
            
        cen = (izq + der) / 2;
		 // condicion del if + 2 asignaciones
    }
 
    // Se puede salir del bucle por haber encontrado el
    // elemento o por haber llegado a un subvector sin elementos
    
    if (izq > der)
    {
        posicion = -1;
		 //salio del ucle en primera condicion (izq>der) 
    }   
    else
    {
        posicion = cen; //salio del bucle ejecutando las 2 condiciones (izq<=der) , (v[i].codine != cod)
    }
         // condicion del if + 1 asignacion de valor de enc
 
 
    return posicion ;
}

/**********************************************************************/ /**
 *
 *  Implementa el metodo de busqueda secuencial con centinela:
 *
 *  @pre  n debe ser un valor entero positivo
 *
 *  @param [in]  v    vector que contiene los datos
 *  @param [in]  n    numero de elementos 'validos' en el vector
 *  @param [in]  nom  clave del elemento a buscar
 *
 *  @retval  >= 1   Posicion donde se ha encontrado el municipio buscado
 *  @retval   -1    Devolvemos -1 si no hemos conseguido encontrar el
 *                  municipio buscado
 *
 */ /**********************************************************************/
int BusquedaConCentinela(VecMunicipios v, int n, string nom)
{
	int i, posicion;
	
        //fijar centinela antes de buscar
    v[n].AsignarNombre(nom);
    i = 0;
    while (v[i].ObtenerNombre() != nom)
	{
        i = i + 1;
	}
    
    if (i == n)
        posicion = -1;
    else
        posicion = i;

    return posicion;
}

/**********************************************************************/ /**
 *
 *  Pide un nuevo nombre para el municipio y se lo asigna
 *
 *  @param [in, out]  municipio  municipio al que vamos a cambiar el nombre
 *
 */ /**********************************************************************/
void CambiarNombreMunicipio(Municipio & municipio)
{
     string nuevoNombre;
    
    cout << "Dame el nuevo nombre del municipio: ";
    cin >> nuevoNombre;
    municipio.AsignarNombre(nuevoNombre);
    return;
}

/**********************************************************************/ /**
 *
 *  Determina el municipio que ha sufrido un menor incremento de poblacion
 *  en los ultimos N_ANYOS
 *
 *  @pre Debe haber al menos un municipio con informacion valida en 
 *       el registro de municipios
 *
 *  @param [in]  municipios  municipios de los que vamos a realizar el
 *                           estudio
 *
 *  @return  el municipio que ha sufrido el menor incremento de poblacion
 *           (o el primero de los encontrados).
 *
 */ /**********************************************************************/
Municipio MenorIncremento(const Municipios & municipios)
{
    Municipio municipio_menor;
    VecDatos dataMen, data_act;
    int MenInc, IncAct, v1, v2;
    
    
		municipio_menor = municipios.info[0];
		
		for (unsigned int i = 1; i < municipios.num; i++)
 	 	{
		
		v2 = municipios.info[i].ObtenerDatos(data_act);
		v1 = municipio_menor.ObtenerDatos(dataMen);
		
		
	  		if (v1 == 25 && v2 == 25)
			{
			
		   	  	  IncAct = data_act[N_ANYOS - 1] - data_act[0];
		   	  	  MenInc = dataMen[N_ANYOS-1] - dataMen[0];
		   	  	  
   				  if (IncAct > MenInc)
		   	  	  {
					 municipio_menor = municipios.info[i]; 
				  }
	 	    }

		}
    return municipio_menor;
}

/**********************************************************************/ /**
 *
 *  Determina el municipio que ha sufrido un mayor incremento relativo
 *  de poblacion en los ultimos N_ANYOS
 *
 *  @pre Debe haber al menos un municipio con informacion valida en 
 *       el registro de municipios
 *
 *  @param [in]  municipios  municipios de los que vamos a realizar el
 *                           estudio
 *
 *  @return  el municipio que ha sufrido el mayor incremento relativo
 *           de poblacion (o el primero de los encontrados).
 *
 */ /**********************************************************************/
Municipio MayorIncrementoRelativo(const Municipios & municipios)
{
    Municipio municipio_mayor;
    VecDatos dataMay, data_act;
    double MayIncRel, IncActRel, x1, x2, x3, x4;
    int v1, v2;
    
    
		municipio_mayor = municipios.info[0];
		
		for (unsigned int i = 1; i < municipios.num; i++)
 	 	{
		
		v2 = municipios.info[i].ObtenerDatos(data_act);
		v1 = municipio_mayor.ObtenerDatos(dataMay);
		
		
	  		if (v1 == 25 && v2 == 25)
			{
			
		   	  	  x1 = static_cast<double>(data_act[0]);
		   	  	  x2 = static_cast<double>(data_act[N_ANYOS - 1]);
		   	  	  x3 = static_cast<double>(dataMay[0]);
		   	  	  x4 = static_cast<double>(dataMay[N_ANYOS - 1]);
					   
					   
			   	  IncActRel = (x1 - x2)/x1;
   	  	  		  MayIncRel = (x3 - x4)/x3;
		   	  	  
   				  if (IncActRel > MayIncRel)
		   	  	  {
					 municipio_mayor = municipios.info[i]; 
				  }
	 	    }

		}
    return municipio_mayor;
}
