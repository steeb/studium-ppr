#include <stdio.h>
#include "ulam.c"

int main(void)
{
    printf ("ulam_max (5): %d | 16\n", ulam_max (5) );
    printf ("ulam_max (7): %d | 52\n", ulam_max (7) );
    printf ("ulam_twins (10): %d | 5\n", ulam_twins (10) );
    printf ("ulam_twins (5): %d | -1\n", ulam_twins (5) );
    printf ("ulam_multiple (10, 2): %d | 5\n", ulam_multiples (10, 2) );
    printf ("ulam_multiple (1000, 3): %d | 972\n", ulam_multiples (1000, 3) );
    printf ("ulam_multiple (108, 3): %d | -1\n", ulam_multiples (108, 3) );
    printf ("ulam_multiple (391, 6): %d | 386\n", ulam_multiples (391, 6) );
    return 0;
}
