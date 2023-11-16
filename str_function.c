#include "main.h"


/**
 * my_strlen - Calculate the length of a string.
 * @str: Input string.
 *
 * Return: Length of the string.
 */
size_t my_strlen(const char *str)
{
	const char *s;

	for (s = str; *s; ++s)
		;
	return (s - str);
}

/**
 * my_strdup - Duplicate a string.
 * @str: String to duplicate.
 *
 * Return: Pointer to the duplicated string.
 */
char *my_strdup(const char *str)
{
	size_t len = my_strlen(str) + 1;
	char *dup = malloc(len);

	if (dup != NULL)
		my_memcpy(dup, str, len);

	return (dup);
}

/**
 * my_strcmp - Compare two strings.
 * @s1: First string.
 * @s2: Second string.
 *
 * Return: Result of the string comparison.
 */

int my_strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;

	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

/**
 * my_strtok - Tokenize a string.
 * @str: String to be tokenized.
 * @delim: Delimiter characters.
 *
 * Return: Next token from the string.
 */
char *my_strtok(char *str, const char *delim)
{
	static char *buffer;

	char *token_start;

	if (str != NULL)
		buffer = str;

	if (buffer == NULL || *buffer == '\0')
		return (NULL);

	while (*buffer != '\0' && my_strchr(delim, *buffer) != NULL)
		buffer++;

	token_start = buffer;

	while (*buffer != '\0' && my_strchr(delim, *buffer) == NULL)
		buffer++;

	if (*buffer == '\0')
		return (token_start);

	*buffer = '\0';
	buffer++;

	return (token_start);
}

/**
 * my_strchr - Locate the first occurrence of a character in a string.
 * @str: String to be searched.
 * @c: Character to be located.
 *
 * Return: Pointer to first occurrence of character or NULL if not found
 */

char *my_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
