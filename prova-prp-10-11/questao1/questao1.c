// Caroline Tews e Vinícius Kappke
#include <stdio.h>

void check(int *array)
{
    int total = 0;
    for (int i = 0; i < 10; i++)
    {
        if (array[i] > 50)
        {
            printf("O valor %d é maior que 50 e está na posição %d do vetor.\n", array[i], i);
            total++;
        }
    }

    if (total == 0)
    {
        printf("Nenhum valor maior que 50 foi digitado.\n");
    }
}

int main()
{
    int array[10];

    for (int i = 0; i < 10; i++)
    {
        printf("Digite um valor: ");
        scanf("%d", &array[i]);
    }

    check(array);
}