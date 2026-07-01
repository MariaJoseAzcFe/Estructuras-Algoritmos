 /****** pr2.cpp ****************************************************/ /**
 *
 * @file pr2.cpp
 *
 * @brief Prácticas de Programación 2.
 *
 * Lee la información de los municipios guardada en un fichero, los pone
 * en una estructura y los muestra por pantalla utilizando la clase Municipio.
 *
 * El programa está preparado para probar y analizar los algoritmos de ordenación
 *
 * @version 5
 * @author Alejandro Hernández Pérez, MaríaJosé Azcarate 
 * @author Jose Fco. Garcia, Jesús Albert
 * @date 29-02-2024
 */ /**************************************************************************/
 
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>  //Equivalente C, #include <stdlib.h>
#include <ctime>    //Equivalente C, #include <time.h>

#include "municipio.h"

using namespace std;

/**
 * Maximo nº de municipios que es posible guardar en la estructura
 */
const int MAX = 8200;

///< Numero de algoritmos con los que trabajar
const int N_ALGORITMOS = 3;

///< Codificación de los algoritmos de ordenación
const int INSERCION = 0;
const int SELECCION = 1;
const int QUICKSORT = 2;

///< Nombre del fichero a leer
const string NOM_FICH = "EvolMunicipios2022.csv"; 
 

/**
 * Usaremos la clase Municipio para guardar la informacion relativa a 
 * cada uno de los municipios.
 */
   
/**
 * Tipo vector de municipios: Estructura auxiliar para construir el 
 * registro Municipios
 */ 
typedef Municipio VecMunicipios[MAX+1];

/**
 * Registro Municipios donde guardar toda la informacion de los municipios
 * (la información de cada municipio, asi como el número de municipios)
 */
struct Municipios
{
    VecMunicipios info;
    unsigned int num;
};

///< Tipo para el vector de contadores
typedef int Contadores[N_ALGORITMOS];

/*
 * Prototipos de las funciones empleadas,
 * implementadas despues de main()
 */
void ResetContadores(Contadores);
 
bool LeerFichero (string, Municipios &);
void MostrarMunicipios (Municipios);

bool Ordenado(VecMunicipios, int);
void Desordenar(VecMunicipios, int);

void OrdenarInsercion(VecMunicipios, int, int &);
void OrdenarSeleccion(VecMunicipios, int, int &);
void OrdenarQuicksort(VecMunicipios, int, int &); 
void Particion(VecMunicipios, int, int, int &);

void ProbarOrdenaciones(Municipios &, int, Contadores);
void RealizarExperimentos(Municipios &, int, Contadores, int);

/*
 * Programa principal
 */
int main ()
{
    Municipios municipios;     // Registro en el que vamos a buscar
   Contadores contadores;  // Contadores del total de operaciones, 1 x algoritmo
   unsigned int talla, repeticiones;
    
/*
    cout << "Indica la talla del vector a estudiar: ";
    cin >> talla;

    cout << "Indica el numero de repeticiones: ";
    cin >> repeticiones;
    
*/
	 do
	 {
	    cout << "Introduce la talla del problema: ",
		cin >> talla;
		cout << "Introduce las repeticiones: ";
		cin >> repeticiones; 
	    while(talla>MAX)
	    {
	    	cout << "No es posible poner ese valor";
	    		cout << "Introduce de nuevo la talla del problema: ",
		 		cin >> talla;
		 
		}
	    if(talla != 0)
	    {
		    if ( LeerFichero (NOM_FICH, municipios) )
		    {
		        // Verificamos en pantalla los datos leidos
		        cout << "Leidos " << municipios.num << " municipios." << endl;
		        //MostrarMunicipios (municipios); Comentamos las lineas de ejecuci�n que se piden para no relentizar innecesariamente el programa
		        if(Ordenado(municipios.info, municipios.num))
		            cout << endl << "El fichero original esta ordenado creciente." << endl;
		        else    
		            cout << endl << "El fichero original NO esta ordenado creciente." << endl;
		        
		        ResetContadores(contadores);      
		       // ProbarOrdenaciones(municipios, municipios.num, contadores);
		
		        ResetContadores(contadores);        
		
		    	RealizarExperimentos(municipios,talla,contadores,repeticiones);
		        	
				
		    }
		    else
		        cerr << "Error al abrir el fichero de municipios." << endl;
		}
	}while(talla != 0);  //Para repetir hasta una talla 0
	    return 0;
}

/**********************************************************************/ /**
 *
 *  Lee la información de los municipios contenidos en el fichero del que se
 *  nos pasa el nombre y la guarda en el registro Municipios de forma
 *  adecuada.
 *  La función devolverá si se abrió con exito el fichero, o si no se pudo
 *  abrir en cuyo caso el número de municipios leidos será 0.
 *
 *  @param [in]  nom_fich   Nombre del fichero donde esta la información de
 *                          los municipios.
 *  @param [in, out]  municipios Registro a rellenar con informacion de todos
 *                               los municipios.
 
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
        
        while ( municipios.info[municipios.num].LeerDeFichero(fich_in) )
            municipios.num++;
            
        fich_in.close ();
        ok = true;
    }
    else
        ok = false;

    return ok;
}

/**********************************************************************/ /**
 *
 *  Muestra la informacion de los municipios contenidos en el vector
 *
 *  @param [in]  municipios  registro con la informacion de los municipios
 *
 */ /**********************************************************************/
