#include <stdio.h>
#include "gol.c"

int main (void)
{
    char spielfeld[] = "000000"
                       "111111"
                       "000000"
                       "111111"
                       "000000";
    char rueckgabe[CELLS + 1];
    set_generation_from_string (spielfeld);
    get_generation_as_string (rueckgabe);
    printf ("%s", rueckgabe);
    return 0;
}
