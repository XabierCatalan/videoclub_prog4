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


void imprimirPeliculas(Pelicula *p){



		int id = p -> id_pelicula;

		char* gen = buscarGenero(p -> cod_genero); //meter buscar codigo de genero
		char* form = buscarFormato(p -> cod_formato); //meter buscar codigo de formato
		float precio = p -> precio;

		printf("Id_ Pelicula: %i | Titulo: %s | Genero: %s | Director: %s | Formato: %s | Precio: %.2f | Cantidad: %i \n",
				id, p -> titulo, gen, p -> director, form, precio, p -> cantidad);





}


