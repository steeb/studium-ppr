#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "binary_heap.h"

/* Größe des Speichers die auf einmal allociert wird */
#define ALLOCSIZE 5


/* oberstes Element des Heaps */
static char *root_element; 

/* größe des Heaps */
static unsigned int size; 


/**
 * stellt die Eigenschaften des Heaps wieder her
 */
static void heapify (void);


extern void heap_init (void)
{
    root_element = malloc (sizeof (char) * ALLOCSIZE);
    if (root_element == NULL)
    {
        fprintf (stderr, "error while allocating: %s", strerror (errno));
        exit (EXIT_FAILURE);
    }
}

extern void heap_destroy (void)
{
    free (root_element);
    root_element = NULL;
}

extern void heap_insert (char element)
{
    if (size % ALLOCSIZE == 0)
    {
        root_element = realloc (root_element, sizeof (char) * (size + ALLOCSIZE));
        if (root_element == NULL)
        {
            fprintf (stderr, "error while allocating: %s", strerror (errno));
            exit (EXIT_FAILURE);
        }
    }
    /*TODO element einfügen */
}

extern BOOL heap_extract_min (char *min_element)
{
    
}

extern void heap_print (void)
{

}

static void heapifiy (void)
{

}

