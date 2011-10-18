#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

double transform_fahrenheit_to_celsius (int fahr);
double transform_celsius_to_fahrenheit (int celsius);
int select_fahrenheit_or_celsius (void);

int main (void)
{
	int selection;
	int current_step;

	selection = select_fahrenheit_or_celsius ();
	current_step = LOWER;
	while (current_step <= UPPER)
	{
		if (selection == 'c')
		{
			printf ("%3d %6.1f\n", current_step, 
					transform_celsius_to_fahrenheit(current_step) );
		}
		else 
		{
			printf ("%3d %6.1f\n", current_step, 
					transform_fahrenheit_to_celsius(current_step) );
		}
		current_step += STEP;
	}
	return 0;
}

double transform_fahrenheit_to_celsius (int fahr)
{
	return (5.0 / 9.0) * (fahr - 32);
}

double transform_celsius_to_fahrenheit (int celsius)
{
	return (celsius * 9.0 / 5.0) + 32;
}

int select_fahrenheit_or_celsius (void)
{
	int selection;
	unsigned int error_output;

	error_output = 0;

	do
	{
		/* Fehler wird erst beim 2ten Durchlauf der Schleife ausgegeben */
		if (error_output > 0)
		{
			printf("Falsche Eingabe. ");
		}
		error_output = 1;
		printf("Wähle zwischen (f)ahrenheit oder (c)elsius): ");
		fflush(stdout);

		selection = getchar();

		if (selection != '\n' && getchar() != '\n')
		{
			selection = 0;
			while (getchar() != '\n')
			{}
		}
	}
	while (selection != 'f' && selection != 'c');

	return selection;
}
