#ifndef INVENTARIO_H
#define INVENTARIO_H

void ingresarProductos(char productos[10][50], float precios[10], int cantidad);
float calcularPrecioTotal(float precios[10], int cantidad);
int encontrarProductoMasCaro(float precios[10], int cantidad);
int encontrarProductoMasBarato(float precios[10], int cantidad);
float calcularPrecioPromedio(float precios[10], int cantidad);
void buscarProducto(char productos[10][50], float precios[10], int cantidad, char nombre[50]);

#endif