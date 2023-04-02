/*
 * pelicula.c
 *
 *  Created on: 2 abr 2023
 *      Author: koldo
 */
#include "pelicula.h"
#include <string.h>
#include <stdio.h>


void imprimirPeliculas(Pelicula *p, int t){
	for (int i = 0; i < t; ++i) {
		int id = p[i].id_pelicula;

		int cod_gen = p[i].cod_genero; //meter buscar codigo de genero
		int cod_formato = p[i].cod_formato; //meter buscar codigo de formato
		float precio = p[i].precio;

		printf("Id_ Pelicula: %i  Titulo: %s Genero: %i  Director %s  Formato: %i Fecha: %s Precio: %.2f \n",
				id, p[i].titulo, cod_gen, p[i].director, cod_formato, p[i].fecha_sal, precio);

	}


}


