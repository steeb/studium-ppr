#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#ifdef FOOBAR
    #include <unistd.h>
#endif

/* Anzhal Spielfeld Zeilen */
#define ALL_ROWS 10
/* Anzahl Spielfeld Spalten */
#define ALL_COLUMNS 10

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

/* In dieser Variable wird die neue Generation erzeugt. */
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

/**
 * Errechnet zu der pos_nr im linearisierten Spielfeld die x,y Koordinaten im
 * Spielfeld.
 *
 * @param pos_nr Position im Spielfeld
 * @param x X-Koordinate
 * @param y Y-Koordinate
 */
void map_pos_to_coords (const unsigned int pos_nr,
                        unsigned int * x,
                        unsigned int * y)
{
    *x = pos_nr % ALL_ROWS;
    *y = pos_nr / ALL_ROWS;
}

/**
 * Errechner zu den x,y-Koordinanten, die echte Position im Speicher
 *
 * @param x X-Koordinate
 * @param y X-Koordinate
 * @param vec_pos Position im Vector
 * @param vec_bit_pos welches bit im Vector
 */
void map_coords_to_generation_array (const unsigned int x,
                                     const unsigned int y,
                                     unsigned int * vec_pos,
                                     unsigned char * vec_bit_pos)
{
    unsigned int pos_nr = ALL_ROWS * y + x;
    map_pos_to_generation_array (pos_nr, vec_pos, vec_bit_pos);
}

/**
 * Prüft ob es auf dem übergebenden Feld eine lebende Kreatur gibt
 *
 * @param x X-Achse, ausgehen von oben links
 * @param y y-Achse, ausgehen von oben links
 *
 * @return TRUE, fals eine Kreatur existiert
 */
BOOL is_creature_alive (const unsigned int x,
                        const unsigned int y)
{
    unsigned char mask;
    unsigned int vec_pos = 0;
    unsigned char vec_bit_pos = 0;

    map_coords_to_generation_array (x, y, &vec_pos, &vec_bit_pos);
    mask = (unsigned char)1 << vec_bit_pos;
    return (generation[vec_pos] & mask) == mask;
}

/**
 * Erzeugt in auf dem übergebenen Feld eine Kreatur
 *
 * @param x X-Achse, ausgehen von oben links
 * @param y y-Achse, ausgehen von oben links
 */
void create_creature (const unsigned int x,
                      const unsigned int y)
{
    unsigned int vec_pos = 0;
    unsigned char vec_bit_pos = 0;

    map_coords_to_generation_array (x, y, &vec_pos, &vec_bit_pos);
    next_generation[vec_pos] |= (unsigned char)1 << vec_bit_pos;
}

/**
 * Prüft von einem Spielfeld und einer Richtung ausgehen ob ein Nachbar
 * existiert.
 *
 * @param pos_nr liniarisierte Position des auszugehenden Feldes
 * @param direction Richtung in der gesucht werden soll
 *
 * @return TRUE, fals ein Nachbar existiert
 **/
BOOL is_neighbour_creature (const unsigned int pos_nr,
                            const DIRECTION direction)
{
    unsigned int x = 0;
    unsigned int y = 0;

    map_pos_to_coords (pos_nr, &x, &y);
    switch (direction)
    {
        case TOPLEFT:
            return (x <= 0 || y <= 0) 
                ? FALSE 
                : is_creature_alive (x - 1, y - 1);
            break;
        case TOP:
            return (y <= 0) 
                ? FALSE 
                : is_creature_alive (x, y - 1);
            break;
        case TOPRIGHT:
            return (x >= ALL_ROWS - 1 || y <= 0) 
                ? FALSE 
                : is_creature_alive (x + 1, y - 1);
            break;
        case RIGHT:
            return (x >= ALL_ROWS - 1) 
                ? FALSE
                : is_creature_alive (x + 1, y);
            break;
        case BOTTOMRIGHT:
            return (x >= ALL_ROWS - 1 || y >= ALL_COLUMNS - 1)
                ? FALSE
                : is_creature_alive (x + 1, y + 1);
            break;
        case BOTTOM:
            return (y >= ALL_COLUMNS - 1)
                ? FALSE
                : is_creature_alive (x, y + 1);
            break;
        case BOTTOMLEFT:
            return (x <= 0 || y > ALL_COLUMNS - 1)
                ? FALSE
                : is_creature_alive (x - 1, y + 1);
            break;
        case LEFT:
            return (x <= 0)
                ? FALSE
                : is_creature_alive (x - 1, y);
            break;
    }
}

/**
 * Zählt alle Nachbarn um einer Kreatur herum.
 *
 * @param pos_nr liniearisierte Position der zu untersuchenden Nachbarschaft
 *
 * @return Anzahl der Nachbarn
 **/
unsigned int count_neigtbour_creatures (const unsigned int pos_nr)
{
    DIRECTION direction;
    unsigned int creatures = 0;

    for (direction = TOPLEFT; direction <= LEFT; direction++)
    {
        if (is_neighbour_creature (pos_nr, direction))
        {
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

    for (i = 0; i < ALL_ROWS; i++)
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
    unsigned int x = 0;
    unsigned int y = 0;

    for (i = 0; i < CELLS; i++)
    {
        map_pos_to_coords (i, &x, &y);
        /* Sind auf der linken Seite des Spielfelds */
        if (x == 0)
        {
            print_horizontal_seperator ();
        }
        printf ("| %c ", is_creature_alive (x, y) ? 'o' : ' ');
        /* Sind auf der rechten Seite des Spielfelds */
        if (x == ALL_ROWS - 1)
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
 *
 * @param string Das Array in welches geschrieben werden soll.
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
 * Löscht den Speicher in der die nächste Generation entsteht
 */
void clear_next_generation (void)
{
    int i;

    for (i = 0; i < ARRAY_SIZE; i++)
    {
        next_generation[i] = 0;
    }
}

/**
 * Vergleicht die alte mit der neuen Generation.
 *
 * @return TRUE fals beide Generationen gleich sind.
 */
BOOL is_generation_equal (void)
{
    int i;

    for (i = 0; i < ARRAY_SIZE; i++)
    {
        if (generation[i] != next_generation[i]) 
        {
            return FALSE;
        }
    }
    return TRUE;
}

/**
 * Es wird die naechste Generation erzeugt.
 *
 * @return Wenn sich die Generation geaendert hat TRUE, sonst FALSE.
 */
BOOL set_next_generation (void)
{
    unsigned int i;
    BOOL generation_equal;

    clear_next_generation ();

    for (i = 0; i < CELLS; i++)
    {
        unsigned int creatures = count_neigtbour_creatures (i);
        unsigned int x = 0;
        unsigned int y = 0;

        map_pos_to_coords (i, &x, &y);
        if (is_creature_alive (x, y))
        {
            if (creatures == 2 || creatures == 3)
            {
                create_creature (x, y);
            }
        }
        else
        {
            if (creatures == 3)
            {
                create_creature (x, y);
            }
        }
    }
    
    /* Merken ob Generationen gleich waren und dann die alte mit der neuen
     * ueberschreien */
    generation_equal = is_generation_equal ();
    memcpy (&generation, &next_generation, sizeof(generation));

    return !generation_equal;
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
    system("clear"); 
    print_generation ();
    for (; max_generations > 0; max_generations--)
    {
        if (!set_next_generation ())
        {
            return;
        }
       #ifdef FOOBAR
        sleep (1);
       #endif
        system("clear");
        print_generation ();
    }
}


