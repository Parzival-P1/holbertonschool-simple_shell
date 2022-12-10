#include "xell.h"
/**
 * _realloc - reallocates a ptr to double the space
 * @ptr: ptr to the prev array
 * @size: ptr to the number of elements in the prev array
 * Return: ptr to the new array
 */

char **_realloc(char **ptr, size_t *size)
{
	char **new;
	size_t i;

	new = malloc(sizeof(char *) * ((*size) + 10));
	if (new == NULL)
	{
		free(ptr);
		return (NULL);
	}
	for (i = 0; i < (*size); i++)
	{
		new[i] = ptr[i];
	}
	*size += 10;
	free(ptr);
	return (new);
}

