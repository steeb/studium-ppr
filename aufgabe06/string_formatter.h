/**
 * @file Dieses Modul stellt Funktionen zur formatierung von Zeichenketten
 * zur Verfügung.
 */

#ifndef _STRING_FORMATTER_H
#define _STRING_FORMATTER_H

/**
 * Formatiert eine Zeichenketten in Blocksatz.
 *
 * @param p_line Zeichenkette die formatiert werden soll.
 * @param target_line_length Länge der Ziel Zeile
 * @param p_justified_line Speicher in der der neue String geschrieben wird.
 */
extern void justify_line (char *p_line,
                          int target_line_length,
                          char *p_justified_line);

#endif
