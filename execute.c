#include "shell.h"


void execute(char *command)
{
    char **argv = malloc(sizeof(char *) * 4);  /* Allocate memory for argv */
    pid_t pid;
    int status;

    if (!argv) {
        perror("Error");
        return;
    }

    argv[0] = "/bin/sh";
    argv[1] = "-c";
    argv[2] = command;
    argv[3] = NULL;

    pid = fork();
    if (pid == 0) {
        /* Child process */
        if (execve(argv[0], argv, NULL) == -1) {
            perror("Error");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        /* Error forking */
        perror("Error");
    } else {
        /* Parent process */
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    free(argv);  /* Don't forget to free argv when you're done with it */
}
