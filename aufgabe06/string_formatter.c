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
                            unsigned int *count_words,
                            unsigned int *count_chars_without_spaces)
{
    BOOL read_word = FALSE;
    char *p_line_position = p_line;

    *count_words = 0;
    *count_chars_without_spaces = 0;

    while (*p_line_position != '\0')
    {
        if (*p_line_position != ' ')
        {
            if (!read_word)
            {
                (*count_words)++;
                read_word = TRUE;
            }
            (*count_chars_without_spaces)++;
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
    unsigned int count_words;
    unsigned int count_chars_without_spaces;
    char *p_word;
    char *delim = " ";
    unsigned int count_spaces;
    unsigned int count_spaces_before_each_word;
    unsigned int count_words_with_extra_spaces;
    char *dest = p_justified_line;

    printf ("%s\n", p_line);

    analyse_string (p_line, &count_words, &count_chars_without_spaces);
    count_spaces = (target_line_length - count_chars_without_spaces
       + count_words - 1);
    count_spaces_before_each_word = count_spaces / (count_words - 1) + 1;
    count_words_with_extra_spaces = count_spaces % (count_words - 1);
    
    p_word = strtok (p_line, delim);
    while (p_word != NULL)
    {
        size_t word_length = strlen (p_word);
        memcpy (dest, p_word, word_length);
        dest += word_length;
        p_word = strtok (NULL, delim);
        if (p_word != NULL)
        {
            memset (dest, ' ', count_spaces_before_each_word 
                    + (count_words_with_extra_spaces > 0 ? 1 : 0));
            dest += count_spaces_before_each_word
                + (count_words_with_extra_spaces > 0 ? 1 : 0);
            count_words_with_extra_spaces--;
        }
    }
}
