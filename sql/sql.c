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
#include "../administrador/administrador.h"


	sqlite3 *db;
	sqlite3_stmt *stmt;
	sqlite3_stmt *stmt2;


	int result;

	char* load_config(char* filename, char* buscar) {
	    FILE* archivo;
	    char linea[100];
	    char* igual;
	    char buscar2[20];
	    fflush(stdout);
	    archivo = fopen(filename, "r");

	    if (archivo == NULL) {
	        printf("Error al abrir el archivo.\n");
	        return NULL;
	    }
	    fflush(stdout);
	    char* resultado = NULL;
	    while (fgets(linea, 100, archivo)) {
	        int i = 0;
	        while (linea[i] != '=') {
	            buscar2[i] = linea[i];
	            i++;
	        }
	        buscar2[i] = '\0';

	        if (strcmp(buscar, buscar2) == 0) {
	            igual = strchr(linea, '=');
	            if (igual != NULL) {
	                int longitud = strlen(igual + 1);
	                resultado = (char*) realloc(resultado, longitud * sizeof(char));
	                if (resultado == NULL) {
	                    printf("Error al asignar memoria.\n");
	                    return NULL;
	                }
	                fflush(stdout);
	                strncpy(resultado, igual + 1, longitud);
	                resultado[longitud - 1] = '\0';
	            }
	        }
	    }

	    fclose(archivo);
	    fflush(stdout);
	    return resultado;
	}

void inicializar()
{
//	char** frase =config();
//	printf("%s", frase[0]);
	char*rutaBDD=load_config("sql/prueba.txt","rutaBDD");

	    sqlite3_open(rutaBDD, &db);
	    free(rutaBDD);


}

void cerrar()
{
	sqlite3_close(db);
}

//INICIAR SESION
int comprobarAdmin(char admin[], char contra[]){
//	 Administrador a;
	    int resultado = 0;


	    char sql[] = "SELECT * FROM Administradores WHERE Nombre_Admin = ? AND Contra_Admin = ?";

	    sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;
	    sqlite3_bind_text(stmt, 1, admin, strlen(admin), SQLITE_STATIC);
	    sqlite3_bind_text(stmt, 2, contra, strlen(contra), SQLITE_STATIC);

	    result = sqlite3_step(stmt);

	    if(result == SQLITE_ROW) {
	        resultado = 1;
	    } else {
	        resultado = 0;
	    }

//	    a.nombre_admin = (char*) sqlite3_column_text(stmt, 1);
//	    a.gmail_admin = (char*) sqlite3_column_text(stmt, 2);
//	    a.contra_admin = (char*)  sqlite3_column_text(stmt, 3);

	    sqlite3_finalize(stmt);



	    return resultado;
}

char* buscarGenero (int cod_gen)
{
	char* gen;

	char sql[] = "select Nombre_Gen from Generos where Cod_Gen = ?";

	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt2, NULL) ;
	sqlite3_bind_int(stmt2,1,cod_gen);


//	printf("\n");
//	printf("Buscando Genero:\n");


	result = sqlite3_step(stmt2) ;
	if (result == SQLITE_ROW) {
		//printf("%s\n", (char*) sqlite3_column_text(stmt, 0));
		gen = (char*) sqlite3_column_text(stmt2, 0);

		return gen;

		} else {

			return gen = "Genero no encontrado";
		}

	sqlite3_finalize(stmt2);

}

char* buscarFormato (int cod_for){
	char* form;

		char sql[] = "select Nombre_For from Formato where Cod_For = ?";

		sqlite3_prepare_v2(db, sql, strlen(sql), &stmt2, NULL) ;
		sqlite3_bind_int(stmt2,1,cod_for);


//		printf("\n");
//		printf("Buscando formato:\n");


		result = sqlite3_step(stmt2) ;
		if (result == SQLITE_ROW) {
			//printf("%s\n", (char*) sqlite3_column_text(stmt, 0));
			form = (char*) sqlite3_column_text(stmt2, 0);

			return form;

			} else {

				return form = "formato no encontrado";
			}

		sqlite3_finalize(stmt2);
}

//METODO DE CONTAR EL NUMERO DE PELICULAS

