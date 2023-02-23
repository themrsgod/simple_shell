#include "main.h"

/**
* getline - get line custom function
* @lineptr: line pointer
* @n: size of input
* @stream: file input stream
*/
ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{
	if (!lineptr || !n || !stream)
	{
		return (-1);
	}

	size_t buffer_size = *n;
	char *buffer = *lineptr;

	if (!buffer || buffer_size < INITIAL_BUFFER_SIZE)
	{
		buffer_size = INITIAL_BUFFER_SIZE;
		buffer = (char *) malloc(buffer_size);
		if (!buffer)
		{
			return (-1);
		}
	}

	size_t i = 0;
	int c;

	while ((c = getc(stream)) != EOF)
	{
		if (i >= buffer_size - 1)
		{
			buffer_size *= 2;
			char *new_buffer = (char *) realloc(buffer, buffer_size);

			if (!new_buffer)
			{
				free(buffer);
				return (-1);
			}
			buffer = new_buffer;		
		}

		buffer[i++] = c;

		if (c == '\n')
		{
			break;
		}
	}

	buffer[i] = '\0';
	*lineptr = buffer;
	*n = buffer_size;

	if (i == 0 && c == EOF)
	{
		return (-1);
	}

	return (i);
}
