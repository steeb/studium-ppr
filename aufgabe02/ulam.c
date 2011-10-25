/**
 * @mainpage Collatz-Problem
 *
 * @file Diese Aufgabe behandelt drei ULAM-Funktionen
 *
 * @author Stefan 'steeb' Ebert
 * @date 2011-10-22
 */

/**
 * Berechnet für a0 den maximalen Wert für die ULAM-Folge.
 *
 * @param a0 - ULAM-Folge
 *
 * @return groesster Wert der ULAM-Folge
 */
int ulam_max (int a0)
{
    int max = a0;
    int an = a0;
    
    while (an > 1)
    {
        an = (an % 2 == 0) ? an / 2 : 3 * an + 1;
        max = (max > an) ? max : an;
    }
    return (a0 < 1 ? -1 : max);
}

/**
 * Pürft ob es im Intervall von 1 bis einschließlich limit zwei benachbarte
 * Werte a0 und a0 + 1 gibt, für die ulam_max(a0) = ulam_max(a0 + 1) gilt.
 *
 * @param limit - Grenze bis zu der gesucht werden soll
 *
 * @return liefert den kleineren der beiden Werte, wenn keiner gefunden wird
 *         -1
 */
int ulam_twins (int limit)
{
    int i;  /* Laufvariable */

    for (i = limit - 1; i >= 2; i--)
    {
        if (ulam_max (i) == ulam_max (i + 1))
        {
            return i;
        }
    }
    return -1;
}

/**
 * Prüft ob es im Intervall von 1 bis einschlieslich limit ULAM-Mehrlinge
 * mit der Anzhal nummer gibt.
 *
 * @param limit - Grenze bist zu der gesucht werden soll
 * @param number - Es soll nach number-lingen gesucht werden
 *
 * @return wenn Mehrlinge gefunden werden liefert die Funktion den kleisten
 *         Wert der Mehrlingsgruppe, sonst -1
 */
int ulam_multiples (int limit, int number)
{
    int i;      /* Laufvariable für auussere Schleife */
    int j;      /* Laufvariable für innere Schleife */
    int multi;  /* Zwischenspeicher um Mehrlinge zu finden */

    if (number > 1 && number < limit)
    {
        /*
         * spezialfall der genau in ulam_twins behandelt wird
         */
        if (number == 2)
        {
            return ulam_twins (limit);
        }
        
        /*
         * sonstige faelle
         * die Abarbeitung erfolgt von hinten nach vorne
         */
        for (i = limit; i >= number; i--)
        {
            multi = ulam_max (i);
            for (j = 1; j <= number - 1; j++)
            {
                multi = (multi == ulam_max (i - j)) ? multi : -1;
            }
            if (multi != -1)
            {
                return i - number + 1;
            }
        }
    }
    return -1;
}

