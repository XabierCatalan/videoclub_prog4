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

Pelicula* buscarPelicula(int id);

void actualizarTitulo(char* titulo, int id_pelicula);

void actualizarGenero(int genero, int id_pelicula);

void actualizarDirector(char* Director, int id_pelicula);

void actualizarFormato(int formato, int id_pelicula);

void actualizarPrecio(float precio, int id_pelicula);


void cerrar();



#endif /* SQL_H_ */
