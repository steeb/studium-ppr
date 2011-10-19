#include <stdio.h>

#define MAX_LENGTH 16

int main (void)
{
    double fahrenheit[MAX_LENGTH];
    double celsius[MAX_LENGTH];
    int fahr;
    int index;
    int size;
    int upper_bound;
    int lower_bound;
    int steps;
    unsigned int input_valid;

    do
    {
        input_valid = 1;
        printf ("Gebe die Grenzen und Strittweite ein "
                "(Format: UntereGrenze ObereGrenze Strittweite): ");
        if (scanf ("%d %d %d", &lower_bound, &upper_bound, &steps) != 3)
        {
            while (getchar() != '\n')
            {}
            input_valid = 0;
            printf ("Format nicht eingehalten.\n");
        }
        else if ( (upper_bound - lower_bound) / steps > MAX_LENGTH)
        {
            input_valid = 0;
            printf ("Angeforderter Bereich zu groß.\n");
        }
        else if (upper_bound < lower_bound)
        {
            input_valid = 0;
            printf ("Obergrenze ist kleiner als Untergrenze.\n");
        }
    } while (input_valid == 0);


    size = 0;
    for (fahr = lower_bound; fahr <= upper_bound; fahr += steps)
    {
        fahrenheit[size] = fahr;
        size++;
    }
    for (index = 0; index < size; index++)
    {
        celsius[index] = (5.0 / 9.0) * (fahrenheit[index] - 32);
    }
    for (index = 0; index < size; index++)
    {
        printf("%6.1f\t%6.1f\n", fahrenheit[index], celsius[index]);
    }
    return 0;
}
