
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "data.h"
#include "validation_utils.h"
#include "string_utils.h"

void cadastrar_pessoa(Pessoa *pessoas[], int *pessoas_tamanho);
void listar_pessoas(Pessoa *pessoas[], int *pessoas_tamanho);

void menuPessoa(bool aluno) {
    int opcao;
    Pessoa *pessoas[TAM];
    int *pessoas_tamanho;
    char opcao_pessoa[12];
    
    if (aluno) {
        strcpy(opcao_pessoa, "alunos");
        *pessoas = alunos;
        pessoas_tamanho = &alunos_tamanho;
    }
    else {
        strcpy(opcao_pessoa, "professores");
        *pessoas = professores;
        pessoas_tamanho = &professores_tamanho;
    }

    do {
        printf("\n=========== Menu %s ===========\n", opcao_pessoa);
        printf("Digite 1 para cadastrar %s:\n", opcao_pessoa);
        printf("Digite 2 para listar %s:\n", opcao_pessoa);
        printf("Digite 0 para voltar ao menu principal:\n");
        printf("============================\n");
        scanf("%d", &opcao);

        switch (opcao){

        case 1:
            cadastrar_pessoa(pessoas, pessoas_tamanho);
            break;

        case 2:
            listar_pessoas(pessoas, pessoas_tamanho);
            break;

        }

    } while(opcao != 0);

}

void cadastrar_pessoa(Pessoa *pessoas[], int *pessoas_tamanho) {
    Pessoa pessoa;
    int data_nascimento;

    __fpurge(stdin);

    printf("Digite o nome:\n");
    fgets(pessoa.nome, 256, stdin);
    remove_nova_linha_fgets(pessoa.nome);

    printf("Digite a matricula:\n");
    fgets(pessoa.matricula, 12, stdin);
    remove_nova_linha_fgets(pessoa.matricula);

    printf("Data de nascimento (no formato DDMMAAAA): ");
    scanf("%d", &data_nascimento);
    __fpurge(stdin);

    printf("CPF (somente numeros): ");
    fgets(pessoa.cpf, 12, stdin);
    __fpurge(stdin);
    remove_nova_linha_fgets(pessoa.cpf);

    printf("Sexo: ");
    scanf("%c", &pessoa.sexo);

    pessoa.dataNascimento.dia = data_nascimento / 1000000;
    pessoa.dataNascimento.mes = data_nascimento % 1000000 / 10000;
    pessoa.dataNascimento.ano = data_nascimento % 1000000 % 10000;

    if (!validar_cpf(pessoa.cpf)) {
        printf("CPF invalido\n");
        return;
    }
    if (!validar_sexo(pessoa.sexo)) {
        printf("Sexo invalido\n");
        return;
    }
    if (!validar_data(pessoa.dataNascimento.dia, pessoa.dataNascimento.mes, pessoa.dataNascimento.ano)) {
        printf("Data de nascimento invalida\n");
        return;
    }

    *pessoas[*pessoas_tamanho] = pessoa;
    *pessoas_tamanho = *pessoas_tamanho + 1;
}

void listar_pessoas(Pessoa *pessoas[], int *pessoas_tamanho) {
    int i;

    if (*pessoas_tamanho == 0)
        printf("AINDA NAO HA NENHUM REGISTRO\n");

    for (i = 0; i < *pessoas_tamanho; i++) {
        Pessoa pessoa = *pessoas[i];
        printf("\n============================");
        printf("\nNome: %s", pessoa.nome);
        printf("\nMatricula: %s", pessoa.matricula);
        printf("\nData de nascimento: %d/%d/%d", pessoa.dataNascimento.dia, 
                                                    pessoa.dataNascimento.mes, 
                                                    pessoa.dataNascimento.ano);

        printf("\nCPF: %s", pessoa.cpf);
        printf("\nSexo: %c", pessoa.sexo);
        printf("\n============================\n");
    }
}