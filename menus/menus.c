/*
 * menus.c
 *
 *  Created on: 1 abr 2023
 *      Author: koldo
 */

#include <stdlib.h>
#include <stdio.h>
#include "sql/sql.h"

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
			cerrar();
			break;

			case '2':

			printf("La opcion elegida es 2.\n");
			break;

			case '3':

			printf("La opcion elegida es 3.\n");
			break;

			case '4':

			printf("La opcion elegida es 4.\n");
			break;

			case '5':

			printf("La opcion elegida es 5.\n");
			break;

			default:

			printf("\nSELECCIONA UNA OPCION VALIDA.\n");
			break;

		}

	} while( opcion != '5');

}
