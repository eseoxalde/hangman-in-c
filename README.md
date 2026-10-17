# Hangman en C

## Abstract

A terminal-based Hangman game implemented in C. Players can guess randomly selected words, view game results, and manage the word list through an interactive menu. The program also records whether each game was won or lost. The project explores modular programming, functions, and file handling in C.

## Descripción

Programa desarrollado en **C** que implementa el clásico juego del **Ahorcado** en modo terminal. Permite jugar adivinando palabras letra por letra y gestionar palabras y resultados de partidas mediante archivos de texto.

## Funcionalidades

- Jugar al Ahorcado con palabras leídas desde `palabras.txt`.
- Consultar el historial de resultados en `puntajes.txt`.
- Consultar la ayuda con las reglas del juego.
- Gestionar las palabras:
  - Ver las palabras existentes.
  - Agregar nuevas palabras.
  - Eliminar palabras.
- Borrar todos los resultados guardados.
- Navegar por un menú interactivo en la terminal.

## Estructura del proyecto

- `main.c`: programa principal y menú.
- `funciones.c`: implementación de las funciones del juego.
- `funciones.h`: prototipos de funciones y constantes.
- `palabras.txt`: archivo con las palabras disponibles para el juego.
- `puntajes.txt`: archivo con el historial de resultados.

## Tecnologías

- **Lenguaje:** C.
- **Compilador:** GCC.
- **Manejo de archivos:** lectura y escritura de archivos de texto.
- **Selección aleatoria:** `rand()`, `srand()` y `time()`.
- **Organización del código:** módulos separados en archivos `.c` y `.h`.

## Cómo compilar y ejecutar

### Linux / macOS

```bash
gcc main.c funciones.c -o ahorcado
./ahorcado
```

### Windows (CMD)

```bash
gcc main.c funciones.c -o ahorcado.exe
ahorcado.exe
```

Se necesita un compilador de C, como GCC, para compilar el programa.

## Uso

1. Compilar y ejecutar el programa.
2. Seleccionar una opción del menú:
   - Jugar.
   - Ver puntajes.
   - Consultar la ayuda.
   - Ver, agregar o eliminar palabras.
   - Borrar los puntajes.
   - Salir.
3. Seguir las instrucciones que aparecen en pantalla.

## Contexto académico

Proyecto desarrollado como trabajo práctico final del **Seminario de Lenguaje: opción C**, de la Facultad de Informática de la Universidad Nacional de La Plata (UNLP).

El objetivo original era implementar el juego del Ahorcado mediante la lectura de palabras desde un archivo de texto, la selección aleatoria de una palabra y la validación de las letras ingresadas por el usuario.

La consigna también requería controlar los intentos disponibles y organizar el código en módulos separados, utilizando funciones, archivos de cabecera y herramientas de la biblioteca estándar de C.

## Licencia

Este proyecto se distribuye bajo la licencia MIT. Consultar el archivo `LICENSE` para conocer las condiciones de uso y distribución.
