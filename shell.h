#ifndef _SHELL
#define _SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_COMMAND 200
#define MAX_COMMAND_LR 200
#define FINAL_TOKENS 40
#define FINAL_LR 20
#define MAX_COMMAND_PARTS 2

int countBySpace(char comando[]);
int countPipeOcurrence(char comando[]);
int countFluxOcurrence(char comando[]);
void split(char comando[], char *slicedCommand[], char c[]);
void finalCommandTokens(char *finalTokens[], char comando[]);
void executeBasicCommand(char *tokens[], char comando[]);
void executeCommandWithPipes(char *args1[], char *args2[]);
void executeOutputFileCommand(char args[], char fileName[]);
void execute(char comando[]);

#endif

