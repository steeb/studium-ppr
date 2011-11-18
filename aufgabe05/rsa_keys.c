/* ===========================================================================
 * Header-Dateien
 * ======================================================================== */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "rsa_keys.h"

/* ===========================================================================
 * Makros
 * ======================================================================== */

#define DPRINT(PARAM) printf(#PARAM " = %d\n", PARAM)

/**
 * Die Zahlen der RSA-Schlüssel müssen kleiner als die Zahl LIMIT sein
 */
#define LIMIT 10000

/**
 * Alle betrachteten Primzahlen müssen kleiner als PRIME_LIMIT sein.
 * 9973 ist die größte Primzahl, die kleiner als 10000 (LIMIT) ist.
 */
#define PRIME_LIMIT 10000

/**
 * Maximale Anzahl an Primzahlen, die berechnet werden. Es gibt 1229
 * Primzahlen, die kleiner sind, als PRIME_LIMIT
 */
#define MAX_PRIMES 1229
 
/**
 * Der ASCII-Wert des größten zu verschlüsselnden Zeichens. DER RSA-Modul muss
 * größer sein als MAX_CHAR
 */
 #define MAX_CHAR 254

 
 /* ===========================================================================
 * Typdefinitionen
 * ======================================================================== */

/* Boolesche Werte */
typedef enum
{
    FALSE,
    TRUE
} BOOL;


/* ===========================================================================
 * Globale Variablen
 * ======================================================================== */

/**
 * Feld, in dem maximal MAX_PRIMES Primzahlen ab 2 abgelegt werden
 */
static int primes[MAX_PRIMES] = {0};

/**
 * Anzahl der in primes tatsächlich enthaltenen Primzahlen
 */
static int number_of_primes = 0;

/**
 * Globale Variablen des aktuell erzeugten RSA-Schlüssels
 */
static int rsa_modul;
static int public_exponent;
static int secret_exponent;


/* ===========================================================================
 * Funktionsprototypen
 * ======================================================================== */

/**
 * Die Funktion erzeugt alle Primzahlen zwischen 2 und limit und legt sie 
 * nacheinander im Feld 'primes' ab. Es werden nicht mehr als MAX_PRIMES
 * Primzahlen erzeugt, auch wenn limit noch nicht erreicht wurde.
 *
 * @param limit gibt das Limit an, bis zu dem die Primzahlen erzeugt
 *              werden sollen. Der Parameter limit muss größer als 0 sein.
 */
static void generate_primes(int limit);

/**
 * Die Funktion liefert eine zufällige Primzahl zwischen 2 und limit - 1.
 * Vor dem ersten Aufruf sollte mit dem Aufruf srand(time(NULL)) der Startpunkt
 * der Zufallszahlenberechnung auf die aktuelle Uhrzeit gesetzt worden sein.
 *
 * @param limit gibt das Limit an, bis zu dem eine Primzahl zufällig bestimmt
 *              werden soll.
 * @return zufällige Primzahl zwischen 2 und limit
 */
static int get_random_prime(int limit);
    
/**
 * berechnet für die Zahlen a und b den größten gemeinsamen Teiler sowie die 
 * Faktoren s und t, so dass gilt: ggT(a, b) = a * s + t * b. 
 *
 * @param a ganze Zahl, deren ggT berechnet werden soll
 * @param b ganze Zahl, deren ggT berechnet werden soll
 * @param s_and_t 2-stelliger Vektor, in dem die berechneten Faktoren s und t 
 *                zurückgegeben werden
 * @return größter gemeinsamer Teiler
 */
static int extended_gcd(int a, int b, int s_and_t[]);


/* ===========================================================================
 * Funktionsdefinitionen
 * ======================================================================== */

/* ----------------------------------------------------------------------------
 * Funktion: get_rsa_modul
 * ------------------------------------------------------------------------- */
extern int get_rsa_module(void)
{
    return rsa_modul;
}

/* ----------------------------------------------------------------------------
 * Funktion: get_public_exponent
 * ------------------------------------------------------------------------- */
