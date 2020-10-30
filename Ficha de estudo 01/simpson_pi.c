#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x)
{
    return sqrt(1 - x * x);
}

float simps(float menor, float maior, float intervalo)
{
    float h, sum1 = 0, sum2 = 0, sum, y0, yn;
    int i;
    h = (maior - menor) / intervalo;
    y0 = f(menor + 0 * h);
    yn = f(menor + intervalo * h);
    for (i = 1; i < intervalo; i++)
        if (i % 2 == 0)
            sum1 = sum1 + f(menor + i * h);
        else
            sum2 = sum2 + f(menor + i * h);
    sum = (h / 3) * (y0 + yn + 2 * sum1 + 4 * sum2);
    return sum;
}

int main()
{
    float Pi;
    Pi = 4 * simps(0, 1, 10);
    printf("Valor: %f", Pi);
    printf("\nPrecisao: %f", (Pi - M_PI));
    return 0;
}