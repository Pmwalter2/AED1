#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct atributos{
    char nome[50];
}agenda;

typedef struct variaveis
{
   int i;
   int qntd;
   int j;
   int cont;
   int escolha;
   char nomeAux[50];
   agenda tmpNome;
}Var;

struct Nodo{
    int tamanho;
    char nome[30];
    int escolha;
    struct Node *prox;
    struct Node *ant;
};

typedef struct Nodo nodo;

nodo *inicio;
nodo *fim;


void *pBuffer=NULL;
Var *v;


void insere();
void apagar();
void listar();
void insertionsort();
void buscarNome();
void Encadeada();
int menu();
void inicioLista();
void insereInicio();
void insereFim();
void removeIni();
void removeFim();
void listaLista();



int main()
{
	pBuffer=malloc(sizeof(Var));
    v=pBuffer;
    v->qntd=0;

do{
printf("\n1.Insere contato");
printf("\n2.Apaga");
printf("\n3.Listar");
printf("\n4.Ordenar");
printf("\n5.Buscar nome");
printf("\n6.Lista duplamente encadeada");
printf("\n0.Sair\n");
scanf("%d", &v->escolha);

switch(v->escolha){

    case 1:
    insere();
    break;

    case 2:
    apagar();
    break;

    case 3:
    listar();
    break;

    case 4:
    insertionsort();
    listar();
    break;

    case 5:
    buscarNome();
    break;

    case 6:
    Encadeada();

    case 0:
    return 0;
    break;

}
}while(v->escolha!=0);

	return 0;
}

void insere(){
    agenda *novo;
    v=pBuffer;
    v->qntd=v->qntd+1;

    pBuffer=realloc(pBuffer, sizeof(Var)+ (sizeof(agenda)*(v->qntd)));
    v=pBuffer;
    novo=pBuffer+(sizeof(Var)+ (sizeof(agenda)*(v->qntd-1)));

    printf("\nNome: ");
    scanf("%s", novo->nome);
}

void listar(){
    agenda *listar;
    
    listar=pBuffer+sizeof(Var);

    if(v->qntd >0){
        for (v->i=0;v->i<v->qntd;v->i++){
            printf("\nNome: %s\n", listar->nome);
            listar++;
        }
    }else{
        printf("\nAgenda vazia\n");
    }
}

void apagar(){
    agenda *escolher;
    escolher=pBuffer+sizeof(Var);

    printf("\nNome a ser excluido: ");
    scanf("%s", v->nomeAux);

    for ( v->i = 0; v->i<v->qntd; v->i++){
        if(strcmp(v->nomeAux, escolher->nome)==0){
            v->qntd--;
            for (v->j=v->i;v->j<v->qntd;v->j++){
                escolher[v->j]=escolher[v->j+1];
            }
            pBuffer=realloc(pBuffer, sizeof(Var)+ (sizeof(agenda)*(v->qntd)));
        }
    }
}

void insertionsort(){
    agenda *pessoa;
    pessoa=pBuffer+sizeof(Var);

    for (v->i = 1; v->i < v->qntd; v->i++) {
       v->tmpNome=pessoa[v->i];
       v->j=v->i-1;

       while(v->j>=0 && (strcmp(v->tmpNome.nome, pessoa[v->j].nome)<0)){
           pessoa[v->j+1]=pessoa[v->j];
           v->j--;
       }
       pessoa[v->j+1]=v->tmpNome;
    }
    
}

void buscarNome(){
    agenda *pessoa;
    pessoa=pBuffer+sizeof(Var);
    printf("\nNome: ");
    scanf("%s", v->nomeAux);

    for ( v->i = 0; v->i <v->qntd-1; v->i++){
        if(strcmp(v->nomeAux, pessoa->nome)==0){
        printf("\n Nome: %s", pessoa->nome);
        printf("\nNome encontrado");
        }
        pessoa++;
    }
}

void Encadeada(){
int escolha;
inicioLista();
 while(escolha != 6){
    printf("\n1.Inserir inicio\n2.Inserior fim\n3.Remove inicio\n4.Remove final\n5.Insere posição\n6.Listar\n7.Sair\n");
    scanf("%d", escolha);
    switch(escolha){
        case 1:
        insereInicio();
        break;

        case 2:
        insereFim();
        break;

        case 3:
        removeIni();
        break;

        case 4:
        removeFim();
        break;

        //case 5:
       // inserePos();
        //break;

        case 5:
        listaLista();
        break;

        case 6:
        printf("\nTchau");
        break;

        default:
        break;
    }
}
}

void inicioLista(){
    inicio=NULL;
    fim=NULL;
}

void insereInicio(){
    nodo *novo=(nodo *)malloc(sizeof(nodo));
    printf("\nNome: ");
    scanf("%s", novo->nome);
    if(inicio==NULL){
        inicio=novo;
        fim=novo;
    }else{
        nodo *atual;
        atual=inicio;
        novo->prox=atual;
        atual->ant=novo;
        inicio=novo;
    }
    novo->tamanho++;
}

void insereFim(){
    nodo *novo=(nodo *)malloc(sizeof(nodo));
    printf("\nNome: ");
    scanf("%s", novo->nome);
    if(inicio==NULL){
        inicio=novo;
        fim=novo;
    }else{
        nodo *atual;
        atual=fim;
        novo->ant=atual;
        atual->prox=novo;
        fim=novo;
    }
    novo->tamanho--;
}

void removeIni(){
    nodo *novo=(nodo *)malloc(sizeof(nodo));
    nodo *sair=inicio;
    inicio=sair->prox;
    inicio->ant=NULL;
    novo->tamanho--;
}

void removeFim(){
    nodo *novo=(nodo *)malloc(sizeof(nodo));
    nodo *sair=fim;
    fim=sair->ant;
    fim->prox=NULL;
    novo->tamanho--;
}

void listaLista(){
    nodo *atual;
    atual=inicio;
    while(atual){
        printf("\n%s", atual->nome);
        atual=atual->prox;
    }
}