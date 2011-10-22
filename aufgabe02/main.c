#include <stdio.h>
#include "ulam.c"

int main(void)
{
    printf ("Max: %d\n", ulam_max (7) );
    printf ("Twins: %d\n", ulam_twins (6) );
    printf ("Multiple: %d\n", ulam_multiples (0, 3) );
    return 0;
}
