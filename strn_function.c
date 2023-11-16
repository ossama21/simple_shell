#include "main.h"

/**
 * my_strncmp - Compares two strings
 * @s1: First string
 * @s2: Second string
 * @n: Maximum number of characters to compare
 *
 * Return: Result of the string comparison.
 */

int my_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		else if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (0);
}

/**
 * my_strncpy - Copies a string
 * @dest: Destination
 * @src: Source
 * @n: Maximum number of characters to copy
 *
 * Return: Destination buffer.
 */

char *my_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}

/**
 * my_strncat - Concatenates two strings
 * @dest: Destination string
 * @src: Source string
 * @n: Maximum number of characters to concatenate
 *
 * Return: Destination string.
 */
char *my_strncat(char *dest, const char *src, size_t n)
{
	size_t dest_len = my_strlen(dest);
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

	return (dest);
}
