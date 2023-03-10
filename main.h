#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <signal.h>
extern char **environ;
extern int dircount;
#define DELIM " \n\t"
#define INITIAL_BUFFER_SIZE 128


void env(char **env);
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
void prompt(void);
char *get_line(void);
char **split_line(char *line);
char *get_env(char **env);
char *pathCat(char *dir, char *av);
char **dirTok(char **env);
void loop(char **env);

void buffers1(char *line, char **command);
void buffers2(char **dir, char *combine);
void buffers3(char **tokens, char *buf);
void buffers4(char **tok, char *buf2);
void buffers5(char *dup);

char *checkPath(char **dir, char *command);
int execute(char *fullPath, char **command);
int exit_sh(char **command);
int cd(char **command);
int printenv(char **command);
int checkBuiltins(char *combine, char **command);
void handler(int sig);


#endif
