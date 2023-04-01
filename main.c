#include <stdio.h>
#include <stdlib.h>

int main() {
    int opcion;

    do {
        printf("\n\n----Menu de opciones----\n\n");
        printf("1. Agregar una película\n");
        printf("2. Eliminar una película\n");
        printf("3. Mostrar todas las películas\n");
        printf("4. Salir del programa\n");
        printf("\nIngrese una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("\nHa seleccionado la opción 1: Agregar una película\n");
                // Aquí iría el código para agregar una película
                break;
            case 2:
                printf("\nHa seleccionado la opción 2: Eliminar una película\n");
                // Aquí iría el código para eliminar una película
                break;
            case 3:
                printf("\nHa seleccionado la opción 3: Mostrar todas las películas\n");
                // Aquí iría el código para mostrar todas las películas
                break;
            case 4:
                printf("\nHa seleccionado la opción 4: Salir del programa\n");
                break;
            default:
                printf("\nOpción no válida. Intente de nuevo.\n");
                break;
        }
    } while(opcion != 4);

    return 0;
}
