#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Pessoas{
    char nome[50];
    char telefone[15];
}Pessoas;

typedef struct vari{
int i;
int escolha;
int nmrPes;
int tambuffer;
char auxNome[50];
int apagados;
int flag;
}vari;

void *pBuffer;
vari *var;
Pessoas *pessoa;
Pessoas *auxRmv;

void menu (void){
    
    printf("\t1.Inserir\n");
    printf("\t2.Excluir\n");
    printf("\t3.Listar\n");
    printf("\t4.Buscar nome\n");
    printf("\t5.Sair\n");
    
}

void insere(){
    var->nmrPes=var->nmrPes+1;//Adiciona mais uma na agenda
    var->tambuffer=sizeof(vari)+sizeof(Pessoas)*var->nmrPes;//Aloca espaço para inserir
    pBuffer=realloc(pBuffer,var->tambuffer);//Realoca o pBuffer para mais uma posição
    var=pBuffer;
    pessoa=pBuffer+var->tambuffer -sizeof(Pessoas);
    printf("\nNome: ");
    scanf("%s", pessoa->nome);
    printf("\nTelefone: ");
    scanf("%s", pessoa->telefone);

}

void listar(){
    printf("\nLista\n");
    pessoa=sizeof(vari)+pBuffer;
    for(var->i=0;var->i<var->nmrPes;var->i++){
        printf("\nNome: %s", pessoa->nome);
        printf("\nTelefone: %s", pessoa->telefone);
        pessoa++;
    }
    printf("\n");
}

void buscar(){
pessoa=pBuffer+sizeof(vari);
var->flag=-1;
printf("Digite o nome que deseja buscar: ");
    scanf("%s", var->auxNome);
    for(var->i=0; var->i < var->nmrPes;var->i++){
    if(strcmp(pessoa->nome, var->auxNome)==0){
        printf("\tNome: %s", pessoa->nome);
        printf("\tTelefone: %s", pessoa->telefone);
        var->flag++;
        }   
        pessoa++;
    }
}
void excluir(){
    pessoa=pBuffer+sizeof(vari);
    var->flag=0;
    printf("\tNome a ser removido: ");
    scanf("%s", var->auxNome);
    printf("\n");
    for(var->i=0;var->i<var->nmrPes;var->i++){
        if(strcmp(pessoa->telefone, var->auxNome)==0){
            var->nmrPes--;

            for(var->flag=var->i;var->flag<var->nmrPes;var->flag){
                pessoa[var->flag]=pessoa[var->flag+1];
            }
            pBuffer=realloc(pBuffer,sizeof(vari)+sizeof(Pessoas) * var->nmrPes);
            var->flag++;
        }  
    }
    if(var->flag!=0){
        printf("\tNome excluido");
    }else{
        printf("\tNome nao existe");
    }

}
void escolher(){

    scanf("%d", &var->escolha);
    getchar();
    switch (var->escolha)
        {
        case 1:
        insere();
        break;
        
        case 2:
        excluir();
        break;

        case 3:
        listar();
        break;

        case 4:
        buscar();
        break;

        case 5:
        printf("\tTchau");
        break;
        
        default:
        break;
        }
    
}
int main (){ 
    
    pBuffer=malloc(sizeof(vari));
    var=pBuffer; //recebe valor do buffer
    var->nmrPes=0;//Numero inicial de contatos
    var->tambuffer=sizeof(vari);
        while(var->escolha!=5){
        menu();
        escolher();
        }
   free(pBuffer);
    return 0;
}
