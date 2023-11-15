#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

char *read_line(void);
char *remove_newline(char *line);
int execute_line(char *line);
char **parse_arguments(char *line);
void free_arguments(char **argv);
char *find_path(char *command);

#endif
