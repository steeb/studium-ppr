/**
 * @mainproject
 * Bla blub blub
 *
 * @author Stefan Ebert
 * @date 2011-11-18
 */

#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "crypt.h"
#include "rsa_keys.h"

/**
 * Liest Nachrichten ein und ver und entschlüsselt sie.
 * Bis das Programm mit x abgebrochen wird.
 *
 * @return success
 */
int main (void)
{
    unsigned char msg[MAX_INPUT_CHARS + 1];
    int code[MAX_INPUT_CHARS + 1];
    int c = 'a';

    ungetc ('\n', stdin);
    do {
        while (c != '\n' && getchar () != '\n');
        read_message (msg);
        calculate_rsa_keys ();
        encrypt (msg, code);
        write_code (code);
        decrypt (code, msg);
        write_message (msg);

        printf ("Gebe 'x' zum Beenden ein: ");
        c = getchar ();
    } while (c != 'x');

    return EXIT_SUCCESS;
}
