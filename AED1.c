#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct agenda{
    char nome[100];
}agenda;

int menu(void);
void ler_string(char palavra[100], int tamanho);
int adicionar(agenda registros[], int Nmr);
void remover(agenda registros[], int Nmr);
void lista(agenda registros[], int Nmr);
int main(int argc, char **argv)
{
   int escolha;
   int cont=0, tam;
  agenda registros[5];
   for (;;){
        escolha=menu();
        switch(escolha){
        case 1:
          tam=adicionar(registros, cont);    
          cont=tam;
           break;
        
        case 2:
            remover(registros, cont);
            break;

        case 3:
            lista(registros, cont);
            break;

        case 4:
            exit(0);
            break;
        }

   }
    return 0;
    }

int menu (void){

int c=0;
do{

    printf("-- Menu:\n");
    printf("\t 1.Adicionar nome\n");
    printf("\t 2.Remover nome\n");
    printf("\t 3.Listar nomes\n");
    printf("\t 4.Sair\n");
    scanf("%d", &c);
    }while(c<=0 || c > 4);
    getchar();
    return c;
}

void ler_string(char palavra[100], int tamanho)
{
	int i = 0;
	char c;
	while((c=getchar())!='\n'){
		palavra[i]=c;
		i++;
		}
palavra[i]='\0';
}

int adicionar(agenda registros[], int Nmr){

printf("\t Nome: ");
ler_string(registros[Nmr].nome, 100);
Nmr++;
return Nmr;
}

void lista(agenda registros[], int Nmr){
int i;

for ( i = 0; i < Nmr; i++)
{
  if(registros[i].nome[0]!='\0'){
  printf("Nome: %s\n", registros[i].nome);
  printf("\n");
  }
}
}
void remover(agenda registros[], int Nmr){
    char nomes[100];
    int i, pos=0;
    printf("\t Nome que deseja remover: ");
    ler_string(nomes, 100);
    
    for(i=0;i<Nmr; i++){
    if(strcmp(registros[i].nome,nomes)==0){
        pos=i;
        }
    }
    
        registros[pos].nome[0]='\0';
    
}
