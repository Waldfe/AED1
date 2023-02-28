#include<stdio.h>
#include<string.h>
#include"biblioteca.h"
#include <stdlib.h>


//implementação das funções


Aluno *listaVazia(Aluno *cabeca)
{
    while(cabeca!=NULL)
    {
        Aluno *limpa;
        limpa = cabeca;
        cabeca = cabeca->prox;
        free(limpa);
    }
    return cabeca;
}

Disciplina *removerDisciplina(Disciplina *cabeca, int x)
{
    Disciplina *remover, *ant, *atual;
    if(cabeca == NULL)
    {
        printf("Aluno nao tem materias.");
        return cabeca;
    }
    if(cabeca->codigo == x)
    {
        remover = cabeca;
        cabeca = cabeca->prox;
        free(remover);
        return cabeca;
    }
    else
    {
        ant = cabeca;
        atual = cabeca->prox;
        while(atual!=NULL && atual->codigo!=x)
        {
            ant = atual;
            atual = atual->prox;
        }
        if(atual == NULL)
        {
            printf("Elemento nao encontrado.\n");
            return cabeca;
        }
        else
        {
            remover = atual;
            ant->prox = atual->prox;
            free(remover);
            return cabeca;
        }
    }

}

void removerDisciplinaAluno(Aluno *cabeca, int x)
{
    Disciplina *materia = NULL;
    materia = cabeca->lista_disciplinas;
    imprimeDisciplina(materia);
    materia = removerDisciplina(materia, x);
    cabeca->lista_disciplinas = materia;
    cabeca->indice=cabeca->indice-1;
    return;
}

Aluno* removerAluno(Aluno *cabeca, int x)
{
    Aluno *remover, *ant, *atual;

    if(cabeca==NULL)
    {
        printf("Lista vazia\n");
        return cabeca;
    }

    if (cabeca->matricula == x)
    {
        printf("Aluno removido com sucesso.!\n");
        remover = cabeca;
        cabeca = cabeca->prox;
        free(remover);
        return cabeca;
    }
    else
    {
        ant = cabeca;
        atual = cabeca->prox;
        while(atual!=NULL && atual->matricula!=x)
        {
            ant = atual;
            atual = atual->prox;
        }
        if (atual == NULL)
        {
            printf("Elemento nao encontrado!\n");
            return cabeca;
        }
        else
        {
            printf("Aluno removido com sucesso!\n");
            remover = atual;
            ant->prox = atual->prox;
            free(remover);
            return cabeca;
        }
    }
}

Aluno *carrega(Aluno *cabeca, FILE *arq)
{
    Aluno *a = malloc(sizeof(Aluno));
    Disciplina *d = malloc(sizeof(Disciplina));
    int i;
    while (fread(a,sizeof(Aluno),1,arq))
    {
        i=0;
        Aluno *efemero;
        efemero = criaAluno(cabeca);
        efemero->matricula = a->matricula;
        strcpy(efemero->nome,a->nome);
        strcpy(efemero->curso,a->curso);
        efemero->prox = cabeca;
        efemero->lista_disciplinas = NULL;
        for(i=0; i<a->indice; i++)
        {
            fread(d,sizeof(Disciplina),1,arq);
            Disciplina *efemeroB;
            efemeroB = criaDisciplina();
            efemeroB->codigo = d->codigo;
            strcpy(efemeroB->nome,d->nome);
            efemeroB->prox = efemero->lista_disciplinas;
            efemero->lista_disciplinas = efemeroB;
        }
        cabeca=efemero;
    }
    free(a);
    free(d);
    return cabeca;
}

void salvaAluno(Aluno *cabeca, FILE *arq)
{

    if(cabeca == NULL)
    {
        return;
    }
    else
    {
        fwrite(cabeca,sizeof(Aluno),1,arq);
        if(cabeca->lista_disciplinas != NULL)
        {
            salvaDisciplina(cabeca->lista_disciplinas, arq);
        }
        salvaAluno(cabeca->prox, arq);
    }
}

void salvaDisciplina(Disciplina *cabeca, FILE *arq)
{
    if(cabeca == NULL)
    {
        return;
    }
    else
    {
        fwrite(cabeca,sizeof(Disciplina),1,arq);
        salvaDisciplina(cabeca->prox, arq);
    }
}

