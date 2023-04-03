/*
 * logger.c
 *
 *  Created on: 3 abr 2023
 *      Author: Usuario
 */
#include <stdio.h>


void mensaje_log(char *mensaje, char *archivo) {
    FILE *log_file = fopen(archivo, "a"); // abre el archivo en modo de escritura (append)
    if (log_file == NULL) {
        printf("No se pudo abrir el archivo de registro.\n");
        return;
    }
    fprintf(log_file, "Error: %s\n", mensaje); // escribe el mensaje de error en el archivo
    fclose(log_file); // cierra el archivo
}
