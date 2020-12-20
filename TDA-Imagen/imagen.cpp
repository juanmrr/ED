#include "imagen.h"
#include <cassert>
#include <iostream>
#include "string.h"

using namespace std;


void Imagen::Copiar(const Imagen &I){

	filas = I.filas;
	cols = I.cols;
	datos = new byte*[filas];
	for (int i = 0; i < filas; i++)
		datos[i] = new byte[cols];
		
	for (int i = 0; i < filas; i++)
		for (int j = 0; j < cols; j++)
			datos[i][j] = I.datos[i][j];
			
}

void Imagen::Borrar(){

	for (int i = 0; i < filas; i++)
		delete[] datos[i];
		
	delete[] datos;
	
}

void Imagen::Swap(Imagen &I){

	int filas_aux = filas;
	filas = I.filas;
	I.filas = filas_aux;
	
	int cols_aux = cols;
	cols = I.cols;
	I.cols = cols_aux;
	
	byte ** datos_aux = datos;
	datos = I.datos;
	I.datos = datos_aux;
	
}

Imagen::Imagen(){

	filas = 0;
	cols = 0;
	datos = NULL;
	
}	

Imagen::Imagen(int nf, int nc){
	
	filas = nf;
	cols = nc;
	datos = new byte*[filas];
	for (int i = 0; i < filas; i++)
		datos[i] = new byte[cols];
		
}

Imagen::Imagen(const Imagen &I){

	Copiar(I);
	
}

Imagen::~Imagen(){

	Borrar();
	
}

Imagen& Imagen::operator=(const Imagen &I){

	Imagen aux (I);
	
	aux.Swap(*this);
	
	return *this;
	
}

int Imagen::numfilas() const{

	return filas;
	
}

int Imagen::numcolumnas() const{
	
	return cols;
	
}

void Imagen::asigna_pixel(int f, int c, byte v){

	assert(f < filas && c < cols);
	datos[f][c] = v;
	
}

byte Imagen::get_pixel(int f, int c) const{

	assert(f < filas && c < cols);
	byte pixel = datos[f][c];
	
	return pixel;
	
}

byte& Imagen::operator() (int i, int j){

	assert(i < filas && j < cols);
	return datos[i][j];
	
}

const byte& Imagen::operator() (int i, int j) const{

	assert(i < filas && j < cols);
	return datos[i][j];
	
}

bool Imagen::CargarImagen(const char * nombre){

	const char *extension = ".pgm";
	string str(nombre);
	
	if (strstr(nombre, extension) == NULL)
		str += ".pgm";
		
	char * fichero = strdup(str.c_str());

	TipoImagen t = LeerTipoImagen(fichero);
	if (t==IMG_PGM){
		int f, c;
		unsigned char *buf = LeerImagenPGM (fichero, f, c);
		if (buf!=0){
			Imagen aux(f, c);
			for (int i = 0; i < f; i++)
				for (int j = 0; j < c; j++)
					aux(i, j) = buf[i*c + j];
			
			delete[] buf;
			*this = aux;
			return true;
			
		}
		else{
			cout << "No se ha podido cargar la imagen" << endl;
			return false;
		}
		
	}
	else{
		cout << "Formato de imagen incorrecto" << endl;
		return false;
	}
	
}
	
bool Imagen::SaveImagen(const char * nombre){

	const char *extension = ".pgm";
	string str(nombre);
	
	if (strstr(nombre, extension) == NULL)
		str += ".pgm";
		
	char * fichero = strdup(str.c_str());

	unsigned char *buf = new unsigned char [filas*cols];
	for (int i = 0; i < filas; i++)
		for (int j = 0; j < cols; j++)
			buf[i*cols + j] = datos [i][j];
			
	if (EscribirImagenPGM(fichero, buf, filas, cols)){
		delete[] buf;
		return true;
	}
	else{
		delete[] buf;
		return false;
	}

}
