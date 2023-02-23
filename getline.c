#include "main.h"

/**
* getline - get line custom function
* @lineptr: line pointer
* @n: size of input
* @stream: file input stream
*/
#include <stdio.h>
#include <stdlib.h>

ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{
	if (!lineptr || !n || !stream)
		return (-1);

	size_t bsz = *n, i = 0;
	char *buf = *lineptr ? *lineptr : malloc(bsz = 64);
	if (!buf)
		return (-1);
		
	int c;
	
	while ((c = getc(stream)) != EOF)
	{
		if (i >= bsz - 1)
		{
			buf = realloc(buf, bsz *= 2);
			if (!buf)
				return (-1);
		}
		buf[i++] = c;
		if (c == '\n')
			break;
	}

	buf[i] = '\0';
	*lineptr = buf;
	*n = bsz;

	if (i == 0 && c == EOF)
		return (-1);

	return (i);
}
