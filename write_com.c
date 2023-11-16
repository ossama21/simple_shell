#include "main.h"

/**
 * get_environ - Gets the current environment.
 *
 * Return: Pointer to the environment.
 */
char **get_environ(void)
{
	return (environ);
}

/**
 * print_env - Prints the current environment.
 *
 * Return: void
 */
void print_env(void)
{
	char **environ = get_environ();

	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		puts(environ[i]);
	}
}
