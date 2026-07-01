/****** main.cpp ****************************************************/ /**
 *
 * @file main.cpp
 *
 * @brief Practica 0 de EDA-GIM
 * Realiza un test de la clase Estudiante
 * Lee los datos del archivo "plantilla.dat" y
 * realiza estadisticas basicas sobre la edad y estatura de los
 * estudiantes, asi como del numero de estudiantes por curso
 *
 * @version 1.0
 * @author Jesus Albert
 * @date 16-03-2020
 */ /**************************************************************************/
 
#include <iostream>
#include <fstream>
#include <vector>
#include "estudiante.h"

using namespace std;

/*
 * Prototipos de las funciones empleadas,
 * implementadas despues de main()
 */
string ExtraerToken(string&);
bool StrToestudiante (string, Estudiante&);
vector<Estudiante> LeerFichero(string);
Estudiante MasAlto (vector<Estudiante>);
Estudiante MasBajo (vector<Estudiante>);
Estudiante MasJoven (vector<Estudiante>);
Estudiante MasViejo (vector<Estudiante>);
unsigned int NumEstudiantesCurso (vector<Estudiante>, int c);

/*
 * Programa principal
 */
int main ()
{
    const string NOMBRE = "data/personal.dat"; //Nombre del archivo de datos
    vector<Estudiante> misestudiantes; //Vector para almacenar estudiantes leidos
    
    cout << endl << "Leyendo archivo ... ";
    misestudiantes = LeerFichero(NOMBRE);
    cout << "Fin." << endl;
    cout << endl;
    cout << "*** Num. estudiantes correctamente leidos: " << misestudiantes.size() << " ***" << endl;
    cout << endl;
    cout << "1. Estudiante mas ALTO:" << endl;
	cout << MasAlto(misestudiantes) << endl;
    cout << endl;
	cout << "2. Estudiante mas BAJO:" << endl;
	cout << MasBajo(misestudiantes) << endl;
    cout << endl;
    cout << "3. Estudiante mas JOVEN:" << endl;
	cout << MasJoven(misestudiantes) << endl;
    cout << endl;
    cout << "4. Estudiante mas VIEJO:" << endl;
	cout << MasViejo(misestudiantes) << endl;
    cout << endl;
	cout << "5. Estudiantes por curso:" << endl;
	for (unsigned int i = 1; i <= 4; i++)
		cout << "\tCurso " << i << " = " << NumEstudiantesCurso(misestudiantes,i) << endl;
	
	return 0;
}

/**********************************************************************/ /**
 *
 *  Extraer 1 token de informacion de la cadena separada por ';'
 *  El token es eliminado de la cadena de entrada
 *
 *  @param [in,out]  s  Cadena de datos
 *
 *  @return  string con el token extraido
 *
 */ /**********************************************************************/
string ExtraerToken(string & s)
{
    string res="";
    size_t pos;
    
    pos = s.find(";");
    if ( pos != string::npos )
    {
        res = s.substr(0,pos);
        s.erase(0,pos+1);
    }
    else
    {
        res = s;
        s = "";
    }
        
    return res;
}

/**********************************************************************/ /**
 *
 *  Asignar valores a un objeto Estudiante a partir de 
 *  una linea de texto con datos separados por ';' 
 *
 *  @param [in]  texto  Linea de texto
 *  @param [in,out]  est  Estudiante modificado
 *
 *  @retval  true   Ha sido posible asignar correctamente valores.
 *  @retval  false  No ha sido posible asignar correctamente valores.
 *
 */ /**********************************************************************/
bool StrToEstudiante (string texto, Estudiante& est)
{
    string dato;
    unsigned int campo;
    string id, a, n;
    char s;
    int e, h, w;
    string tit;
    int curs;
    bool ok = true;
    
    campo = 0;
    while ( ok && campo < 9 )
    {
        dato = ExtraerToken(texto);
        if ( dato.length() != 0 )
        {
            switch ( campo )
            {
                case 0: id = dato; break;
                case 1: a = dato; break;
                case 2: n = dato; break;
                case 3: s = dato[0]; break;
                case 4: e = stoi(dato); break;
                case 5: h = stoi(dato); break;
                case 6: w = stoi(dato); break;
                case 7: tit = dato; break;
                case 8:
                	curs = stoi(dato);
                	ok = est.AsignarValores(id,a,n,s,e,h,w,tit,curs);
                	break;
            }
            campo++;
        }
        else
            ok = false;
    }
    return ok;
}

