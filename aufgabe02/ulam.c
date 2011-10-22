#include <stdio.h>

int ulam_max (int a0)
{
    int max = -1;
    
    while (a0 > 1)
    {
        a0 = (a0 % 2 == 0) ? a0 / 2 : 3 * a0 + 1;
        max = (max > a0) ? max : a0;
    }
    return max;
}

int ulam_twins (int limit)
{
    int twin = -1;
    int i;

    for (i = 1; i <= limit; i++)
    {
        if (ulam_max (i) == ulam_max (i + 1) )
        {
            twin = i;
        }
    }
    return twin;
}

int ulam_multiples (int limit, int number)
{
    return 0;
}

