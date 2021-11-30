#include <stdio.h>
int main()
{
    int r = 4, c = 4;
    int a[4][4] = {{0, 1, 2, 3},
                   {14, 25, 26, 27},
                   {8, 9, 10, 11},
                   {12, 13, 14, 15}};

    for (int i = 0; i < r-1; i++)
    {
        for (int j = 0; j < c-1; j++)
        {
            int sum = 0;
            for (int k = 0; k <= 1; k++)
            {
                for (int l = 0; l <= 1; l++)
                {
                    sum = sum + a[i + k][j + l];
                }
            }
            if (sum == 46)
            {
                for (int k = 0; k <= 1; k++)
                {
                    for (int l = 0; l <= 1; l++)
                    {
                        printf("%d ", a[i + k][j + l]);
                    }
                    printf("\n");
                }
            }
        }
    }
    return 0;
}