extern int get_public_exponent(void)
{
    return public_exponent;
}

/* ----------------------------------------------------------------------------
 * Funktion: get_secret_exponent
 * ------------------------------------------------------------------------- */
extern int get_secret_exponent(void)
{
    return secret_exponent;
}

/* ----------------------------------------------------------------------------
 * Funktion: calculate_rsa_keys
 * ------------------------------------------------------------------------- */
extern void calculate_rsa_keys(void)
{
    int p = 0;            /* p und q sind zwei zufällig ausgewählte Primzahlen */
    int q = 0;            /* im Intervall von 2 bis LIMIT */
    int phi_n;            /* Wert der Eulerschen phi-Funktion: (p - 1) * (q - 1) */
    int e = 0;            /* Exponent des öffentlichen Schlüssels */
    int d = 0;            /* Exponent des privaten Schlüssels */
    int n;                /* RSA-Modul */
    int gcd;              /* ggt von e und n */
    int d_and_k[2] = {0}; /* Hilfsvektor, um die beiden Werte d und k, die im
                           * erweiterten Euklidschen Algorithmus berechnet werden, 
                           * zurückzugeben. */ 
    BOOL found_e;         /* TRUE, wenn ein teilerfremdes e zu n gefunden wurde,
                           * FALSE sonst. */
    
    /* Berechnung der Primzahlen von 2 bis PRIME_LIMIT */
    generate_primes(PRIME_LIMIT);
    
    /* 
     * Wähle zwei zufällige Primzahlen, so dass deren Produkt (das RSA-Modul)
     * größer als der ASCII-Wert des größten zu verschlüsselnden 
     * Zeichens ist und kleiner als die Zahl (PRIME_LIMIT), die die 
     * RSA-Schlüssel nicht überschreiten dürfen. 
     */
    n = 0;
    while (n <= MAX_CHAR || n >= PRIME_LIMIT)
    {
        p = get_random_prime(LIMIT); 
        q = get_random_prime(LIMIT);   
        n = p * q;
    }
#ifdef DEBUG
    DPRINT(p);
    DPRINT(q);
    DPRINT(n);
#endif 

    /* Berechne die eulersche Phi-Funktion von p und q */
    phi_n = (p - 1) * (q - 1);
#ifdef DEBUG
    DPRINT(phi_n);
#endif 

    /* 
     * Wähle eine zu phi_n teilerfremde Zahl e und berechne d, so dass gilt:
     * d > 1, e != d, e * d + k * phi_n = 1 = ggt(e, phi_n)
     */
    gcd = -1;
    while (d <= 1 || d == e || gcd != 1)
    {
        /*
         * Wähle eine Primzahl e, so dass e kleiner ist als phi_n und 
         * e kein Teiler von phi_n ist --> e und phi_n sind teilerfremd. 
         */
        found_e = FALSE;
        while (found_e == FALSE)
        {
            e = get_random_prime(phi_n);
            if (e < phi_n && phi_n % e != 0)
            {
                found_e = TRUE;
            }
        }
#ifdef DEBUG
        DPRINT(e);
#endif 
        /*
         * Bestimme die Zahl d mit dem erweiterten euklidschen Algorithmus, 
         * so dass gilt: e * d + k * phi_n = 1 = ggT(e, phi_n)
         */
        gcd = extended_gcd(e, phi_n, d_and_k);
        d = d_and_k[0];
    }
#ifdef DEBUG
    DPRINT(phi_n);
    DPRINT(e);
    DPRINT(n);
    DPRINT(d);
#endif

    /* Globale Variablen auf die generierten Schlüsselwerte setzen */
    rsa_modul = n;
    public_exponent = e;
    secret_exponent = d;

#ifdef DEBUG
    printf("Es wurde folgendes Schluesselpaar erzeugt:\n");
    printf("oeffentlicher Schluessel: (%4d, %4d)\n", e, n);
    printf("privater Schluessel     : (%4d, %4d)\n", d, n);
    printf("\n");
#endif
}


/* ----------------------------------------------------------------------------
 * Funktion: extended_gcd
 * ------------------------------------------------------------------------- */
