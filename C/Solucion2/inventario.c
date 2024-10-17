#include <stdio.h>
#include <string.h>
#include "inventario.h"

void ingresarProductos(char productos[10][50], float precios[10], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("Ingrese el nombre del producto %d: ", i + 1);
        scanf("%s", productos[i]);

        // Validación del precio para que no sea 0 o negativo
        printf("Ingrese el precio del producto %d: ", i + 1);
        scanf("%f", &precios[i]);
        if (precios[i] <= 0) {
            printf("El precio debe ser mayor a 0. El precio ingresado no es valido.\n");
            return;
        }
    }
}

void calcularTodo(float precios[10], int cantidad, float *total, float *promedio, int *indiceCaro, int *indiceBarato) {
    *total = 0;
    *indiceCaro = 0;
    *indiceBarato = 0;

    for (int i = 0; i < cantidad; i++) {
        *total += precios[i];

        if (precios[i] > precios[*indiceCaro]) {
            *indiceCaro = i;
        }
        if (precios[i] < precios[*indiceBarato]) {
            *indiceBarato = i;
        }
    }
    *promedio = *total / cantidad;
}


void buscarProducto(char productos[10][50], float precios[10], int cantidad, char nombre[50]) {
    for (int i = 0; i < cantidad; i++) {
        if (strcmp(productos[i], nombre) == 0) {
            printf("El precio del producto %s es: %.2f\n", productos[i], precios[i]);
            return;
        }
    }
    printf("Producto no encontrado\n");
}