#include "main.h"

/**
 * my_memcpy - Copies memory.
 * @dest: Pointer to the destination.
 * @src: Pointer to the source.
 * @n: Number of bytes to copy.
 *
 * Return: Pointer to the destination memory.
 */

void *my_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *cdest = (unsigned char *)dest;

	const unsigned char *csrc = (const unsigned char *)src;

	size_t i;

	if (dest == NULL || src == NULL)
		return (NULL);

	for (i = 0; i < n; i++)
		cdest[i] = csrc[i];

	return (dest);
}
