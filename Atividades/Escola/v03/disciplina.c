#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "pessoa.h"
#include "data.h"
#include "validation_utils.h"
#include "string_utils.h"
#include "models.h"

void cadastrar_disciplina();
void associar_aluno_a_disciplina();
void listar_disciplinas_sem_alunos();
void listar_disciplinas_com_alunos();
Disciplina* obter_disciplina_por_codigo(char *codigo);

void menu_disciplina() {

    int opcao;

    do {
        printf("\n=========== Menu disciplinas ===========\n");
        printf("Digite 1 para cadastrar disciplinas:\n");
        printf("Digite 2 para associar alunos a disciplinas:\n");
        printf("Digite 3 para listar disciplinas sem alunos:\n");
        printf("Digite 4 para listar disciplinas com alunos:\n");
        printf("Digite 0 para voltar ao menu principal:\n");
        printf("============================\n");
        scanf("%d", &opcao);

        switch (opcao){

        case 1:
            cadastrar_disciplina();
            break;
        case 2:
            associar_aluno_a_disciplina();
            break;

        case 3:
            listar_disciplinas_sem_alunos();
            break;

        case 4:
            listar_disciplinas_com_alunos();
            break;

        }

    } while(opcao != 0);
}

void cadastrar_disciplina() {
    Disciplina disciplina;
    int matricula_professor;
    
    __fpurge(stdin);
    printf("Digite o nome:\n");
    fgets(disciplina.nome, 256, stdin);
    remove_nova_linha_fgets(disciplina.nome);

    printf("Digite o cod. da disciplina:\n");
    fgets(disciplina.codigo, 7, stdin);
    remove_nova_linha_fgets(disciplina.codigo);

    __fpurge(stdin);
    printf("Digite o semestre (ex: '2019.2'):\n");
    fgets(disciplina.semestre, 7, stdin);
    remove_nova_linha_fgets(disciplina.semestre);

    listar_pessoas(false);

    printf("Digite a matricula do professor da disciplina:\n");
    scanf("%d", &matricula_professor);

    if (!existe_professor_com_matricula(matricula_professor)) {
        printf("Matricula nao existente\n");
        return;
    }

    if (existe_disciplina_com_codigo(disciplina.codigo)) {
        printf("\nJá existe uma disciplina com o código informado.\n");
    }
    
    disciplina.professor = obter_professor_por_matricula(matricula_professor);

    disciplina.quantidade_alunos_matriculados = 0;

    disciplinas[disciplinas_tamanho] = disciplina;
    disciplinas_tamanho++;
}

void associar_aluno_a_disciplina() {

    Disciplina *disciplina_selecionada;
    disciplina_selecionada;
    char cod[7];
    int matricula_aluno = 0;

    listar_disciplinas_sem_alunos();

    __fpurge(stdin);
    printf("Digite o codigo da disciplina que se deseja editar:\n");
    fgets(cod, 7, stdin);
    remove_nova_linha_fgets(cod);

    if (!existe_disciplina_com_codigo(cod)) {
        printf("Nao existe uma disciplina com o codigo %s\n", cod);
        return;
    }

    disciplina_selecionada = obter_disciplina_por_codigo(cod);

    listar_pessoas(true);

    printf("Digite a matricula do aluno que se deseja inserir na disciplina %s:\n", disciplina_selecionada->nome);
    scanf("%d", &matricula_aluno);

    if (!existe_aluno_com_matricula(matricula_aluno) && matricula_aluno != 0) {
        printf("Nao existe um aluno com a matricula %d\n", matricula_aluno);
        return;
    }
    disciplina_selecionada->alunos[disciplina_selecionada->quantidade_alunos_matriculados] = *obter_aluno_por_matricula(matricula_aluno);
    disciplina_selecionada->quantidade_alunos_matriculados++;

}

void listar_disciplinas_sem_alunos() {
    int i;
    for (i = 0; i < disciplinas_tamanho; i++) {
        printf("\n============================");
        printf("\nNome: %s", disciplinas[i].nome);
        printf("\nCod: %s", disciplinas[i].codigo);
        printf("\nSemestre: %s", disciplinas[i].semestre);

        printf("\nProfessor: %s", disciplinas[i].professor->nome);
        printf("\n============================\n");
    }
    
}

void listar_disciplinas_com_alunos() {
    char cod[7];
    int j;
    Disciplina *disciplina_selecionada;

    printf("Digite o codigo da disciplina que se deseja editar:\n");
    fgets(cod, 7, stdin);
    remove_nova_linha_fgets(cod);

    disciplina_selecionada = obter_disciplina_por_codigo(cod);

    printf("\n============================");
    printf("\nNome: %s", disciplina_selecionada->nome);
    printf("\nCod: %s", disciplina_selecionada->codigo);
    printf("\nSemestre: %s", disciplina_selecionada->semestre);

    printf("\nProfessor: %s", disciplina_selecionada->professor->nome);
    if (disciplina_selecionada->quantidade_alunos_matriculados == 0) {
        printf("\nAinda não há nenhum aluno matriculado na disciplina");
    }
    else {
        printf("\nAlunos:\n");
        for (j = 0; j < disciplina_selecionada->quantidade_alunos_matriculados; j++)
            printf("%s\n",disciplina_selecionada->alunos[j].nome);
        
    }
    printf("\n============================\n");
}

Disciplina* obter_disciplina_por_codigo(char *codigo) {
    Disciplina* disciplina;
    int i;
    for (i = 0; i < disciplinas_tamanho; i++)
        if (strcmp(disciplinas[i].codigo, codigo) == 0)
            disciplina = &disciplinas[i];
    return disciplina;
}
