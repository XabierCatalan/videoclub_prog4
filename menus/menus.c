/*
 * menus.c
 *
 *  Created on: 1 abr 2023
 *      Author: koldo
 */

#include <stdlib.h>
#include <stdio.h>

void menuPrincipal(){
	int opcion;

	do{
		printf("\n");
		printf("[MENU ADMINISTRADOR] \n");
		printf("--------------------------\n");
		printf("1. Cargar datos.\n");
		printf("2. Insertar pelicula.\n");
		printf("3. Modificar pelicula.\n");
		printf("4. Eliminar pelicula.\n");
		printf("5.Salir\n");
		printf("Introduce una opcion del menu: \n");
		fflush(stdout);
		scanf("%i", &opcion);
		if ( opcion == 1 ){
			printf("La opcion elegida es 1.");
			//break;
		} else if( opcion == 2 ){
			printf("La opcion elegida es 2.");
			//break;
		} else if( opcion == 3 ){
			printf("La opcion elegida es 3.");
			//break;
		}else if( opcion == 4 ){
			printf("La opcion elegida es 4.");
			//break;
		}else if( opcion == 5 ){
			printf("La opcion elegida es 5.");
			//break;
		}else{
			printf("SELECCIONA UNA OPCION VALIDA.\n");
			//break;
		}

	}while( opcion =! 5);

}
