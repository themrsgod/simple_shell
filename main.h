#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 80
#define BUFFER_SIZE 1024

int run_shell(char *args[MAX_LINE / 2 + 1], int should_run, char buffer[BUFFER_SIZE]);
int wait_for(void);
int execute_cild_process(char *args[MAX_LINE / 2 + 1], char buf[BUFFER_SIZE]);

#endif
