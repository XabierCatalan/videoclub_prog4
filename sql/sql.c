/*
 * sql.c
 *
 *  Created on: 1 abr 2023
 *      Author: oscar
 */

#include "sqlite3.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../pelicula/pelicula.h"


	sqlite3 *db;
	sqlite3_stmt *stmt;
	int result;

void inicializar()
{
	sqlite3_open("sql/BDD_Prog.db", &db);
}

int contarPeliculas(){
	char sql[] = "select count(*) from Peliculas";
	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;

	result = sqlite3_step(stmt) ;


	sqlite3_finalize(stmt);

	return result +1;

}

void cargarPeliculas()
{
	char sql[] = "select * from Peliculas";

//	int num_pelis = contarPeliculas();
//	int cont = 0;
//
//	Pelicula *pelis;
//	pelis = (Pelicula*) malloc(sizeof(Pelicula)*num_pelis);

	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;

	printf("\n");
	printf("Mostrando peliculas:\n");

	do {
			result = sqlite3_step(stmt) ;




			if (result == SQLITE_ROW) {


			}
		}  while (result == SQLITE_ROW);

	printf("\n");

	 sqlite3_finalize(stmt);

}


//void cargarPeliculas()
//{
//	char sql[] = "select Titulo_Pelicula from Peliculas";
//
//	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;
//
//	printf("\n");
//	printf("Mostrando peliculas:\n");
//
//	do {
//			result = sqlite3_step(stmt) ;
//			if (result == SQLITE_ROW) {
//				printf("%s\n", (char*) sqlite3_column_text(stmt, 0));
//			}
//		} while (result == SQLITE_ROW);
//		printf("\n");
//
//		sqlite3_finalize(stmt);
//
//}

char* buscarGenero (int cod_gen)
{
	char* gen;

	char sql[] = "select Nombre_Gen from Generos where Cod_Gen = ?";

	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;
	sqlite3_bind_int(stmt,1,cod_gen);


//	printf("\n");
//	printf("Buscando Genero:\n");


	result = sqlite3_step(stmt) ;
	if (result == SQLITE_ROW) {
		//printf("%s\n", (char*) sqlite3_column_text(stmt, 0));
		gen = (char*) sqlite3_column_text(stmt, 0);

		return gen;

		} else {

			return gen = "Genero no encontrado";
		}

	sqlite3_finalize(stmt);

}

char* buscarFormato (int cod_for){
	char* form;

		char sql[] = "select Nombre_For from Formato where Cod_For = ?";

		sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;
		sqlite3_bind_int(stmt,1,cod_for);


//		printf("\n");
//		printf("Buscando formato:\n");


		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			//printf("%s\n", (char*) sqlite3_column_text(stmt, 0));
			form = (char*) sqlite3_column_text(stmt, 0);

			return form;

			} else {

				return form = "formato no encontrado";
			}

		sqlite3_finalize(stmt);
}

void insertarPelicula(Pelicula p) {
	char sql[] = "insert into Peliculas (Id_pelicula, Titulo_Pelicula, Cod_Gen, Director, Cod_For, Precio"
			") values (NULL, ?,?,?,?,?)";

	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;
	sqlite3_bind_text(stmt, 1, p.titulo, strlen(p.titulo), SQLITE_STATIC);
	sqlite3_bind_int(stmt,2,p.cod_genero);
	sqlite3_bind_text(stmt, 3, p.director, strlen(p.director), SQLITE_STATIC);
	sqlite3_bind_int(stmt,4,p.cod_formato);
	sqlite3_bind_double(stmt,5,p.precio);

	result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			printf("Error insertando la pelicula\n");
		}else{
			printf("Pelicula INSERTADA\n");
			imprimirPeliculas(&p, 1);
		}

		sqlite3_finalize(stmt);

}

void borrarPelicula(int id){
	char sql[] = "delete from Peliculas where Id_Pelicula = ?";
	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;

	sqlite3_bind_int(stmt,1,id);


	result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			printf("Error eliminando la pelicula\n");
		}else{
			printf("Pelicula ELIMINADA\n");
		}
	sqlite3_finalize(stmt);



}



void cerrar()
{
	sqlite3_close(db);
}



