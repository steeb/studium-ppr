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

typedef enum
{
    TOPLEFT,
    TOP,
    TOPRIGHT,
    RIGHT,
    BOTTOMRIGHT,
    BOTTOM,
    BOTTOMLEFT,
    LEFT
}
DIRECTION;

/* In dieser Variable wird die aktuelle Generation abgelegt */
unsigned char generation[ARRAY_SIZE];

unsigned char next_generation[ARRAY_SIZE];

/**
 * Errechnet zu der pos_nr im linearisierten Spielfeld die echte Position
 * im Speicher.
 *
 * @param pos_nr Position im Spielfeld
 * @param vec_pos Position im Vector
 * @param vec_bit_pos Welches bit im Vector
 */
void map_pos_to_generation_array (const unsigned int pos_nr, 
                                  unsigned int * vec_pos, 
                                  unsigned char * vec_bit_pos)
{
    *vec_pos = pos_nr / CHAR_BIT;
    *vec_bit_pos = pos_nr % CHAR_BIT;
}

void map_pos_to_coords (const unsigned int pos_nr,
                        unsigned int * x,
                        unsigned int * y)
{
    *x = pos_nr / ALL_COLUMNS;
    *y = pos_nr % ALL_ROWS;
}

void map_coords_to_generation_array (const unsigned int x,
                                     const unsigned int y,
                                     unsigned int * vec_pos,
                                     unsigned char * vec_bit_pos)
{
    unsigned int pos_nr = ALL_COLUMNS * x + y;
    map_pos_to_generation_array (pos_nr, vec_pos, vec_bit_pos);
}

BOOL is_creature (const unsigned int x,
                  const unsigned int y)
{
    unsigned char mask;
    unsigned int vec_pos = 0;
    unsigned char vec_bit_pos = 0;
    BOOL tmp;

    printf ("  check creature at %d x %d\n", x, y);
    map_coords_to_generation_array (x, y, &vec_pos, &vec_bit_pos);
    mask = (unsigned char)1 << vec_bit_pos;
    tmp = (generation[vec_pos] & mask) == mask;
    printf (         "%x & %x == %x = %x\n", generation[vec_pos], mask, mask, tmp);
    return tmp;
}

void kill_creature (const unsigned int x,
                    const unsigned int y)
{
    unsigned int vec_pos = 0;
    unsigned char vec_bit_pos = 0;

    map_coords_to_generation_array (x, y, &vec_pos, &vec_bit_pos);
    next_generation[vec_pos] = generation[vec_pos] 
        ^ ~((unsigned char)1 << vec_bit_pos);
}

void create_creature (const unsigned int x,
                      const unsigned int y)
{
    unsigned int vec_pos = 0;
    unsigned char vec_bit_pos = 0;

    map_coords_to_generation_array (x, y, &vec_pos, &vec_bit_pos);
    next_generation[vec_pos] = generation[vec_pos] 
        | (unsigned char)1 << vec_bit_pos;
}

BOOL is_neighbour_creature (const unsigned int pos_nr,
                            const DIRECTION direction)
{
    unsigned int x = 0;
    unsigned int y = 0;

    map_pos_to_coords (pos_nr, &x, &y);
    printf ("pos: %d: %d x %d -> %d\n", pos_nr, x, y, direction);
    switch (direction)
    {
        case TOPLEFT:
            return (x <= 0 || y <= 0) 
                ? FALSE 
                : is_creature (x - 1, y - 1);
            break;
        case TOP:
            return (y <= 0) 
                ? FALSE 
                : is_creature (x, y - 1);
            break;
        case TOPRIGHT:
            return (x >= ALL_ROWS - 1 || y <= 0) 
                ? FALSE 
                : is_creature (x + 1, y - 1);
            break;
        case RIGHT:
            return (x >= ALL_ROWS - 1) 
                ? FALSE
                : is_creature (x + 1, y);
            break;
        case BOTTOMRIGHT:
            return (x >= ALL_ROWS - 1 || y >= ALL_COLUMNS - 1)
                ? FALSE
                : is_creature (x + 1, y + 1);
            break;
        case BOTTOM:
            return (y >= ALL_COLUMNS - 1)
                ? FALSE
                : is_creature (x, y + 1);
            break;
        case BOTTOMLEFT:
            return (x <= 0 || y > ALL_COLUMNS - 1)
                ? FALSE
                : is_creature (x - 1, y + 1);
            break;
        case LEFT:
            return (x <= 0)
                ? FALSE
                : is_creature (x - 1, y);
            break;
    }
    return FALSE;
}

unsigned int count_neigtbour_creatures (const unsigned int pos_nr)
{
    DIRECTION direction;
    unsigned int creatures = 0;

    for (direction = TOPLEFT; direction < LEFT; direction++)
    {
        if (is_neighbour_creature (pos_nr, direction))
        {
            printf ("             #\n");
            creatures++;
        }
    }
    return creatures;
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
        if (vec_bit_pos == (unsigned char)CHAR_BIT - 1)
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
    unsigned int i;

    memcpy (&generation, &next_generation, sizeof(generation));

    for (i = 0; i < CELLS; i++)
    {
        unsigned int creatures = count_neigtbour_creatures (i);
        unsigned int x = 0;
        unsigned int y = 0;

        map_pos_to_coords (i, &x, &y);
        if (creatures == 2 || creatures == 3)
        {
            create_creature (x, y);
        }
        else
        {
            kill_creature (x, y);
        }
    }

    memcpy (&next_generation, &generation, sizeof(generation));

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