void MostrarMunicipios (Municipios municipios)
{
    unsigned int i;
    
    // Mostrar por pantalla los datos leidos
    for (i = 0; i < municipios.num; i++)
    {
        municipios.info[i].Mostrar();// Mostrar por pantalla los datos del objeto municipios.info[i] que es 
        // de la clase Municipio
    } 
}

/**********************************************************************/ /**
 *
 *  Inicia a 0 los contadores de pasos de los algoritmos
 *
 *  @param [in,out]  t  array de contadores de pasos
 *
 */ /**********************************************************************/
void ResetContadores(Contadores t)
{
    unsigned int i;
    
    for (i = 0; i < N_ALGORITMOS; i++)
        t[i] = 0;
}

/**********************************************************************/ /**
 *
 *  Indica si los primeros num elementos de un vector de municipios están en 
 *  orden creciente
 *
 *  @param [in]  v  Vector de objetos de la clase Municipio.
 *
 *  @param [in]  num Número de municipios a comprobar del vector
 *
 *  @return  Verdadero si cada elemento es "menor" que el siguiente
 *
 */ /**********************************************************************/
bool Ordenado(VecMunicipios v, int num)
{
    bool respuesta;
    int i;
    
    i = 0;
    while ( i < (num - 1) && v[i].DevuelveCodine() < v[i+1].DevuelveCodine() ) //Se puede comprobar que se ordena por codine
        i++;
        
    if (i == num - 1)
        respuesta = true;
    else
        respuesta = false;
                
    return respuesta;
}

/**********************************************************************/ /**
 *
 *  Desordena n elementos de un vector aleatoriamente
 *
 *  @param [in/out]  v  Vector de objetos de la clase Municipio.
 *
 *  @param [in]  n Número de municipios que se ordenan
 *
 */ /**********************************************************************/
void Desordenar(VecMunicipios v, int n)
{
    int i, cual;
    Municipio auxmunicipio;
    
    for (i = 0; i < n; i++)
    {
        cual = rand()%n;
        auxmunicipio = v[cual];
        v[cual] = v[0];
        v[0] = auxmunicipio;
    }
}

/**********************************************************************/ /**
 *
 *  Ordena de modo creciente n elementos de un vector por el algoritmo de 
 *  inserción
 *
 *  @param [in/out]  v  Vector de objetos de la clase Municipio
 *
 *  @param [in]  n Número de municipios que se ordenan
 *
 *  @param [in/out]  pasos  incrementa el numero de pasos
 *
 */ /**********************************************************************/
void OrdenarInsercion(VecMunicipios v, int n, int & pasos)
{ 

    int i, j;
 
    //la parte ordenada está al final de vector
    for (i = n-2; i>=0; i--)
    {
        v[n].DevuelveCodine() = v[i].DevuelveCodine(); //centinela
        pasos++;
        j = i+1;
        while ( v[j].DevuelveCodine() < v[n].DevuelveCodine() )
        {       
            v[j-1].DevuelveCodine() = v[j].DevuelveCodine();
            j++;
            pasos += 2;
        }
        v[j-1].DevuelveCodine() = v[n].DevuelveCodine();
        pasos+=2;
    }
    
}

/**********************************************************************/ /**
 *
 *  Ordena de modo creciente n elementos de un vector por el algoritmo de 
 *  selección
 *
 *  @param [in/out]  v  Vector de objetos de la clase Municipio.
 *
 *  @param [in]  n Número de municipios que se ordenan
 *
 *  @param [in/out]  pasos  incrementa el numero de pasos
 *
 */ /**********************************************************************/
void OrdenarSeleccion(VecMunicipios v, int n, int & pasos)
{ 
  
    int i, j, pos_min;
    Municipio aux;
  
    for (i = 0; i < n - 1; i++)
    {    
        pos_min = i;
        for (j = i + 1; j < n; j++)
        {
            if (v[j].DevuelveCodine() < v[pos_min].DevuelveCodine() )
                pos_min = j;
                pasos++;
        }
              
        if (pos_min != i)
        {  
            aux = v[i];
            v[i].DevuelveCodine() = v[pos_min].DevuelveCodine();
            v[pos_min] = aux;
            pasos+=3;
        }
    }    

}

/**********************************************************************/ /**
 *
 *  Ordena de modo creciente n elementos de un vector por el algoritmo 
 *  Quicksort
 *
 *  @param [in/out]  v  Vector de objetos de la clase Municipio.
 *
 *  @param [in]  n Número de municipios que se ordenan
 *
 *  @param [in/out]  pasos  incrementa el numero de pasos
 *
 */ /**********************************************************************/
void OrdenarQuicksort(VecMunicipios v, int n, int & pasos)
{
 
    Particion(v, 0, n-1, pasos);

}

