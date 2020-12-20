#include <cstdlib>
#include <iostream>
#include <cassert>
#include "../include/vd.h"

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
        *  Es un vestor dinámico de elementos
        *  Teniendo e valor introduciodo y el 
        *  máximo hasta ahora. 
        */
		VD<elemento> datos; // Cómo instanciar la clase?
	/*
        *  @brief endica el número de elementos almacenados
        *         en la pila. 
        */
		int numeroElementos;

	public:

        /*
        *  @brief Constructor por defecto de la clase
        */
		Pila_max(){
			numeroElementos = 0; 
		}
        /*
        *  @brief Constructor de copias. 
        *  @param Pila_max pila_max a copiar  
        */
		Pila_max(const Pila_max& pila_max_param){
            		datos = pila_max_param.datos;
            		numeroElementos = pila_max_param.numeroElementos;
		}
        /*
        *  @brief Sobrecarga del operador de asignación. 
        *  @param Pila_max pila_max a copiar  
        *  @return Referencia al objeto copiado.
        */
		Pila_max& operator= (const Pila_max & pila_max_param){
			datos = pila_max_param.datos;
            		numeroElementos = pila_max_param.numeroElementos;
            		
			return *this;
		}
        /*
        *  @brief indica si la pila está vacía
        *  @return devuelve true si está vacía o 
        *  false si no lo está. 
        */
		bool vacia() const{
		    return (datos.Size()==0);
		}
        /*
        *  @brief Devuelve el tope de la pila
        *  @return Devuelve el elemento tope de la pila.   
        */
		elemento tope (){
		    assert(datos.Size()>0);       //Si la pila está vacía, abortar
		    return datos.Get(0); //Devuelve el elemento del tope de la pila
		}
        /*
        *  @brief Devuelve el tope de la pila en modo constante. 
        *  @return Devuelve el elemento tope de la pila en modo constante.
        */
		 const elemento tope () const{
		       assert(datos.Size()>0);       //Si la pila está vacía, abortar
		       return datos.Get(0); //Devuelve el elemento del tope de la pila
		 }
        /*
        *  @brief Inserta un elemento en la pila
        *  @param valor es el elemento a insertar en la pila.
        */
		void poner(const int & valor){

		    elemento elementoAux;
		    if ( datos.Size() == 0 ){
			  elementoAux.valor = valor;
			  elementoAux.maximo = valor;
			  datos.Insertar(elementoAux, 0);
		    }
		    else{
		    	int maximo = datos.Get(0).maximo;
				if ( maximo < valor ){
				  	maximo = valor;
				}
				
				elementoAux.valor = valor;
			  	elementoAux.maximo = maximo;

				//Lo insertamos en la nueva posición. 
				for (int i = numeroElementos; i > 0; i--){
					datos.Insertar(datos.Get(i - 1), i);
				}

				datos.Insertar(elementoAux, 0);

		    }
		    numeroElementos++;
		}
        /*
        *  @brief Quita el tope de la pila
        */
		void quitar(){
		        assert(datos.Size()>0);       //Si la pila está vacía, abortar

		      	for ( int i = 0; i < numeroElementos; i++ ){
				datos.Insertar(datos.Get( i + 1 ), i);
			}

			numeroElementos--;  

		    } 
        /*
        *  @brief indica el número de elementos en la pila
        *  @return devuelve el número de elemetos que hay actualmente en la pila. 
        */
		int num_elementos() const{
		  	return numeroElementos;
		}

};
