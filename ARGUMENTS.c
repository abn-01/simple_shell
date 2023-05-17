#include <stdio.h>

/**
 *  main - Entry point of the program
 *
 * This function calculates the result by performing a division operation
 * and prints the result to the standard output.
 *
 * Return: 0 on success
 */
int main(void)
{
	int variable = 0;
	int value = 10;
	int increment = 2;

	if (variable == 0)
	{
		variable = value / increment;
	}

	printf("Result: %d\n", variable);

	return (0);
}
