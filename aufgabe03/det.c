#include <string.h>
#include <stdio.h>

#define MAX_SIZE 10

double get_determinant (double matrix[MAX_SIZE][MAX_SIZE], int size)
{
    if (size == 1)
    {
        return matrix[0][0];
    }
    else if (size == 2)
    {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    else
    {
        double det = 0;
        double matrix2[MAX_SIZE][MAX_SIZE]; 
        int i;
        int j;
        int p;

        for (p = 0; p < size; p++)
        {
            int h = 0;
            int k = 0;
            for (i = 1; i < size; i++)
            {
                for (j = 0; j < size; j++)
                {
                    if (j != p)
                    {
                        matrix2[h][k] = matrix[i][j];
                        k++;
                        if (k == size - 1)
                        {
                            h++;
                            k = 0;
                        }
                    }
                }
            }
            det += (p % 2 == 0 ? 1 : -1) * matrix[0][p] * get_determinant(matrix2, size - 1); 
        }
        return det;
    }
}
