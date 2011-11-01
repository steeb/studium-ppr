#include <stdio.h>
#include <stdlib.h>

#define ALL_ROWS    10
#define ALL COLUMNS 10

/* Boolean Datentyp */
typedef enum
{
    FALSE,
    TRUE
}
BOOL;

/* In dieser Variable wird die aktuelle Generation abgelegt */
unsigned int generation;

/**
 * Gibt die aktuelle Generation grafisch auf der Konsole aus.
 */
void print_generation (void)
{

}

/**
 * Über die Zeichenkette lässt sich eine Anfangsgeneration bestimmen.
 *
 * @param string liniearisierte Anfangsgeneration
 */
void set_generation_from_string (char string[])
{

}

/**
 * Schreibt die momentane Generation in die die uebergebene Variable.
 */
void get_generation_as_string (char string[])
{

}

/**
 * Es wird die naechste Generation erzeugt.
 *
 * @return Wenn sich die Generation geaendert hat TRUE, sonst FALSE.
 */
BOOL set_next_generation (void)
{

}

/**
 * Berechnet solange Generationen und gibt sie auf dem Bildschirm aus, bis die
 * Anzahl von max_generations erreicht wurde oder sich die Generationen nicht
 * mehr aendern.
 *
 * @param max_generations Die maximale Anzahl an Generationen die berechnet
 *                        werden.
 */
void game_of_lifei (int max_generations)
{

}

/* system("echo -e \"\\E[2J\""); */

