#include <stdio.h>
#include "gol.c"

int main (void)
{
    char spielfeld[] = "010"
                       "000"
                       "000";
    char rueckgabe[CELLS + 1] = {0}; 

    set_generation_from_string (spielfeld);
    /*/print_generation ();
    set_next_generation ();
    print_generation ();*/
    printf ("%d\n", count_neigtbour_creatures(4));
    return 0;
}
