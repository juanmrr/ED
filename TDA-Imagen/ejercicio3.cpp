#include <iostream>
#include "imagen.h"
#include "math.h"

using namespace std;

void Zoom(const char * origen, const char * destino, int x1, int y1, int x2, int y2){

	Imagen aux;
	// cargamos en un objeto imagen la imagen con nombre "origen"
	aux.CargarImagen(origen);
	
	int filas = x2 - x1;
	int cols = y2 - y1;
	
	// creamos un primer objeto imagen intermedio sobre el que interpolar las columnas
	Imagen interp_cols(filas, 2*cols - 1);
	
	for (int i = 0; i < filas; i++)
		for (int j = 0; j < cols; j++)
			interp_cols(i,j*2) = aux(y1+i,x1+j);

	// interpolamos entre columnas
	for (int i = 0; i < filas; i++)
		for (int j = 1; j < interp_cols.numcolumnas(); j+=2)
			interp_cols(i,j) = ceil((interp_cols(i,j-1) + interp_cols(i,j+1))/2);
				
	// creamos un segundo objeto imagen sobre el que interpolar sobre las filas
	Imagen interp_filas(2*filas - 1, 2*cols -1);
	
	for (int i = 0; i < filas; i++)
		for (int j = 0; j < interp_filas.numcolumnas(); j++)
			interp_filas(i*2,j) = interp_cols(i,j);
	
	// interpolamos sobre las filas	
	for (int i = 1; i < interp_filas.numfilas(); i+=2)
		for (int j = 0; j < interp_filas.numcolumnas(); j++)
			interp_filas(i,j) = ceil((interp_filas(i-1,j) + interp_filas(i+1,j))/2);
				
	// comprobamos que guardamos el objeto imagen correctamente
	if (interp_filas.SaveImagen(destino))
		cout << "zoom realizado con éxito" << endl;
	else
		cout << "No se ha podido aplicar el zoom" << endl;

}

int main(){

	char *fich_origen = new char[100];
	char *fich_destino = new char[100];
	int x1, x2, y1, y2;

	cout << "Introduzca el nombre del fichero de origen" << endl;
	cin >> fich_origen;
	
	cout << "Introduzca las coordenadas del pixel superior izquierdo en x e y" << endl;
	cin >> x1;
	cin >> y1;
	
	cout << "Introduzca las coordenadas del pixel inferior derecho en x e y" << endl;
	cin >> x2;
	cin >> y2;
	
	cout << "Introduzca el nombre del fichero destino" << endl;
	cin >> fich_destino;
	
	Zoom(fich_origen, fich_destino, x1, y1, x2, y2);
		
	return 0;
		
}
