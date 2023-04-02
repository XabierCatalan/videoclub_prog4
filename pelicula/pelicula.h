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
	char titulo[30];
	int cod_genero;  //crear una tabla en la base de datos con cod_genero y genero
	char director[30];
	int cod_formato;  //crear una tabla en la base de datos con cod_formato y formato
	char fecha_sal[30];
	float precio;

}Pelicula;


void imprimirPeliculas(Pelicula *p, int t);

#endif /* PELICULA_H_ */