int contarPeliculas(){
	char sql[] = "select count(*) from Peliculas";
	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;

	result = sqlite3_step(stmt) ;


	sqlite3_finalize(stmt);

	return result +1;

}

//METODO DE CARGAR PELICULAS

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

//			sqlite3_column_int(stmt, 0)
//			(char*) sqlite3_column_text(stmt, 1)


			if (result == SQLITE_ROW) {

//				printf("%i + %s\n", sqlite3_column_int(stmt, 0), (char*) sqlite3_column_text(stmt, 1));





				printf("Id_Pelicula: %i | Titulo: %s | Genero: %s | Director: %s | Formato: %s | Precio: %.2f | Cantidad: %i \n ",
						sqlite3_column_int(stmt,0), (char*) sqlite3_column_text(stmt, 1), buscarGenero(sqlite3_column_int(stmt, 2)),
						(char*) sqlite3_column_text(stmt, 3), buscarFormato(sqlite3_column_int(stmt, 4)), sqlite3_column_double(stmt, 5),
						sqlite3_column_int(stmt, 6));

//				printf("Id_ Pelicula: %i | Titulo: %s | Genero: %s | Director: %s | Formato: %s | Precio: %.2f | Cantidad: %i \n",
//						sqlite3_column_int(stmt, 0), (char*) sqlite3_column_text(stmt, 1), buscarGenero(sqlite3_column_int(stmt, 2))
//						, (char*) sqlite3_column_text(stmt, 3), buscarFormato(sqlite3_column_int(stmt, 4)), sqlite3_column_double(stmt, 5),
//						sqlite3_column_int(stmt, 6));
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


//METODODOS DE ACTUALIZAR PELICULAS

void actualizarTitulo(char* titulo, int id_pelicula){

	char sql[] = "UPDATE Peliculas SET Titulo_Pelicula = ? where Id_Pelicula = ?";

	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);
	sqlite3_bind_text(stmt, 1, titulo, strlen(titulo), SQLITE_TRANSIENT);
	sqlite3_bind_int(stmt, 2, id_pelicula);

	 if (result != SQLITE_OK) {
	    fprintf(stderr, "Error en la consulta: %s\n", sqlite3_errmsg(db));

	  }

	result = sqlite3_step(stmt);

	if (result != SQLITE_DONE) {
		fprintf(stderr, "Error en la actualización: %s\n", sqlite3_errmsg(db));

	  } else {
		 printf("titulo actualizado\n");

	  }

	  sqlite3_finalize(stmt);

}




void actualizarGenero(int genero, int id_pelicula){

	char sql[] = "UPDATE Peliculas SET Cod_Gen = ? where Id_Pelicula = ?";

		sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);
		sqlite3_bind_int(stmt, 1, genero);
		sqlite3_bind_int(stmt, 2, id_pelicula);
		 if (result != SQLITE_OK) {
		    fprintf(stderr, "Error en la consulta: %s\n", sqlite3_errmsg(db));
		  }
		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			fprintf(stderr, "Error en la actualización: %s\n", sqlite3_errmsg(db));

		  } else {

			 printf("genero actualizado\n");

		  }

		  sqlite3_finalize(stmt);
}

void actualizarDirector(char* Director, int id_pelicula){
	char sql[] = "UPDATE Peliculas SET Director = ? where Id_Pelicula = ?";

		sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);
		sqlite3_bind_text(stmt, 1, Director, strlen(Director), SQLITE_TRANSIENT);
		sqlite3_bind_int(stmt, 2, id_pelicula);

		 if (result != SQLITE_OK) {
		    fprintf(stderr, "Error en la consulta: %s\n", sqlite3_errmsg(db));

		  }

		result = sqlite3_step(stmt);

		if (result != SQLITE_DONE) {
			fprintf(stderr, "Error en la actualización: %s\n", sqlite3_errmsg(db));

		  } else {
			 printf("titulo actualizado\n");

		  }

		  sqlite3_finalize(stmt);

}

