#include "shell.h"

/**
 * _memset - fills memory with a constant byte
 * @s: pointer to the memory area
 * @b: the byte to fill *s with
 * @n: the number of bytes to be filled
 *
 * Return: pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;
	char *ptr = s;

	for (i = 0; i < n; i++)
		*(ptr++) = b;
	return s;
}

/**
 * free_str_array - frees an array of strings
 * @arr: the array of strings
 *
 * Return: void
 */
void free_str_array(char **arr)
{
	char **ptr = arr;

	if (!arr)
		return;

	while (*arr)
		free(*(arr++));

	free(ptr);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to the previously allocated block
 * @old_size: size of the old block
 * @new_size: size of the new block
 *
 * Return: pointer to the reallocated memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;

	if (!ptr)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);

	if (new_size < old_size)
		old_size = new_size;

	_memset(new_ptr, 0, new_size);
	while (old_size--)
		new_ptr[old_size] = ((char *)ptr)[old_size];

	free(ptr);
	return (new_ptr);
}
