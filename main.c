

#include <stdio.h>
#include <stdlib.h>
#include "menus/menus.h"
#include "pelicula/pelicula.h"
#include "sql/sql.h"

int main(void) {
	menuPrincipal();

//	Pelicula *p;
//	p = (Pelicula*) malloc(sizeof(Pelicula)*2);
//
//	Pelicula peli = {1,"transformers", 3, "koldo", 4, "fecha", 34.02};
//	Pelicula peli2 = {2,"transformers2", 1, "oscar", 3, "fecha1", 24.02};
//
//	p[0] = peli;
//	p[1] = peli2;
//
// 	imprimirPeliculas(p, 2);

	int num_pelis = contarPeliculas();
	printf("%i", num_pelis);
	return 0;

}

