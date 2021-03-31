typedef struct Data {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Pessoa {
    char matricula[12];
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
    Pessoa *alunos[50];
} Disciplina;