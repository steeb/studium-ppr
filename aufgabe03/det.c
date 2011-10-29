/**
 * @file Berechnet Determinanten zu quadratischen Matrizen und kann diese
 * ausgeben
 *
 * @author steeb
 * @date 2011-10-29
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

/**
 * Berechnet die Determinante einer quadratischen Matrix
 *
 * @param matrix - Matrix zu der die Determinante berechnet werden soll
 * @param size - Groesse der Matrix
 *
 * @return Determinante der Matrix oder im Fehlerfall 0.0
 */
double get_determinant (double matrix[MAX_SIZE][MAX_SIZE], int size)
{
    if (size < 1 || size > MAX_SIZE)
    {
        printf ("Size Parameter falsch");
        return 0.0;
    }
    else if (size == 1)
    {
        return matrix[0][0];
    }
    else if (size == 2)
    {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    else
    {
        double det = 0; /* Ausgerechnete Determinante */
        double matrix2[MAX_SIZE][MAX_SIZE]; /* Untermatrix */
        int p; /* Laufvariable für die Laplaceformel */
        int i; /* Laufvariable um horizontal über die Matrix zu laufen */
        int j; /* Laufvariable um vertikal über die Matrix zu laufen */
        int h; /* Laufvariable um horizontal über die Untermatrix zu laufen */
        int k; /* Laufvariable um vertikal über die Untermatrix zu laufen */

        for (p = 0; p < size; p++)
        {
            h = 0;
            k = 0;
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

/**
 * Gibt die üebergebene Matrix auf der stdout aus. Die Zahlen werden mit einer
 * Nachkommastelle ausgegeben.
 *
 * @param matrix - Matrix die ausgegeben werden soll
 * @param size - Größe der Matrix 
 */
void print_matrix (double matrix[MAX_SIZE][MAX_SIZE], int size)
{
    int i; /* horizontale Laufvariable */
    int j; /* vertikale Laufvariable */

    if (size < 0 || size > MAX_SIZE )
    {
        printf ("size Paramter flasch");
        return;
    }

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf ("%3.1f ", matrix[i][j]);
        }
        printf ("\n");
    }
}
