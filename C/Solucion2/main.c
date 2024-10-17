#include "inventario.h"
#include <stdio.h>

int main() {
    char productos[10][50];
    float precios[10];
    int cantidad;

    // Solicitar la cantidad de productos
    printf("Cuantos productos quieres ingresar? (1 a 10): ");
    scanf("%d", &cantidad);

    // Mostrar advertencia si la cantidad de productos no es válida, pero continuar el programa
    if (cantidad < 1 || cantidad > 10) {
        printf("Advertencia: Solo se pueden ingresar entre 1 y 10 productos. Se continuaran tomando los 10 primeros productos.\n");
        cantidad = 10;  // Si el valor es inválido, se establecerá en 10 por defecto
    }

    ingresarProductos(productos, precios, cantidad);

    float total, promedio;
    int indiceCaro, indiceBarato;

    calcularTodo(precios, cantidad, &total, &promedio, &indiceCaro, &indiceBarato);

    printf("Precio total del inventario: %.2f\n", total);
    printf("El producto mas caro es: %s con un precio de %.2f\n", productos[indiceCaro], precios[indiceCaro]);
    printf("El producto mas barato es: %s con un precio de %.2f\n", productos[indiceBarato], precios[indiceBarato]);
    printf("El precio promedio es: %.2f\n", promedio);

    char nombreProducto[50];
    printf("Ingrese el nombre del producto a buscar: ");
    scanf("%s", nombreProducto);
    buscarProducto(productos, precios, cantidad, nombreProducto);

    // Pausa para esperar a que el usuario presione Enter antes de salir
    printf("Presione Enter para salir...\n");
    getchar();  // Captura el Enter que quedó en el buffer
    getchar();  // Espera a que el usuario presione Enter

    return 0;
}
