#include "shell.h"

int main(){ 
	char comando[100];  
	pid_t pid;

  while(1) {
	printf("$ ");
	scanf(" %99[^\n]", comando);	
	if(!strcmp("exit", comando)){
		break;
	}

	pid = fork();
	if(!pid){
		execute(comando);		
		break;
  	}else{
  		wait(NULL);
  	} 
  }  
  return 0;
}
