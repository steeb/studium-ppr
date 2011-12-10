/**
 * @file Dieses Modul realisiert einen binären Heap durch Arrays
 */

#ifndef _BINARY_HEAP_H
#define _BINARY_HEAP_N

typedef enum
{
    FALSE,
    TRUE
}
BOOL;

/**
 * initialisiert den Heap
 */
extern void heap_init (void);

/**
 * löscht den Heap 
 */
extern void heap_destroy (void);

/**
 * fügt ein Element in den Heap ein und hält seine Eigenschaften aufrecht
 *
 * @param element einzufügendes Element
 */
extern void heap_insert (char element);

/**
 * gibt das kleinste Element zurück.
 *
 * @param Adresse an der das Element geschrieben werden soll
 *
 * @return true, falls der heap leer ist.
 */
extern BOOL heap_extract_min (char *min_element);

/**
 * gibt den heap auf dem Bildschirm aus
 */
extern void heap_print (void);

#endif
