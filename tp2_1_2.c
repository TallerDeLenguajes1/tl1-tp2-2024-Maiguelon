#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int main()
{
    srand(time(NULL));

    int i;
    double vt[N];
    double *p_vt;
    p_vt = vt;

    for (i = 0; i < N; i++)
    {
        *(p_vt + i) = 1 + rand() % 100;
        printf("%.2f \n", *(p_vt + i));
    }

    return 0;
}