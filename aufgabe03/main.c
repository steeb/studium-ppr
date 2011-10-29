/**
 * @mainpage Determinanten Berechnung
 *
 * Rumspielen mit Determinantenberechnung
 *
 *
 * @author steeb
 * @date 2011-10-29
 */

#include <stdio.h>
#include "det.c"

/** 
 * funktionen testen
 */
int main (void)
{
    double matrix[][MAX_SIZE] = 
    {
        {1.0, 0.0, 3.0, 4.0},
        {-2.0, 1.0, 0.0, 3.0},
        {2.0, 8.0, 2.0, 10.0},
        {0.0, 1.0, 1.0, 0.0},
    };
    double matrix_sarah[][MAX_SIZE] =
    {
        {-5.0, -4.0, 0.0, -5.0},
        {-3.0, -1.0, 4.0, 4.0},
        {-5.0, 2.0, -5.0, -4.0},
        {-1.0, -4.0, 3.0, -3.0},
    };
    print_matrix (matrix, 4);
    printf ("%f\n", get_determinant (matrix_sarah, 4));
    return 0;
}
