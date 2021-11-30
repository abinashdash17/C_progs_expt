#include <stdio.h>
#include <stdlib.h>

void print_mat(int **x, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", x[i][j]);
        }
        printf("\n");
    }
}

void rotate_mat(int **x, int r, int c)
{
    print_mat(x, r, c);
    for (int i = 0; i < r; i++)
    {
        for (int j = i + 1; j < c; j++)
        {
            // printf("%d%d", i + 1, j + 1);
            int temp = x[i][j];
            x[i][j] = x[j][i];
            x[j][i] = temp;
        }
    }
    printf("after transpose\n");
    print_mat(x, r, c);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c / 2; j++)
        {
            int temp = x[i][j];
            x[i][j] = x[i][c - 1 - j];
            x[i][c - 1 - j] = temp;
        }
    }
    printf("after mirroring\n");
    print_mat(x, r, c);
}

int main()
{
    int n = 9;
    int rows = n, cols = n;
    int **x;
    x = malloc(rows * sizeof *x);
    for (int i = 0; i < rows; i++)
    {
        x[i] = malloc(cols * sizeof *x[i]);
    }
    // int x[4][4];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            x[i][j] = 10 * (i + 1) + (j + 1);
        }
    }
    rotate_mat(x, rows, cols);
}