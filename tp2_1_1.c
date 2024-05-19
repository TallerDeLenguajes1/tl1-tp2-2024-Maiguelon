#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// codigo a completar
#define N 20
int main() 
{
    srand(time(NULL)); 

    double vt[N];

    for (int i = 0; i < N; i++)
    {
        vt[i] = (double)(rand() % 100) + 1;
        printf("%.2lf\n", vt[i]);
    } 
}