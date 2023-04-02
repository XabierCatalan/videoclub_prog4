/*
 * sql.c
 *
 *  Created on: 1 abr 2023
 *      Author: oscar
 */

#include "sqlite3.h"
#include <string.h>
#include <stdio.h>


	sqlite3 *db;
	sqlite3_stmt *stmt;
	int result;

void inicializar()
{
	sqlite3_open("BDD_Prog.db", &db);
}

void cargarPeliculas()
{
	char sql2[] = "select Titulo_Pelicula from Peliculas";

	sqlite3_prepare_v2(db, sql2, strlen(sql2), &stmt, NULL) ;

	printf("\n");
	printf("Mostrando peliculas:\n");

	do {
			result = sqlite3_step(stmt) ;
			if (result == SQLITE_ROW) {
				printf("%s\n", (char*) sqlite3_column_text(stmt, 0));
			}
		} while (result == SQLITE_ROW);
		printf("\n");

		sqlite3_finalize(stmt);

}

void cerrar()
{
	sqlite3_close(db);
}



