 #ifndef MODELS_H
 #define MODELS_H

typedef struct Data {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Pessoa {
    int matricula;
    char nome[256];
    char sexo;
    Data dataNascimento;
    char cpf[12];
} Pessoa;

typedef struct Disciplina {
    char nome[256];
    char codigo[7];
    char semestre[7];
    Pessoa *professor;
    Pessoa alunos[50];
    int quantidade_alunos_matriculados;
} Disciplina;

#endif