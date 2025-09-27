#include <stdio.h>
#include "funciones.h"

int main() {
    int op;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Jugar\n");
        printf("2. Ver puntajes\n");
        printf("3. Ayuda\n");
        printf("4. Ver palabras\n");
        printf("5. Agregar palabra\n");
        printf("6. Eliminar palabra\n");
        printf("7. Borrar puntajes\n");
        printf("8. Salir\n");
        printf("Opcion: ");
        scanf("%d",&op);
        switch(op) {
            case 1: jugar(); break;
            case 2: verPuntajes(); break;
            case 3: mostrarAyuda(); break;
            case 4: verPalabras(); break;
            case 5: agregarPalabra(); break;
            case 6: eliminarPalabra(); break;
            case 7: borrarPuntajes(); break;
            case 8: printf("Gracias por jugar!\n"); break;
            default: printf("Opcion invalida\n");
        }
    } while(op!=8);
    return 0;
}
