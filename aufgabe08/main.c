#include <stdio.h>
#include "binary_heap.h"

int main (void)
{
    char a;
    heap_init ();
    heap_insert ('0');
    heap_insert ('3');
    heap_insert ('2');
    heap_insert ('1');
    heap_insert ('4');
    heap_insert ('5');
    heap_insert ('6');
    heap_insert ('7');
    heap_insert ('8');
    heap_insert ('9');
    heap_print ();
    heap_extract_min (&a);
    do
    {
        printf ("\n--------------------\nremove: %c\n", a);
        heap_print ();
    } while (heap_extract_min (&a));
    heap_destroy ();
}
