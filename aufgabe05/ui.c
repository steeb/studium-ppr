#include <stdio.h>
#include "ui.h"

extern void read_message (unsigned char msg[])
{
    unsigned char readed_chars = 0; /* Anzahl der gelesenen Zeichen */
    unsigned char act_char;                   /* Aktuell gelesenen Zeichen */

    printf ("Bitte Nachricht eingeben: ");
    act_char = (unsigned char)getchar ();
    while (act_char != '\n' && readed_chars < MAX_INPUT_CHARS)
    {
        msg[readed_chars] = act_char;
        act_char = (unsigned char)getchar ();
        readed_chars++;
    }
    msg[readed_chars] = '\0';
}

extern void write_message (unsigned char msg[])
{
    printf ("Ihre Nachricht: %s\n", (char *)msg);
}

extern void write_code (int code[])
{
    int i; /* Laufvariable */

    printf ("Code: ");
    for (i = 0; code[i] != '\0'; i++)
    {
        printf ("%d %c ", code[i], code[i + 1] != '\0' ? '|' : ' ');
    }
    printf ("\n");
}
