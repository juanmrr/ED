/**
 * @file vd.h
 * @brief Fichero cabecera del TDA VD
 *
*/
#ifndef __VD__H
#define __VD__H
#include <iostream>
#include <cassert>
using namespace std;

const unsigned int MINIMO=10; 
/**
  * @brief T.D.A VD
  * Una instancia @e c del tipo de dato abstracto VD es una secuencia de datos de tipo T
  *       m1,m2,....mn
  * de manera que m1 es el primer elmento (posicion principio) y mn es el ultimo elemento (posicion final)
  * El espacio requerido para almacenar la n datos de tipo T es O(n) .
  *
  * @author : Rosa Rodriguez
  * 
  * @date: Septiembre 2014
*/
template <class T>
class VD{
  private:
    /**
      * @page repVD Rep del TDA VD
      * @section invVDa Invariante de la representacion
	* rep.n>=0
	* rep.datos tiene un espacio reservado para alojar rep.n datos de tipo T
	* rep.reservados>=rep.n
      * @section faVD Función de Abstracción
      * Un objeto válido #e rep del TDA VD representa al valor 
      *          rep.datos[0] rep.datos[1]....rep.datos[n-1]
   */ 
    
   int reservados; /**< cantidad de memoria reservada */
   int n; /**< numero de datos almacenados */
   T *datos; /**< zona de memoria para almacenar los datos*/
   
   /**
    * @brief Modifica la zona de memoria a una zona con nueva_dim elementos
    * @param nueva_dim: nueva dimension de la zona de memoria
    * @note si nueva_dim es menor que n se perderan los elementos desde nueva_dim hasta n.
    */
   
   void Redimensionar(int nueva_dim);
   
     /**
    * @brief Copia un VD en el objeto actual
    * param I: VD a ser copiada
    * 
    **/
   void Copia(const VD<T> & I);
   
   
public:
   /**
    * @brief Constructor por defecto y con parametros. Reserva un zona de memoria con tam posiciones
    * 
    */  
  VD(int tam=MINIMO);
  
  
     /**
    * @brief Constructor de copia. 
    * @param I: VD de entrada a ser copiada
    * 
    */
   VD(const VD<T> & I);
   
   /**
    * @brief Destruye la memoria reservada
    
    * 
    */
   ~VD();
   /**
    * @brief Asignacion 
    * @param I: VD de entrada a ser asignado
    * @return referencia al objeto que apunta this
    */
   VD & operator=(const VD<T> & I);
   
   
   /**
    * @brief Devuelve el elemento en la posicion posicion
    */
   T Get(int pos)const;
   
   /**
    * @brief Devuelve el elemento en la posicion posicion
    */
   
   const T & operator[](int pos)const;
   
   /**
    * @brief Devuelve el elemento en la posicion posicion
    */
   T & operator[](int pos);
   
   /**
    * @brief Devuelve el numero de elementos almacenadas
    * 
    */
   int Size()const{return n;}
   
   /**
    * @brief Elimina el elemento en la posicion pos
    * @note El numero de elementos n se decrementa en uno. Eficiencia O(n)
    */
   void Borrar(int pos);
   
   /**
    * @brief Inserta un nuevo elemento en un posicion
    * @param nuevo: elemento a insertar
    * @param pos: posicion donde se inserta
    
    */
    void Insertar(const T &nuevo,int pos);
    
    
   
};
#include "../src/vd.cpp"
#endif
   
