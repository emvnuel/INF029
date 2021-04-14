
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "models.h"
#include "data.h"
#include "validation_utils.h"
#include "string_utils.h"
#include <ctype.h>

void cadastrar_pessoa(bool aluno);
void listar_pessoas(bool aluno);
void listar_alunos();
void listar_professores();
Pessoa* obter_professor_por_matricula(int matricula);
Pessoa* obter_aluno_por_matricula(int matricula);
void listar_pessoas_por_sexo(bool aluno);
void listar_pessoas_ordernadas_por_nome(bool aluno);
void listar_pessoas_ordernadas_por_data_nascimento(bool aluno);
void listar_pessoas_aniversariantes();
void imprimePessoa(Pessoa pessoa);


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
        printf("Digite 3 para listar %s por sexo:\n", opcao_pessoa);
        printf("Digite 4 para listar %s ordenados por nome:\n", opcao_pessoa);
        printf("Digite 5 para listar %s ordenados por data de nascimento:\n", opcao_pessoa);
        printf("Digite 6 para listar os aniversariantes do mês:\n");
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

        case 3:
            listar_pessoas_por_sexo(aluno);
            break;

        case 4:
            listar_pessoas_ordernadas_por_nome(aluno);
            break;
        
        case 5:
            listar_pessoas_ordernadas_por_data_nascimento(aluno);
            break;

        case 6:
            listar_pessoas_aniversariantes();
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
    pessoa.dataNascimento.valor = ((pessoa.dataNascimento.ano * 100 + pessoa.dataNascimento.mes) * 100) + pessoa.dataNascimento.dia;

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

    int tamanho_array;
    Pessoa *pessoas_array;
    int i;

    if (aluno) {
        tamanho_array = alunos_tamanho;
        pessoas_array = alunos;
    }
    else {
        tamanho_array = professores_tamanho;
        pessoas_array = professores;
    }

    if (tamanho_array == 0)
        printf("NAO HA REGISTROS\n");

    for (i = 0; i < tamanho_array; i++) {
        imprimePessoa(pessoas_array[i]);
    }

}

void listar_pessoas_por_sexo(bool aluno) {

    char sexo;
    __fpurge(stdin);
    printf("Sexo:\n");
    scanf("%c", &sexo);

    if (!validar_sexo(sexo)) {
        printf("Sexo invalido\n");
        return;
    }

    int tamanho_array;
    Pessoa *pessoas_array;
    int i;

    if (aluno) {
        tamanho_array = alunos_tamanho;
        pessoas_array = alunos;
    }
    else {
        tamanho_array = professores_tamanho;
        pessoas_array = professores;
    }

    if (tamanho_array == 0)
        printf("NAO HA REGISTROS\n");

    for (i = 0; i < tamanho_array; i++) {

        if (toupper(pessoas_array[i].sexo) == toupper(sexo)) {
            imprimePessoa(pessoas_array[i]);
        }

    }

}

void listar_pessoas_ordernadas_por_nome(bool aluno) {

    int tamanho_array;
    Pessoa *pessoas_array;
    Pessoa pessoas_array_ordernado[TAM];
    Pessoa temp;
    int i, j;

    if (aluno) {
        tamanho_array = alunos_tamanho;
        pessoas_array = alunos;
    }
    else {
        tamanho_array = professores_tamanho;
        pessoas_array = professores;
    }

    if (tamanho_array == 0)
        printf("NAO HA REGISTROS\n");
            
    for ( i = 0; i < tamanho_array; i++)
        pessoas_array_ordernado[i] = pessoas_array[i];
    

    for (i = 0; i <= tamanho_array; i++) {
        for(j = i + 1; j <= tamanho_array; j++) {
            if (strcmp(pessoas_array_ordernado[i].nome, pessoas_array_ordernado[j].nome) > 0) {
                temp = pessoas_array_ordernado[i];
                pessoas_array_ordernado[i] = pessoas_array_ordernado[j];
                pessoas_array_ordernado[j] = temp;
            }
        }
    }

    for (i = 0; i < tamanho_array; i++) {
        imprimePessoa(pessoas_array_ordernado[i]);
    }

}

void listar_pessoas_ordernadas_por_data_nascimento(bool aluno) {
    int tamanho_array;
    Pessoa *pessoas_array;
    Pessoa pessoas_array_ordernado[TAM];
    Pessoa temp;
    int i, j;

    if (aluno) {
        tamanho_array = alunos_tamanho;
        pessoas_array = alunos;
    }
    else {
        tamanho_array = professores_tamanho;
        pessoas_array = professores;
    }

    if (tamanho_array == 0)
        printf("NAO HA REGISTROS\n");
            
    for ( i = 0; i < tamanho_array; i++)
        pessoas_array_ordernado[i] = pessoas_array[i];
    

    for (i = 0; i <= tamanho_array; i++) {
        for(j = i + 1; j <= tamanho_array; j++) {
            if (pessoas_array_ordernado[i].dataNascimento.valor > pessoas_array_ordernado[j].dataNascimento.valor) {
                temp = pessoas_array_ordernado[i];
                pessoas_array_ordernado[i] = pessoas_array_ordernado[j];
                pessoas_array_ordernado[j] = temp;
            }
        }
    }

    for (i = 0; i < tamanho_array; i++) {
        imprimePessoa(pessoas_array_ordernado[i]);
    }

}

void imprimePessoa(Pessoa pessoa) {
    printf("\n============================");
    printf("\nNome: %s", pessoa.nome);
    printf("\nMatricula: %d", pessoa.matricula);
    printf("\nData de nascimento: %d/%d/%d", pessoa.dataNascimento.dia, 
                                                pessoa.dataNascimento.mes, 
                                                pessoa.dataNascimento.ano);

    printf("\nCPF: %s", pessoa.cpf);
    printf("\nSexo: %c", pessoa.sexo);
    printf("\n============================\n");
}

void listar_pessoas_aniversariantes() {
    int i, mes;
    printf("Mês:\n");
    scanf("%d", &mes);

    for (i = 0; i < professores_tamanho; i++)
        if (professores[i].dataNascimento.mes == mes)
            imprimePessoa(professores[i]);

    for (i = 0; i < alunos_tamanho; i++)
        if (alunos[i].dataNascimento.mes == mes)
            imprimePessoa(alunos[i]);
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