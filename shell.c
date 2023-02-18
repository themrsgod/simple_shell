#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"

/**
 * main - Entry point for the shell
 * Return: Always 0 (Success)
 */
int main(void)
{
	/* Command line arguments */
	char *args[MAX_LINE / 2 + 1];
	char buffer[BUFFER_SIZE]; /* Buffer for error output */
	int should_run = 1;		  /* Flag to determine when to exit program*/
	char *token;			  /* Tokenize input string into arguments*/
	int i = 0;

	while (should_run)
	{
		printf("$ "); /* Prompt for user input*/

		fflush(stdout); /* Flush output stream to ensure prompt is printed*/

		/* Read user input*/
		fgets(buffer, BUFFER_SIZE, stdin);

		/* Remove trailing newline character*/
		if (buffer[strlen(buffer) - 1] == '\n')
		{
			buffer[strlen(buffer) - 1] = '\0';
		}

		token = strtok(buffer, " ");

		while (token != NULL)
		{
			args[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		args[i] = NULL; /* Null-terminate argument list */
		should_run = run_shell(args, should_run, buffer);
	}

	return (0);
}
