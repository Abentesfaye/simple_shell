#include "main.h"
/**
 *my_getline - a function which reads line from a stream
 *@buffer: address of the string to be stored
 *@buflen: buffer size
 *
 *Return: buffer size
 */
int my_getline(char *buffer, int buflen)
{
    static char *buffer_pos = NULL;
    static int buffer_size = 0;
    int read_size = 0;
    int total_size = 0;
    char c;
    /* If buffer_pos is NULL or buffer_pos has reached the end of the buffer, read more data from stdin */
    if (buffer_pos == NULL || buffer_pos - buffer >= buffer_size)
    {
        buffer_size = read(STDIN_FILENO, buffer, buflen);
        buffer_pos = buffer;
    }
    /* Read character by character from buffer */
    while (1)
    {
        c = *buffer_pos;
        buffer_pos++;
        /* Break loop on newline or end of buffer */
        if (c == '\n' || c == '\0' || total_size == buflen - 1)
            break;
        buffer[total_size++] = c;
    }
    buffer[total_size] = '\0'; // Null-terminate the string
    return total_size;
}
