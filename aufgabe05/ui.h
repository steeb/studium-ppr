/**
 * @file
 * Dieses Modul stellt Funktionen für die Benutzerinteraktion zur Verfügung.
 * Nachrichten bis zu einer Länge von 50 Zeichen können eingelesen werden
 * und auch wieder ausgegeben werden. Auch der Code der Zeichenketten kann
 * ausgegeben werden.
 *
 * @author Stefan Ebert
 * @date 2011-11-18
 */

#ifndef _UI_H
#define _UI_H

/* Maximale Zeichen die eingelesen werden können. */
#define MAX_INPUT_CHARS 50

/**
 * Liest eine Nachricht bis zu 50 Zeichen Lang von der Standardeingabe ein.
 *
 * @param msg Vector in der die Nachricht abgelegt wird.
 */
extern void read_message (unsigned char msg[]);

/**
 * Gibt die Nachricht auf der Standardausgabe aus.
 *
 * @param msg Nachricht die ausgegeben werden soll.
 */
extern void write_message (unsigned char msg[]);

/**
 * Gibt den Code einer Nachricht auf der Standardausgabe aus.
 *
 * @param code Nachricht zu der der Code ausgegen wird.
 */
extern void write_code (int code[]);

#endif
