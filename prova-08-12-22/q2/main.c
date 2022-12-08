#include <stdio.h>
#define SIZE 5

int calc_qty_shoes_below_hundred(int shoes[])
{
    int qty = 0;
    for (int i = 0; i < SIZE; i++)
        if (shoes[i] < 100) qty++;

    return qty;
}

int main()
{
    int shoes[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        printf("Valor do sapato: ");
        scanf("%d", &shoes[i]);
    }

    printf("Quantidade de sapatos abaixo de 100 reais: %d\n", calc_qty_shoes_below_hundred(shoes));
}