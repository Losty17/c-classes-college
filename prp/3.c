#include <stdio.h>

float increase(float value, float percentage)
{
    return value + (value * percentage / 100);
}

int main()
{
    float income;
    do 
    {
        printf("Salário atual R$ ");
        scanf("%f", &income);

        if (income <= 300) income = increase(income, 35);
        else income = increase(income, 15);

        printf("O novo salario eh R$ %.2f\n", income);
    } while (1 == 1);
}