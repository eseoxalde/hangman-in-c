#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funciones.h"


int cargarPalabras(char lista[][MAX_LEN]) {
    FILE *f = fopen("palabras.txt", "r");
    if (!f) { printf("No se pudo abrir palabras.txt\n"); return 0; }
    int n = 0;
    while (n < MAX_PALABRAS && fscanf(f, "%19s", lista[n]) == 1) n++;
    fclose(f);
    return n;
}

char *elegirPalabra(char lista[][MAX_LEN], int cant) {
    srand(time(NULL));
    return lista[rand() % cant];
}

void guardarResultado(const char *nombre, int gano) {
    FILE *pf = fopen("puntajes.txt", "a");
    if (!pf) { printf("No se pudo abrir puntajes.txt\n"); return; }
    fprintf(pf, "%s %s\n", nombre, (gano ? "GANO" : "PERDIO"));
    fclose(pf);
}

void jugar() {
    char lista[MAX_PALABRAS][MAX_LEN];
    int cant = cargarPalabras(lista);
    if (cant == 0) return;

    char *palabra = elegirPalabra(lista, cant);
    int len = strlen(palabra);
    char intento[MAX_LEN];
    for (int i=0; i<len; i++) intento[i]='_';
    intento[len]='\0';

    int vidas = VIDAS;
    char letra;
    while (vidas > 0 && strcmp(intento, palabra)!=0) {
        printf("\n%s  (vidas: %d)\n", intento, vidas);
        printf("Letra: ");
        scanf(" %c", &letra);

        int acierto = 0;
        for (int i=0; i<len; i++) {
            if (palabra[i] == letra) {
                intento[i] = letra;
                acierto = 1;
            }
        }
        if (!acierto) vidas--;
    }

    char nombre[30];
    printf("\nTu nombre: ");
    scanf("%s", nombre);

    if (strcmp(intento, palabra)==0) {
        printf("\n¡Ganaste! La palabra era %s\n", palabra);
        guardarResultado(nombre,1);
    } else {
        printf("\nPerdiste. La palabra era %s\n", palabra);
        guardarResultado(nombre,0);
    }
}

void verPuntajes() {
    FILE *pf = fopen("puntajes.txt","r");
    if (!pf) { printf("No hay puntajes guardados.\n"); return; }
    char linea[100];
    printf("\n--- Puntajes ---\n");
    while(fgets(linea,sizeof(linea),pf)) printf("%s",linea);
    fclose(pf);
}


void mostrarAyuda() {
    printf("\n--- Ayuda ---\n");
    printf("Objetivo: adivinar la palabra letra por letra.\n");
    printf("Tienes %d vidas. Cada letra incorrecta resta 1 vida.\n", VIDAS);
    printf("Si completas la palabra antes de quedarte sin vidas, ganas.\n");
    printf("Si se acaban las vidas, pierdes.\n");
    printf("Las palabras se leen desde 'palabras.txt'.\n");
}

void verPalabras() {
    FILE *f = fopen("palabras.txt","r");
    if (!f) { printf("No se pudo abrir palabras.txt\n"); return; }
    char palabra[MAX_LEN];
    int i=1;
    printf("\n--- Palabras ---\n");
    while(fscanf(f,"%19s",palabra)==1) {
        printf("%d. %s\n",i++,palabra);
    }
    fclose(f);
}

void agregarPalabra() {
    char nueva[MAX_LEN];
    printf("Ingrese la nueva palabra (max %d letras): ", MAX_LEN-1);
    scanf("%19s", nueva);
    FILE *f = fopen("palabras.txt","a");
    if (!f) { printf("No se pudo abrir palabras.txt\n"); return; }
    fprintf(f,"%s\n",nueva);
    fclose(f);
    printf("Palabra agregada!\n");
}

void eliminarPalabra() {
    verPalabras();
    int num;
    printf("Ingrese el número de la palabra a eliminar: ");
    scanf("%d",&num);

    FILE *f = fopen("palabras.txt","r");
    if (!f) { printf("No se pudo abrir palabras.txt\n"); return; }

    char lista[MAX_PALABRAS][MAX_LEN];
    int n=0;
    while(n<MAX_PALABRAS && fscanf(f,"%19s",lista[n])==1) n++;
    fclose(f);

    if (num<1 || num>n) { printf("Número inválido\n"); return; }

    FILE *fa = fopen("palabras_temp.txt","w");
    for(int i=0;i<n;i++) if(i!=num-1) fprintf(fa,"%s\n",lista[i]);
    fclose(fa);

    remove("palabras.txt");
    rename("palabras_temp.txt","palabras.txt");
    printf("Palabra eliminada!\n");
}

void borrarPuntajes() {
    FILE *f = fopen("puntajes.txt","w");
    if(!f) { printf("No se pudo abrir puntajes.txt\n"); return; }
    fclose(f);
    printf("Todos los puntajes han sido borrados.\n");
}