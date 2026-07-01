/**
 * @file main.cpp
 * @brief Programa de Test de la Practica 1 de EDA (GIM).
 * 
 * Utilizacion de Punto3d y Segmento
 *
 * @author Jesus Albert
 * @date 08/10/2024
 * @version 1.0
 */

#define _USE_MATH_DEFINES
#include "punto3d.h"
#include "segmento.h"
#include <cmath>
#include <iostream>

void Test1();
void Test2();
void Test3();
void Test4();

int main()
{
    Test1();
    //Test2();
    //Test3();
    //Test4();
   
    return 0;
}

/**
 * @brief Manipulacion de puntos
 * 
 */
void Test1()
{
    /* Crear 3 puntos en diferentes localizaciones */
    Punto3d p1(1,0,0), p2(3,5,4), p3;
   

    cout << "**************" << endl;
    cout << "*   Test 1   *" << endl;
    cout << "**************" << endl;

    /* Mostrar los puntos en pantalla 
    Resultado correcto:
        (1,0,0)
        (3,5,4)
        (0,0,0)
    */
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    cout << "p3 = " << p3 << endl;
    cout << "-------------" << endl;

    /* Modificar el punto p1 con Set */
    p1.Set(5,25,78.9);
    /* Rotar el punto p2 un angulo pi/2 (90º) */
    p2.RotarX(M_PI/2);
    /* Desplazar el punto p3 */
    p3.Desplazar(-1,7,10);

    /* Mostrar los puntos en pantalla 
    Resultado correcto:
        p1 = (5,25,78.9)
        p2 = (3,-4,5)
        p3 = (-1,7,10)
    */
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    cout << "p3 = " << p3 << endl;
    cout << "-------------" << endl;
    cout << "Fin Test 1" << endl;
    cout << "Presiona Enter para salir..." <<endl;
    cin.get();
   
   
}

/**
 * @brief Manipulacion simple de Segmentos, solo Set y <<
 * 
 */

void Test2()
{
    /* Crear 2 Segmentos con valores por defecto */
    Segmento t, s;

    cout << "**************" << endl;
    cout << "*   Test 2   *" << endl;
    cout << "**************" << endl;

    /* Mostrar los Segmentos (vertices) por pantalla 
    Resultado correcto:
        t = (0,0,0) ; (1,1,1) ; long.= 1.73205
        s = (0,0,0) ; (1,1,1) ; long.= 1.73205
    */
    cout << "t = " << t << endl;
    cout << "s = " << s << endl;

    /* Comprueba si los dos Segmentos son iguales */
    if ( t == s )
        cout << "t y s son IGUALES" << endl;
    else
        cout << "ERROR en el test" << endl;
    cout << "-------------" << endl;

    /* Modificar los vertices del Segmento t 
    con valores correctos */
    t.SetIni( Punto3d(10,10,10) );
    t.SetFin( Punto3d(20,20,20) );

    /* Mostrar el Segmento t por pantalla 
    Resultado correcto:
        (10,10,10) ; (20,20,20)
    */
    cout << "t = " << t << endl;

    /* Comprueba si los dos Segmentos son iguales */
    if ( t == s )
        cout << "ERROR en el test" << endl;
    else
        cout << "t y s son DIFERENTES" << endl;
    cout << "-------------" << endl;

    /* Modificar los vertices del Segmento s 
    con valores INcorrectos */
    s.SetIni( Punto3d(5,7,10) );
    s.SetFin( Punto3d(-10,15,-20) ); //Fuera del escenario

    /* Mostrar el Segmento s por pantalla 
    Resultado correcto:
        No se debe llegar a ejecutar porque ha debido
        saltar un aserto incumplido en SetFin
    */
    cout << "ERROR: Esto no deberia mostrarse. Deberia haber saltado un aserto en SetFin." << endl;
    cout << "s = " << s << endl;
    cout << "-------------" << endl;
    cout << "Fin Test 2. Incorrecto" << endl;
    cout << "Presiona Enter para salir..." <<endl;
    cin.get();
  
   
}

