#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <math.h>
#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;







void menu();
void ejercicio_1();
void ejercicio_2();
void ejercicio_3();
void mayor_menor(int n, float vector[n]);
void repeticion(int n, float dato, float vector[n]);
void texto(int n, float dato, float vector[n]);
#define TAM 50
void llenarArray(double array[], double arrayDesordenado[], int tam);
void imprimirArray(double array[], int tam);
void ordenarMergesort_dividir(double array[], int pinicial, int pfinal);
void ordenarMergesort_fusionar(double array[],int pinicial, int medio, int
pfinal);
int busquedaLineal(double array[], int tam, double busquedaUsuario);
void busquedaTransaccion(double array[], int tam, double valorTransaccion);
void escribirArchivo(double array[], double arrayDesordenado[], int tam, double
valorTransaccion);

void Sucursal();
void Datos();

