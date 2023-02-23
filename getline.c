#include <stdio.h>
#include <stdlib.h>

/**
* my_getline - get line custom function
* @lineptr: line pointer
* @n: size of input
* @stream: file input stream
* Return: size_t
*/
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
		size_t i, max;
		int c;

		if (!lineptr || !n || !stream)
			return (-1);
		i = 0;
		max = *n;

		while ((c = fgetc(stream)) != EOF)
		{
			if (i == max - 1)
			{
					max *= 2;
					char *new_ptr = realloc(*lineptr, max);
			
					if (!new_ptr)
							return (-1);
					*lineptr = new_ptr;
					*n = max;
			}
			(*lineptr)[i++] = c;
			if (c == '\n')
					break;
		}
		(*lineptr)[i] = '\0';

		if (i == 0 && c == EOF)
			return (-1);
		return (i);
}
