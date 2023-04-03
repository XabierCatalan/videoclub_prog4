/*
 * pelicula.h
 *
 *  Created on: 1 abr 2023
 *      Author: oscar
 */

#ifndef PELICULA_H_
#define PELICULA_H_

typedef struct {
	int id_pelicula;
	char *titulo;
	int cod_genero;  //crear una tabla en la base de datos con cod_genero y genero
	char *director;
	int cod_formato;  //crear una tabla en la base de datos con cod_formato y formato
	float precio;
	int cantidad;

}Pelicula;


void imprimirPeliculas(Pelicula *p, int t);

#endif /* PELICULA_H_ */
