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
void mostrarCompus(compu *compus, int cantidad);
void masAntigua(compu *compus, int cantidad);
void masVeloz(compu *compus, int cantidad);
void liberarMemoria(compu *compus, int cantidad);

int main() {
    // preparo el tiempo
    srand(time(NULL));

    // pregunto cuantas compus y reservo la memoria según eso
    int cantidad;
    printf("Ingrese el numero de computadoras (1 a 5): ");
    scanf("%d", &cantidad);
    compu *computadoras =(compu *)malloc(sizeof(compu) * cantidad);

    // Relleno las compus
    compu *ptrCompu = computadoras; // puntero auxiliar
    for (int i = 0; i < cantidad; i++) {
        generarCompu(ptrCompu);
        ptrCompu++;
    }

    // Muestro las compus
    mostrarCompus(computadoras, cantidad);
    // Muestro la pc más antigua
    masAntigua(computadoras, cantidad);
    // Muestro la mas veloz
    masVeloz(computadoras, cantidad);

    // Libero la memoria
    liberarMemoria(computadoras, cantidad);
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

void mostrarCompus(compu *compus, int cantidad)
{
    compu *ptrCompu = compus;

    for (int i = 0; i < cantidad; i++) {
        printf("\nComputadora %d: \n", i + 1);
        printf("Velocidad: %d\n", ptrCompu->velocidad);
        printf("Anio: %d\n", ptrCompu->anio);
        printf("Cantidad: %d\n", ptrCompu->cantidad);
        printf("CPU: %s\n", ptrCompu->tipo_cpu);

        ptrCompu++;
    }
}

void masAntigua(compu *compus, int cantidad)
{
    compu *ptrCompu = compus;
    compu *masAntiqua = compus;

    for (int i = 0; i < cantidad; i++) {
        if (ptrCompu->anio < masAntiqua->anio) {
            masAntiqua = ptrCompu;
        }
        ptrCompu++;
    }

    printf("\nLa computadora mas Antiqua es:\n");
    mostrarCompus(masAntiqua, 1);
}

void masVeloz(compu *compus, int cantidad)
{
    compu *ptrCompu = compus;
    compu *fastest = compus;

    for (int i = 0; i < cantidad; i++)
    {
        if (ptrCompu->velocidad > fastest->velocidad) {
            fastest = ptrCompu;
        }
        ptrCompu++;
    }
    
    printf("\nLa computadora mas Veloz es:\n");
    mostrarCompus(fastest, 1);
}

void liberarMemoria(compu *compus, int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        free(compus[i].tipo_cpu);
    }
    free(compus);
}
