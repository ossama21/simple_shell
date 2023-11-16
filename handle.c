#include "shell.h"

/**
 * handle_exit - Handles the "exit" command.
 * @arguments: Array of command arguments.
 */
void handle_exit(char **arguments)
{
    if (my_strcmp(arguments[0], "exit") == 0)
        exit(EXIT_SUCCESS);
}

/**
 * get_full_path - Retrieves the full path of the command.
 * @arguments: Array of command arguments.
 *
 * Return: Full path of the command.
 */
char *get_full_path(char **arguments)
{
    char *full_path = find_command(arguments[0]);

    if (full_path == NULL)
    {
        write(STDERR_FILENO, arguments[0], my_strlen(arguments[0]));
        write(STDERR_FILENO, ": No such file or directory\n", 28);
        return (NULL);
    }

    return (full_path);
}

/**
 * handle_env - Handles the "env" command.
 * @arguments: Array of command arguments.
 */
void handle_env(char **arguments)
{
    if (my_strcmp(arguments[0], "env") == 0)
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