/**********************************************************************/ /**
 *
 *  Función de partición para el algoritmo de ordenación por Quicksort
 *
 *  @param [in/out]  v  Vector de objetos de la clase Municipio.
 *
 *  @param [in]  izq  posición izquierda
 *
 *  @param [in]  der  posición derecha
 *
 *  @param [in/out]  pasos  incrementa el numero de pasos
 *
 */ /**********************************************************************/
void Particion(VecMunicipios v, int izq, int der, int & pasos)
{    

    int i, j;
	string piv, aux;
	
    piv = v[(izq+der)/2].DevuelveCodine();
    i = izq;
    j = der;
    
    while(i<=j)
    {
        while( v[i].DevuelveCodine() < piv ) 
        {
            i++;
            pasos+=2;
        }
        while( piv < v[j].DevuelveCodine() )
        {
            j--;
            pasos+=2;
        }
            
        if(i < j)
        {
            aux = v[i].DevuelveCodine();
            v[i].DevuelveCodine() = v[j].DevuelveCodine();
            v[j].DevuelveCodine() = aux;
            i++;
            j--;
            pasos+=3;
        } 
        else if (i == j)
        {   
            i++;
            j--;   
        }          
    }    
    
    if(izq < j)
        Particion(v, izq, j, pasos);
    if(i < der)
        Particion(v, i, der, pasos);    

}

/**********************************************************************/ /**
 *
 *  Prueba los diferentes algoritmos de ordenación.
 *
 *  @param [in/out] municipios Estr. con vector de municipios y nº de elementos.
 *  @param [in]     n         Tamaño del vector con el que se va a trabajar
 *  @param [in/out] pasos     Contadores de pasos acumulados por algoritmo
 *
 */ /**********************************************************************/
	void ProbarOrdenaciones(Municipios & municipios, int n, Contadores pasos)
{
    Municipios municipios_copia;
    
    if(Ordenado(municipios.info, municipios.num))
        cout << endl << "Original ordenado." << endl;
    else
        cout << endl << "Original desordenado." << endl;    
    
    // desordenamos un conjunto de municipios con la talla estudiada
    Desordenar(municipios.info, n);
    cout << "Se ha desordenado el vector." << endl;

    // hacemos una copia para utilizar el mismo "desorden" en los diferentes
    // algoritmos
    municipios_copia = municipios;
         
    OrdenarInsercion(municipios.info, n, pasos[INSERCION]);
    if(Ordenado(municipios.info, n))
        cout << endl << "Vector de " << n << " elementos ordenado";
    else
        cout << endl << "Vector de " << n << " elementos desordenado";        
    cout << " por insercion en " << pasos[INSERCION] << " pasos." << endl;    
    //municipios.num = n; 
    //MostrarMunicipios(municipios);

    // retomamos el mismo "desorden"
    municipios = municipios_copia;
            
    OrdenarSeleccion(municipios.info, n, pasos[SELECCION]);
    if(Ordenado(municipios.info, n))
        cout << endl << "Vector de " << n << " elementos ordenado";
    else
        cout << endl << "Vector de " << n << " elementos desordenado";        
    cout << " por seleccion en " << pasos[SELECCION] << " pasos." << endl;    
    //municipios.num = n; 
    //MostrarMunicipios(municipios);
    
    // retomamos el mismo "desorden"
    municipios = municipios_copia;

    OrdenarQuicksort(municipios.info, n, pasos[QUICKSORT]);
    if(Ordenado(municipios.info, n))
        cout << endl << "Vector de " << n << " elementos ordenado";
    else
        cout << endl << "Vector de " << n << " elementos desordenado";        
    cout << " por quicksort en " << pasos[QUICKSORT] << " pasos." << endl;    
    //municipios.num = n; 
    //MostrarMunicipios(municipios);
}

/**********************************************************************/ /**
 *
 *  Realiza experimentos con los diferentes algoritmos de ordenación.
 *
 *  @param [in/out] municipios Estr. con vector de municipios y nº de elementos.
 *  @param [in]     n         Tamaño del vector con el que se va a trabajar
 *  @param [in/out] pasos     Contadores de pasos acumulados por algoritmo
 *  @param [in]     veces     Numero de repeticiones del experimento. 
 *
 */ /**********************************************************************/
void RealizarExperimentos(Municipios & municipios, int n, Contadores pasos, int veces)
{
    Municipios municipios_copia;
    
	ProbarOrdenaciones(municipios, n, pasos);
	
	srand(time(NULL)); //para que los experimentos sean aleatorios
    cout << endl << "Talla: " << n << endl;
    cout << "\t Numero de repeticiones: " << veces << endl;    
    cout << "\t Media de pasos realizados por los 3 algoritmos" << endl;
    cout << "\t\t insercion: " << pasos[INSERCION]/(double)veces << endl;
    cout << "\t\t seleccion: " << pasos[SELECCION]/(double)veces << endl;
    cout << "\t\t quicksort: " << pasos[QUICKSORT]/(double)veces << endl;
    cout << endl;    
}

