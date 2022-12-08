#include "shell.h"
#include "shell2.c"
/**
 * finalCommandTokens - fills every positin of the fianl tokens
 * array
 * @finalTokens: final tokens get by the command line
 * @comando: command enter by the user inn the command line
 */
void finalCommandTokens(char *finalTokens[], char comando[])
{
	char *puntero;
	int i = 0;

	puntero = strtok(comando, " ");
	while (puntero != NULL)
	{
		finalTokens[i] = puntero;
		puntero = strtok(NULL, " ");
		i++;
	}
	finalTokens[i] = NULL;
}

/**
 * executeBasicCommand - execute the commands entered by the user
 * @tokens: get the tokens to tokenized them
 * @comando: gets the command entered by the user
 */
void executeBasicCommand(char *tokens[], char comando[])
{
	execvp(tokens[0], tokens);
	printf("%s: the command could not by found\n", comando);
}

/**
 * executeCommandWithPipes - execute the command enter by the user with pipes
 * @args1: first line of args enterd by the useer
 * @args2: seconde line of args entered by the user
 *
 */
void executeCommandWithPipes(char *args1[], char *args2[])
{
	pid_t pid1, pid2;
	int pipefd[2]; /* , status1, status2; */

	pipe(pipefd);
	pid1 = fork();

	if (pid1 == 0)
	{
		dup2(pipefd[1], STDOUT_FILENO); /* opens the extreme writter */
		close(pipefd[0]); /* closes the extreme writter when isn't used */
		execvp(args1[0], args1);
		printf("the command could not by found\n");
	}

	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(pipefd[0], STDIN_FILENO); /* opens the extreme reader */
		close(pipefd[1]); /* closes the extreme reader if isn't used */
		execvp(args2[0], args2);
		printf("the command could not by found\n");
	}
	close(pipefd[0]);
	close(pipefd[1]);
	wait(NULL);
}

/**
 * executeOutputFileCommand - redirect the stdout to a file
 * @args: first argument
 * @fileName: file name to be redirect by the stdout
 */
void executeOutputFileCommand(char args[], char fileName[])
{
	close(STDOUT_FILENO);
	open(fileName, O_EXCL | O_CREAT | O_WRONLY, S_IRWXU);
	execute(args);
}

/**
 * execute - separetes and executes the differnt methods
 * @comando: gets the command entered by the user
 */
void execute(char comando[])
{
	int cantPipes = countPipeOcurrence(comando);
	int cantFluxCommand = countFluxOcurrence(comando);
	char copiacadena[MAX_COMMAND];
	char *finalTokens[FINAL_TOKENS];
	char *slicedCommand[MAX_COMMAND_PARTS];
	char copiacadena1[MAX_COMMAND_LR];
	char *tokensFirstArray[FINAL_LR];
	char copiacadena2[MAX_COMMAND_LR];
	char *tokensSecondArray[FINAL_LR];

	strcpy(copiacadena, comando);
	if (cantPipes == 0 && cantFluxCommand == 0)
	{
		finalCommandTokens(finalTokens, comando);
		executeBasicCommand(finalTokens, comando);
	}
	else if (cantPipes != 0 && cantFluxCommand == 0)
	{
		split(copiacadena, slicedCommand, "|");
		strcpy(copiacadena1, slicedCommand[0]);
		finalCommandTokens(tokensFirstArray, slicedCommand[0]);
		strcpy(copiacadena2, slicedCommand[1]);
		finalCommandTokens(tokensSecondArray, slicedCommand[1]);
		executeCommandWithPipes(tokensFirstArray, tokensSecondArray);
	}
	else if (cantFluxCommand == 1)
	{
		split(copiacadena, slicedCommand, ">");
		slicedCommand[1] = strtok(slicedCommand[1], " ");
		executeOutputFileCommand(slicedCommand[0], slicedCommand[1]);
	}
}

