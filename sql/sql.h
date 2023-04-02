/*
 * sql.h
 *
 *  Created on: 1 abr 2023
 *      Author: oscar
 */

#ifndef SQL_H_
#define SQL_H_
#include "../pelicula/pelicula.h"


void inicializar();

void cargarPeliculas();

char* buscarGenero (int cod_gen);

char* buscarFormato (int cod_for);

void insertarPelicula(Pelicula p);

int borrarPelicula(int id);

int contarPeliculas();

void cerrar();



#endif /* SQL_H_ */
