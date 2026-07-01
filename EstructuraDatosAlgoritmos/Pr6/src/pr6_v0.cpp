/**
 * @file pr6_v0.cpp
 * @brief Pr�ctica 6 EDA-GIM
 * Uso de tablas hash para hacer hashing espacial
 * Objetivo: Determinar las particulas de una simulacion que colisionan 
 * = est�n a distancia inferior a  una distancia UMBRAL .
 *
 * @author: Jes�s Albert
 * @date: 04/12/2024
 * @version 1.0
 */

#include "pr6_definiciones.h"
#include "tablaHash.h"
#include <fstream>
#include <iostream>
#include <utility>
#include <stdexcept>
#include <chrono>

using namespace std;

const string LINEA = string(50,'-');
const string RUTA = "data/"; //<<< ruta de datos

//Funciones del programa
TVector LeerArchivo(string);
void CrearTabla(const TVector&, TablaHash&);
unsigned int TipoCelda(size_t);
float Distancia(const TVector&, size_t, size_t);
vector<size_t> CalcularColisiones(size_t, const TVector&, const TablaHash&, const vector<int>&);
void GuardarResultadosTotales(const TVectorColisiones&, string);
void GuardarColisionesParticula(size_t, const TVector&, const TVectorColisiones&, string);
void MostrarDatosTiempo(chrono::duration<double>);

//Programa principal
int main()
{    
    //Variables para medicion de tiempos de ejecucion
    chrono::time_point<chrono::system_clock> t_ini, t_fin;
    chrono::duration<double> duracion(0);
    
    cout << endl;       
    cout << "CALCULO DE COLISIONES PARA UNA SECUENCIA DE " << NUM_FRAMES << " FOTOGRAMAS." << endl;
    cout << LINEA << endl;

    for (size_t frame=1; frame<=NUM_FRAMES; frame++)
    {
        //Definiciones de variables locales al bucle para que cada nueva iteracion las reinicie "vacias"
        TVector particulas; //Posiciones de todas las particulas
        TVectorColisiones colisiones; //Registro de todas las colisiones para cada particula
        TablaHash tabla(NCELDAS_TOTAL,particulas); //Tabla hash para acelerar el calculo
        string nombre_input, nombre_output; //Nombres archivo de entrada y salida

        //1: Leer archivo de entrada (2D) + incorporar cada nueva particula a la tabla hash
        nombre_input = RUTA + PRE_NOM_IN + to_string(frame) + ".dat";
        cout << "Fotograma: " << frame << " (" << nombre_input << ")" << endl;
        cout << endl;
        cout << "\t>> Tarea 1: Leer particulas ... ";
        try
        {
            particulas  = LeerArchivo(nombre_input);
            t_ini = chrono::system_clock::now(); //Tomar tiempo inicial, creacion tabla hash
            CrearTabla(particulas,tabla);
            t_fin = chrono::system_clock::now(); //Tomar tiempo final, creacion tabla hash    
            duracion += t_fin - t_ini;
        }
        catch ( const runtime_error& e)
        {
            cerr << "Error lectura de datos:" << endl;
            cerr << e.what() << endl;
        }
        cout << "fin." << endl;
        cout << "\tParticulas leidas: " << particulas.size() << endl;
        cout << endl;
        
        //2: Para cada particula calcular sus posibles colisiones sobre los 8 vecinos del grid
        cout << "\t>> Tarea 2: Calcular distancias ... ";
        colisiones.resize(particulas.size()); //Dimesionar el vector de colisiones igual que el de particulas
        t_ini = chrono::system_clock::now(); //Tomar tiempo inicial, calculo de colisiones
        for (size_t i = 0 ; i < particulas.size(); i++)
        {
            unsigned int tipo;
            //Determinar el tipo de celda en la que se ubica la particula
            tipo = TipoCelda(tabla.Bucket(i));
            //Calcular las colisiones de la particula i usando el vector de vecinos adecuado
            switch(tipo)
            {
                case 0: colisiones[i] = CalcularColisiones(i, particulas, tabla, VECINOS_STD);
                        break;
                case 1: colisiones[i] = CalcularColisiones(i, particulas, tabla, VECINOS_IZQ);
                        break;
                case 2: colisiones[i] = CalcularColisiones(i, particulas, tabla, VECINOS_DER);
                        break;
            }
        }
        t_fin = chrono::system_clock::now(); //Tomar tiempo final, calculo de colisiones
        duracion += t_fin - t_ini;
        cout << "fin." << endl;
        cout << endl;
        
        //3: Guardar resultados para todas las particulas en archivo de salida
        nombre_output = RUTA + PRE_NOM_OUT + to_string(frame) + ".dat";
        cout << "\t>> Tarea 3: Guardar resultados en " << nombre_output << " ... ";
        GuardarResultadosTotales(colisiones,nombre_output);
        cout << "fin." << endl;
        cout << endl;

        //4: Verificacion de resultados = Generar archivo de posiciones de particulas que colisionan en la particula 0
        cout << "\t>> Tarea 4: Generar archivo de particulas que colisionan con la particula 0" << endl;
        nombre_output = RUTA + "p0_" + PRE_NOM_OUT + to_string(frame) + ".dat";
        cout << "\tGenerando archivo ... ";
        GuardarColisionesParticula(0, particulas, colisiones, nombre_output); 
        cout << "fin." << endl;
        cout << LINEA << endl;
    }
    cout << endl;
    MostrarDatosTiempo(duracion);
    cout << endl;
    return 0;
}

