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
 * gibt den Baum rekursiv aus
 *
 * @param pos startposition von dem an der Baum ausgegeben werden soll
 * @param depth tiefe auf der man sich gerade befindet
 */
static void heap_print_reku (unsigned int pos, unsigned int depth);


extern void heap_init (void)
{
    root_element = malloc (sizeof (char) * ALLOCSIZE);
    if (root_element == NULL)
    {
        fprintf (stderr, "error while allocating: %s", strerror (errno));
        exit (EXIT_FAILURE);
    }
    size = 0;
}

extern void heap_destroy (void)
{
    free (root_element);
    root_element = NULL;
}

extern void heap_insert (char element)
{
    unsigned int parent_pos;
    unsigned int insert_pos;
    if (size != 0 && size % ALLOCSIZE == 0)
    {
        root_element = realloc (root_element, sizeof (char) * (size + ALLOCSIZE));
        if (root_element == NULL)
        {
            fprintf (stderr, "error while allocating: %s", strerror (errno));
            exit (EXIT_FAILURE);
        }
    }
    /* element ans ende des baums einfügen */
    root_element[size] = element;
    size++;
    /* rechnen mit array index + 1, weils einfach ist */
    insert_pos = size;
    /* Wenn nur ein Element im Baum ist, muss nicht sortiert werden */
    if (size == 1)
    {
        return;
    }
    /* heapify */
    parent_pos = insert_pos / 2;
    while (parent_pos != 0)
    {
        if (root_element[insert_pos - 1] < root_element[parent_pos - 1])
        {
            char tmp = root_element[insert_pos - 1];
            root_element[insert_pos - 1] = root_element[parent_pos -1];
            root_element[parent_pos - 1] = tmp;
        }
        insert_pos = parent_pos;
        parent_pos /= 2;
    }
}

extern BOOL heap_extract_min (char *min_element)
{
    unsigned int parent_pos;
    unsigned int smallest;
    if (size == 0)
    {
        return FALSE;
    }
    /* das kleinste element ist das oberste */
    *min_element = *root_element;
    /* letzes element nach oben schieben */
    *root_element = root_element[size - 1];
    size--;
    if (size % ALLOCSIZE == 0)
    {
        root_element = realloc (root_element, sizeof (char) * size);
    }
    /* heapify */
    parent_pos = 1;
    smallest = parent_pos;
    while (parent_pos <= size) {
        /* linken zweig prüfen */
        if (parent_pos * 2 <= size 
                && root_element[parent_pos * 2 - 1] < root_element[parent_pos - 1])
        {
            smallest = parent_pos * 2;
        }
        /* rechten zweig prüfen */
        if (parent_pos * 2 + 1<= size 
                && root_element[parent_pos * 2] < root_element[smallest - 1])
        {
            smallest = parent_pos * 2 + 1;
        }
        if (smallest != parent_pos)
        {
            char tmp = root_element[parent_pos - 1];
            root_element[parent_pos - 1] = root_element[smallest - 1];
            root_element[smallest - 1] = tmp;
        }
        else
        {
            return TRUE;
        }
        parent_pos = smallest;
    }
    return TRUE;
}

extern void heap_print (void)
{
    if (size != 0)
    {
        heap_print_reku (1, 0);
    }
}

static void heap_print_reku (unsigned int pos, unsigned int depth)
{
    unsigned int i;
    for (i = 0; i < depth; i++)
    {
        printf ("    ");
    }
    printf ("|-- %c\n", root_element[pos - 1]);
    depth++;
    if (pos * 2 <= size)
    {
        heap_print_reku (pos * 2, depth);
    }
    if (pos * 2 + 1 <= size)
    {
        heap_print_reku (pos * 2 + 1, depth);
    }
}

