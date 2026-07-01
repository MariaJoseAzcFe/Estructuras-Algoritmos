/****** pr1.cpp ***********************************************************/ /**
 *
 * @file pr1.cpp
 *
 * @brief Prácticas de Programación.
 *
 * Lee la informacion de los municipios de un fichero, la pone en un 
 * registro y realiza diferentes bÃºsquedas en el mismo para realizar medidas
 * empíricas de esas búsquedas.
 *
 * @version 4
 * @author Jesúss Albert, Jose García
 * @author Maria Jose Azcarate, Alejandro Hernandez
 * @date 22-02-2024
 */ /**************************************************************************/
 
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

#include <clocale>    // para poder mostrar acentos,
#include <windows.h>  // año etc.

using namespace std;

/**
 * Maximo de municipios que es posible guardar en la estructura
 */
const int MAX = 10000;

/**
 * Número de años sobre los que se recoge datos
 */
const int N_ANYOS = 25;

/**
 * Último año del que se tienen datos
 */
const int ANYO_INICIO = 2022;

/**
 * Numero de algoritmos con los que trabajar
 */
const int N_ALGORITMOS = 4;

/* Codificacion de los algoritmos de busqueda */
const int SECUENCIAL           = 0; ///< Valor busqueda secuencial
const int SECUENCIAL_PARADA    = 1; ///< Valor busqueda secuencial con parada
const int SECUENCIAL_CENTINELA = 2; ///< Valor busqueda con centineal
const int BUSQUEDA_BINARIA     = 3; ///< Valor busqueda binaria

const string NOM_FICH = "EvolMunicipios_small.dat";  ///< Nombre del fichero a leer

/**
 * Tipo vector de datos de poblacion desde 1998 a 2022: 25 años
 */ 
typedef int VecDatos[N_ANYOS];

/**
 * Registro Municipio donde guardamos la informacion relativa uno de los
 * municipios. Solo se desea guardar: codigo, nombre, puntuaciones de los
 * ultimos 25 años.
 */
struct Municipio
{
    string codine;          ///< Codigo INE del municipio
    string nombre;          ///< Nombre del municipio
    unsigned int ndatos;    ///< num. de años para los que hay datos
    VecDatos datos;         ///< Datos de poblacion de los ultimos 25 años
                            //   datos[0] = 2022, datos[1] = 2021, ...
};
   
/**
 * Tipo vector de municipios: Estructura auxiliar para construir el registro
 * Municipios
 */ 
typedef Municipio VecMunicipios[MAX];

/**
 * Registro Municipios donde guardar toda la informacion de los municipios
 * (la informacion de cada municipio, asÃ­ como el numero de municipios)
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


void MostrarMunicipio(Municipio);
bool LeerFichero(string, Municipios &);
bool LeerMunicipioFichero(ifstream &, Municipio &);
int BusquedaSecuencial(VecMunicipios, int, string, int &);
int BusquedaSecuencialParada(VecMunicipios, int, string, int &);
int BusquedaConCentinela(VecMunicipios, int, string, int &);
int BusquedaBinaria(VecMunicipios, string, int, int &);
int RealizarBusquedas(Municipios, string, Contadores);

/*
 * Programa principal
 */
int main ()
{
    Municipios municipios;     // Registro en el que vamos a buscar
    Contadores contar;      // Contadores de pasos, 1 x algoritmo
    // Estas 3 instrucciones son para que se visualice bien los 
    // caracteres propios del idioma español: ñ, acentos, ...
    setlocale(LC_CTYPE, "SPANISH"); // Suficiente para maquinas LINUX
    SetConsoleCP(1252);             // Cambia STDIN -  Para maquinas Windows
    SetConsoleOutputCP(1252);       // Cambia STDOUT - Para maquinas Windows
    int posicion; //Para guardar la posici�n en la que se encuentra en identificador
    string codigos [5] = {"28079","08019","46250","08022","46126"}; //Vector con los identificadores a buscar
    string identificador;// donde vamos a almacenar cada string del anterior vector, sino el c�digo no compila por tipos de datos distintos en los parametros
    int i;//variable del bucle for para controlar sus iteraciones, que no deben ser superior al vector creado
    
    // Leer la informacion de los municipios
    if (LeerFichero(NOM_FICH, municipios))
    {
        cout << "leidos: " << municipios.num << endl;
        
        // Verificar en pantalla los datos leidos
        for (unsigned int i = 0; i < municipios.num; i++)
            MostrarMunicipio(municipios.info[i]);
    }
    else
        cerr << "No se pudo abrir el fichero." << endl;
        
    for(i=0;i < 5; i++)
    {
    identificador = codigos[i];
    cout << "Para el identificador " << identificador <<" :"<< endl;
    posicion = RealizarBusquedas(municipios,identificador,contar);
    if (posicion == -1)
    	cout << "no encontrado" << endl;
    else
    	cout << "se encuentra en la posicion " << posicion << endl;
	}
    
        
    return 0;
}