void actualizarFormato(int formato, int id_pelicula){
	char sql[] = "UPDATE Peliculas SET Cod_For = ? where Id_Pelicula = ?";

			sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);
			sqlite3_bind_int(stmt, 1, formato);
			sqlite3_bind_int(stmt, 2, id_pelicula);

			 if (result != SQLITE_OK) {
			    fprintf(stderr, "Error en la consulta: %s\n", sqlite3_errmsg(db));

			  }

			result = sqlite3_step(stmt);

			if (result != SQLITE_DONE) {
				fprintf(stderr, "Error en la actualización: %s\n", sqlite3_errmsg(db));

			  } else {
				 printf("titulo actualizado\n");

			  }

			  sqlite3_finalize(stmt);

}

void actualizarPrecio(float precio, int id_pelicula){
	char sql[] = "UPDATE Peliculas SET Precio = ? where Id_Pelicula = ?";

			sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);
			sqlite3_bind_double(stmt, 1, precio);
			sqlite3_bind_int(stmt, 2, id_pelicula);

			 if (result != SQLITE_OK) {
			    fprintf(stderr, "Error en la consulta: %s\n", sqlite3_errmsg(db));

			  }

			result = sqlite3_step(stmt);

			if (result != SQLITE_DONE) {
				fprintf(stderr, "Error en la actualización: %s\n", sqlite3_errmsg(db));

			  } else {
				 printf("titulo actualizado\n");

			  }

			  sqlite3_finalize(stmt);

}

void actualizarStock(int stock, int id_pelicula){

	char sql[] = "UPDATE Peliculas SET Cantidad = ? where Id_Pelicula = ?";

		sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);
		sqlite3_bind_int(stmt, 1, stock);
		sqlite3_bind_int(stmt, 2, id_pelicula);
		 if (result != SQLITE_OK) {
		    fprintf(stderr, "Error en la consulta: %s\n", sqlite3_errmsg(db));
		  }
		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			fprintf(stderr, "Error en la actualización: %s\n", sqlite3_errmsg(db));

		  } else {

			 printf("genero actualizado\n");

		  }

		  sqlite3_finalize(stmt);
}




//METODOS DE BUSCAR

Pelicula* buscarPelicula(int id){
	char sql[] = "select * from Peliculas where Id_Pelicula = ?";
	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;
	sqlite3_bind_int(stmt,1,id);

	result = sqlite3_step(stmt) ;

	Pelicula* p ;
	p = (Pelicula*) malloc(sizeof(Pelicula));
	p->id_pelicula = id;
	p->titulo = (char*) sqlite3_column_text(stmt, 1);
	p->cod_genero = sqlite3_column_int(stmt, 2);
	p->director = (char*) sqlite3_column_text(stmt, 3);
	p->cod_formato = sqlite3_column_int(stmt, 4);
	p->precio = sqlite3_column_double(stmt, 5);
	p->cantidad = sqlite3_column_int(stmt, 6);

	imprimirPeliculas(p);

	sqlite3_finalize(stmt);






	return p;

}






//METODO DE INSERTAR PELICULAS

void insertarPelicula(Pelicula p) {
	char sql[] = "insert into Peliculas (Id_pelicula, Titulo_Pelicula, Cod_Gen, Director, Cod_For, Precio, Cantidad"
			") values (NULL, ?,?,?,?,?,?)";

	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;
	sqlite3_bind_text(stmt, 1, p.titulo, strlen(p.titulo), SQLITE_STATIC);
	sqlite3_bind_int(stmt,2,p.cod_genero);
	sqlite3_bind_text(stmt, 3, p.director, strlen(p.director), SQLITE_STATIC);
	sqlite3_bind_int(stmt,4,p.cod_formato);
	sqlite3_bind_double(stmt,5,p.precio);
	sqlite3_bind_double(stmt,6,p.cantidad);



	 if (result != SQLITE_OK) {
		    fprintf(stderr, "Error en la consulta: %s\n", sqlite3_errmsg(db));

		  }

		result = sqlite3_step(stmt);



		if (result != SQLITE_DONE) {
			fprintf(stderr, "Error en la actualización: %s\n", sqlite3_errmsg(db));

		  } else {
			 printf("titulo actualizado\n");
			 imprimirPeliculas(&p);
		  }

		  sqlite3_finalize(stmt);


		sqlite3_finalize(stmt);

}

//METODO DE BORRAR PELICULAS

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






