/*
  Fabrício de Souza Maruta  RA:138313

  Laboratorio 1 - Somador

  Identifica e soma os numeros de uma sequencia a ser digitada como entrada.

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

int fatorial(int num);  /*Funcao auxiliar para calculo do fatorial*/
int final_test(char num[MAX]);

int main(){
  char palavra[MAX]; /*String para ler cada elemento escrito como entrada*/
  float soma = 0;
  int tam;

  while(scanf("%s", palavra)!= EOF){ /*Le entrada ate que seja pressionado o atalho correspondente à EOF (Linux: ctrl+d)*/
    if(atof(palavra) != 0 && (palavra[strlen(palavra) -1] != '!') && (final_test(palavra) != 1)){ /*Vê se é possível converter de string pra int*/
        soma += atof(palavra);
      }

    else if(atoi(palavra) != 0 && (palavra[strlen(palavra) -1] != '!') && (final_test(palavra) != 1)){ /*Vê se é possível converter de string pra float*/
      soma += atoi(palavra);                /*Se for um numero puro, soma*/
    }
    else {
      tam = strlen(palavra);
      if(tam != 1){
        if(palavra[tam-1] == '!'){    /*Verifica se ultimo algarismo eh "!", se for, retira da string e calcula o fatorial*/
        palavra[tam-1] = '\0';
          if(atoi(palavra) != 0){
            soma += fatorial(atoi(palavra));
          }
        }
      }

    }
  }

  printf("%.2f\n", soma);
}


int fatorial(int num){ /*Funcao para calcular fatorial de um numero*/
  int fat;
  if(num<=1){
      return 1;
  }
  else{
    fat = num*fatorial(num-1);
    return fat;
  }
}

/* Funcao foi feita devido as funcoes atoi e atof, pois se for numero seguido de palavra,
  as funcoes ignoram as letras e transformam apenas os primeiros numeros em int e float */
int final_test(char num[MAX]){ /*funcao verifica se nao eh um numero seguido de letras sem espaco*/
  int tam = strlen(num);
  for(int i = 0; i<tam; i++){
    if((num[i] < 46 || num[i] > 57) || num[i] == '!'){
      return 1; //Tem palavra no meio do numero
    }
  }
  return 0;
}
