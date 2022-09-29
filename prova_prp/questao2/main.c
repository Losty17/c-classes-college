/**
 * @file main.c
 * @authors Leonardo Mattos (131571), Vinícius Kappke (71254)
 * @date 2022-09-29
 */
#include <stdio.h>

int calcRenda()
{
    int rendaPessoal = -1;
    int rendaFamiliar = -1;
    int count = 0;

    while (rendaPessoal != 0)
    {
        printf("Digite a renda pessoal: ");
        scanf("%d", &rendaPessoal);

        if (rendaPessoal == 0)
            break;

        printf("Digite a renda familiar: ");
        scanf("%d", &rendaFamiliar);

        if (rendaPessoal > rendaFamiliar)
            count++;
    }
    return count;
}

int main()
{
    int calc = calcRenda();
    printf("Quantidade de alunos que possuem renda pessoal maior que a renda familiar: %d\n", calc);
}