/**********************************************************************/ /**
 *
 *  Leer fichero de datos, devuelve vector de Estudiantes
 *
 *  @param [in]  nom  Nombre del fichero
 *
 *  @return  vector de Estudiantes
 *
 */ /**********************************************************************/
vector<Estudiante> LeerFichero(string nom)
{
    ifstream fich_in;
    vector<Estudiante> v;
    string linea;
    
    fich_in.open (nom);
    
    if (fich_in)
    {
        while ( getline(fich_in, linea) )
        {
            Estudiante e;
            if ( StrToEstudiante(linea,e) )
                v.push_back(e);
        }
            
        fich_in.close ();
    }
    else
    	cerr << "LeerFichero: Error al abrir el archivo de datos." << endl;

    return v;
}

/**********************************************************************/ /**
 *
 *  Determina el estudiante mas alto de un vector de Estudiantes
 *
 *  @param [in]  v  Vector de Estudiantes
 *
 *  @return  Estudiante de mayor estatura (el primero del vector)
 *
 */ /**********************************************************************/
Estudiante MasAlto (vector<Estudiante> v)
{
	unsigned int max;
	Estudiante e;
	if ( v.size() > 0 )
	{
		max = 0;
		for (unsigned int i=0; i < v.size(); i++)
			if (v[i].GetEstatura() > v[max].GetEstatura())
				max = i;	
		e = v[max]; 
	}	
	return e;
}

/**********************************************************************/ /**
 *
 *  Determina el estudiante mas bajo de un vector de Estudiantes
 *
 *  @param [in]  v  Vector de Estudiantes
 *
 *  @return  Estudiante de menor estatura (el primero del vector)
 *
 */ /**********************************************************************/
Estudiante MasBajo (vector<Estudiante> v)
{
	unsigned int min;
	Estudiante e;
	if ( v.size() > 0 )
	{
		min = 0;
		for (unsigned int i=0; i < v.size(); i++)
			if (v[i].GetEstatura() < v[min].GetEstatura())
				min = i;	
		e = v[min]; 
	}	
	return e;
}

/**********************************************************************/ /**
 *
 *  Determina el estudiante mas joven de un vector de Estudiantes
 *
 *  @param [in]  v  Vector de Estudiantes
 *
 *  @return  Estudiante de menor edad (el primero del vector)
 *
 */ /**********************************************************************/
Estudiante MasJoven (vector<Estudiante> v)
{
	unsigned int min;
	Estudiante e;
	if ( v.size() > 0 )
	{
		min = 0;
		for (unsigned int i=0; i < v.size(); i++)
			if (v[i].GetEdad() < v[min].GetEdad())
				min = i;	
		e = v[min]; 
	}	
	return e;
}

/**********************************************************************/ /**
 *
 *  Determina el estudiante mas viejo de un vector de Estudiantes
 *
 *  @param [in]  v  Vector de Estudiantes
 *
 *  @return  Estudiante de mayor edad (el primero del vector)
 *
 */ /**********************************************************************/
Estudiante MasViejo (vector<Estudiante> v)
{
	unsigned int max;
	Estudiante e;
	if ( v.size() > 0 )
	{
		max = 0;
		for (unsigned int i=0; i < v.size(); i++)
			if (v[i].GetEdad() > v[max].GetEdad())
				max = i;	
		e = v[max]; 
	}	
	return e;
}

/**********************************************************************/ /**
 *
 *  Determina el num. de estudiantes de un curso de un vector de Estudiantes
 *
 *  @param [in]  v  Vector de Estudiantes
 *  @param [in]  c  Curso a buscar
 *
 *  @return  numero de estudiantes en el curso c
 *
 */ /**********************************************************************/
unsigned int NumEstudiantesCurso (vector<Estudiante> v, int c)
{
	unsigned int num = 0;
	
	for (unsigned int i=0; i < v.size(); i++)
		if ( v[i].GetCurso() == c )
			num++;
	return num;
}
