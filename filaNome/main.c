#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// estruturas do código

struct sfila
{
    struct fila *inicio;
    struct fila *final;
};
typedef struct sfila Sfila;

struct pessoa
{
    char nome[40];
    int idade;
};
typedef struct pessoa Pessoa;

struct fila
{
    struct pessoa   info;
    struct fila     *prox;
};
typedef struct fila Fila;

// protótipos das Funções

void clearConsole( );
Sfila* criaNodo( Sfila *controle );
Sfila* inserePessoa( Sfila *controle );
Sfila* removeNodo( Sfila *controle);
Sfila* imprimeFila( Sfila *controle );

int main( )
{
    int valorMenu = 0;
    Sfila *controle;

    controle->final  = NULL;
    controle->inicio = NULL;

    while( valorMenu != 9 ){
        clearConsole( );
        printf("--------main--------\n");
        printf("1) adicionar pessoa a fila:\n");
        printf("2) remover primeira pessoa da fila:\n");
        printf("3) imprimir fila:\n");
        printf("9) encerrar programa:\n");
        printf("digite a letra relacionado ao que deseja: ");
        scanf("%d", &valorMenu);

        if( valorMenu == 1 ){
            clearConsole( );
            controle = inserePessoa( controle );
        }

        if( valorMenu == 2){
            clearConsole( );
            controle = removeNodo(controle);
        }

        if( valorMenu == 3){
            clearConsole( );
            controle = imprimeFila(controle);
        }
    }
}

// Funões 

void clearConsole( ){

    printf("\e[1;1H\e[2J");

}

Sfila* criaNodo( Sfila *controle ){

    Fila *novo;
    novo = malloc(sizeof(Fila));

    if( controle->inicio == NULL && controle->final == NULL ){

        novo->prox       = NULL;
        controle->final  = novo;
        controle->inicio = novo;

    } else{
        novo->prox = controle->inicio;
        controle->inicio = novo;
    }
    return controle;
}

Sfila* inserePessoa( Sfila *controle ){
    Sfila *ctrlnew;
    int   i=0;
    int   idade;
    char  nome[40];
    char  c;

    ctrlnew = criaNodo(controle);
    printf( "digite a idade da pessoa: " );
    scanf( "%d", &idade );
    printf( "digite o nome da pessoa: " );
    i=0;
    getchar();
    while((c=getchar())!= '\n')
    {
    nome[i] = c;
    i++;
    }
    nome[i] = '\0';
    
    ctrlnew->inicio->info.idade = idade;
    strcpy( ctrlnew->inicio->info.nome, nome );
    return ctrlnew;
}
Sfila* imprimeFila( Sfila *controle ){
    Fila *ctrl;
    int retorno;
    ctrl = controle->inicio;
    if( ctrl == NULL){
        printf("lista vazia!!\n");
    } else{
        do{
            printf("\n----Dados da pesssoa----\n");
            printf("\nnome da pessoa: ");
            puts(ctrl->info.nome);
            printf("\nidade da pessoa: %d", ctrl->info.idade);
            ctrl = ctrl->prox;
            if(ctrl->prox == NULL){
                printf("\n----Dados da pesssoa----\n");
                printf("\nnome da pessoa: ");
                puts(ctrl->info.nome);
                printf("\nidade da pessoa: %d", ctrl->info.idade);
            }
        }while(ctrl->prox != NULL);
    }
    printf("\ndigite 1 para voltar ao menu: ");
    scanf("%d", &retorno);
    return controle;
}
Sfila* removeNodo( Sfila *controle ){
    Fila *ctrl;
    ctrl = controle->inicio;
    while( ctrl->prox != controle->final ){
        ctrl = ctrl->prox;
    }
    free( ctrl->prox );
    ctrl->prox = NULL;
    controle->final = ctrl;
    return controle;
}