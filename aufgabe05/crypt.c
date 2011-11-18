#include <string.h>
#include "rsa_keys.h"
#include "crypt.h"

/**
 * Es wird die modulare Eponentation berechnet.
 *
 * @param b Basis
 * @param e Exponent
 * @param n Modul
 */
static int modular_exponentiation (int b,
                                   int e,
                                   int n)
{
    int square_mod = b;
    int half       = e;
    int result     = 1;

    while (half > 0)
    {
        if (half % 2 > 0)
        {
            result = (result * square_mod) % n;
        }
        square_mod = (square_mod * square_mod) % n;
        half /= 2;
    }
    return result;
}

extern void encrypt (unsigned char msg[],
                     int code[])
{
    int i = 0;                      /* Laufvariable */
    int n = get_rsa_module ();      /* Gemeinsames Modul */
    int e = get_public_exponent (); /* Öffentlicher Exponent */

    while (msg[i] != '\0')
    {
        code[i] = modular_exponentiation (msg[i], e, n);
        i++;
    }
    code[i] = '\0';
}

extern void decrypt (int code[],
                     unsigned char msg[])
{
    int i = 0;                      /* Laufvariable */
    int n = get_rsa_module ();      /* Gemeinsames Modul */
    int d = get_secret_exponent (); /* Geheimer Exponent */

    while (code[i] != '\0')
    {
        msg[i] = (unsigned char)modular_exponentiation (code[i], d, n);
        i++;
    }
    msg[i] = '\0';
}
