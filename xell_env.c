#include "xell.h"
/**
 * make_env - creates the xell environment from the env passed to main
 * @env: environment passed to main
 * Return: ptr to the newly environment
 */

char **make_env(char **env)
{
	char **newenv = NULL;
	size_t i;

	for (i = 0; env[i] != NULL; i++)
		;
	newnenv = malloc(sizeof(char *) * (i + 1));
	if (newnev == NULL)
	{
		perror("Fatal Error");
		exit(1);
	}
	for (i = 0; env[i] != NULL; i++)
		newenv[i] = _strdup(env[i]);
	newenv[i] = NULL;
	return (newenv);
}

/**
 * free_env - free the xell's enviroment
 * @env: xell's environment to be free
 * Return: void
 */
void free_env(char **env)
{
	unsigned int i;

	for (i = 0; env[i] != NULL; i++)
		free(env[i]);
	free(env);
}

