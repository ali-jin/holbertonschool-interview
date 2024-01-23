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
 * sum_sanpiles - sum of sandpiles
 * @grid1: first sandpile
 * @grid2: second sandpile
*/
void sum_sanpiles(int grid1[3][3], int grid2[3][3]) {
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
        
    }
}

/**
 * check_if_grid1_is_stable - check if grid1 is table
 * @grid1: first sandpile
 * @grid2: second sandpile
 * Return: returns 1 if stable. Otherwise 0.
*/
int check_if_grid1_is_stable(int grid1[3][3], int grid2[3][3]) {
    int stable = 1;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grid2[i][j] = grid1[i][j];
            if (grid1[i][j] > 3) {
                stable = 0;
            }
        }
    }

    return stable;
}

/**
 * toppling_round - iterate sandpile
 * @grid1: first sandpile
 * @grid2: second sandpile
*/
void toppling_round(int grid1[3][3], int grid2[3][3]) {

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid2[i][j] > 3) {
                if (i > 0)
                    grid1[i - 1][j] += 1;
                if (i < 2)
                    grid1[i + 1][j] += 1;
                if (j > 0)
                    grid1[i][j - 1] += 1;
                if (j < 2)
                    grid1[i][j + 1] += 1;
                grid1[i][j] -= 4;
            }
        }
    }
}

/**
 * sandpiles_sum - function that computes the sum of two sandpiles
 * @grid1: first sandpile
 * @grid2: second sandpile
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3]) {

    sum_sanpiles(grid1, grid2);
    while(!check_if_grid1_is_stable(grid1, grid2)) {
        print_grid(grid1);
        toppling_round(grid1, grid2);
    }
}
