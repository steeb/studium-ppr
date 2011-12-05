/**
 * @main Blocksatzformatierer
 *
 * @author steeb
 * @date 2011-12-01
 */

#include <stdio.h>
#include <stdlib.h> /* for exit */
#include <string.h>
#include <errno.h>
#include "string_formatter.h"

#define READ_ONLY "r"
#define READ_WRITE "w+"
#define BUFFERSIZE 1000

static void read_args (int argc,
                       char **argv,
                       FILE **in,
                       FILE **out,
                       int *linelength);


int main (int argc,
          char **argv)
{
    FILE *input_stream = NULL;
    FILE *output_stream = stdout;
    int linelength = 80;
    char string_buffer[BUFFERSIZE + 1];
    char output_line[BUFFERSIZE + 1];

    read_args (argc, argv, &input_stream, &output_stream, &linelength);

    fgets (string_buffer, BUFFERSIZE, input_stream);
    string_buffer[strlen(string_buffer) - 1] = '\0';
    while (!feof (input_stream) )
    {
        justify_line (string_buffer, linelength, output_line);
        fputs (output_line, output_stream);
        fputc ('\n', output_stream);
        fgets (string_buffer, BUFFERSIZE, input_stream);
        string_buffer[strlen(string_buffer) - 1] = '\0';
    }

    fclose (input_stream);
    fclose (output_stream);

    return EXIT_SUCCESS;
}

static void read_args (int argc,
                       char **argv,
                       FILE **in,
                       FILE **out,
                       int *linelength)
{
    char *filename = NULL;
    *argv++;

    while (argc > 1)
    {
        if (strcmp (*argv, "-h") == 0)
        {
            printf ("[-h]            diese Hilfe\n");
            printf ("-i file         Eingabedatei\n");
            printf ("[-o file]       Ausgabedatei\n");
            printf ("[-l linelength] Zeilenlänge (default:80)\n");
            exit (EXIT_SUCCESS);
        } 
        else if (strcmp (*argv, "-i") == 0)
        {
            *argv++;
            argc--;
            if (filename != NULL)
            {
                if (strcmp (*argv, filename) == 0)
                {
                    fprintf (stderr, "in and output file are the same\n");
                    exit (EXIT_FAILURE);
                }
            }
            *in = fopen (*argv, READ_ONLY);
            if (*in == NULL)
            {
                fprintf (stderr, "%s: %s\n", *argv, strerror (errno));
                exit (EXIT_FAILURE);
            }
            filename = *argv;
        }
        else if (strcmp (*argv, "-o") == 0)
        {
            *argv++;
            argc--;
            if (filename != NULL)
            {
                if (strcmp (*argv, filename) == 0)
                {
                    fprintf (stderr, "in and output file are the same\n");
                    exit (EXIT_FAILURE);
                }
            }
            *out = fopen (*argv, READ_WRITE);
            if (*out == NULL)
            {
                fprintf (stderr, "%s: %s\n", *argv, strerror (errno));
                exit (EXIT_FAILURE);
            }
            filename = *argv;
        }
        else if (strcmp (*argv, "-l") == 0)
        {
            *argv++;
            argc--;
            *linelength = atoi (*argv);
            if (*linelength <= 0)
            {
                fprintf (stderr, "Zeilenlänge muss größer 0 sein\n");
                exit (EXIT_FAILURE);   
            }
        }
        else
        {
            fprintf (stderr, "%s ist ein falsche Paramter\n", *argv);
            exit (EXIT_FAILURE);
        }
        *argv++;
        argc--;
    }

    if (*in == NULL)
    {
        fprintf (stderr, "Paramter -i erforderlich\n");
        exit (EXIT_FAILURE);
    }
}

