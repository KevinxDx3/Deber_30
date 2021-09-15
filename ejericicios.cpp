#include "taller.h"



void menu(){
   cout<<"SELECCION DE EJERCICIOS\n";
 cout<<"Seleccione su EJERCICIO:\n";
 cout<<"1)Ejercicio 1\n";
 cout<<"2)Ejercicio 2\n";
 cout<<"3)Ejercicio 3\n";
 cout<<"4)Salir\n";
}

void ejercicio_1(){
int n=0, i = 0;
double J = false;
cout<<"Bienvenido al Ejercicio de Bsqueda y almacenamiento en vector\n";
cout<<"Ingrese la cantidad de elementos a ingresar (entre 15 y 80)\n";
while(J == false){
cin>>n;
if(n>=15 && n<=80){
J=true;
}
else{
 cout<< "El tamño ingresado no esta dentro del rango permitido, ingrese un rango valido\n";
}
}
float vector[n];
cout<<"Ingrese los elementos del vector:\n";
for(i = 0; i<n ; i++){
 cin>>vector[i];
}
cout<<"Su vecotr es: "<<endl;
for(i = 0; i<n ; i++){
 cout<<"["<<vector[i]<<"]";
}
cout<<endl;
mayor_menor(n, vector);
cout<<endl;
float dato=0;
cout<<"\nIngrese el elemento a buscar: ";
cin>>dato;
cin.ignore();
repeticion(n, dato, vector);
texto( n, dato, vector);
}



void ejercicio_2(){
 int tam;
 double dinero[TAM], dineroDesordenado[TAM], valorTransaccion;
 cout << "Ingrese el numero de transacciones que va a realizar: " << endl;
 cin >> tam;
 llenarArray(dinero, dineroDesordenado, tam);
 cout << "Sus transacciones ingresadas: " << endl;
 imprimirArray(dinero, tam);
 ordenarMergesort_dividir(dinero, 0, tam - 1);
 cout << "\nSus transacciones ordenadas: " << endl;
 imprimirArray(dinero, tam);
 cout << "\nIngrese el valor de la transaccion que desea buscar: " << endl;
 cin >> valorTransaccion;
 while(valorTransaccion <= 0){
 cout << "No puede ingresar cantidades negativas de dinero o iguales acero." << endl;
 cout << "Ingrese el valor de la transaccion que desea buscar: " << endl;
 cin >> valorTransaccion;
 }
 busquedaTransaccion(dinero, tam, valorTransaccion);
 escribirArchivo(dinero, dineroDesordenado, tam, valorTransaccion);
}






void ejercicio_3(){
 Datos();
}






//Funciones
void mayor_menor(int n, float vector[n]){
 int i=0,may=0,men=0;
may=vector[0];
men=vector[0];
for(i=0;i<n;i++)
{if(may<vector[i])
{may=vector[i];}}
for(i=0;i<n;i++)
{if(men>vector[i])
{men=vector[i];}}
cout<<endl;
cout<<"El menor es ="<<men<<endl;
cout<<"El mayor es ="<<may<<endl;
}






void repeticion(int n, float dato, float vector[n]){
char band = 'F';


 //Busqueda Secuencial
 int i=0,nrep=0;
 while((i<n)){
 if(vector[i] == dato){
 band = 'V';
 }
 i++;

 if(band == 'V'){
 cout<<"El numero a sido encontrado en la pos: "<<i-1<<endl;
 band = 'm';
 nrep++;
 }
 }
 if(band == 'F'){
 cout<<"El numero a buscar no existe en el arreglo"<<endl;
 }
 cout<<"El numero se repite un total de: "<<nrep<<" veces"<<endl;

}






void texto(int n, float dato, float vector[n]){
 int i = 0;
 ofstream ejercicio1;
ejercicio1.open("ejercicio1.txt",ios::out); //abrir
if(ejercicio1.fail()){
 cout<<"No se pudo abrir el archivo.\n";
 exit(1);
}
ejercicio1<<"Bienvenido al Ejercicio de Bsqueda y almacenamiento en vector\n";
ejercicio1<<"Su arreglo es: \n";
for(i = 0; i<n ; i++){
 ejercicio1<<"["<<vector[i]<<"]";
}
ejercicio1<<endl;
 int may=0,men=0;
may=vector[0];
men=vector[0];
for(i=0;i<n;i++)
{if(may<vector[i])
{may=vector[i];}}
for(i=0;i<n;i++)
{if(men>vector[i])
{men=vector[i];}}
ejercicio1<<endl;
ejercicio1<<"El menor es ="<<men<<endl;
ejercicio1<<"El mayor es ="<<may<<endl;
char band = 'F';

 i = 0;
 //Busqueda Secuencial
 int nrep=0;
 while((i<n)){
 if(vector[i] == dato){
 band = 'V';
 }
 i++;

 if(band == 'V'){
 ejercicio1<<"El numero a sido encontrado en la pos: "<<i-1<<endl;
 band = 'm';
 nrep++;
 }
 }
 if(band == 'F'){
 ejercicio1<<"El numero a buscar no existe en el arreglo"<<endl;
 }
 ejercicio1<<"El numero se repite un total de: "<<nrep<<" veces"<<endl;
ejercicio1.close();
}






