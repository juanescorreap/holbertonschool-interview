#include <stdlib.h>
#include <stdio.h>
#include "sandpiles.h"
/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * sandpiles_sum - Function that computes the sum of two sandpiles
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;
    int processAgain = 1;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] = grid1[i][j] + grid2[i][j];
        }
    }
    while (processAgain == 1)
    {
        processAgain = 0;

        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (grid1[i][j] >= 4)
                {
                    if (i - 1 >= 0)
                    {
                        grid1[i - 1][j] += 1;
                        if (grid1[i - 1][j] >= 4)
                        {
                            processAgain = 1;
                        }
                    }
                    if (i + 1 < 3)
                    {
                        grid1[i + 1][j] += 1;
                        if (grid1[i + 1][j] >= 4)
                        {
                            processAgain = 1;
                        }
                    }
                    if (j - 1 >= 0)
                    {
                        grid1[i][j - 1] += 1;
                        if (grid1[i][j - 1] >= 4)
                        {
                            processAgain = 1;
                        }
                    }
                    if (j + 1 < 3)
                    {
                        grid1[i][j + 1] += 1;
                        if (grid1[i][j + 1] >= 4)
                        {
                            processAgain = 1;
                        }
                    }
                    grid1[i][j] -= 4;
                    if (grid1[i][j] >= 4)
                    {
                        processAgain = 1;
                    }


                }
            }
        }
    }
}