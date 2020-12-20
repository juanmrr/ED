#include <cstdlib>
#include <iostream>
#include <cassert>
#include "../include/cola.h"

//#include <pila_max.h>
using namespace std;

typedef struct{
  int valor; ///<elemento a almacenar
  int maximo; ///<el minimo
}elemento;
std::ostream & operator<<(std::ostream & ostreamParam,const elemento & elementoParam){
 ostreamParam << elementoParam.valor << " Maximo: " << elementoParam.maximo << "\n";
 return ostreamParam;
} 
/**
 * @brief T.D.A. Pila_max
 *
 * Pila donde se almacenan enteros sabiendo cual es
 * máximo introducido. 
 */
class Pila_max
{

	private: 
		/*
		*  @brief Alamacena los valores de la pila. 
		* 		  Es una cola donde se almacenan los elementos
		*		  de la pila.  
		*/
		Cola<elemento> datos;
		/*
		*  @brief guardamos el máximo hasta el momento.  
		*/
		int maximo;
	public:

	/*
        *  @brief Constructor por defecto de la clase
        */
		Pila_max(){

		}
	/*
        *  @brief Constructor de copias. 
        *  @param Pila_max pila_max a copiar  
        */
		Pila_max(const Pila_max& pila_max_param){
			datos = pila_max_param.datos;
			maximo = pila_max_param.maximo;
		}
	/*
        *  @brief Sobrecarga del operador de asignación. 
        *  @param Pila_max pila_max a copiar  
        *  @return Referencia al objeto copiado.
        */
		Pila_max& operator= (const Pila_max& pila_max_param){
			datos = pila_max_param.datos;
			maximo = pila_max_param.maximo;
			return *this;
		}
	/*
        *  @brief indica si la pila está vacía
        *  @return devuelve true si está vacía o 
        *  false si no lo está. 
        */
		bool vacia() const{
		    return (datos.num_elementos() == 0);
		}
	/*
        *  @brief Devuelve el tope de la pila
        *  @return Devuelve el elemento tope de la pila.   
        */
		elemento tope ()const{
		    assert(datos.num_elementos()>0);       //Si la pila está vacía, abortar

		    Cola<elemento> colaAux(datos);
		    int num_elementos = datos.num_elementos();
		    for (int i = 0; i < num_elementos - 1; i++ ){
		    	colaAux.quitar();
		    }

		    // Recuperamos el último elemento de la cola es el tope de la pila
		    elemento tope = colaAux.frente();

		    return tope; //Devuelve el elemento del tope de la pila
		}
	/*
        *  @brief Inserta un elemento en la pila
        *  @param valor es el elemento a insertar en la pila.
        */
		void poner(const int & valor){

			elemento elementoAux;

			if ( datos.num_elementos() == 0 ){
				maximo = valor;
			  
		    	}
		    	else{
				if ( maximo < valor ){
				  	maximo = valor;
				}
		    }

		    elementoAux.valor = valor;
		    elementoAux.maximo = maximo;
		    datos.poner(elementoAux); 

		}
	/*
        *  @brief Quita el tope de la pila
        */
		void quitar(){
		        assert(datos.num_elementos()>0);       //Si la pila está vacía, abortar
			
		      	Cola<elemento> colaAux;

		      	int num_elementos = datos.num_elementos();
		      	for (int i = 0; i < num_elementos - 2; i++ ){
		      		colaAux.poner(datos.frente());
		      		datos.quitar();
		      	}

		      	//En la úlima iteración necesitamos el máximo para actualizar la pila
		      	colaAux.poner(datos.frente());
		      	maximo = datos.frente().maximo; //Actualizamos el máximo
		      	datos.quitar();

		      	
		      	datos = colaAux; 

		    } 
	/*
        *  @brief indica el número de elementos en la pila
        *  @return devuelve el número de elemetos que hay actualmente en la pila. 
        */
		int num_elementos() const{
		  	return datos.num_elementos();
		}

};
