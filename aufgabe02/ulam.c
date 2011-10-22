#include <stdio.h>

int ulam_max (int a0)
{
    int max = -1;
    int an = a0;
    
    while (an > 1)
    {
        an = (an % 2 == 0) ? an / 2 : 3 * an + 1;
        max = (max > an) ? max : an;
    }
    return (a0 == 1 ? 1 : max);
}

int ulam_twins (int limit)
{
    int i;

    for (i = limit - 1; i >= 2; i--)
    {
        /*printf ("%2d %2d: %3d %3d\n", i, i + 1, ulam_max (i), ulam_max (i + 1));*/
        if (ulam_max (i) == ulam_max (i + 1) )
        {
            return i;
        }
    }
    return -1;
}

int ulam_multiples (int limit, int number)
{
    int i;
    int j;
    int multi;

    if (number == 2)
    {
        return ulam_twins (limit);
    }
    for (i = limit; i >= number; i--)
    {
        multi = ulam_max (i);
        for (j = 1; j <= number - 1; j++)
        {
            multi = (multi == ulam_max (i - j) ) ? multi : -1;
        }
        if (multi != -1)
        {
            return i - number + 1;
        }
    }
        
    return -1;
}

