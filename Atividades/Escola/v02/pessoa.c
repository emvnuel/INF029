
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "models.h"
#include "data.h"
#include "validation_utils.h"
#include "string_utils.h"

void cadastrar_pessoa(bool aluno);
void listar_pessoas(bool aluno);
void listar_alunos();
void listar_professores();
Pessoa* obter_professor_por_matricula(int matricula);
Pessoa* obter_aluno_por_matricula(int matricula);

void menu_pessoa(bool aluno) {
    int opcao;
    char opcao_pessoa[12];
    
    if (aluno) {
        strcpy(opcao_pessoa, "alunos");

    }
    else {
        strcpy(opcao_pessoa, "professores");
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
            cadastrar_pessoa(aluno);
            break;

        case 2:
            listar_pessoas(aluno);
            break;

        }

    } while(opcao != 0);

}

void cadastrar_pessoa(bool aluno) {
    Pessoa pessoa;
    int data_nascimento;

    __fpurge(stdin);

    printf("Digite o nome:\n");
    fgets(pessoa.nome, 256, stdin);
    remove_nova_linha_fgets(pessoa.nome);

    pessoa.matricula = matricula_atual++;

    printf("Data de nascimento (no formato DDMMAAAA):\n");
    scanf("%d", &data_nascimento);
    __fpurge(stdin);

    printf("CPF (somente numeros):\n");
    fgets(pessoa.cpf, 12, stdin);
    __fpurge(stdin);
    remove_nova_linha_fgets(pessoa.cpf);

    printf("Sexo:\n");
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

    if (aluno) {
        alunos[alunos_tamanho] = pessoa;
        alunos_tamanho++;
    }
    else {
        professores[professores_tamanho] = pessoa;
        professores_tamanho++;
    }

}

void listar_pessoas(bool aluno) {
    if (aluno)
        listar_alunos();
    else
        listar_professores();
}

void listar_alunos() {
    int i;
    if (alunos_tamanho == 0)
        printf("Nao ha alunos cadastrados\n");

    for (i = 0; i < alunos_tamanho; i++) {
        printf("\n============================");
        printf("\nNome: %s", alunos[i].nome);
        printf("\nMatricula: %d", alunos[i].matricula);
        printf("\nData de nascimento: %d/%d/%d", alunos[i].dataNascimento.dia, 
                                                    alunos[i].dataNascimento.mes, 
                                                    alunos[i].dataNascimento.ano);

        printf("\nCPF: %s", alunos[i].cpf);
        printf("\nSexo: %c", alunos[i].sexo);
        printf("\n============================\n");
    }
}

void listar_professores() {
    int i;

    if (professores_tamanho == 0)
        printf("Nao ha alunos cadastrados\n");

    for (i = 0; i < professores_tamanho; i++) {
        printf("\n============================");
        printf("\nNome: %s", professores[i].nome);
        printf("\nMatricula: %d", professores[i].matricula);
        printf("\nData de nascimento: %d/%d/%d", professores[i].dataNascimento.dia, 
                                                    professores[i].dataNascimento.mes, 
                                                    professores[i].dataNascimento.ano);

        printf("\nCPF: %s", professores[i].cpf);
        printf("\nSexo: %c", professores[i].sexo);
        printf("\n============================\n");
    }
}

Pessoa* obter_professor_por_matricula(int matricula) {
    Pessoa *pessoa;
    int i;
    for (i = 0; i < professores_tamanho; i++)
        if (professores[i].matricula == matricula)
            pessoa = &professores[i];
    return pessoa;
}

Pessoa* obter_aluno_por_matricula(int matricula) {
    Pessoa *pessoa;
    int i;
    for (i = 0; i < alunos_tamanho; i++)
        if (alunos[i].matricula == matricula)
            pessoa = &alunos[i];
    return pessoa;
}