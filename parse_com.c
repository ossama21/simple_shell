#include "main.h"

/**
 * parse_command - Parses a command.
 * @cmd: Command to parse.
 * @argv: Array to store parsed arguments.
 */
void parse_command(char *cmd, char **argv)
{
	char *token;

	int i = 0;

	if (cmd == NULL || argv == NULL)
		return;

	token = my_strtok(cmd, " ");
	while (token != NULL && i < MAX_NUM_ARGS - 1)
	{
		argv[i] = token;
		i++;
		token = my_strtok(NULL, " ");
	}
	argv[i] = NULL;
}
