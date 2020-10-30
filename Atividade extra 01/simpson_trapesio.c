#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x)
{
    return 10 * x - x * x;
}

float simps(float menor, float maior, float intervalo)
{
    float sum = 0, h;
    int i;
    h = (maior - menor) / intervalo;

    for (int i = 1; i < intervalo; i++)
    {
        sum += f(menor) + f(menor + h);
        menor += h;
    }
    sum *= h / 2;
    return sum;
}

int main()
{
    float result;
    result = simps(0, 10, 5);
    printf("Valor: %f", result);
    return 0;
}