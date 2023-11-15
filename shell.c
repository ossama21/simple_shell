#include "shell.h"

int execute_line(char *line)
{
    pid_t pid;
    int status;

    line = remove_newline(line);

    if (line == NULL)
    {
        if (isatty(STDIN_FILENO))
            printf("\n");
        return 0;
    }

    pid = fork();
    if (pid == -1)
    {
        perror("./shell");
        return 1;
    }

    if (pid == 0)
    {
        char **argv = parse_arguments(line);
        if (argv == NULL)
        {
            perror("./shell");
            exit(EXIT_FAILURE);
        }

        if (execve(argv[0], argv, NULL) == -1)
        {
            perror("./shell");
            free_arguments(argv);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        wait(&status);
    }

    return 1;
}

char **parse_arguments(char *line)
{
    char **argv = NULL;
    char *token;
    int argc = 0;

    token = strtok(line, " ");
    while (token != NULL)
    {
        argv = realloc(argv, (argc + 1) * sizeof(char *));
        if (argv == NULL)
        {
            perror("./shell");
            exit(EXIT_FAILURE);
        }

        argv[argc] = strdup(token);
        if (argv[argc] == NULL)
        {
            perror("./shell");
            free_arguments(argv);
            exit(EXIT_FAILURE);
        }

        argc++;
        token = strtok(NULL, " ");
    }

    argv = realloc(argv, (argc + 1) * sizeof(char *));
    if (argv == NULL)
    {
        perror("./shell");
        exit(EXIT_FAILURE);
    }
    argv[argc] = NULL;

    return argv;
}

void free_arguments(char **argv)
{
    int i;
    for (i = 0; argv[i] != NULL; i++)
    {
        free(argv[i]);
    }
    free(argv);
}
