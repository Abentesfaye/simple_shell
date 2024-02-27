/**
 * _strcpyey - copies string to its destination
 * @enco: destination string
 * @half: source string
 * Return: dest
 */
char *_strcpyey(char *enco, char *half)
{
	int i;
	int j = strlene(half);

	for (i = 0; i < j; i++)
		enco[i] = half[i];
	return (enco);
}
/**
 * _strlene - length of a string
 * @last: the string value
 * Return: the number of charachters or length
 */
int _strlene(char *last)
{
	int i = 0;

	while (last[i] != '\0')
		i++;

	return (i);
}
