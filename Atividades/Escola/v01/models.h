typedef struct Data {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Aluno {
    char matricula[12];
    char nome[256];
    char sexo;
    Data dataNascimento;
    char cpf[12];
} Aluno;