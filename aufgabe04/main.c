#include <stdio.h>
#include "gol.c"

int main (void)
{
    char spielfeld[] = "1010"
                       "0100"
                       "1010"
                       "0000";
    char rueckgabe[CELLS + 1] = {0};
    unsigned int a;
    unsigned char b;

    set_generation_from_string (spielfeld);
    game_of_life (20);
    

    return 0;
}
