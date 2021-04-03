#include <stdio.h>
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

    if (!existe_professor_com_matricula(matricula_professor))
        printf("Matricula nao existente\n");
    
    disciplina.professor = obter_professor_por_matricula(matricula_professor);

    disciplinas[disciplinas_tamanho] = disciplina;
    disciplinas_tamanho++;
}

void associar_aluno_a_disciplina() {

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

}