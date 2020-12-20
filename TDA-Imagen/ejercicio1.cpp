#include <iostream>
#include "imagen.h"

using namespace std;

void Umbral(const char * origen, const char * destino, int inf, int sup){

	Imagen umbral;
	// cargamos la imagen en un objeto imagen
	umbral.CargarImagen(origen);
	
	// recorremos la matriz asociada a la imagen comparando el valor de los píxeles con los valores inferior y superior (inf, sup)
	for (int i = 0; i < umbral.numfilas(); i++)
		for (int j = 0; j < umbral.numcolumnas(); j++)
			if (umbral(i,j) <= inf || umbral(i,j) >= sup)
				umbral(i,j) = 255;
				
	// comprobamos si hemos tenido éxito al guardar
	if (umbral.SaveImagen(destino))
		cout << "Umbral aplicado con éxito" << endl;
	else
		cout << "No se ha podido aplicar el umbral" << endl;
	
}

int main(){

	char *fich_origen = new char[100];
	char *fich_destino = new char[100];
	int intervalo_inferior, intervalo_superior;

	cout << "Introduzca el nombre del fichero de origen" << endl;
	cin >> fich_origen;
	
	cout << "Introduzca el intervalo inferior" << endl;
	cin >> intervalo_inferior;
	
	cout << "Introduzca el intervalo superior" << endl;
	cin >> intervalo_superior;
	
	cout << "Introduzca el nombre del fichero destino" << endl;
	cin >> fich_destino;

	Umbral(fich_origen, fich_destino, intervalo_inferior, intervalo_superior);
		
	return 0;
		
}
