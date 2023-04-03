/*
 * pelicula.c
 *
 *  Created on: 2 abr 2023
 *      Author: koldo
 */
#include "pelicula.h"
#include <string.h>
#include <stdio.h>
#include "../sql/sql.h"


void imprimirPeliculas(Pelicula *p, int t){


	for (int i = 0; i < t; ++i) {
		int id = p[i].id_pelicula;

		char* gen = buscarGenero(p[i].cod_genero); //meter buscar codigo de genero
		char* form = buscarFormato(p[i].cod_formato); //meter buscar codigo de formato
		float precio = p[i].precio;

		printf("Id_ Pelicula: %i | Titulo: %s | Genero: %s | Director: %s | Formato: %s | Precio: %.2f | Cantidad: %i \n",
				id, p[i].titulo, gen, p[i].director, form, precio, p[i].cantidad);

	}



}


