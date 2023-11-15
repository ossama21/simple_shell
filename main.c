#include "shell.h"

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while (1) {
        printf("#cisfun$ ");
        read = getline(&line, &len, stdin);
        if (read == -1) {  /* End of file or error */
            break;
        }
        execute(line);
    }

    free(line);
    return (0);
}
