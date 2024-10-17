#include <stdio.h>
#include <string.h>
#include "inventario.h"

void ingresarProductos(char productos[10][50], float precios[10], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("Ingrese el nombre del producto %d: ", i+1);
        scanf("%s", productos[i]);
        printf("Ingrese el precio del producto %d: ", i+1);
        scanf("%f", &precios[i]);
    }
}

float calcularPrecioTotal(float precios[10], int cantidad) {
    float total = 0;
    for (int i = 0; i < cantidad; i++) {
        total += precios[i];
    }
    return total;
}

int encontrarProductoMasCaro(float precios[10], int cantidad) {
    int indice = 0;
    for (int i = 1; i < cantidad; i++) {
        if (precios[i] > precios[indice]) {
            indice = i;
        }
    }
    return indice;
}

int encontrarProductoMasBarato(float precios[10], int cantidad) {
    int indice = 0;
    for (int i = 1; i < cantidad; i++) {
        if (precios[i] < precios[indice]) {
            indice = i;
        }
    }
    return indice;
}

float calcularPrecioPromedio(float precios[10], int cantidad) {
    float total = calcularPrecioTotal(precios, cantidad);
    return total / cantidad;
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