/**
 * @brief Desplazar Segmentos
 * 
 */
void Test3()
{
    /* Crear 2 Segmentos con valores por defecto */
    Segmento t, s;

    cout << "**************" << endl;
    cout << "*   Test 3   *" << endl;
    cout << "**************" << endl;

    /* Mostrar los Segmentos (vertices) por pantalla 
    Resultado correcto:
        t = (0,0,0) ; (1,1,1) ; long.= 1.73205
        s = (0,0,0) ; (1,1,1) ; long.= 1.73205
    */
    cout << "t = " << t << endl;
    cout << "s = " << s << endl;
    cout << "-------------" << endl;

    /* Desplazar el Segmento t +10, +20, +30 */
    t.Desplazar(10,20,30);
    /* Desplazar el Segmento s +500, +300, +100 */
    s.Desplazar(500,300,100);
    /* Mostrar los Segmentos (vertices) por pantalla 
    Resultado correcto:
        t = (10,20,30) ; (11,21,31) ; long.= 1.73205
        s = (500,300,100) ; (501,301,101) ; long.= 1.73205
    */
    cout << "t = " << t << endl;
    cout << "s = " << s << endl;
    cout << "-------------" << endl;

    /* Desplazar el Segmento t -100, -100 */
    t.Desplazar(-100,-100,-100);

    /* Mostrar el Segmento t por pantalla 
    Resultado correcto:
        No se debe llegar a ejecutar porque ha debido
        saltar un aserto incumplido en Desplazar
    */
    cout << "ERROR: Esto no deberia mostrarse. Deberia haber saltado un aserto en Desplazar." << endl;
    cout << "t = " << t << endl;
    cout << "-------------" << endl;
    cout << "Fin Test 3" << endl;
    cout << "Presiona Enter para salir..." <<endl;
    cin.get();
}

/**
 * @brief Rotacion de Segmentos
 * 
 */
void Test4()
{
    /* Crear un Segmento con valores por defecto */
    Segmento t;

    cout << "**************" << endl;
    cout << "*   Test 4   *" << endl;
    cout << "**************" << endl;

    /* Modificar los vertices del Segmento t  */
    t.SetIni( Punto3d(100,110,120) );
    t.SetFin( Punto3d(200,220,240) );
    /* Mostrar el Segmento por pantalla 
    Resultado correcto:
        t = (100,110,120) ; (200,220,240) ; long.= 191.05
    */
    cout << "t = " << t << endl;
    cout << "-------------" << endl;

    /* Rotar el Segmento pi/6 (30º) radianes en el eje X*/
    t.RotarX(M_PI/6);

    /* Mostrar el Segmento por pantalla 
    Resultado correcto:
        t = (100,35.2628,158.923) ; (200,70.5256,317.846) ; long.= 191.05
    */
    cout << "t = " << t << endl;
    cout << "-------------" << endl;

    /* Deshacer la rotacion anterior */
    t.RotarX(-M_PI/6);

    /* Mostrar el Segmento por pantalla 
    Resultado correcto:
        t = (100,110,120) ; (200,220,240) ; long.= 191.05
    */
    cout << "t = " << t << endl;
    cout << "-------------" << endl;

    /* Rotar el Segmento pi/2 (90º) radianes en el eje Y*/
    t.RotarY(M_PI/2);

    /* Mostrar el Segmento por pantalla 
    Resultado correcto:
        No se debe llegar a ejecutar porque ha debido
        saltar un aserto incumplido en RotarY
    */
    cout << "ERROR: Esto no deberia mostrarse. Deberia haber saltado un aserto en RotarY." << endl;
    cout << "t = " << t << endl;
    cout << "-------------" << endl;
    cout << "Fin Test 4" << endl;
    cout << "Presiona Enter para salir..." <<endl;
    cin.get();
}