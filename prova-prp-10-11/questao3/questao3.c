#include <stdio.h>
#include <stdbool.h>
#define SIZE 9

bool verify_column(int sudoku[SIZE][SIZE], int col)
{
    int count[SIZE] = {0};

    for (int i = 0; i < SIZE; i++)
        count[sudoku[i][col]]++;

    for (int i = 1; i < SIZE; i++)
        if (count[i] != 1)
            return false;

    return true;
}

bool verify_row(int row[SIZE])
{
    for (int i = 0; i < SIZE; i++)
        for (int j = i + 1; j < SIZE; j++)
            if (row[i] == row[j])
                return false;

    return true;
}

bool verify_quadrant(int sudoku[SIZE][SIZE], int row, int col)
{
    int count[SIZE] = {0};

    for (int i = row; i < row + 3; i++)
        for (int j = col; j < col + 3; j++)
            count[sudoku[i][j]]++;

    for (int i = 1; i < SIZE; i++)
        if (count[i] != 1)
            return false;

    return true;
}

bool is_valid_game(int sudoku[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        if (!verify_row(sudoku[i]))
            return false;
        if (!verify_column(sudoku, i))
            return false;
        if (!verify_quadrant(sudoku, i / 3 * 3, i % 3 * 3))
            return false;
    }

    return true;
}

int main()
{
    int sudoku[9][9] = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9}};

    printf("O sudoku fornecido eh %s\n", is_valid_game(sudoku) ? "valido" : "invalido");
}
