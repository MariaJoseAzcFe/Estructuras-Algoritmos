#include <iostream>
#include <cassert>
#include "math.h"
#include "segmento.h"
using namespace std;

/**
 * @brief Construye un objeto segmento:: Segmento object
 * 
 */
Segmento::Segmento()
{
 
  vertice[0] = Punto3d(0, 0, 0);
  vertice[1] = Punto3d(1, 1, 1);  
  assert(Invariante());
}
/**
 * @brief Asigna valores al punto inicial del segmento
 * 
 * @param p 
 */
void Segmento::SetIni(const Punto3d& p)
{
 
  vertice[0]=p;
  assert(Invariante());
}
/**
 * @brief Asigna valores al punto final del segmento
 * 
 * @param p 
 */
void Segmento::SetFin(const Punto3d& p)
{
  
  vertice[1]=p;
  assert(Invariante());
}
            
/**
 * @brief  Desplaza un segmento una cantidad de unidades determinada
 * 
 * @param dx 
 * @param dy 
 * @param dz 
 */
void Segmento::Desplazar(float dx, float dy ,float dz)
{
  
  vertice[0].Desplazar(dx, dy, dz);
  vertice[1].Desplazar(dx, dy, dz);
  assert(Invariante());


}
/**
 * @brief Rota sobre el eje X el segmento un angulo determinado 
 * 
 * @param a 
 */
void Segmento::RotarX(float a)
{
    vertice[0].RotarX(a);
    vertice[1].RotarX(a);
    assert(Invariante());
}
/**
 * @brief Rota sobre el eje Y el segmento un angulo determinado 
 * 
 * @param a 
 */
void Segmento::RotarY(float a)
{
    vertice[0].RotarY(a);
    vertice[1].RotarY(a);
    assert(Invariante());
}
/**
 * @brief Rota sobre el eje Z el segmento un angulo determinado 
 * 
 * @param a 
 */
void Segmento::RotarZ(float a)
{
    vertice[0].RotarZ(a);
    vertice[1].RotarZ(a);
    assert(Invariante());
}
/**
 * @brief Calcula la longitud del segmento
 * 
 * @return float 
 */
float Segmento::Longitud() const
{
  float l;
  float x0,y0,z0,x1,y1,z1;
  x0= vertice[0].GetX();
  y0= vertice [0].GetY();
  z0=vertice[0].GetZ();
  x1= vertice[1].GetX();
  y1= vertice [1].GetY();
  z1=vertice[1].GetZ();
  l = sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0) + (z1 - z0) * (z1 - z0));
  return l;
}
/**
 * @brief Funcion que sobrecarga el operador "==" para comparar dos segmentos
 * 
 * @param s1 
 * @param s2 
 * @return true 
 * @return false 
 */
bool operator==(const Segmento s1, const Segmento s2)
{
    bool res = false;
    if ((fabs(s1.vertice[0].GetX() - s2.vertice[0].GetX()) < CERO) && (fabs(s1.vertice[1].GetX() - s2.vertice[1].GetX()) < CERO) && (fabs(s1.vertice[0].GetY() - s2.vertice[0].GetY()) < CERO) && (fabs(s1.vertice[1].GetY() - s2.vertice[1].GetY()) < CERO )&&(fabs(s1.vertice[0].GetZ() - s2.vertice[0].GetZ()) < CERO)&&(fabs(s1.vertice[1].GetZ() - s2.vertice[1].GetZ()) < CERO))
        res = true;
    return res;
}

/**
* @brief Imprimir un segmento
*/
ostream& operator<<(ostream& s, const Segmento s1)
{
    
   
    
    s << "El punto inicial es: (" << s1.vertice[0].GetX() << "," << s1.vertice[0].GetY()<<"," << s1.vertice[0].GetZ()<< ") y el punto final es: (" << s1.vertice[1].GetX() << "," << s1.vertice[1].GetY()<< ","  << s1.vertice[1].GetZ()<< ")"<<endl;
    s << "Y la longitud es de: "<<s1.Longitud()<< "."<<endl;
    return s;

} 
/**
 * @brief Funcion invariante usada a modo de aserto para comprobar el correcto funcionamiento del programa
 * 
 * @return true 
 * @return false 
 */
bool Segmento::Invariante() const
{
  bool b;
  b= true;

  for (int i=0; i<2; i++)
  {
    
    if(vertice[i].GetX() <0 || vertice[i].GetX()> MAX_X)
      b= false;

    if(vertice[i].GetY() <0 || vertice[i].GetY()> MAX_Y)
      b= false;

    if(vertice[i].GetZ() <0 || vertice[i].GetZ()> MAX_Z)
      b= false; 
  }
  
  if(vertice[0] == vertice[1])
      b=false;

  return b;
}
