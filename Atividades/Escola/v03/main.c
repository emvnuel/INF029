#include <stdio.h>
#include <stdbool.h>
#include "pessoa.h"
#include "disciplina.h"

int main(){

    int opcao;
    bool aluno;

    do {
        
        printf("\n=========== MENU ===========\n");
        printf("Digite 1 para gerenciar alunos:\n");
        printf("Digite 2 para gerenciar professores:\n");
        printf("Digite 3 para gerenciar disciplinas:\n");
        printf("Digite 0 para sair:\n");
        printf("============================\n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                aluno = true;
                menu_pessoa(aluno);
                break;

            case 2:
                aluno = false;
                menu_pessoa(aluno);
                break;
            case 3:
                menu_disciplina();
                break;
        }

    } while(opcao != 0);

    return 0;
}
