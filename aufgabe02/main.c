/**
 * @mainpage Collatz-Problem
 *
 * @file Ruft ULAM-Funktionen auf
 *
 * @author Stefan 'steeb' Ebert
 * @date 2011-10-22
 */

#include <stdio.h>
#include "ulam.c"

/**
 * Ein paar Tests
 *
 * @return 0
 */
int main(void)
{
    printf ("ulam_max (-5): %d | -1\n", ulam_max (-5) );
    printf ("ulam_max (0): %d | -1\n", ulam_max (0) );
    printf ("ulam_max (1): %d | 1\n", ulam_max (1) );
    printf ("ulam_max (2): %d | 2\n", ulam_max (2) );
    printf ("ulam_max (4): %d | 4\n", ulam_max (4) );
    printf ("ulam_twins (10): %d | 5\n", ulam_twins (10) );
    printf ("ulam_twins (5): %d | -1\n", ulam_twins (5) );
    printf ("ulam_multiple (10, 2): %d | 5\n", ulam_multiples (10, 2) );
    printf ("ulam_multiple (1000, 3): %d | 972\n", ulam_multiples (1000, 3) );
    printf ("ulam_multiple (108, 3): %d | -1\n", ulam_multiples (108, 3) );
    printf ("ulam_multiple (391, 6): %d | 386\n", ulam_multiples (391, 6) );
    return 0;
}
