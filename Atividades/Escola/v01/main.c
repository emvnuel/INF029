#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "validation_utils.h"
#include "string_utils.h"
#include "models.h"

void cadastrar_aluno(Aluno alunos[], int *alunos_tamanho);
void listar_alunos(Aluno alunos[], int alunos_tamanho);

int main(){

    Aluno alunos[10];
    int alunos_tamanho = 0;


    int opcao;

    do {

        printf("\n=========== MENU ===========\n");
        printf("Digite 1 para cadastrar alunos:\n");
        printf("Digite 2 para listar alunos:\n");
        printf("Digite 0 para sair:\n");
        printf("============================\n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrar_aluno(alunos, &alunos_tamanho);
                break;

            case 2:
                listar_alunos(alunos, alunos_tamanho);
                break;
        }

    } while(opcao != 0);

    return 0;
}

void cadastrar_aluno(Aluno alunos[], int *alunos_tamanho) {
    Aluno aluno;
    int data_nascimento;

    printf("\nCadastro de alunos:\n");
    __fpurge(stdin);

    printf("Digite o nome do aluno:\n");
    fgets(aluno.nome, 256, stdin);
    remove_nova_linha_fgets(aluno.nome);

    printf("Digite a matricula do aluno:\n");
    fgets(aluno.matricula, 12, stdin);
    remove_nova_linha_fgets(aluno.matricula);

    printf("Data de nascimento (no formato DDMMAAAA): ");
    scanf("%d", &data_nascimento);
    __fpurge(stdin);

    printf("CPF (somente numeros): ");
    fgets(aluno.cpf, 12, stdin);
    __fpurge(stdin);
    remove_nova_linha_fgets(aluno.cpf);

    printf("Sexo: ");
    scanf("%c", &aluno.sexo);

    aluno.dataNascimento.dia = data_nascimento / 1000000;
    aluno.dataNascimento.mes = data_nascimento % 1000000 / 10000;
    aluno.dataNascimento.ano = data_nascimento % 1000000 % 10000;

    if (!validar_cpf(aluno.cpf)) {
        printf("CPF invalido\n");
        return;
    }
    if (!validar_sexo(aluno.sexo)) {
        printf("Sexo invalido\n");
        return;
    }
    if (!validar_data(aluno.dataNascimento.dia, aluno.dataNascimento.mes, aluno.dataNascimento.ano)) {
        printf("Data de nascimento invalida\n");
        return;
    }

    alunos[*alunos_tamanho] = aluno;
    *alunos_tamanho = *alunos_tamanho + 1;
}

void listar_alunos(Aluno alunos[], int alunos_tamanho) {
    int i;

    for (i = 0; i < alunos_tamanho; i++) {
        printf("\n============================");
        printf("\nNome: %s", alunos[i].nome);
        printf("\nMatricula: %s", alunos[i].matricula);
        printf("\nData de nascimento: %d/%d/%d", alunos[i].dataNascimento.dia, 
                                                    alunos[i].dataNascimento.mes, 
                                                    alunos[i].dataNascimento.ano);

        printf("\nCPF: %s", alunos[i].cpf);
        printf("\nSexo: %c", alunos[i].sexo);
        printf("\n============================\n");
    }
}