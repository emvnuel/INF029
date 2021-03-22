/*
8. Crie um programa que tenha uma função cadastrarCliente. Essa função deve ler os dados do
cliente (nome, dataNascimento, cpf, sexo) e retornar os dados do cliente. A função main deve
imprimir os dados do cliente.
*/


#include <stdio.h>

typedef struct Data {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Cliente {
    char nome[256];
    Data dataNascimento;
    char cpf[12];
    char sexo;
} Cliente;

Cliente cadastrarCliente();

int main() {

    Cliente clienteCadastrado = cadastrarCliente();

    printf("\nNOME DO CLIENTE: %s", clienteCadastrado.nome);
    printf("DATA NASCIMENTO DO CLIENTE: %d/%d/%d\n", clienteCadastrado.dataNascimento.dia, 
                                                   clienteCadastrado.dataNascimento.mes, 
                                                   clienteCadastrado.dataNascimento.ano);

    printf("CPF DO CLIENTE: %s\n", clienteCadastrado.cpf);
    printf("SEXO DO CLIENTE: %c\n", clienteCadastrado.sexo);

	return 0;
}

Cliente cadastrarCliente() {
    Cliente cliente;
    int dataNascimento, dia, mes, ano;
    int tamanhoData = 0;

    printf("NOME: ");
    fgets(cliente.nome, 256, stdin);

    printf("DATA DE NASCIMENTO (NO FORMATO DDMMYYYY): ");
    scanf("%d", &dataNascimento);
    __fpurge(stdin);

    printf("CPF (SOMENTE NUMEROS): ");
    fgets(cliente.cpf, 12, stdin);
    __fpurge(stdin);

    printf("SEXO: ");
    scanf("%c", &cliente.sexo);

    cliente.dataNascimento.dia = dataNascimento / 1000000;
    cliente.dataNascimento.mes = dataNascimento % 1000000 / 10000;
    cliente.dataNascimento.ano = dataNascimento % 1000000 % 10000;

    return cliente;

}

