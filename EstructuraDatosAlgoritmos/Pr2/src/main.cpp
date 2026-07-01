#include <iostream>
#include <fstream>
#include <pr2_funciones.h>

using namespace std;

 /**
  * @brief Programa principal
  * 
  * @return int 
  */
int main()
{
    const unsigned int tini = 10;   // Tamaño mínimo del vector
    const unsigned int tfin = 1000; // Tamaño máximo del vector
    const int inc = 10;             // Incremento para cada experimento

    Experimento(tini, tfin, inc);

    return 0;
}


/**
 * @brief Función para comparar costes de 3 algoritmos: Busqueda secuencial, binaria y con centinela.
 * 
 * @param tini 
 * @param tfin 
 * @param inc 
 */
void Experimento(unsigned tini, unsigned tfin, int inc)
{
    srand(time(NULL));
    size_t pasos;
    unsigned int pasos_totales_bs, pasos_totales_bc, pasos_totales_bb;
    unsigned int n;
    unsigned int valores; 
    int x;
    TVector v;
    ofstream salida_BS;
    ofstream salida_BC;
    ofstream salida_BB;
    

    salida_BB.open("data/salida_BB.txt");
    salida_BC.open("data/salida_BC.txt");
    salida_BS.open("data/salida_BS.txt");

    if(!salida_BS.is_open() || !salida_BC.is_open() || !salida_BB.is_open())
    {
        cout << "error al cargar los archivos"<< endl;
    }
 

    for(n = tini ; n <= tfin; n += inc )
    {
        valores = 20 * n; // Hay que resetear la variable para evitar conflicto de información
        GenerarVectorOrdenado(v, n);

        // Búsqueda Binaria
        pasos_totales_bb = 0;// Resetear contadores
        pasos_totales_bs = 0;
        pasos_totales_bc = 0;
        for (unsigned int i = 0; i < valores; i++) {
            x = rand() % (2 * n-1); // Generar un valor aleatorio en el rango pedido (0, 2.n-1)
            BusquedaBinaria(v, x, pasos);
            pasos_totales_bb += pasos;
            BusquedaConCentinela(v,x,pasos);
            pasos_totales_bc += pasos;
            BusquedaSecuencialParada(v,x,pasos);
            pasos_totales_bs += pasos;
        }
        salida_BB << n << " " << pasos_totales_bb/valores << endl; 
        salida_BC << n << " " << pasos_totales_bc/valores << endl; 
        salida_BS << n << " " << pasos_totales_bs/valores << endl; 
    }
}

