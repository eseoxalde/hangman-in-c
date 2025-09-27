# Juego del Ahorcado en C

## Motivacion

Seminario de Lenguajes (Opción:C) año 2008.
Facultad de informática
Universidad Nacional de La Plata

## Descripción

Este es un programa en **C** que implementa el clásico juego del **Ahorcado** en modo terminal.  
Permite jugar adivinando palabras letra por letra, gestionar palabras y puntajes desde archivos de texto.

## Funcionalidades

- Jugar al Ahorcado con palabras leídas desde `palabras.txt`.
- Ver el historial de puntajes en `puntajes.txt`.
- Mostrar ayuda con las reglas del juego.
- Gestionar palabras:
  - Ver palabras existentes.
  - Agregar nuevas palabras.
  - Eliminar palabras.
- Borrar todos los puntajes guardados.
- Menú interactivo por terminal.

## Estructura del proyecto

/ahorcado
├── main.c # Programa principal con menú
├── funciones.c # Implementación de funciones
├── funciones.h # Prototipos y constantes
├── palabras.txt # Archivo con palabras para el juego
└── puntajes.txt # Archivo con historial de puntajes

## Cómo compilar y ejecutar

### Linux / Mac

gcc main.c funciones.c -o ahorcado
./ahorcado

### Windows (cmd)

gcc main.c funciones.c -o ahorcado.exe
ahorcado.exe

## Archivos de datos

palabras.txt: Cada palabra en una línea, máximo 15 caracteres.

puntajes.txt: Se genera automáticamente, registra el nombre del jugador y si ganó o perdió.

## Uso

1. Ejecutar el programa.
2. Seleccionar una opción del menú:
   - Jugar
   - Ver puntajes
   - Ayuda
   - Ver/Agregar/Eliminar palabras
   - Borrar puntajes
   - Salir
3. Seguir las instrucciones en pantalla.
