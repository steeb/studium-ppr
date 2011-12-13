#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "binary_heap.h"

int main (void)
{
    int i;
    char outOld;
    char out;
    BOOL allesJut;
    srand (time (NULL));
    heap_init ();

    for (i = 0; i < 10; i++)
    {
        heap_insert ( (26 * (rand () / (RAND_MAX + 1.0))) + 97);
    }

    heap_print ();

    heap_extract_min (&outOld);
    allesJut = heap_extract_min (&out);
    while (allesJut) 
    {
        printf ("\n  %c <= %c\n", outOld, out);
        if (outOld <= out)
        {
            outOld = out;
            allesJut = heap_extract_min (&out);
        }
        else
        {
            printf ("\n\tFUCK\n");
            allesJut = FALSE;
        }
    }

}
