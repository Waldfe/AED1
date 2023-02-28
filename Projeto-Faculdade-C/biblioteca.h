#include <stdio.h>
#include <stdlib.h>

//A definção da struct

struct disciplina
{
    int codigo;
    char nome[40];
    struct disciplina *prox;
};
typedef struct disciplina Disciplina;

struct aluno
{
    int matricula;
    int indice;
    char nome[40];
    char curso[40];
    struct disciplina *lista_disciplinas;
    struct aluno *prox;
};


typedef struct aluno Aluno;


//protótipos das funções:
Aluno *listaVazia(Aluno *cabeca);
Disciplina *removerDisciplina(Disciplina *, int );
void removerDisciplinaAluno(Aluno *, int);
Aluno* removerAluno(Aluno *, int);
Aluno *carrega(Aluno *cabeca, FILE *arq);
void salvaAluno(Aluno *, FILE *);
void salvaDisciplina(Disciplina *, FILE *);
Disciplina *inseredisciplina(Aluno *, int, char *);
void imprimeAluno(Aluno*);
Aluno *buscaAluno(Aluno*, int);
Disciplina *buscaDisciplina(Disciplina *, int);
Aluno *insereAluno(Aluno *, int,char *, char *);
Aluno *criaAluno(Aluno *cabeca);
void imprimeDisciplina(Disciplina*);
Disciplina *criaDisciplina();
int verificaDisciplina(Disciplina *);
void editaAluno(Aluno *cabeca);
void clearConsole();
