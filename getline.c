#include <stdio.h>
#include <stdlib.h>
/**
* my_getline - get line custom function
* @lineptr: line pointer
* @n: size of input
* @stream: file input stream
*/
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
		if (!lineptr || !n || !stream) {
				return (-1);
		}

		size_t i = 0, max = *n;
		int c;

		while ((c = fgetc(stream)) != EOF) {
				if (i == max - 1) {
						max *= 2;
						*lineptr = realloc(*lineptr, max);
						if (!*lineptr) {
								return (-1);
						}
						*n = max;
				}

				(*lineptr)[i++] = c;

				if (c == '\n') {
						break;
				}
		}

		(*lineptr)[i] = '\0';

		if (i == 0 && c == EOF) {
				return (-1);
		}

		return (i);
}
