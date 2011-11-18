/**
 * @file
 * Dieses Modul stellt Funktionen zur Verfügung um Zeichenketten zu ver- oder 
 * zu entschlüsseln.
 *
 * @author Stefan Ebert
 * @date 2011-11-04
 */

#ifndef _CRYPT_H
#define _CRYPT_H

/**
 * Verschlüsselt eine Nachricht.
 *
 * @param msg Nachricht die verschlüsselt werden soll.
 * @param code Liefert die verschlüsselte Nachricht zurück.
 */
extern void encrypt (unsigned char msg[],
                     int code[]);

/**
 * Entschlüsselt eine Nachricht.
 *
 * @param code Nachricht die entschlüsselt werden soll.
 * @param msg Liefert die entschlüsselte Nachricht zurück.
 */
extern void decrypt (int code[],
                     unsigned char msg[]);

#endif
