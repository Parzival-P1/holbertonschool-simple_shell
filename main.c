#include "shell.h"

int main(){ 
  while(1) {
    char comando[100];  
	printf("$ ");
	scanf(" %99[^\n]", comando);	
	if(!strcmp("exit", comando)){
		break;
	}

	pid_t pid = fork();
	if(!pid){
		execute(comando);		
		break;
  	}else{
  		wait(NULL);
  	} 
  }  
  return 0;
}