/**********************************************************************/ /**
 *
 *  Muestra por pantalla la informacion de 1 Municipio
 *
 *  @param [in]  mu  Municipio cuyos datos se van a mostrar
 *
 */ /**********************************************************************/
void MostrarMunicipio(Municipio mu)
{
    string sep = "    ";
    int anyo;
    
    cout << "*** Datos del municipio:" << endl;
    cout << sep << "- Codigo   : " << mu.codine << endl;
    cout << sep << "- Nombre   : " << mu.nombre << endl;
    cout << sep << "- Registro poblacion últimos " << mu.ndatos << " años:\n";
    
    anyo = ANYO_INICIO;
    for (unsigned int i = 0; i < mu.ndatos; i++)
    {
        cout << sep << "Datos del año " << anyo - i << ": ";
        cout << mu.datos[i] << " habitantes" << endl;
    }
    cout << endl;
}

/**********************************************************************/ /**
 *
 *  Lee la informacion de los municios contenidos en el fichero del que se
 *  nos pasa el nombre y la guarda en el registro Municipios de forma
 *  adecuada.
 *  Si el fichero no se puede abrir, el numero de municipios leido sera cero.
 *
 *  @param [in]      nom_fich  Nombre del fichero donde esta la informacion de
 *                         los municipios.
 *  @param [in/out]  municipios  El registro Municipios a rellenar debidamente.
 *
 *  @retval true   Se pudo leer el fichero y rellenar los municipios.
 *  @retval false  No se pudo leer el fichero, registro municipios se queda sin
 *                 instanciar.
 *
 */ /**********************************************************************/
