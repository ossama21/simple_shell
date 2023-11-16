#include "shell.h"

/**
* main - main function for the custom shell
*
* Return: 0 on success
*/
int main(void)
{
	char *input_cmd = NULL;

	size_t cmd_len = 0;
	ssize_t read;
	char *cmd_args[MAX_NUM_ARGS];

	char *full_path;

	while (1)
	{
		if (checker())
			write(STDOUT_FILENO, SHELL_PROMPT, my_strlen(SHELL_PROMPT));

		read = getline(&input_cmd, &cmd_len, stdin);
		if (read == -1)
		{
			free(input_cmd);
			write(0, "\n", 1);
			return (0);
		}
		if (input_cmd[read - 1] == '\n')
			input_cmd[read - 1] = '\0';

		if (my_strlen(input_cmd) == 0)
			continue;

		parse_command(input_cmd, cmd_args);
		handle_exit(cmd_args);
		handle_env(cmd_args);

		full_path = get_full_path(cmd_args);
		if (full_path == NULL)
			continue;

		if (run_command(cmd_args, full_path))
			return (1);

		free(full_path);
	}
	return (0);
}

