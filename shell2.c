/* Cuenta la cantidad de tokens en el comando (cuenta un token cuando encuentra un espacio) */
int countBySpace(char comando[]){
  char * puntero;
  int cont = 0;
  puntero = strtok(comando, " ");

  while(puntero != NULL){
    cont++;
    puntero = strtok(NULL, " ");
  }
  return cont;
}

/* Cuenta si hay un pipe en el comando */
int countPipeOcurrence(char comando[]){
  if(strchr(comando, '|')!=NULL){ 
    return 1;
  }
  return 0;
}

/* Cuenta si hay un '>' en el comando */
int countFluxOcurrence(char comando[]){
  if(strchr(comando, '>')!=NULL){ 
    return 1;
  }
  return 0;
}

/* Separa el comando en dos subarreglos cuando encuentra el pipe o el '>' */
void split(char comando[], char *slicedCommand[], char c[]){
  char * puntero; 
  int i = 0;
  puntero = strtok(comando, c);
  
  while(puntero != NULL){
    slicedCommand[i] = puntero;
    puntero = strtok(NULL, c);
    i++;
  } 
}
