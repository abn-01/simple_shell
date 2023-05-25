#include "main.h"

/**
 * arg_count - Returns the number of times,
 * commands are entered in the shell.
 * @flag: A flag that determines whether the count should be incremented.
 *
 * Return: The count of commands entered in the shell.
 */
char arg_count(int flag)
{
	static int count;
	char i = '1' + count;

	if (flag)
		count++;

	return (i);
}
