#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 100
#define SHELL_PROMPT "$ "
#define MAX_NUM_ARGS 100

extern char **environ;

int is_interactive(void);
void parse_command(char *cmd, char **argv);
int run_command(char **argv, char *full_path);
char *find_command(char *cmd);
void print_env(void);
void handle_exit(char **argv);
void handle_env(char **argv);
char *get_full_path(char **argv);

char *my_strdup(const char *str);
size_t my_strlen(const char *str);
int my_strcmp(char *s1, char *s2);
char *my_strtok(char *str, const char *delim);
char *my_strchr(const char *str, int c);

int my_strncmp(const char *s1, const char *s2, size_t n);
char *my_strncat(char *dest, const char *src, size_t n);
char *my_strncpy(char *dest, const char *src, size_t n);
char *my_getenv(const char *name);

void *my_memcpy(void *dest, const void *src, size_t n);

#endif

