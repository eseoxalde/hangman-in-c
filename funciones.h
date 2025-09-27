#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_PALABRAS 50
#define MAX_LEN 20
#define VIDAS 6

int cargarPalabras(char lista[][MAX_LEN]);
char *elegirPalabra(char lista[][MAX_LEN], int cant);
void jugar();
void verPuntajes();
void guardarResultado(const char *nombre, int gano);

void mostrarAyuda();
void verPalabras();
void agregarPalabra();
void eliminarPalabra();
void borrarPuntajes();

#endif
