#include "shell.h"

/**
 * parse_command - Parses a command.
 * @cmd: Command to parse.
 * @argv: Array to store parsed arguments.
 */

void parse_input_command(char *cmd, char **args)
{
	char *token;

	int i = 0;

	if (cmd == NULL || args == NULL)
		return;

	token = my_strtok(cmd, " ");
	while (token != NULL && i < MAX_NUM_ARGS - 1)
	{
		args[i] = token;
		i++;
		token = my_strtok(NULL, " ");
	}
	args[i] = NULL;
}

