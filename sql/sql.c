/*
 * sql.c
 *
 *  Created on: 1 abr 2023
 *      Author: oscar
 */

#include "sqlite3.h"

void inicializar();
{
	sqlite3 *db;
	sqlite3_stmt *stmt;
	int result;

	sqlite3_open("futbol.sqlite", &db);
}

void cargarPeliculas();



