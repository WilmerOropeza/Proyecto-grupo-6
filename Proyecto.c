#include<stdio.h> //libreria para entrada/salida
#include<string.h> //libreria para funciones de cadena
#include<time.h> //libreria para obtener la hora

//[100]:Maxima capacidad de vehiculos
//[10]:Tamaño de la placa(max. 9 caracteristicas)
char placas[100][10];
char hora_entrada[100][9];//[9]:Tamaño de la hora 

int contador_registro = 0; 

void limpiador_buffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }

}

