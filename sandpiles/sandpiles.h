#ifndef SANDPILES_H
#define SANDPILES_H
#include <stdlib.h>
#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void toppling_round(int grid1[3][3], int grid2[3][3]);
int check_if_grid1_is_stable(int grid1[3][3], int grid2[3][3]);

#endif
