#include <string.h>
#include <stdio.h>
#include "string_formatter.h"

typedef enum
{
    FALSE,
    TRUE
}
BOOL;

static void analyse_string (char *p_line,
                            unsigned int *words,
                            unsigned int *letters)
{
    BOOL read_word = FALSE;
    char *p_line_position = p_line;

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
    unsigned int words;
    unsigned int letters;
    char *p_word;
    char *delim = " ";
    unsigned int total_spaces;
    unsigned int spaces_before_word;
    signed int extra_spaces;
    char *dest = p_justified_line;

    analyse_string (p_line, &words, &letters);
    total_spaces = target_line_length - letters;
    if (total_spaces && (words - 1) > 0)
    {
        spaces_before_word = total_spaces / (words - 1);
        extra_spaces = total_spaces % (words - 1);
    }
    p_word = strtok (p_line, delim);
    while (p_word != NULL)
    {
        size_t word_length = strlen (p_word);
        memcpy (dest, p_word, word_length);
        dest += word_length;
        p_word = strtok (NULL, delim);
        if (p_word != NULL)
        {
            size_t space_length = spaces_before_word 
                + (extra_spaces > 0 ? 1 : 0);
            memset (dest, ' ', space_length);
            dest += space_length;
            extra_spaces--;
        }
    }
    *dest = '\0';
}
