// Caroline Tews e Vinícius Kappke
#include <stdio.h>
#include <stdlib.h>

void distribute(int arr[18], int matrix[3][6])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 6; j++)
            matrix[i][j] = arr[i * 6 + j];
}

void print_matrix(int matrix[3][6])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int arr[18] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
    int matrix[3][6];
    
    distribute(arr, matrix);
    print_matrix(matrix);
}