/**********************************************************************/ /**
 *
 *  @brief Leer posiciones de todas las particulas a partir de un archivo
 *  Posiciones x, y (1 posicion por linea)
 *
 *  @param [in] nom Nombre del archivo de entrada
 *  @return Vector de posiciones de particulas
 *  @throw runtime_error si lee posicion fuera de los limites del escenario
 *
 */ /**********************************************************************/
TVector LeerArchivo(string nom)
{
    TVector particulas;
    TParticula particula;
    string linea;
    int pos;
    ifstream archivo(nom);
  

    if (!archivo.is_open()) 
    {
        cerr<<"Error al abrir el archivo";
        exit (1);
    }
    else
    {
        try
        {
            while (getline(archivo,linea)) 
            {
                pos= linea.find(" ");
                particula.first =stoul(linea.substr(0,pos));
                particula.second =stoul(linea.substr(pos+1));
                particulas.push_back(particula);
            }
        }

        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
  
    archivo.close();
 
    return particulas;
}

/**********************************************************************/ /**
 *
 *  @brief Guardar los indices de todas las particulas en una tabla hash
 *
 *  @param [in] part Vector de part�culas
 *  @param [in,out] tabla Tabla hash
 *
 */ /**********************************************************************/
void CrearTabla(const TVector& particulas, TablaHash& tablaHash)
{
    for (size_t i = 0; i < particulas.size(); i++)
    {
        tablaHash.Insertar(particulas[i].first);  
    }
}

/**********************************************************************/ /**
 *
 *  @brief Indica el tipo de celda en funcion de la zona de la rejilla 
 *  en la que esta ubicada la celda
 *  @param [in] i Identificador numerico de la celda
 *  @retval 0 Celda fuera de los laterales de la rejilla con 8 potenciales celdas vecinas
 *  @retval 1 Celda situada en la columna izquierda, no tiene vecinos a la izquierda
 *  @retval 2 Celda situada en la columna derecha, no tiene vecinos a la derecha
 *
 */ /**********************************************************************/
unsigned int TipoCelda(size_t i)
{
	unsigned int tipo = 0;
	
	if ( i%NCELDAS_X == 0 )
		tipo = 1;
	else if ( (i+1)%NCELDAS_X == 0 )
		tipo = 2;
		
	return tipo;
}

/**********************************************************************/ /**
 *
 *  @brief Distancia (al cuadrado) entre dos particulas de indices i y j
 *  @param [in] v Vector de posiciones de las particulas
 *  @param [in] i Indice de la primera particula
 *  @param [in] j Indice de la segunda particula 
 *  @return Distancia al cuadrado entre las particulas i y j
 *
 */ /**********************************************************************/
float Distancia(const TVector& v, size_t i, size_t j)
{
	float dx2 = (v[i].first-v[j].first)*(v[i].first-v[j].first);
	float dy2 = (v[i].second-v[j].second)*(v[i].second-v[j].second);
	return dx2+dy2;
}

/**********************************************************************/ /**
 *
 *  @brief Determinar las particulas que estan a distancia inferior a UMBRAL
 *  de la particula i (aquellas que colisionan con i)
 *  @param [in] i Indice de la particula a la que calculan distancias
 *  @param [in] part Vector de posiciones de las particulas
 *  @param [in] tabla Tabla hash con las particulas agrupadas por celdas
 *  @param [in] vec Vector auxiliar con posiciones relativas de las celdas vecinas
 *  @return Vector con los identificadores de las particulas que afectan a i
 *
 */ /**********************************************************************/

std::vector<size_t> CalcularColisiones(size_t i, const TVector& particulas, const TablaHash& tablaHash, const std::vector<int>& vec)
{
    std::vector<size_t> colisiones;  
    const TParticula& p1 = particulas[i];  

 
    size_t celdaParticula = tablaHash.Bucket(i);

 
    for (int desplazamiento : vec)
    {
        size_t celdaVecina = celdaParticula + desplazamiento;

        // Verificamos si la celda vecina está dentro del rango válido
        if (celdaVecina < NCELDAS_TOTAL)  
        {
            
            const std::vector<size_t>& bucketVecino = tablaHash.GetBucket(celdaVecina);

           
            for (size_t j : bucketVecino)
            {
                
                if (i != j)
                {
                    const TParticula& p2 = particulas[j];  

                    
                    float dx = p1.first - p2.first;
                    float dy = p1.second - p2.second;
                    float distanciaCuadrada = dx * dx + dy * dy;

                    if (distanciaCuadrada < UMBRAL * UMBRAL)
                    {
                        colisiones.push_back(j); 
                    }
                }
            }
        }
    }

    return colisiones;
}




/**********************************************************************/ /**
 *
 *  @brief Guardar en un archivo los INDICES de todas las particulas que
 *  colisionan con cada una de las particulas de la simulacion
 *  @param [in] col Vector con todas las colisiones entre particulas
 *  @param [in] nom Nombre del archivo de salida
 *
 *  Formato del archivo:
 *  2 lineas por particula: (i) en la primera se indica el identificador de la
 *  particula a la que se hace referencia, precedido por el caracter '#', y
 *  el numero de particulas que colisionan con ella; (ii) en la segunda linea
 *  se indican los identificadores de todas las particulas que colisionan separados por ' '
 *  #<id_particula> <numero_colisiones>
 *  <id> <id> <id> ...
 * 
 */ /**********************************************************************/
void GuardarResultadosTotales (const TVectorColisiones& col, string nom)
{
    ofstream archivo(nom);
    if (!archivo.is_open())
    {
        throw runtime_error("Error al abrir el archivo: " + nom);
    }

    for (size_t i = 0; i < col.size(); i++)
    {
        archivo << "#" << i << " " << col[i].size() << "\n";
        
        for (size_t id : col[i])
        {
            archivo << id << " ";
        }

        archivo << "\n";
    }

    archivo.close();
}


/**********************************************************************/ /**
 *
 *  @brief Guardar en un archivo las posiciones de todas las particulas que
 *  colisionan con una particula concreta
 *  @param [in] i Indice de la particula para la que se generan resultados
 *  @param [in] part Vector de posiciones de las particulas
 *  @param [in] col Vector con todas las colisiones entre particulas
 *  @param [in] nom Nombre del archivo de salida
 *
 */ /**********************************************************************/
void GuardarColisionesParticula(size_t i, const TVector& part, const TVectorColisiones& col, string nom)
{
    ofstream archivo(nom);
    if (!archivo.is_open())
    {
        throw runtime_error("No se pudo abrir el archivo: " + nom);
    }

    for (size_t id : col[i])
    {
        archivo << part[id].first << " " << part[id].second << "\n";
    }

    archivo.close();
}
/**********************************************************************/ /**
 *
 *  @brief Mostrar datos temporales de ejecucion del procesamiento
 *  no se han considerado los tiempos de lectura y escritura de archivos
 *  @param [in] d Duracion del procesadmiento de todos los fotogramas
 *
 */ /**********************************************************************/
void MostrarDatosTiempo(chrono::duration<double> d)
{
    double temp = d.count();
    cout << "TIEMPO DE PROCESAMIENTO:" << endl;
    cout << "\tTotal: " << temp << " segs." << endl;
    cout << "\tTiempo medio por fotograma: " << temp/NUM_FRAMES << " segs." << endl;
    cout << "\tVelocidad de procesado: " << NUM_FRAMES/temp << " fotogramas por segundo." << endl;   
}