Disciplina *inseredisciplina(Aluno *cabeca, int x, char n[])
{
    Disciplina *nova;
    nova = criaDisciplina();
    nova->codigo = x;
    strcpy(nova->nome,n);
    nova->prox = cabeca->lista_disciplinas;
    cabeca->indice=cabeca->indice+1;
    return nova;
}

void imprimeAluno(Aluno *cabeca)
{
    if(cabeca == NULL)
        return;
    else
    {
        if(cabeca->matricula != -1)
        {
            printf("\n=============");
            printf("\nMatricula: %d\n", cabeca->matricula);
            printf("Nome: %s\n", cabeca->nome);
            printf("Curso: %s\n\n", cabeca->curso);
            if(cabeca->lista_disciplinas != NULL)
            {
                printf("Disciplinas: \n");
                imprimeDisciplina(cabeca->lista_disciplinas);
                printf("=============\n");
            }
            else
            {
                printf("=============\n");
            }
        }
        else
            return;
    }
    imprimeAluno(cabeca->prox);
};

Aluno *buscaAluno(Aluno *cabeca, int x)
{
    while(cabeca != NULL && cabeca->matricula != x)
        cabeca = cabeca->prox;
    return cabeca;
}
Disciplina *buscaDisciplina(Disciplina *cabeca, int x)
{
    if(cabeca == NULL)
    {
        return cabeca;
    }
    if(cabeca->codigo == x)
    {
        return cabeca;
    }
    else
    {
        return buscaDisciplina(cabeca->prox, x);
    }
}

Aluno *insereAluno(Aluno *cabeca, int matricula,char *nome, char *curso)
{
    Aluno *novo;
    novo = criaAluno(cabeca);
    novo->matricula = matricula;
    strcpy(novo->nome, nome);
    strcpy(novo->curso, curso);
    novo->indice=0;
    novo->lista_disciplinas = NULL;
    return novo;
}

Aluno *criaAluno(Aluno *cabeca)
{
    Aluno *novo;
    novo = malloc(sizeof(Aluno));
    if(cabeca==NULL)
    {
        novo->matricula = -1;
        novo->lista_disciplinas = NULL;
        novo->prox = NULL;
        cabeca = novo;
    }
    else
    {
        novo->prox=cabeca;
        cabeca=novo;
    }

    return cabeca;
}

void imprimeDisciplina(Disciplina *cabeca)
{
    if(cabeca == NULL)
    {
        return;
    }
    else
    {
        if(cabeca->codigo != -1)
        {
            printf("Codigo: %d\n", cabeca->codigo);
            printf("Nome: %s \n\n", cabeca->nome);
        }
        else
            return;
    }
    imprimeDisciplina(cabeca->prox);
}

Disciplina *criaDisciplina(Disciplina *cabeca)
{
    Disciplina *novo;
    novo = malloc(sizeof(Disciplina));
    if(cabeca==NULL)
    {
        novo->codigo = -1;
        novo->prox = NULL;
        cabeca=novo;
    }
    else
    {
        novo->prox=cabeca;
        cabeca=novo;
    }
    return cabeca;
}

int verificaDisciplina(Disciplina *cabeca)
{
    if(cabeca == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void editaAluno(Aluno *cabeca)
{
    int x;
    Aluno *ctrl;
    int codAluno, i=0;;
    char nome[40], curso[40], c=' ';
    printf("digite a matricula do aluno: ");
    scanf(" %d",&x);
    ctrl=buscaAluno(cabeca, x);
    printf("Digite a nova matricula do aluno: ");
    scanf(" %d", &codAluno);
    printf("Digite o novo nome do aluno: ");
    getchar();
    while((c=getchar())!= '\n')
    {
        nome[i] = c;
        i++;
    }
    nome[i] = '\0';

    printf("Digite o novo curso do aluno: ");
    i=0;
    c=' ';
    while((c=getchar())!= '\n')
    {
        curso[i] = c;
        i++;
    }
    curso[i] = '\0';
    ctrl->matricula=codAluno;
    strcpy(ctrl->nome,nome);
    strcpy(ctrl->curso,curso);
    return;
}


void clearConsole()
{
    printf("\e[1;1H\e[2J");
}
