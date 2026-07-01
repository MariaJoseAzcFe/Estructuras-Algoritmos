#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

using namespace std;
void tarea1();
void tarea2();


/**
 * @brief Programa principal que crea un mapa de usuarios y las IP que uilizan los mismos para acceder a un servicio.
 * 
 * @return int 
 */
int main() 
{
    int opcion;

    cout << "Seleccione la tarea a ejecutar:" << endl;
    cout << "1. Tarea 1" << endl;
    cout << "2. Tarea 2" << endl;
    cout << "Opcion: ";
    cin >> opcion;

    switch (opcion) 
    {
        case 1:
            tarea1();
            break;
        case 2:
            tarea2();
            break;
        default:
            cout << "Opción no válida." << endl;
    }

    return 0;
}
 /**
  * @brief Función ejercicio 2
  * 
  */
void tarea2()
{
    string linea, usuario, ip;
    size_t pSeparacion;

    // Mapa para almacenar los datos
    map<string, map<string, unsigned int>> registro;

    
    ifstream archivoEntrada("data/conexiones.txt");
    if (!archivoEntrada) 
    
        cerr << "Error: No se pudo abrir el archivo conexiones.txt" << endl;
        
    

   
    while (getline(archivoEntrada, linea)) 
    {
        // Encontrar la posición del ;
        pSeparacion = linea.find(';');
        
        // Obtener el usuario y la IP
        usuario = linea.substr(0, pSeparacion);          
        ip = linea.substr(pSeparacion + 1);               

        // Incrementar el contador para la IP en el registro del usuario
        registro[usuario][ip]++;
    }

    archivoEntrada.close();

    // Abrir el archivo de salida
    ofstream archivoSalida("data/informe.txt");
    if (!archivoSalida) 
    
        cerr << "Error: No se pudo crear el archivo informe.txt" << endl;
   
    

    // Escribir los datos ordenados en el archivo de salida
    for (const auto& par : registro)  
    {
        archivoSalida << par.first;  

        
        for (const auto& ip : par.second)  
        {
            archivoSalida << ";" << ip.first << "#" << ip.second; 
        }

        archivoSalida << endl;  
    }

    archivoSalida.close();

    cout << "Informe generado en 'informe.txt'." << endl;

}

/**
 * @brief Función ejercicio 1
 * 
 */
void tarea1()
{
    string linea, usuario, ip;
    size_t pSeparacion;

    // Mapa para almacenar el ABB (usuario -> vector de IPs)
    map<string, vector<string>> registro;

  
    ifstream archivoEntrada("data/conexiones.txt");

    if (!archivoEntrada) 
    
        cerr << "Error: No se pudo abrir el archivo conexiones.txt" << endl;
       

   
    while (getline(archivoEntrada, linea)) 
    {
      
        pSeparacion = linea.find(';');

        
            
        usuario = linea.substr(0,pSeparacion);        // Desde el inicio hasta el ';'
        ip = linea.substr(pSeparacion + 1);           // Desde el carácter después del ';' hasta el final

            // Agregar la IP al vector del usuario en el ABB
        registro[usuario].push_back(ip);
        
    }

    archivoEntrada.close();

    // Abrir el archivo de salida
    ofstream archivoSalida("data/informe.txt");
    if (!archivoSalida) 
    
        cerr << "Error: No se pudo crear el archivo informe.txt" << endl;
      
    

    // Escribir los datos ordenados al archivo de salida
    for (const auto& par : registro) 
    {
        archivoSalida << par.first; // Nombre del usuario

        for (const auto& ip : par.second) 
        {
            archivoSalida << ";" << ip; // Lista de IPs separadas por ';'
        }

        archivoSalida << endl;
    }

    archivoSalida.close();

    cout << "Informe generado en 'informe.txt'." << endl;

    

}