static int extended_gcd(int a, int b, int s_and_t[])
{
    /* 
     * Berechnung der Faktoren s und t nach dem erweiterten Euklidschen 
     * Alogrithmus: ggT(a, b) = s * a + t * b 
     */
    int old_s = 1;
    int old_t = 0;
    int new_s = 0;
    int new_t = 1;
    int s = 0;
    int t = 0;
    int rest;
    int quotient;

    do 
    {
        /* normaler Euklid */
        rest = a % b;
        quotient = a / b;
        a = b;
        b = rest;
        
        /* neues s und t berechnen */
        if (b != 0) 
        {
            new_s = old_s - quotient * s;
            old_s = s; 
            s = new_s;

            new_t = old_t - quotient * t;
            old_t = t;
            t = new_t;
        }
    } while (b != 0);
     
    /* Ergebniswerte werden über Vektor zurück gegeben */
    s_and_t[0] = s;
    s_and_t[1] = t;
    
    /* größten gemeinsamen Teiler zurückgeben */
    return a; 
}


/* ----------------------------------------------------------------------------
 * Funktion: get_random_prime
 * ------------------------------------------------------------------------- */
static int get_random_prime(int limit)
{
    int prime;                  /* zufällig ausgewählte Primzahl, die 
                                 * kleiner als limit ist */
    static BOOL seed = FALSE;   /* TRUE, wenn die Zufallszahlengenerierung
                                 * initialisiert wurde, FALSE, sonst */
    
    /* Die Zufallszahlengenerierung soll nur einmal initialisiert werden. */
    if (seed == FALSE)
    {
        srand((unsigned int) time(NULL));
        seed = TRUE;
    }
    
    prime = limit + 1;
    while (prime >= limit)
    {
        prime = primes[rand() % number_of_primes];
    }
    
    return prime;
}

/* ----------------------------------------------------------------------------
 * Funktion: generate_primes
 * ------------------------------------------------------------------------- */
static void generate_primes(int limit)
{
    /* Das i-te Element von gestrichen ist TRUE, wenn i eine Primzahl ist, 
     * im anderen Fall ist es FALSE */
    BOOL gestrichen[PRIME_LIMIT];
    
    int number; /* Aktuelle Zahl, die auf Primzahl geprüft werden soll */
    int i;      /* Index in 'primes', auf den eine Primzahl eingetragen wird */
    
    if (number_of_primes > 0)
    {
        /* Primzahlen wurden bereits berechnet. */
        return;
    }
    
    /* 
     * Initialisierung des Feldes 'gestrichen': Alle Zahlen außer 0 und 1 
     * sind zu Beginn nicht gestrichen.
     */
    gestrichen[0] = TRUE;   /* 0 ist keine Primzahl */
    gestrichen[1] = TRUE;   /* 1 ist keine Primzahl */
    for (number = 2; number < PRIME_LIMIT; number++)
    {
        gestrichen[number] = FALSE;
    } 

    /* Streiche alle Zahlen, die ein Vielfaches einer Primzahl sind, da sie
     * keine Primzahl sein können. Beginne mit 2 als kleinster Primzahl */
    
    /* Iteration solange noch ein Vielfaches von number im Intervall drin ist */
    for (number = 2; number * number < PRIME_LIMIT; number++)
    {
        if (gestrichen[number] == FALSE)
        {
            /* i ist prim, streiche seine Vielfachen mit i * i beginnend: */
            for (i = number * number; i < PRIME_LIMIT; i = i + number)
            {
                gestrichen[i] = TRUE;
            }
        }
    }
    
    /* Schreibe alle Primzahlen hintereinander in das Primzahlfeld 'primes' */
    i = 0;
    for (number = 0; number < PRIME_LIMIT && i < MAX_PRIMES; number++)
    {
        if (gestrichen[number] == FALSE && i < limit)
        {
            /* number ist Primzahl */
            primes[i] = number;
            i++;
        }
    }
    /* Anzahl der generierten Primzahlen global merken */
    number_of_primes = i;
}

