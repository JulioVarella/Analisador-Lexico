//=======================================//
//           ANALISADOR LÉXICO           //
//      Julio Cesar Benelli Varella      //
//             RA: 181024594             //
//           Feito no Windows            //
//     compilado com gcc no terminal     //
//=======================================//

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char proximo (FILE *arq, int *numLinha){
  char proximo;
  proximo = getc(arq);
  if(proximo == 10){ // newline
    *numLinha += 1;
   // printf("\n%d\t", *numLinha);
  }
  return proximo;
}

void erro() {
	printf("Erro!");
	//getchar();
    return;
}

void verificaToken (char token[100]){
  int i = 0;
  char identificador[] = "IDENTIFICADOR_";
  char operador[] = "OPERADOR_";
  char numero[] = "NUMERO_";
  while (token[i]!='\0') { // até o fim do token deixa tudo maisuculo
    token[i] = toupper(token[i]);
    i++;
  }
  if(!strcmp(token, "PROGRAM"))
    printf("PALAVRA_RESERVADA_PROGRAM ");
  else if(!strcmp(token, "LABEL"))
    printf("PALAVRA_RESERVADA_LABEL ");
  else if(!strcmp(token, "VAR"))
    printf("PALAVRA_RESERVADA_VAR ");
  else if(!strcmp(token, "PROCEDURE"))
    printf("PALAVRA_RESERVADA_PROCEDURE ");
  else if(!strcmp(token, "FUNCTION"))
    printf("PALAVRA_RESERVADA_FUNCTION ");
  else if(!strcmp(token, "BEGIN"))
    printf("PALAVRA_RESERVADA_BEGIN ");
  else if(!strcmp(token, "END"))
    printf("PALAVRA_RESERVADA_END ");
  else if(!strcmp(token, "IF"))
    printf("PALAVRA_RESERVADA_IF ");
  else if(!strcmp(token, "THEN"))
    printf("PALAVRA_RESERVADA_THEN ");
  else if(!strcmp(token, "ELSE"))
    printf("PALAVRA_RESERVADA_ELSE ");
  else if(!strcmp(token, "WHILE"))
    printf("PALAVRA_RESERVADA_WHILE ");
  else if(!strcmp(token, "DO"))
    printf("PALAVRA_RESERVADA_DO ");
  else if(!strcmp(token, "OR"))
    printf("PALAVRA_RESERVADA_OR ");
  else if(!strcmp(token, "AND"))
    printf("PALAVRA_RESERVADA_AND ");
  else if(!strcmp(token, "DIV"))
    printf("PALAVRA_RESERVADA_DIV ");
  else if(!strcmp(token, "NOT"))
    printf("PALAVRA_RESERVADA_NOT ");
  else{// identificador
    strcat(identificador, token);
    strcat(identificador, " ");
    printf("%s", identificador);
  }

}

void codigo (){
  int numLinha = 1, i;
  printf("1\t");
  char token[50], caracter, operador[] = "OPERADOR_", numero[] = "NUMERO_";
  FILE *arq;
  arq = fopen("Trab1_Compiladores.txt","rb");
  if (arq == NULL)
    printf("Erro ao abrir arquivo!");
  else
    while(caracter != EOF){ //até o fim do arquivo
      //inicia token
      strcpy(token, "");
      strcpy(operador, "OPERADOR_");
      strcpy(numero, "NUMERO_");
      i = 0; 
      caracter = proximo(arq, &numLinha);

      //verifica se é : ou :=
      if(caracter == 58 ){
        token[i] = caracter;
        i++;
        caracter = proximo(arq, &numLinha);
        if(caracter == 61){
            token[i] = '=';
            i++;
            token[i] = '\0';
            strcat(operador,token);
            strcat(operador," ");
            printf("%s", operador);
        }else{
            fseek(arq,-1,SEEK_CUR);
            token[i] = '\0';
            strcat(operador,token);
            strcat(operador," ");
            printf("%s", operador);
        }//else
      }else if(caracter == 60 || caracter == 62){ //verifica se é < > ou <= >=
        token[i] = caracter;
        i++;
        caracter = proximo(arq, &numLinha);
        if(caracter == 61){
            token[i] = '=';
            i++;
            token[i] = '\0';
            strcat(operador,token);
            strcat(operador," ");
            printf("%s", operador);
        }else{
            fseek(arq,-1,SEEK_CUR);
            token[i] = '\0';
            strcat(operador,token);
            strcat(operador," ");
            printf("%s", operador);
        } //else
      }else if((caracter >= 40 && caracter <= 46) || (caracter >=58  && caracter <=62)){ // verefica outros simbolos especiais
            token[i] = caracter;
            i++;
            token[i] = '\0';
            strcat(operador,token);
            strcat(operador," ");
            printf("%s", operador);
      }else if(((caracter >= 65) && (caracter <= 90)) || ((caracter >=97) && (caracter <= 122))){ //verifica letras     
        while (((caracter >= 65) && (caracter <= 90)) || ((caracter >=97) && (caracter <= 122)) ||  //enquanto for letras ou
        ((caracter >=48) && (caracter <= 57))  || (caracter == 95)) { //numeros ou _
          token[i] = caracter;
          i++;
          caracter = proximo(arq, &numLinha);                  
        }//while
        fseek(arq,-1,SEEK_CUR); //volta o ponteiro do ultimo proximo() que quebrou o while
        token[i] = '\0';
        verificaToken(token);
      }else if ((caracter >=48) && (caracter <= 57)){ // verifica se eh numero
        while ((caracter >=48) && (caracter <= 57)){ //enquanto for numero
            token[i] = caracter;
            i++;
            caracter = proximo(arq, &numLinha);
            if((caracter >= 65 && caracter <=90) || (caracter >=97) && (caracter <= 122)) //numero seguido de letra = erro
                erro();
        }//while
        fseek(arq,-1,SEEK_CUR); //volta o ponteiro do ultimo proximo() que quebrou o while
        token[i] = '\0';
        strcat(numero,token);
        strcat(numero," ");
        printf("%s", numero);
      }else if(caracter == 10) //printa o numero da linha
          printf("\n%d\t",numLinha);
    }//while
}

int main (){
  codigo();
}
