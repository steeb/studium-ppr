#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_formatter.h"

#define MAX_LINE_LENGTH 80

int main (void) {

    char line01[] = "01234567890123456789012345678901234567890123456789012345678901234567890123456789";
    char loes01[] = "01234567890123456789012345678901234567890123456789012345678901234567890123456789";
    char line02[] = "";
    char loes02[] = "";
    char line03[] = "   0123456789012345678901234567890123456789012345678    ";
    char loes03[] = "0123456789012345678901234567890123456789012345678";
    char line04[] = "012345678 012345678 012345678 012345678 012345678 012345678 012345678 0123456789";
    char loes04[] = "012345678 012345678 012345678 012345678 012345678 012345678 012345678 0123456789";
    char line05[] = "123456789 345678901 567890123 789012345 901234567 123456789 234567890";
    char loes05[] = "123456789   345678901   567890123   789012345   901234567   123456789  234567890";
    char line06[] = " 1234567 3456789 4567890 56789012 78901234 901234567 234567890";
    char loes06[] = "1234567     3456789    4567890    56789012    78901234    901234567    234567890";
    char line07[] = "    1234567 3456789 4567890 56789012 78901234 901234567 234567890";
    char loes07[] = "1234567     3456789    4567890    56789012    78901234    901234567    234567890";
    char line08[] = "123456789 345678901 567890123 789012345 901234567 123456789 234567890 ";
    char loes08[] = "123456789   345678901   567890123   789012345   901234567   123456789  234567890";
    char line09[] = "123456789 345678901 567890123 789012345 901234567 123456789 234567890     ";
    char loes09[] = "123456789   345678901   567890123   789012345   901234567   123456789  234567890";
    char line10[] = "123456789 345678901   567890123 789012345     901234567 123456789 234567890     ";
    char loes10[] = "123456789   345678901   567890123   789012345   901234567   123456789  234567890";
    char line11[] = "123456789 567890123 890123456 123456789 456789012 789012345 0";
    char loes11[] = "123456789     567890123    890123456    123456789    456789012    789012345    0";
    char line12[] = "123456789 567890123 901234567 345678901 789012345 1234567890";
    char loes12[] = "123456789     567890123     901234567     345678901     789012345     1234567890";
    
    char justiy[MAX_LINE_LENGTH + 1] = "";

    printf ("%s\nin: \"%s\"\n", "test01", line01);
    justify_line (line01, MAX_LINE_LENGTH, justiy);
    printf ("out:\"%s\"\n    \"%s\"\n%d\n\n", justiy, loes01, strcmp (loes01, justiy));
    
    printf ("%s\nin: \"%s\"\n", "test02", line02);
    justify_line (line02, MAX_LINE_LENGTH, justiy);
    printf ("out:\"%s\"\n    \"%s\"\n%d\n\n", justiy, loes02, strcmp (loes02, justiy));
    
    printf ("%s\nin: \"%s\"\n", "test03", line03);
    justify_line (line03, MAX_LINE_LENGTH, justiy);
    printf ("out:\"%s\"\n    \"%s\"\n%d\n\n", justiy, loes03, strcmp (loes03, justiy));

    printf ("%s\nin: \"%s\"\n", "test04", line04);
    justify_line (line04, MAX_LINE_LENGTH, justiy);
    printf ("out:\"%s\"\n    \"%s\"\n%d\n\n", justiy, loes04, strcmp (loes04, justiy));

    printf ("%s\nin: \"%s\"\n", "test05", line05);
    justify_line (line05, MAX_LINE_LENGTH, justiy);
    printf ("out:\"%s\"\n    \"%s\"\n%d\n\n", justiy, loes05, strcmp (loes05, justiy));

    printf ("%s\nin: \"%s\"\n", "test06", line06);
    justify_line (line06, MAX_LINE_LENGTH, justiy);
    printf ("out:\"%s\"\n    \"%s\"\n%d\n\n", justiy, loes06, strcmp (loes06, justiy));

    printf ("%s\nin: \"%s\"\n", "test07", line07);
    justify_line (line07, MAX_LINE_LENGTH, justiy);
    printf ("out:\"%s\"\n    \"%s\"\n%d\n\n", justiy, loes07, strcmp (loes07, justiy));

    printf ("%s\nin: \"%s\"\n", "test08", line07);
    justify_line (line08, MAX_LINE_LENGTH, justiy);
    printf ("out:\"%s\"\n    \"%s\"\n%d\n\n", justiy, loes08, strcmp (loes08, justiy));

    printf ("%s\nin: \"%s\"\n", "test09", line09);
    justify_line (line09, MAX_LINE_LENGTH, justiy);
    printf ("out:\"%s\"\n    \"%s\"\n%d\n\n", justiy, loes09, strcmp (loes09, justiy));

    printf ("%s\nin: \"%s\"\n", "test10", line10);
    justify_line (line10, MAX_LINE_LENGTH, justiy);
    printf ("out:\"%s\"\n    \"%s\"\n%d\n\n", justiy, loes10, strcmp (loes10, justiy));
    
    printf ("%s\nin: \"%s\"\n", "test11", line11);
    justify_line (line11, MAX_LINE_LENGTH, justiy);
    printf ("out:\"%s\"\n    \"%s\"\n%d\n\n", justiy, loes11, strcmp (loes11, justiy));

    printf ("%s\nin: \"%s\"\n", "test12", line12);
    justify_line (line12, MAX_LINE_LENGTH, justiy);
    printf ("out:\"%s\"\n    \"%s\"\n%d\n\n", justiy, loes12, strcmp (loes12, justiy));
    return (EXIT_SUCCESS);
}
