#include "main.h"

/**
 * run_shell - runs the shell given arguments
 * @args: arguments for the commant
 * @flag: Flag to determine when to exit program
 * @buf: Buffer for error output
 * Return: integer
 */
int run_shell(char *args[MAX_LINE / 2 + 1], int flag, char buf[BUFFER_SIZE])
{
	/* Exit program if user enters "exit"*/
	if (strcmp(args[0], "exit") == 0)
	{
		flag = 0;
	}
	else
	{
		/* Fork process to execute command*/
		pid_t pid = fork();

		if (pid < 0)
		{
			printf("Fork failed.\n");
		}
		else if (pid == 0)
		{
			int return_value = execute_cild_process(args, buf);

			exit(return_value);
		}
		else
		{
			return (wait_for());
		}
	}
	return (flag);
}

/**
 * execute_cild_process - child process to execute command
 * @args: arguments for the commant
 * @buf: Buffer for error output
 * Return: integer
 */
int execute_cild_process(char *args[MAX_LINE / 2 + 1], char buf[BUFFER_SIZE])
{
	if (execvp(args[0], args) == -1)
	{
		sprintf(buf, "Error executing command '%s'\n", args[0]);
		perror(buf);
		return (1);
	}
	else
	{
		return (-1);
	}
}

/**
 * wait_for - Parent process waits for child to complete
 * Return: void
 */
int wait_for(void)
{
	int status;

	wait(&status);
	return (status);
}
