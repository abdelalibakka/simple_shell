#include "shell.h"

/**
 * bfree - frees a pointer and NULLs the address
 * @ptr: address of the pointer to free
 *
 * This function frees the memory allocated for the pointer and sets the pointer
 * to NULL.
 *
 * Return: 1 if the memory was freed successfully, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr != NULL && *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}

	return (0);
}
