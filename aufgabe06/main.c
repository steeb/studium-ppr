#include <stdlib.h>
#include "string_formatter.h"

int main (void)
{
    char line[] = "   abc defg  hij";
    char line2[] = "sdfsdf";
    char line3[] = "   ";
    justify_line (line, 80, NULL);
    justify_line (line2, 80, NULL);
    justify_line (line3, 80, NULL);

    return EXIT_SUCCESS;
}
