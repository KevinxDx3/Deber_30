#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <math.h>
#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;
#include "taller.h"
//prototipos


char fin;
int main() {
system("clear");
int opcion = 0;
bool i = false;
menu();
while(i == false){
 cin>>opcion;
 cin.ignore();
 switch (opcion){
 case 1:
 ejercicio_1();
 cout<<"\n seleccione su siguiente ejercicio\n";
 break;
 case 2:
 ejercicio_2();
 cout<<"\n seleccione su siguiente ejercicio\n";
 break;
 case 3:
 ejercicio_3();
 cout<<"\n seleccione su siguiente ejercicio\n";
 break;
 case 4:
 cout<<"Gracias por usar la SELECCION DE EJERCICIO";
 i = true;
 break;
 default:
 cout<<"Ingeso de opcion no valido\n";
 cout<<"Por favor seleccione una opcion valida\n";

 break;
 }



}
}



