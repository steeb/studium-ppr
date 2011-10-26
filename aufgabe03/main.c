#include <stdio.h>
#include "det.c"

int main (void)
{
    double matrix[][MAX_SIZE] = 
    {
        {1.0, 0.0, 3.0, 4.0},
        {-2.0, 1.0, 0.0, 3.0},
        {2.0, 8.0, 2.0, 10.0},
        {0.0, 1.0, 1.0, 0.0},
    };
    print_matrix (matrix, 4);
    printf ("%f\n", get_determinant (matrix, 4));
    return 0;
}
