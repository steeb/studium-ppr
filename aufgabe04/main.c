#include <stdio.h>
#include "gol.c"

#define FOOBAR

int main (void)
{
    char spielfeld[] = "1010"
                       "0100"
                       "1010"
                       "0000";

    set_generation_from_string (spielfeld);
    game_of_life (20);
    

    return 0;
}