void llenarArray(double array[], double arrayDesordenado[], int tam){
 for(int i = 0; i < tam; i++){
 cout << "Ingrese la cantidad de dinero correspondiente a la transaccionnumero " << i + 1 << endl;
 cin >> array[i];
 while(array[i] <= 0){
 cout << "No puede ingresar cantidades negativas de dinero o iguales acero." << endl;
 cout << "Ingrese la cantidad de dinero correspondiente a latransaccion numero " << i + 1 << endl;
 cin >> array[i];
 }
 }
 for(int j = 0; j < tam; j++){
   arrayDesordenado[j] = array[j];
 }
}





void imprimirArray(double array[], int tam){
 for(int i = 0; i < tam; i++){
 cout << "[$" << array[i] << "]";
 }
}





void ordenarMergesort_dividir(double array[], int pinicial, int pfinal){
 if(pinicial >= pfinal){
 return;
 }
 int medio = pinicial + (pfinal - pinicial) / 2;
 ordenarMergesort_dividir(array, pinicial, medio);
 ordenarMergesort_dividir(array,medio + 1, pfinal);
 ordenarMergesort_fusionar(array, pinicial, medio, pfinal);
}






void ordenarMergesort_fusionar(double array[], int pinicial, int medio, int
pfinal){
 int n1 = medio - pinicial + 1;
 int n2 = pfinal - medio;
 double L[n1], R[n2];
 for (int i = 0; i < n1; i++){
 L[i] = array[pinicial + i];
 }
 for (int j = 0; j < n2; j++){
 R[j] = array[medio + 1 + j];
 }
 int i = 0;
 int j = 0;
 int k = pinicial;
 while (i < n1 && j < n2) {
 if (L[i] <= R[j]) {
 array[k] = L[i];
 i++;
 } else {
 array[k] = R[j];
 j++;
 }
 k++;
 }
 while (i < n1) {
 array[k] = L[i];
 i++;
 k++;
 }
 while (j < n2) {
 array[k] = R[j];
 j++;
 k++;
 }
}






int busquedaLineal(double array[], int tam, double busquedaUsuario){
 for(int i = 0; i < tam; i++){
 if(array[i] == busquedaUsuario){
 return i;
 }
 }
 return -1;
}







void busquedaTransaccion(double array[], int tam, double valorTransaccion){
 cout << "El valor de la transaccion a buscar es de: $" << valorTransaccion <<
endl;
 if(busquedaLineal(array, tam, valorTransaccion) == -1){
 cout << "La transaccion a buscar no se encuentra ingresada." << endl;
 } else {
 cout << "Transaccion encontrada en la posicion: " <<
busquedaLineal(array, tam, valorTransaccion) << "." << endl;
 }
}









void escribirArchivo(double array[], double arrayDesordenado[], int tam, double
valorTransaccion){
 ofstream archivo2;
 archivo2.open("Ejercicio2.txt", ios::out);
 archivo2 << "Sus transacciones ingresadas: " << endl;
 for(int i = 0; i < tam; i++){
 archivo2 << "[$" << arrayDesordenado[i] << "]";
 }
 archivo2 << "Sus transacciones ordenadas: " << endl;
 for(int i = 0; i < tam; i++){
 archivo2 << "[$" << array[i] << "]";
 }
 archivo2 << "El valor de la transaccion a buscar es de: $" << valorTransaccion
<< endl;
 if(busquedaLineal(array, tam, valorTransaccion) == -1){
 archivo2 << "La transaccion a buscar no se encuentra ingresada." << endl;
 } else {
 archivo2 << "Transaccion encontrada en la posicion: " <<
busquedaLineal(array, tam, valorTransaccion) << "." << endl;
 }
}













void Datos(){
  fstream archivo;
 archivo.open("productos.txt",ios::out);
 archivo<<"\t***** DATOS DE LA SUCURSAL *****"<<endl;
 archivo<<"Codigo\t"<<"Nombre\t"<<" Ciudad\t"<<" Telefono";
 archivo<<"\nABC001\t"<<"AKI-Cuenca\t"<<"\tQuito\t"<<"\t 095644186";
 archivo<<"\n\n***** DATOS DEL PRODUCTO *****";
 archivo<<"\nNombre\t"<<" Precio\t"<<" Cantidad\t"<<" Estado\n";
 char nombre[30];
 float precio;
 int cantidad;
 char estado[30];
 string r;
 int n,m;
 float suma_precios=0,cant=0;
 do{
 cout<<"\nIngrese el nombre: ";
 cin>>nombre;
 cout<<"\nIngrese el precio del producto: ";
 cin>>precio;
 cout<<"\nIngrese la cantidad del producto: ";
 cin>>cantidad;
 cout<<"\nIngrese el estado del producto (bueno, malo): ";
 cin>>estado;

archivo<<nombre<<"\t\t\t\t"<<precio<<"\t\t\t\t"<<cantidad<<"\t\t\t\t\t"<<estado<<
endl;
 cout<<"Presione * para salir o cualquier letra para continuar ingresando productos...";
 cin>>r;
  cin.ignore();
 n= 1 + n;
 cant=cant+cantidad;

 suma_precios=precio*cantidad;
 suma_precios += suma_precios;
 }
 while(r!= "*");
 archivo<<"\n\nCantidad total del producto: "<<cant<<endl;
 archivo<<"cantidad de Productos Ingresados: "<<n<<endl;
 archivo<<"Valor total de productos: "<<suma_precios;
}

