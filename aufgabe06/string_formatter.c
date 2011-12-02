#include <string.h>
#include <stdio.h>
#include "string_formatter.h"

/* Booleandatentyp */
typedef enum
{
    FALSE,
    TRUE
}
BOOL;

/**
 * Analysiert einen String und gibt zurück wieviele einzelne Wörter (durch
 * Leerzeichen getrennt) vorhanden sind. Und auch die Gesamtanzahl aller
 * Zeichen ohne Leerzeichen werden zurück gegeben.
 *
 * @param p_line String
 * @param words Anzahl der Wörter
 * @param letters Anzahl der Buchstaben
 */
static void analyse_string (char *p_line,
                            unsigned int *words,
                            unsigned int *letters)
{
    BOOL read_word = FALSE; /* Liest gerade ein Wort */
    char *p_line_position = p_line; /* Position im String */

    *words = 0;
    *letters = 0;

    while (*p_line_position != '\0')
    {
        if (*p_line_position != ' ')
        {
            if (!read_word)
            {
                (*words)++;
                read_word = TRUE;
            }
            (*letters)++;
        }
        else
        {
            read_word = FALSE;
        }
        *p_line_position++;
    }
}
                            
extern void justify_line (char *p_line,
                          int target_line_length,
                          char *p_justified_line)
{
    unsigned int words; /* Anzahl der Wörter */
    unsigned int letters; /* Anzahl der Buchstaben */
    char *p_word; /* Zu kopierendes Wort */
    char *delim = " "; /* Trennzeichen für de Tokenizer */
    unsigned int total_spaces; /* Insgesamt Anzahl der Leerzeichen */
    unsigned int spaces_before_word; /* Leerzeichen die vor ein Wort kommen */
    signed int extra_spaces; /* Anzahl der Wörter die ein zustätzliches 
                                Leerzeichen erhalten */
    char *dest = p_justified_line; /* Position im String */

    analyse_string (p_line, &words, &letters);
    total_spaces = (unsigned int)target_line_length - letters;
    if (total_spaces && (words - 1) > 0)
    {
        spaces_before_word = total_spaces / (words - 1);
        extra_spaces = (signed int)total_spaces % (words - 1);
    }
    if (target_line_length <= letters + words - 1)
    {
        spaces_before_word = 1;
        extra_spaces = 0;
    }
    p_word = strtok (p_line, delim);
    while (p_word != NULL)
    {
        size_t word_length = strlen (p_word); /* Länge des momentanen Worts */
        memcpy (dest, p_word, word_length);
        dest += word_length;
        p_word = strtok (NULL, delim);
        if (p_word != NULL)
        {
            size_t space_length = spaces_before_word 
                + (extra_spaces > 0 ? 1 : 0); /* Leerzeichen die hinter das
                                                 Wort gepackt werden */
            memset (dest, ' ', space_length);
            dest += space_length;
            extra_spaces--;
        }
    }
    *dest = '\0';
}
