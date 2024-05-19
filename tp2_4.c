// Nota: No me queda claro si deben generarse valores automáticamente o si debo preguntar, asumo lo primero y procedo de esa forma

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct compu {
    int velocidad; // entre 1 y 3 GHz
    int anio; // Entre 2015 y 2023
    int cantidad; // entre 1 y 8
    char *tipo_cpu; // valores del arreglo "tipos"
} compu;

char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

// Declaración de funciones
void generarCompu(compu *compu);
void mostrarCompus(compu *compu);
void masAntigua(compu *compu);
void masVeloz(compu *compu);

int main() {
    // preparo el tiempo
    srand(time(NULL));

    // pregunto cuantas compus y reservo la memoria según eso
    int cantidad;
    printf("Ingrese el número de computadoras (1 a 5): ");
    scanf("%d", &cantidad);
    compu *computadoras =(compu *)malloc(sizeof(compu) * cantidad);

    // Relleno las compus
    compu *ptrCompu = computadoras; // puntero auxiliar
    for (int i = 0; i < cantidad - 1; i++) {
        generarCompu(ptrCompu);
        ptrCompu++;
    }

    
}

void generarCompu(compu *compu)
{
    compu->velocidad = rand() %3 + 1;
    compu->anio = rand() %9 + 2015;
    compu->cantidad = rand() %9;
    // reservo memoria para el texto, genero el orden y relleno
    compu->tipo_cpu =(char *)malloc(sizeof(char) * 15);
    int cpu = rand() %6;
    strcpy(compu->tipo_cpu, tipos[cpu]);
}

