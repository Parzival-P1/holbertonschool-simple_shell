#include "xell.h"
/**
 * check_match - checks if a char matches with a string
 * @c: char to be checked by the function
 * @str: string to be checked by
 * Return: 1 if it matches, 0 if not.
 */

unsigned int check_match(char c, const char *str)
{
	for (i = 0; str[i] != '\0'; i++)
	{
		if (c == str[i])
			return (1);
	}
	return (0);
}

/**
 * new_strtok - custom strtok
 * @str: string to tokenize
 * @delim: delimiter ot tokenize
 * Return: ptr to the next token
 */
char *new_strtok(char *str, const char *delim)
{
	static char *token_start;
	static char *next_token;
	unsigned int i;

	if (str != NULL)
		next_token = str;
	token_start = next_token;
	if (token_start == NULL)
		return (NULL);
	for (i = 0; nezt_token[i] != '\0'; i++)
	{
		if (check_match(next_token[i], delim) == 0)
			break;
	}
	if (next_token[i] == '\0' || next_token[i] == '#')
	{
		next_token = NULL;
		return (NULL);
	}
	token_start = next_token + i;
	next_token  = token_start;
	for (i = 0; next_token[i] != '\0'; i++)
	{
		if (check_match(next_token[i], delim) == 1)
			break;
	}
	if (next_token[i] == '\0')
		next_token = NULL;
	else
	{
		next_token[i] = '\0';
		next_token = next_token + i + 1;
		if (*next_token == '\0')
			next_token = NULL;
	}
	return (token_start);
}

