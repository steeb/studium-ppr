#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/* Anzhal Spielfeld Zeilen */
#define ALL_ROWS 8 
/* Anzahl Spielfeld Spalten */
#define ALL_COLUMNS 8 

/* Anzahl aller Felder des Spielfelds */
#define CELLS ALL_ROWS * ALL_COLUMNS

/* Groesse des Arrays um alle Felder drin ablegen zu koennen */
#define ARRAY_SIZE (CELLS / CHAR_BIT) + (CELLS % CHAR_BIT == 0 ? 0 : 1)

/* Boolean Datentyp */
typedef enum
{
    FALSE,
    TRUE
}
BOOL;

/* In dieser Variable wird die aktuelle Generation abgelegt */
unsigned char generation[ARRAY_SIZE];

/**
 *
 */
void map_pos_to_generation_array (const unsigned int pos_nr, unsigned int *vec_pos, 
                                  unsigned char *vec_bit_pos)
{
    *vec_pos = (pos_nr / CHAR_BIT);
    *vec_bit_pos = (pos_nr % CHAR_BIT);
}

/**
 * Gibt eine Seperatorzeile für Begrenzung der einzelenen Zeilen aus.
 */
void print_horizontal_seperator (void)
{
    int i; /* Laufvariable für die Länge der Zeile */

    for (i = 0; i < ALL_COLUMNS; i++)
    {
        printf ("+---");
    }
    printf ("+\n");
}

/**
 * Gibt die aktuelle Generation grafisch auf der Konsole aus.
 */
void print_generation (void)
{
    unsigned int i;
    unsigned char mask;
    unsigned int vec_pos = 0;
    unsigned char vec_bit_pos = 0;

    for (i = 0; i < CELLS; i++)
    {
        map_pos_to_generation_array (i, &vec_pos, &vec_bit_pos);
        if (vec_bit_pos == 0)
        {
            print_horizontal_seperator ();
        }
        mask = (unsigned char)1 << vec_bit_pos;
        printf ("| %c ", (generation[vec_pos] & mask) == mask ? 'o' : ' ');
        if (vec_bit_pos == (unsigned int)CHAR_BIT - 1)
        {
            printf ("|\n");
        }
    }
    print_horizontal_seperator ();
}

/**
 * Über die Zeichenkette lässt sich eine Anfangsgeneration bestimmen.
 *
 * @param string liniearisierte Anfangsgeneration
 */
void set_generation_from_string (char string[])
{
    unsigned int i;
    unsigned int vec_pos = 0;
    unsigned char vec_bit_pos = 0;

    for (i = 0; i < CELLS; i++)
    {
        map_pos_to_generation_array (i, &vec_pos, &vec_bit_pos);
        generation[vec_pos] |= (string[i] - '0') << vec_bit_pos;
    }
}

/**
 * Schreibt die momentane Generation in die die uebergebene Variable.
 */
void get_generation_as_string (char string[])
{
    unsigned int i;
    unsigned int vec_pos = 0;
    unsigned char vec_bit_pos = 0;
    unsigned char mask;

    for (i = 0; i < CELLS; i++)
    {
        map_pos_to_generation_array (i, &vec_pos, &vec_bit_pos);
        mask = (unsigned char)1 << vec_bit_pos;
        string[i] = (generation[vec_pos] & mask) == mask ? '1' : '0';
    }
    string[i] = '\0';
}

/**
 * Es wird die naechste Generation erzeugt.
 *
 * @return Wenn sich die Generation geaendert hat TRUE, sonst FALSE.
 */
BOOL set_next_generation (void)
{
    return FALSE;
}

/**
 * Berechnet solange Generationen und gibt sie auf dem Bildschirm aus, bis die
 * Anzahl von max_generations erreicht wurde oder sich die Generationen nicht
 * mehr aendern.
 *
 * @param max_generations Die maximale Anzahl an Generationen die berechnet
 *                        werden.
 */
void game_of_life (int max_generations)
{

}

/* system("echo -e \"\\E[2J\""); */

