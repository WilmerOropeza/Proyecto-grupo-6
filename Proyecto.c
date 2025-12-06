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

void registrar_entrada() { 
    if (contador_registro >= 100){
        printf("Error: El registro de vehiulo esta lleno.\n");
        return;
    
}
printf("\n--- Registro de entrada ---\n");

printf ("Ingrese la placa del vehiculo (max. 9 caracteres): ");
if (scanf("%9s", placas[contador_registro]) != 1) {
    limpiador_buffer();
    printf("Error al leer la placa.\n");
    return;

}

time_t tiempo_actual;
struct tm *info_tiempo;

tiempo_actual = time(NULL);
info_tiempo = localtime(&tiempo_actual);

strftime(hora_entrada[contador_registro], 
    9, 
    "%H:%M:%S", 
    info_tiempo);

printf("Vehículo con placa **%s** registrado a la hora: **%s**\n", 
        placas[contador_registro], 
        hora_entrada[contador_registro]);

contador_registro++;
    
    limpiar_buffer();
}

void mostrar_registro(){
    printf("\n--- Vehículos Registrados (%d) ---\n", contador_registro);
    if (contador_registro == 0) {
        printf("No hay vehículos registrados.\n");
        return;
}

printf("%-10s | %s\n", "PLACA", "HORA DE ENTRADA");
    printf("-----------|----------------\n");

    // Recorrido con ciclo 'for'
    for (int i = 0; i < contador_registro; i++) {
        printf("%-10s | %s\n", placas[i], hora_entrada[i]);
    }
}

int main(){
    int opcion;

do {
    printf("\n==================================\n");
    printf("SISTEMA DE REGISTRO DE VEHÍCULOS\n");
    printf("==================================\n");
    printf("1. Registrar Entrada de Vehiculo\n");
    printf("2. Mostrar Todos los Registros\n");
    printf("3. Salir\n");
    printf("Selecione una opcion: ");

    if (scanf("%d", &opcion) != 1) {
            opcion = 0; 
        }
        
        limpiar_buffer(); 

        // Estructura switch (similar a if-else anidado)
        switch (opcion) {
            case 1:
                registrar_entrada();
                break;
            case 2:
                mostrar_registros();
                break;
            case 3: 
                printf("\nSaliendo del sistema.");
                break; 
            default:
                printf("\nOpción no válida. Intente de nuevo.\n");
        }

    }while (opcion !=3);
    
    return 0;
}
