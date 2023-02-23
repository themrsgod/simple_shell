#include <stdio.h>
#include <stdlib.h>
/**
* getline - get line custom function
* @lineptr: line pointer
* @n: size of input
* @stream: file input stream
*/

size_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
  size_t bsz, i;
  char *buf;
  int c;

  if (!lineptr || !n || !stream) {
    return (-1);
  }

  bsz = *n;
  i = 0;
  buf = *lineptr ? *lineptr : malloc(bsz = 64);

  if (!buf) {
    return (-1);
  }

  while ((c = getc(stream)) != EOF) {
    if (i >= bsz - 1) {
      char *new_buf = realloc(buf, bsz *= 2);

      if (!new_buf) {
	free(buf);
	return (-1);
      }

      buf = new_buf;
    }

    buf[i++] = c;

    if (c == '\n') {
      break;
    }
  }

  buf[i] = '\0';
  *lineptr = buf;
  *n = bsz;

  if (i == 0 && c == EOF) {
    return (-1);
  }

  return (i);
}
