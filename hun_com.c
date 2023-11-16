#include "main.h"


/**
 * handle_exit - Handles the "exit" command.
 * @argv: array of command arguments
 */
void handle_exit(char **argv)
{
	if (my_strcmp(argv[0], "exit") == 0)
		exit(EXIT_SUCCESS);
}


/**
 * get_full_path - Retrieves the full path of the command.
 *  @argv: array.
 *
 * Return: Full path of the command.
 */
char *get_full_path(char **argv)
{
	char *full_path = find_command(argv[0]);

	if (full_path == NULL)
	{
		write(STDERR_FILENO, argv[0], my_strlen(argv[0]));
		write(STDERR_FILENO, ": No such file or directory\n", 28);
		return (NULL);
	}

	return (full_path);
}

/**
 * handle_env - Handles the "env" command.
 *  @argv: array.
 */
void handle_env(char **argv)
{
	if (my_strcmp(argv[0], "env") == 0)
	{
		print_env();
	}
}

/**
 * my_getenv - Gets the value of an environment variable.
 * @name: Name of the environment variable.
 *
 * Return: Value of the environment variable, or NULL if not found.
 */
char *my_getenv(const char *name)
{
	int i;

	size_t len = my_strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (my_strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
			return (&environ[i][len + 1]);
	}

	return (NULL);
}
