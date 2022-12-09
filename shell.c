#include "shell.h"
#include "shell2.c"

/*Llena cada posicion del arreglo finalTokens con cada token presente en el comando */
void finalCommandTokens(char * finalTokens[], char comando[]){
  char * puntero;   
  int i = 0;
  puntero = strtok(comando, " ");
  
  while(puntero != NULL){
    finalTokens[i] = puntero;
    puntero = strtok(NULL, " ");
    i++;
  }
  finalTokens[i]=NULL;
}

/*--------------------------------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------EJECUCION DE COMANDOS-------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------*/

void executeBasicCommand(char *tokens[], char comando[]){     
  execvp(tokens[0], tokens); /* , environ); */
  printf("%s: no se encontró la orden\n", comando);
}

void executeCommandWithPipes(char *args1[], char *args2[]){  
  pid_t pid1, pid2;  
  int pipefd[2]; /* , status1, status2; */
  
  pipe(pipefd);
  pid1 = fork();

  if (pid1==0){
    dup2(pipefd[1], STDOUT_FILENO); /* Abre el extremo de escritura */
    close(pipefd[0]); /* Cierra el extremo de lectura ya que no se utilizara */
    execvp(args1[0], args1); /* , environ); */   
    printf("No se encontró la orden\n");
  }

  pid2 = fork();
  if(pid2 == 0){
    dup2(pipefd[0], STDIN_FILENO); /* Abre el extremo de lectura */
    close(pipefd[1]); /* Cierra el extremo de escritura ya que no se utiliza */
    execvp(args2[0], args2); /* , environ); */
    printf("No se encontró la orden\n");
  }

  close(pipefd[0]);
  close(pipefd[1]);
  wait(NULL);
}

/*Redirecciona la salida estandar a un archivo */
void executeOutputFileCommand(char args[], char fileName[]){
    close(STDOUT_FILENO);
    open(fileName, O_EXCL|O_CREAT|O_WRONLY, S_IRWXU);      
    execute(args);      
}


/*--------------------------------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------FUNCION DE CONTROL----------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------*/

/*Recibe el comando y dependiendo del tipo, lo separa y llama a los metodos que lo ejecutan
Tipos: 1) sin pipes y sin flujo; 2) con pipes y sin flujo; 3) con flujo */
void execute(char comando[]){
  /* int commandSize = strlen(comando);  */
  int cantPipes = countPipeOcurrence(comando);
  int cantFluxCommand = countFluxOcurrence(comando);  
  char copiacadena[MAX_COMMAND]; /* char copiacadena[commandSize]; */
  char *finalTokens[FINAL_TOKENS];
  char *slicedCommand[MAX_COMMAND_PARTS];
  char copiacadena1[MAX_COMMAND_LR];
  char *tokensFirstArray[FINAL_LR];
  char copiacadena2[MAX_COMMAND_LR];
  char *tokensSecondArray[FINAL_LR];
/* 	char * slicedCommand[2]; */

  strcpy(copiacadena, comando);

  if(cantPipes==0 && cantFluxCommand==0){     
    /* int cantTokens = countBySpace(copiacadena); */
    /* char *finalTokens[cantTokens+1]; */    
    finalCommandTokens(finalTokens, comando);   
    executeBasicCommand(finalTokens, comando);            
  }else if(cantPipes!=0 && cantFluxCommand==0){  	    
    split(copiacadena, slicedCommand, "|");    

    /* separar tokens del primer subarreglo */
    /* char copiacadena1[strlen(slicedCommand[0])]; */
    strcpy(copiacadena1, slicedCommand[0]);
    /* int sizeFirstArray = countBySpace(copiacadena1);
    char *tokensFirstArray[sizeFirstArray+1]; */
    finalCommandTokens(tokensFirstArray, slicedCommand[0]);
    
    /* separar tokens del segundo subarreglo */
    /* char copiacadena2[strlen(slicedCommand[1])]; */
    strcpy(copiacadena2, slicedCommand[1]);
    /* int sizeSecondArray = countBySpace(copiacadena2);
    char *tokensSecondArray[sizeSecondArray+1]; */
    finalCommandTokens(tokensSecondArray, slicedCommand[1]);    

    executeCommandWithPipes(tokensFirstArray, tokensSecondArray);
  }else if(cantFluxCommand==1){
  	split(copiacadena, slicedCommand, ">");
  	slicedCommand[1] = strtok(slicedCommand[1], " ");  	
  	executeOutputFileCommand(slicedCommand[0], slicedCommand[1]);
  }
}
