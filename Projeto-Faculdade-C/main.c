#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main()
{
    int i, codAluno, matricula, codMateria;
    char menu, c;
    char nome[40], curso[40], nomedisciplina[40];
    Aluno* cabeca=NULL, *b=NULL;
    FILE *arq;
    menu = 'z';
    while(menu!='k')
    {
        //menu FEITO ! B C D E F G ! I J K

        clearConsole();
        printf("---------  MENU  ---------\n");
        printf("a) Carregar uma lista de alunos de um arquivo\n");
        printf("b) Criar uma lista de alunos vazia\n");
        printf("c) Inserir aluno\n");
        printf("d) Inserir disciplina na lista de disciplinas de um aluno\n");
        printf("e) Remover disciplina da lista de disciplinas de um aluno\n");
        printf("f) Remover aluno\n");
        printf("g) Buscar aluno\n");
        printf("h) Editar informacoes de um aluno\n");
        printf("i) Imprimir lista de alunos\n");
        printf("j) Salvar lista de alunos em um arquivo\n");
        printf("k) Encerrar");

        printf("\nDigite a letra relacionada ao que procura: ");
        scanf("%c",&menu);
        getchar();

        if(menu== 'a')
        {
            clearConsole();
            arq = fopen("dados.bin","rb");
            cabeca = carrega(cabeca, arq);
            fclose(arq);
            printf("\n\nAcao realizada com sucesso sucesso!\n\n");
            printf("Digite uma tecla para continuar.\n");
            getchar();
        }
        if(menu=='b')
        {
            clearConsole();
            cabeca = listaVazia(cabeca);
            printf("\n\nAcao realizada com sucesso sucesso!\n\n");
            printf("Digite uma tecla para continuar.\n");
            getchar();
        }
        if(menu=='c')
        {
            clearConsole();
            printf("Digite o codigo do aluno: ");
            scanf("%d", &codAluno);
            printf("Digite o nome do aluno: ");
            i=0;
            getchar();
            while((c=getchar())!= '\n')
            {
                nome[i] = c;
                i++;
            }
            nome[i] = '\0';

            printf("Digite o curso do aluno: ");
            i=0;
            while((c=getchar())!= '\n')
            {
                curso[i] = c;
                i++;
            }
            curso[i] = '\0';
            cabeca = insereAluno(cabeca,codAluno,nome, curso);
            clearConsole();
            printf("\nAcao realizada com sucesso sucesso!\n");
            printf("Digite uma tecla para continuar.\n");
            getchar();
        }
        if(menu=='d')
        {
            clearConsole();
            printf("Digite a matricula do aluno: ");
            scanf("%d", &matricula);
            b = buscaAluno(cabeca, matricula);
            printf("Aluno: ");
            puts(b->nome);
            printf("Digite o nome da materia que deseja adicionar: ");
            i=0;
            getchar();
            c=' ';
            while((c=getchar())!= '\n')
            {
                nomedisciplina[i] = c;
                i++;
            }
            nomedisciplina[i] = '\0';
            printf("Digite o codigo da materia: ");
            scanf("%d", &codMateria);
            b->lista_disciplinas = inseredisciplina(b,codMateria,nomedisciplina);
            imprimeAluno(b);
            printf("Digite uma tecla para continuar.\n");
            getchar();
        }
        if(menu=='e')
        {
            clearConsole();
            printf("Digite a matricula do aluno que deseja remover a disciplina: ");
            scanf("%d", &codAluno);
            printf("Digite o codigo da disciplina que deseja remover: ");
            scanf("%d", &codMateria);
            b = buscaAluno(cabeca, codAluno);
            removerDisciplinaAluno(b, codMateria);
            getchar();
            printf("Digite uma tecla para continuar.\n");
            getchar();
        }
        if(menu=='f')
        {
            clearConsole();
            printf("Digite a matricula do aluno que deseja remover: ");
            scanf("%d", &codAluno);
            cabeca = removerAluno(cabeca, codAluno);
            printf("\n\nAcao realizada com sucesso sucesso!\n\n");
            printf("Digite uma tecla para continuar.\n");
            getchar();
        }
        if(menu=='g')
        {
            clearConsole();
            printf("Digite a matricula que deseja buscar: ");
            scanf("%d", &codAluno);
            b = buscaAluno(cabeca, codAluno);
            printf("\nMatricula: %d\n", b->matricula);
            printf("Nome: %s\n", b->nome);
            if(b->lista_disciplinas != NULL)
            {
                printf("Disciplinas: \n");
                imprimeDisciplina(b->lista_disciplinas);
            }
            getchar();
            printf("Digite uma tecla para continuar.\n");
            getchar();
        }
        if(menu=='h')
        {
            clearConsole();
            editaAluno(cabeca);
            printf("\n\nAcao realizada com sucesso sucesso!\n\n");
            printf("Digite uma tecla para continuar.\n");
            getchar();
        }
        if(menu=='i')
        {
            if(cabeca!=NULL)
            {
                clearConsole();
                imprimeAluno(cabeca);
                printf("\n\nAcao realizada com sucesso sucesso!\n\n");
                printf("Digite uma tecla para continuar.\n");
                getchar();
            }
            else
            {
                clearConsole();
                printf("\n\nAluno inexistente.\n\n");
                printf("Digite uma tecla para continuar.\n");
                getchar();
            }
        }
        if(menu=='j')
        {
            arq = fopen("dados.bin","wb");
            salvaAluno(cabeca, arq);
            fclose(arq);
            printf("\n\nAcao realizada com sucesso sucesso!\n\n");
            printf("Digite uma tecla para continuar.\n");
            getchar();
        }
        if(menu=='k')
        {
            return 0;
        }

    }
    return 0;
}
