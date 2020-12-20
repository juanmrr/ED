/**
  * @file imagen.h
  * @brief Fichero cabecera del TDA Imagen
  *
  */

#ifndef _IMAGEN_H
#define _IMAGEN_H
#include "imagenES.h"
typedef unsigned char byte;

/**
  *  @brief T.D.A. Racional
  *
  * Una instancia @e I del tipo de datos abstracto @c Imagen es un objeto
  * representado por dos números enteros que representan el número de filas y 
  * de columnas respectivamente, así como un array bidimensional de char para
  * representar la imagen en forma de matriz
  *
  * Un ejemplo de su uso:
  * @include ejercicio1.cpp
  *
  * @author Juan Manuel Rubio Rodríguez
  * @date Noviembre 2020
  */

class Imagen{
private:
/**
  * @page repImagen Rep del TDA Imagen
  *
  * @section invImagen Invariante de la representación
  *
  * El invariante es \e rep.filas>=0 & rep.cols>=0
  *
  * @section faImagen Función de abstracción
  *
  * Un objeto válido @e rep del TDA Imagen representa al valor viene representado
  * por un valor positivo de filas y columnas, así como un valor comprendido 
  * 0 <= datos(i,j) <= 255 para cada i,j (filas, columnas) del array bidimensional
  *
  */
	int filas, cols; /**< filas */ /**< columnas */
	byte ** datos; /**< matriz asociada a la imagen */
	void Copiar(const Imagen &I);
	void Borrar();
	void Swap(Imagen &I);
	
public:
/**
  * @brief Constructor por defecto de la clase. Crea la imagen para filas=cols=0
  */
	Imagen();
/**
  * @brief Constructor de la clase
  * @param nf número de filas del objeto imagen a construir
  * @param nc número de columnas del objeto imagen a construir
  * @return Crea el objeto imagen con nf filas, nc columnas y reserva memoria para el array bidimensional de tamaño nf x nc
  * @pre nf >= 0 & nc >= 0
  */
	Imagen(int nf, int nc);
/**
  * @brief Constructor de copias de la clase
  * @param I referencia al objeto imagen que desea ser copiado
  */
	Imagen(const Imagen &I);
/**
  * @brief Destructor de la clase
  * @post se libera la memoria reservada para la representación de la imagen
  */
	~Imagen();
/**
  * @brief Operador de asignación de la clase
  * @return devuelve el control del objeto mediante el intercambio de punteros
  */
	Imagen & operator=(const Imagen &I);
/**
  * @brief Número de filas
  * @return Devuelve el número de filas de la matriz asociada a la imagen
  */ 
	int numfilas() const;
/**
  * @brief Número de columnas
  * @return Devuelve el número de columnas de la matriz asociada a la imagen
  */ 
	int numcolumnas() const;
/**
  * @brief Asignación de un valor de gris a un pixel
  * @param f número de la fila del pixel a asignar
  * @param c número de la columna del pixel a asignar
  * @param v valor comprendido entre 0 y 255 correspondiente a la escala de gris
  * @return Asigna al pixel(i,j) el valor v de gris
  * @pre c >= 0 & f >= 0
  */ 
	void asigna_pixel(int f, int c, byte v);
/**
  * @brief Obtiene el valor del pixel ubicado en la fila i y columna j
  * @param f número de la fila del pixel
  * @param c número de la columna del pixel
  * @return valor del pixel comprendido entre 0 y 255
  * @pre c >= 0 & f >= 0
  */
	byte get_pixel(int f, int c) const;
/**
  * @brief Sobrecarga del operador()
  * @param f número de la fila del pixel
  * @param c número de la columna del pixel
  * @return valor del pixel comprendido entre 0 y 255
  * @pre c >= 0 & f >= 0
  */
	byte & operator() (int i, int j);
/**
  * @brief Sobrecarga del operador() const
  * @param f número de la fila del pixel
  * @param c número de la columna del pixel
  * @return valor del pixel comprendido entre 0 y 255
  * @pre c >= 0 & f >= 0
  */
	const byte &operator() (int i, int j) const;
/**
  * @brief Carga una imagen en un objeto de la clase a partir del nombre de un fichero
  * @param nombre nombre del archivo que contiene la imagen
  * @return retorna true si se carga la imagen con éxito, retorna false en otro caso
  * @pre el nombre debe tener extensión .pgm
  */
	bool CargarImagen(const char * nombre);
/**
  * @brief Guarda una imagen con formato .pgm a partir de un objeto imagen
  * @param nombre nombre con el que se guarda la imagen
  * @return true en el caso de que se guarde la imagen con éxito, false para otro caso
  * @post la imagen se almacenará en disco con la extensión .pgm
  */
	bool SaveImagen(const char * nombre);
	
};
#endif
