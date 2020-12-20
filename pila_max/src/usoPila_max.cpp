#include <iostream>
#include "../include/Pila_max.h"
using namespace std;

int main(){
	
  Pila_max pila_max; // Cómo hacer el new?
  int i;
  
  for ( i=0; i < 10 ; i++) 
    pila_max.poner(i);
   

   elemento tope = pila_max.tope();
  int valor = tope.valor;
  int maximo = tope.maximo;

   cout << "El valor es: " << valor << endl;
   cout << "El máximo introducido es " << maximo << endl;


  pila_max.quitar();

  valor = pila_max.tope().valor;
  maximo = pila_max.tope().maximo;
  cout << "El penúltimo valor es: " << valor << endl;
  cout << "El nuevo máximo introducido es " << maximo << endl;
 
  cout << "El número de elementos de la pila es: " << pila_max.num_elementos() << endl;

  Pila_max pila_max2( pila_max);


  for( i = 0; i < 20; i++){
    pila_max2.poner(i);
    
  }
  

  Pila_max pila_max3 = pila_max2;

  for( i = 0; i < 10; i++){
    pila_max3.quitar();

  }
  
  pila_max3.poner(2000); 

  pila_max3.quitar();

  pila_max3.poner(1000); 

  valor = pila_max2.tope().valor;
  maximo = pila_max2.tope().maximo;
  cout << "El último valor de pila_max2 es: " << valor << endl;
  cout << "El último maximo de pila_max2 es:  " << maximo << endl;

valor = pila_max3.tope().valor;
  maximo = pila_max3.tope().maximo;
  cout << "El último valor de pila_max3 es: " << valor << endl;
  cout << "El último maximo de pila_max3 es:  " << maximo << endl;
  
  return 0;
}
