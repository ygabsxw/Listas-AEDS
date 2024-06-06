#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int idade;
} pessoa;

int menu()
{
    int opcao;
    do {
        printf("\n0 - Sair");
        printf("\n1 - Cadastrar");
        printf("\n2 - Listar alunos");
        printf("\n3 - Listar media da turma");
        printf("\n\n Opcao: ");
        scanf("%i", &opcao);
    } while (opcao < 0 || opcao > 3);
    
    return opcao;
}

int tamanho()
{
    int qtPessoas;
    printf("\n Digite quantas pessoas serao cadastradas: ");
    scanf("%i", &qtPessoas);

    return qtPessoas;
}

void cadastrar (pessoa * Alunos[], int i, int tam, int *soma)
{
    if (i < tam)
    {
        printf("\n------Ficha ALunos------\n");
        Alunos[i] = (pessoa*)malloc(sizeof(pessoa));
        printf("\nNome do %i.o aluno: ", i + 1);
        getchar();
        fgets(Alunos[i]->nome, 50, stdin);
        printf("\nIdade do %i.o aluno: ", i + 1);
        scanf("%i", &Alunos[i]->idade);
        *soma += Alunos[i]->idade;
    } else {
        printf("\n-----------------------\n");
        printf("\nLimite de alunos atingido.\n");
        printf("\n-----------------------\n");
    }
}

void listarA(pessoa * Alunos[], int i)
{
    if (i > 0) {
        printf("\n------Resultados------\n");
        for(int j = 0 ; j < i ; j++) {
            printf("\n Nome: %s\n Idade: %i\n", Alunos[j]->nome, Alunos[j]->idade);
            printf("\n-----------------------\n");
        } 
    } else {
        printf("\n-----------------------\n");
        printf("\nNenhum aluno cadastrado.\n");
        printf("\n-----------------------\n");
    }
}

void mediaT(pessoa * Alunos[], int i, int soma)
{
    if (i > 0) {
        float media = (float)soma/i;
    printf("\n------Média------\n");
    printf("\nA idade média da turma é %.2f", media);
    } else {
        printf("\n-----------------------\n");
        printf("\nNenhum aluno cadastrado.\n");
        printf("\n-----------------------\n");
    }
    
}

int main()
{
    int opcao;
    int i = 0;
    int soma = 0;
    int tam = tamanho();
    pessoa * Alunos[tam];
    do {
        opcao = menu();
        switch(opcao)
        {
            case 0: printf("\nObrigado");
            break;
            case 1: cadastrar(Alunos,i , tam, &soma); i++; 
            break;
            case 2: listarA(Alunos, i);
            break;
            case 3: mediaT(Alunos, i, soma);
            break;
        }
    } while (opcao != 0);


    return 0;
}

