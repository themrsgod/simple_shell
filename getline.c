#include "main.h"

/**
* getline - get line custom function
* @lineptr: line pointer
* @n: size of input
* @stream: file input stream
*/
ssize_t getline(char **lineptr, size_t *n, FILE *stream) {
    if (!lineptr || !n || !stream) return -1;
    ssize_t count = 0, capacity = *n;
    char *buffer = *lineptr ? *lineptr : malloc(capacity = 128);
    if (!buffer) return -1;
    for (;;)
	{
        int c = fgetc(stream);
        if (c == EOF || c == '\n') break;
        if (++count >= capacity) buffer = realloc(buffer, capacity *= 2);
        if (!buffer) return -1;
        buffer[count - 1] = c;
    }
    if (count == 0 && c == EOF) return -1;
    buffer[count] = '\0';
    *lineptr = buffer;
    *n = capacity;
    return count;
}