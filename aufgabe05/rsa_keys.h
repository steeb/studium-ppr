/**
 * @file
 * Dieses Modul stellt Funktionen zur Erzeugung von Schlüsselpaaren für 
 * die RSA-Verschlüsselung zur Verfügung sowie zum Zugriff auf die 
 * einzelnen Komponenten der Schlüsselpaare. Die erzeugten Schlüssel 
 * enthalten nur Zahlen, die kleiner als 10.000 sind.
 *
 * @author  Ulrike Griefahn
 * @date    2011-11-04
 */

#ifndef _RSA_KEYS_H
#define	_RSA_KEYS_H
/* ------------------------------------------------------------------------- */


/* ===========================================================================
 * Funktions-Prototypen
 * ======================================================================== */

/**
 * Die Funktion erzeugt ein Schlüsselpaar für die RSA-Verschlüsselung. Durch
 * die Verwendung von Zufallszahlen erzeugt die Funktion bei jedem Aufruf ein
 * anderes Schlüsselpaar, d.h., die Funktion darf nicht zwischen der 
 * Verschlüsselung eines Textes und seiner Entschlüsselung aufgerufen werden, 
 * da sonst das aktuelle Schlüsselpaar überschrieben wird.
 */
extern void calculate_rsa_keys(void);

/**
 * Diese Funktion liefert den Exponenten des durch den letzten Aufruf von 
 * calculate_rsa_keys() erzeugten öffentlichen RSA-Schlüssels. Der Exponent 
 * ist eine positive ganze Zahl kleiner als 10.000.
 *
 * @return Exponent des öffentlichen RSA-Schlüssels 
 */
extern int get_public_exponent(void);

/**
 * Diese Funktion liefert den Exponenten des durch den letzten Aufruf von 
 * calculate_rsa_keys() erzeugten geheimen RSA-Schlüssels. Der Exponent ist 
 * eine positive ganze Zahl kleiner als 10.000.
 * 
 * @return Exponent des geheimen RSA-Schlüssels 
 */
extern int get_secret_exponent(void);

/**
 * Diese Funktion liefert den RSA-Modul des durch den letzten Aufruf von 
 * calculate_rsa_keys() erzeugten RSA-Schlüsselpaars. Der RSA-Modul ist eine 
 * positive ganze Zahl kleiner als 10.000.
 *
 * @return RSA-Modul des RSA-Schlüsselpaares 
 */
extern int get_rsa_module(void);


/* ------------------------------------------------------------------------- */
#endif	/* _RSA_KEYS_H */
