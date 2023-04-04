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
	float precio;
	int cantidad;

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


	printf("Introduzca el Precio de la pelicula: \n");
	fflush(stdout);
	scanf("%f", &precio);

	printf("Introduzca la cantidad de Stock pelicula: \n");
	fflush(stdout);
	scanf("%i", &cantidad);



	Pelicula p = {0, titulo, cod_gen, director, cod_form, precio, cantidad};

	insertarPelicula(p);

}

void menuEliminar(){
	int id_Pelicula;
	printf("Introduzca el Id_Pelicula de la pelicula que desee Eliminar: \n");
	fflush(stdout);
	scanf("%i", &id_Pelicula);
	borrarPelicula(id_Pelicula);


}

void menuModificar() {
	int id_Pelicula;

	printf("Introduzca el Id_Pelicula de la pelicula que desee Modificar: \n");
	fflush(stdout);
	scanf("%i", &id_Pelicula);



	Pelicula* p = buscarPelicula(id_Pelicula);
//	imprimirPeliculas(p, 1);

	char opcion1;

	printf("Que desea actualizar de la pelicula?\n");
	printf("1. Titulo\n");
	printf("2. Genero\n");
	printf("3. Director\n");
	printf("4. Formato\n");
	printf("5. Precio\n");
	printf("6. Volver\n");

	fflush(stdout);
	scanf("%s", &opcion1);

	switch(opcion1) {
		case '1':
			printf("Inserte el nuevo Titulo de la pelicula:\n");
			char* titulo;
			titulo = (char*) malloc(sizeof(char)*50);

			fflush(stdout);
			scanf("%s", titulo);

			actualizarTitulo(titulo, id_Pelicula);

			imprimirPeliculas(p);
			break;

		case '2':
			printf("Seleccione el nuevo Genero de la pelicula:\n");
			printf("1. Accion\n");
			printf("2. Aventura\n");
			printf("3. Ciencia Ficcion\n");
			printf("4. Comedia\n");
			printf("5. Documentales\n");
			printf("6. Drama\n");
			printf("7. Fantasia\n");
			printf("8. Musical\n");
			printf("9. Suspense\n");
			printf("10. Terror\n");
			int g;
			fflush(stdout);
			scanf("%i", &g);

//			actualizarGenero(g, id_Pelicula);

			break;

		case '3':
			printf("Inserte el nuevo Director de la pelicula:\n");
			char *director;
			director = (char*) malloc(sizeof(char)*50);

			fflush(stdout);
			scanf("%s", director);

			actualizarDirector(director, id_Pelicula);

//			imprimirPeliculas(p, 1);
			break;

		case '4':

			printf("Seleccion el nuevo Formato de la pelicula:\n");
			printf("1. DVD\n");
			printf("2. Blu-Ray\n");
			printf("3. VHS\n");
			int f;
			fflush(stdout);
			scanf("%i", &f);

//			actualizarFormato(f, id_Pelicula);


			break;

		case '5':

			printf("\n Inserte el nuevo Precio de la pelicula:\n");
			float p;
			fflush(stdout);
			scanf("%f", &p);

//			actualizarPrecio(p, id_Pelicula);

			break;

		case '6':
			printf("\n Volviendo al menu principal\n");
			break;
	}



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

			cargarPeliculas();

			break;

			case '2':

				printf("La opcion elegida es 2.\n");
				menuInsertar();
			break;

			case '3':

				printf("La opcion elegida es 3.\n");
				menuModificar();
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

void menuInicioSesion(){
	inicializar();
	char* nombreAdmin = malloc(sizeof(char)*20);
	char* contraAdmin = malloc(sizeof(char)*20);
	printf("\nInicia sesión como administrador \n");
		printf("Escribe tu nombre: \n");
		fflush(stdout);
		scanf("%s", nombreAdmin);

		printf("Escribe tu contraseña: \n");
		fflush(stdout);
		scanf("%s", contraAdmin);

		int r = comprobarAdmin(nombreAdmin, contraAdmin);
		if(r==1){
			menuPrincipal();
		} else {
			printf("\nESTE USUARIO NO EXISTE\n");
			menuInicioSesion();
		}
}


