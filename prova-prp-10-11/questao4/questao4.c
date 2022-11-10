// Caroline Tews e Vinícius Kappke
#include <stdio.h>

int sum_diagonal(int matrix[3][3])
{
    int sum = 0;
    for (int i = 0; i < 3; i++)
        sum += matrix[i][i];

    return sum;
}

int main()
{
    int matrix1[3][3];
    int matrix2[3][3];
    int matrix3[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Digite um valor para a linha %d e coluna %d da matriz A: ", i + 1, j + 1);
            scanf("%d", &matrix1[i][j]);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Digite um valor para a linha %d e coluna %d da matriz B: ", i + 1, j + 1);
            scanf("%d", &matrix2[i][j]);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Digite um valor para a linha %d e coluna %d da matriz C: ", i + 1, j + 1);
            scanf("%d", &matrix3[i][j]);
        }
    }

    printf("Soma da diagonal principal da matriz A: %d\n", sum_diagonal(matrix1));
    printf("Soma da diagonal principal da matriz B: %d\n", sum_diagonal(matrix2));
    printf("Soma da diagonal principal da matriz C: %d\n", sum_diagonal(matrix3));
}