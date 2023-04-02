/*
 * menus.c
 *
 *  Created on: 1 abr 2023
 *      Author: koldo
 */

#include <stdlib.h>
#include <stdio.h>
#include "../sql/sql.h"
#include "../pelicula/pelicula.h"

void menuInsertar() {
	char *titulo;
	titulo = (char*) malloc(sizeof(char)*30);
	int cod_gen;
	char *director;
	director = (char*) malloc(sizeof(char)*30);
	int cod_form;
	char *fecha;
	fecha = (char*) malloc(sizeof(char)*30);

	float precio;

	printf("Introduzca el titulo: \n");
	fflush(stdout);
	scanf("%s", titulo);

	printf("Introduzca el Cod_Genero: \n");
	fflush(stdout);
	scanf("%i", &cod_gen);


	printf("Introduzca el Director: \n");
	fflush(stdout);
	scanf("%s", director);


	printf("Introduzca el Cod_Formato: \n");
	fflush(stdout);
	scanf("%i", &cod_form);


	printf("fecha de Estreno(yyyy/mm/dd): \n");
	fflush(stdout);
	scanf("%s", fecha);


	printf("Introduzca el Precio de la pelicula: \n");
	fflush(stdout);
	scanf("%f", &precio);



	Pelicula p = {0, titulo, cod_gen, director, cod_form, fecha, precio};

	insertarPelicula(p);

}

void menuEliminar(){
	int id_Pelicula;
	printf("Introduzca el Id_Pelicula de la pelicula que desee Eliminar: \n");
	fflush(stdout);
	scanf("%i", &id_Pelicula);
	borrarPelicula(id_Pelicula);

}



void menuPrincipal(){
	char opcion;

	do{
		printf("\n[MENU ADMINISTRADOR] \n");
		printf("--------------------------\n");
		printf("1. Cargar datos.\n");
		printf("2. Insertar pelicula.\n");
		printf("3. Modificar pelicula.\n");
		printf("4. Eliminar pelicula.\n");
		printf("5.Salir\n");
		printf("Introduce una opcion del menu: \n");
		fflush(stdout);
		scanf("%s", &opcion);

		switch(opcion) {
			case '1':

			printf("La opcion elegida es 1.\n");
			inicializar();
			cargarPeliculas();

			break;

			case '2':

				printf("La opcion elegida es 2.\n");
				menuInsertar();
			break;

			case '3':

			printf("La opcion elegida es 3.\n");
			break;

			case '4':

			printf("La opcion elegida es 4.\n");
				menuEliminar();
			break;

			case '5':

			printf("La opcion elegida es 5.\n");
			cerrar();
			break;

			default:

			printf("\nSELECCIONA UNA OPCION VALIDA.\n");
			break;

		}

	} while( opcion != '5');

}

