#include "shell.h"
/**
 * countBySpace - count the num of tokens in the command line
 * @comando: gets the command enter by the user
 * Return: the number of charachters in the command line
 */

int countBySpace(char comando[])
{
	char *puntero;

	int cont = 0;

	puntero = strtok(comando, " ");
	while (puntero != NULL)
	{
		cont++;
		puntero = strtok(NULL, " ");
	}
	return (cont);
}

/**
 * countPipeOcurrence - count if there's a pipe in the command line
 * @comando: gets the command enter by the user
 * Return: Always 0 (success)
 */
int countPipeOcurrence(char comando[])
{
	if (strchr(comando, '|') != NULL)
	{
		return (1);
	}
	return (0);
}

/**
 * countFluxOcurrence - counts if there's an '>' in the command line
 * @comando: gets the command enter by the user
 * Return: Always 0 (success)
 */
int countFluxOcurrence(char comando[])
{
	if (strchr(comando, '>') != NULL)
	{
		return (1);
	}
	return (0);
}

/**
 * split - splits the command in 2 subarrays if finds the pipe
 * or the '>' simbol
 * @comando: gets the command enter by the user
 * @slicedCommand: slice the arr
 * @c: gets the char enter by the user
 */

void split(char comando[], char *slicedCommand[], char c[])
{
	char *puntero;
	int i = 0;

	puntero = strtok(comando, c);
	while (puntero != NULL)
	{
		slicedCommand[i] = puntero;
		puntero = strtok(NULL, c);
		i++;
	}
}

