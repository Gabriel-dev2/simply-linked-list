#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct sAluno {
  int matricula;
  char nome[80];
  char curso[40];
  struct sAluno *prox;
}Aluno;

static Aluno *inicio,*fim;

// Criando um tipo booleano
enum boolean{
	true = 1, false = 0
};
typedef enum boolean bool;

//metodo para verificar se a matricula já existe
int ehRepetido(int matricula){
	Aluno *aux = inicio;
	bool repetido = false;

	while(aux != NULL){
		if(aux->matricula == matricula){
			repetido = true;
			break;
		}
		aux = aux->prox;
	}
	return repetido;
}

//Cadastrar no fim da lista
void Cadastrar(){
	Aluno *novo = (Aluno*)malloc(sizeof(Aluno));
	printf("Informe a matricula\n");
	scanf("%i",&novo->matricula);
	if (ehRepetido(novo->matricula) == 1){
			printf("Matricula ja cadastrada\n");
	}else{
		puts("Informe o nome\n");
		fflush(stdin);
		gets(novo->nome);
		puts("Informe o curso: \n");
		gets(novo->curso);

		if (inicio == NULL){
			inicio = novo;
		}else{
			fim->prox = novo;
		}
		fim = novo;
		fim->prox = NULL;

	}
}

void Listar() {
  if(inicio == NULL) {
   printf("Nao ha resultados para listar.");
  } else {
    Aluno *aux = inicio;

    while(aux != NULL) {
      printf("\nMatricula: %d \nNome: %s", aux->matricula,aux->nome);
      aux = aux->prox;
    }
  }
 }

void Consultar() {
  if(inicio == NULL) {
    printf("Nao ha resultados para listar.");
  } else {
   int matricula;
   printf("Informe a matricula: ");
   scanf("%d",&matricula);

   Aluno *aux = inicio;
   int achou = 0;

   while(aux != NULL) {
    if(aux->matricula == matricula){
     printf("%s \n%d \n%s",aux->nome,aux->matricula,aux->curso);
     achou = 1;
     aux = NULL;
    } else {
      aux = aux ->prox;
    }
     if(achou == 0) {
       printf("Nao foi possivel encontrar sua solicitacao.");
     }
   }
  }
}

void Remover() {
  if(inicio == NULL) {
    printf("Lista vazia");
  } else {
     int matricula;

     printf("Informe a matricula: ");
     scanf("%d",&matricula);
     int achou = 0;
     Aluno *aux = inicio;
     Aluno *ant = inicio;

     while(aux != NULL) {
    if(aux->matricula == matricula) {
    //unico elemento;
    if(aux == inicio && aux == fim) {
     inicio = NULL;
     fim = NULL;
    } //no inicio;
    else if(aux == inicio) {
     inicio = inicio->prox;
    }//no fim;
    else if(aux == fim) {
     fim = ant;
     fim->prox = NULL;
    } else {
      ant->prox = aux->prox;
    }
     free(aux);
     aux = NULL;
     printf("Aluno Removida!");
     achou = 1;
    } else {
      ant = aux;
      aux = aux->prox;
    }
     }//enquanto;
     if(achou == 0) {
      printf("A matricula informada nao foi encontrada.");
     }
  }
}//remover;
//Limpar espaços na memoria apos termino do programa;
void Destruir() {
  Aluno *aux;

  while(inicio != NULL) {
   aux = inicio;
   inicio = inicio->prox;
   free(aux);
  }
  fim = NULL;
  printf("Executado!");
 }

 int strcmp (const char* s1, const char* s2) {
     Aluno *aux = inicio;
     int igual = 0;
     char *curso;
     s1 = aux->curso;
     s2 = curso;
    while(aux != NULL) {
        if(strcmp(aux->curso, curso) == 0) {
        igual = 1;
        break;
      }
      aux = aux->prox;
    }
    return igual;
  }


 void Imprimir() {
  if(inicio == NULL) {
     printf("Lista Vazia");
  } else {
    Aluno *aux = inicio;
    while(aux != NULL) {
            char *curso;
            printf("Informe o curso: \n");
            scanf("%c",&curso);
       if(strcmp(aux->curso,curso) == 0){
        printf("\nAluno(a): %s \nMatricula: %d \nCurso: %s",aux->nome, aux->matricula, aux->curso);
       } else {
           printf("Nenhum Aluno neste curso.\n");
       }
       aux = aux->prox;
    }
  }
 }

 int main(int argc, char *argv[]) {
  int op;
  while(op > 0){
        system("CLS");
        printf("\n--------------------------------Menu------------------------------------------\n");
        printf("\n0 - Sair\t");
        printf("1 - Cadastrar\t");
        printf("2 - Listar\t");
        printf("3 - Consultar\t\n");
        printf("\n");
        printf("4 - Remover\t");
        printf("5 - Destruir\t");
        printf("6 - Imprimir\t");
          scanf("%d",&op);
       system("PAUSE");
       if(op == 1){
        system("CLS");
        Cadastrar();
        system("PAUSE");
       }else if(op == 2){
           system("CLS");
           Listar();
           system("PAUSE");
       } else if(op == 3){
           system("CLS");
            Consultar();
           system("PAUSE");
       } else if(op == 4){
           system("CLS");
            Remover();
           system("PAUSE");
       } else if(op == 5){
           system("CLS");
            Destruir();
           system("PAUSE");
       } else if(op == 6){
           system("CLS");
            Imprimir();
           system("PAUSE");
       }
  }
  return 0;
 }

