#include <stdio.h>
#include "gol.c"

int main (void)
{
    char spielfeld[] = "00000000"
                       "00000000"
                       "00000000"
                       "00011100"
                       "00000000"
                       "00000000"
                       "00000000"
                       "00000000";
    char rueckgabe[CELLS + 1] = {0}; 
    set_generation_from_string (spielfeld);
    get_generation_as_string (rueckgabe);
    printf ("i: %s\no: %s\n", spielfeld, rueckgabe);
    print_generation ();
    set_next_generation ();
    print_generation ();
    return 0;
}