bool LeerFichero(string nom_fich, Municipios & municipios)
{
    ifstream fich_in;
    string cab;
    bool ok;
    
    fich_in.open (nom_fich);
    
    municipios.num = 0;
    
    if (fich_in)
    {
        //Leer la linea de cabecera, no se utiliza
        getline(fich_in,cab);
        
        while (municipios.num < MAX
               && LeerMunicipioFichero(fich_in, municipios.info[municipios.num]))
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
 *  Lee, si es posible, un municipio del fichero del que se pasa el descriptor
 *  y devuelve el registro Municipio debidamente rellenado y si ha podido o no
 *  rellenarlo adecuadamente.
 *
 *  @pre  El descriptor del fichero debe referirse a un fichero previamente
 *        abierto de forma correcta.
 *
 *  @param [in,out]  fich_in  Descriptor del fichero del que vamos a leer
 *                            la informacion.
 *
 *  @param [out]     municipio  Registro Municipio debidamente rellenado con la
 *                            informacion leida del fichero.
 *
 *  @retval  true   La informacion ha podido ser leÃ­da de forma correcta.
 *
 *  @retval  false  La informacion no ha podido ser leÃ­da de forma correcta
 *                  (probablemente porque se ha terminado el fichero).
 *
 */ /**********************************************************************/
bool LeerMunicipioFichero(ifstream & fich_in, Municipio & municipio)
{
    bool ok, quedan;
    string dato_ine;

    //código del municipio
    if (getline(fich_in, municipio.codine, ';')) 
    {
        //nombre del municipio
        getline(fich_in, municipio.nombre, ';');    
        
        cout << "Municipio: " << municipio.nombre << endl;
        municipio.ndatos = 0;
        quedan = true;
        while (municipio.ndatos < N_ANYOS - 1 && quedan)
        {
            //cogemos datos de población de cada año 
            //mientas haya, si no hay más aparece una 'x'.
            getline(fich_in, dato_ine, ';');  
            if (dato_ine != "x")              
            {
                cout << dato_ine << endl;
                municipio.datos[municipio.ndatos] = stoi(dato_ine);   
                municipio.ndatos++;
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
            cout << dato_ine << endl;
            municipio.datos[municipio.ndatos] = stoi(dato_ine); 
            municipio.ndatos++;
        }
        ok = true;
    }
    else
        ok = false;
        
    return ok;
}

/**********************************************************************/ /**
 *
 *  Implementa el metodo de busqueda secuencial (sin parada):
 *
 *  @pre  n debe ser un valor entero positivo
 *
 *  @param [in]  v    vector que contiene los datos
 *  @param [in]  n    numero de elementos 'validos' en el vector
 *  @param [in]  cod  clave del elemento a buscar
 
 *  @param [out]  pasos  Numero total de pasos realizados para completar
 *                       la busqueda. Se pone a cero (0) al iniciar la funcion
 *
 *  @retval  True   Si hemos concluido la busqueda con exito
 *  @retval  False  Si no hemos conseguido encontrar el municipio buscado
 *
 */ /**********************************************************************/
int BusquedaSecuencial(VecMunicipios v, int n, string cod, int & pasos)
{
    int i,posicion=-1; 
    
    i = 0;  
    pasos = 2; // enc = false, i  =0
    while (i < n)   
    {
        if (v[i].codine == cod)
        {
            posicion = i;           
            pasos++; 
        }
        i = i + 1;
		pasos += 3;  // i<n , v[i].codine == cod, i = i + 1
    }
    pasos++; // salida de la condicion  (i < n)
    
    return posicion;
}

/**********************************************************************/ /**
 *
 *  Implementa el metodo de busqueda secuencial con parada:
 *
 *  @pre  n debe ser un valor entero positivo
 *
 *  @param [in]  v    vector que contiene los datos
 *  @param [in]  n    numero de elementos 'validos' en el vector
 *  @param [in]  cod  clave del elemento a buscar
 
 *  @param [out]  pasos  Numero total de pasos realizados para completar
 *                       la busqueda. Se pone a cero (0) al iniciar la funcion
 *
 *  @retval  True   Si hemos concluido la busqueda con exito
 *  @retval  False  Si no hemos conseguido encontrar el municipio buscado
 *
 */ /**********************************************************************/
int BusquedaSecuencialParada(VecMunicipios v, int n, string cod, int & pasos)
{
    int i,posicion;
    
    i = 0;
    pasos = 1; // i = 0
    while ((i < n) && (v[i].codine != cod))
	{
        i = i + 1;
		pasos += 3; // (i < n), (v[i].codine != cod), i = i + 1;
	}

    // Si i ha llegado a n es que el elemento 'cod' no se ha encontrado
    // si no es que nos hemos detenido antes y el 'cod' si que esta en v
    if (i == n)
    {
        posicion = -1;
        pasos++; //salio del bucle en primera condicion (i<n) 
    }
    else
    {
        posicion = i;
        pasos += 2; //salio del bucle ejecutando las 2 condiciones (i<n) , (v[i].codine != cod)
    }
        
    pasos += 2; // (i==n), (enc = false o enc = true)

    return posicion;
}

/**********************************************************************/ /**
 *
 *  Implementa el metodo de busqueda secuencial con centinela:
 *
 *  @pre  n debe ser un valor entero positivo
 *
 *  @param [in]  v    vector que contiene los datos
 *  @param [in]  n    numero de elementos 'validos' en el vector
 *  @param [in]  cod  clave del elemento a buscar
 
 *  @param [out]  pasos  Numero total de pasos realizados para completar
 *                       la busqueda. Se pone a cero (0) al iniciar la funcion
 *
 *  @retval  True   Si hemos concluido la busqueda con exito
 *  @retval  False  Si no hemos conseguido encontrar el municipio buscado
 *
 */ /**********************************************************************/
int BusquedaConCentinela(VecMunicipios v, int n, string cod, int & pasos)
{
    int i,posicion;
    
    //fijar centinela antes de buscar
    v[n].codine = cod;
    i = 0;
    pasos = 2;
    while (v[i].codine != cod)
	{
        i = i + 1;
		pasos += 2; //(v[i].codine != cod), i = i + 1
	}
    
     /* Si i ha llegado a n es que hemos localizado al centinela
      * y el 'cod' no esta en v
      * sino es que nos hemos detenido antes de localizar al centinela
      * y el 'cod' si que esta en v
      */
    if (i == n)
        posicion = -1;
    else
        posicion = i;
    pasos += 3; // salida del while (v[i].codine != cod), condicion if (i==n), (enc = false Ã³ enc = true)

    return posicion;
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
 
 *  @param [out]  pasos  Numero total de pasos realizados para completar
 *                       la busqueda. Se pone a cero (0) al iniciar la funcion
 *
 *  @retval  True   Si hemos concluido la busqueda con exito
 *  @retval  False  Si no hemos conseguido encontrar el municipio buscado
 *
 */ /**********************************************************************/
int BusquedaBinaria(VecMunicipios v, int n, string cod, int & pasos)
{
    int izq, der, cen,posicion;
    
    // izq y der delimitan la zona del vector donde se busca
    // cen es la posicion del elemento central de esta zona
     
    izq = 0;
    der = n - 1;
    cen = (izq + der) / 2;
    
    pasos = 3; // 3 asignaciones iniciales
    
    // Mientras no se encuentre el elemento
    // y existan mas de un elemento en el subvector continua
    // la busqueda
    
    while ((izq <= der) && (v[cen].codine != cod))
    {
		pasos += 2; // doble comparacion del while (izq <= der) && (v[cen].codine != cod)
        if (cod < v[cen].codine)
            der = cen - 1;
        else
            izq = cen + 1;
            
        cen = (izq + der) / 2;
		pasos += 3; // condicion del if + 2 asignaciones
    }
 
    // Se puede salir del bucle por haber encontrado el
    // elemento o por haber llegado a un subvector sin elementos
    
    if (izq > der)
    {
        posicion = -1;
        pasos++; //salio del bucle en primera condicion (izq>der) 
    }   
    else
    {
        posicion = cen;//cen representa la posici�n del vector en la que no se cumple (v[cen].codine != cod)
        pasos += 2; //salio del bucle ejecutando las 2 condiciones (izq<=der) , (v[i].codine != cod)
    }
        
    pasos += 2; // condicion del if + 1 asignacion de valor de enc
 
    return posicion; //devuelve integer, la posici�n
}

/**********************************************************************/ /**
 *
 *  Lanza secuencialmente los 4 algoritmos de busqueda sobre
 *  el mismo codigo de municipio.
 *
 *  @pre  El vector de municipios debe estar correctamente rellenado.
 *
 *  @param [in]  municipios Registro Municipios con la informacion de los
 *                       municipios y el numero de municipios validos para la
 *                       realizacion de la busqueda.
 *
 *  @param [in]  cod     Codigo del municipio a buscar.
 *
 *  @param [out]  contadores  Vector en donde guardaremos el numero 
 *                            de pasos realizados dependiendo del metodo
 *                            de busqueda seleccionado.
 *
 *  @retval  True   Si hemos concluido la busqueda con exito
 *  @retval  False  Si no hemos conseguido encontrar el municipio buscado
 *
 */ /**********************************************************************/
int RealizarBusquedas(Municipios municipios, string cod, Contadores contadores)
{
    int pos1, pos2; //debemos usar los tipos de datos int para acceder a la posicion
    
    cout << endl << "** Buscando " << cod << " ... " << endl;
    
    cout << "Busqueda secuencial...";
    pos1 = BusquedaSecuencial(municipios.info, municipios.num, cod,
                            contadores[0]);
    cout << "Hecho" << endl;
    cout << "Se realiza en " << contadores[0] << " pasos" << endl; //se imprimen los pasos por pantalla
    cout << "Busqueda secuencial con Parada...";
    pos2 = BusquedaSecuencialParada(municipios.info, municipios.num, cod,
                                   contadores[1]);
    cout << "Hecho" << endl;
     cout << "Se realiza en " << contadores[1] << " pasos" << endl;
    
    if ( pos2 != pos1 )// si las posicion no es igual a la busqueda secuencial hay que recurrir a otro tipo de busqueda
        cerr << "BusquedaSecuencialParada proporciona otro resultado." << endl;
        
    cout << "Busqueda secuencial con centinela...";
    pos2 = BusquedaConCentinela(municipios.info, municipios.num, cod,
                               contadores[2]);
    cout << "Hecho" << endl;
     cout << "Se realiza en " << contadores[2] << " pasos" << endl;
    
    if ( pos2 != pos1 )
        cerr << "BusquedaConCentinela proporciona otro resultado." << endl;
        
    cout << "Busqueda binaria...";
    pos2 = BusquedaBinaria(municipios.info, municipios.num, cod, contadores[3]);
    cout << "Hecho." << endl;
     cout << "Se realiza en " << contadores[3] << " pasos" << endl;
    
    if ( pos2 != pos1 )
        cerr << "BusquedaBinaria proporciona otro resultado." << endl;
    cout << endl;
        
    return pos1;
}
