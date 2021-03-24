/*
8. Crie um programa que tenha uma função cadastrarCliente. Essa função deve ler os dados do
cliente (nome, dataNascimento, cpf, sexo) e retornar os dados do cliente. A função main deve
imprimir os dados do cliente.
*/


#include <stdio.h>
#include <stdbool.h>

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
bool validarNome(char nome[256]);
bool validarSexo(char sexo);
bool validarCPF(char cpf[12]);
bool validarNacimento(Data dataNascimento);
bool anoEhBissexto(int ano);
int ultimoDiaDoMes(int ano, int mes);

int main() {

    Cliente clienteCadastrado = cadastrarCliente();

    bool estaValido = validarNome(clienteCadastrado.nome) && validarSexo(clienteCadastrado.sexo)
                      && validarNacimento(clienteCadastrado.dataNascimento) && validarCPF(clienteCadastrado.cpf);

    if (!validarNome(clienteCadastrado.nome))
        printf("NOME INVÁLIDO\n");

    if (!validarSexo(clienteCadastrado.sexo))
        printf("SEXO INVÁLIDO\n");

    if (!validarNacimento(clienteCadastrado.dataNascimento))
        printf("DATA INVALIDA\n");

    if (!validarCPF(clienteCadastrado.cpf))
        printf("CPF INVALIDO\n");

    if (estaValido) {
        printf("\nCLIENTE CADASTRADO COM SUCESSO:\n");
        printf("\nNOME DO CLIENTE: %s", clienteCadastrado.nome);
        printf("DATA NASCIMENTO DO CLIENTE: %d/%d/%d\n", clienteCadastrado.dataNascimento.dia, 
                                                    clienteCadastrado.dataNascimento.mes, 
                                                    clienteCadastrado.dataNascimento.ano);

        printf("CPF DO CLIENTE: %s\n", clienteCadastrado.cpf);
        printf("SEXO DO CLIENTE: %c\n", clienteCadastrado.sexo);
    }

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

bool validarNome(char nome[256]) {
    int numeroCaracteres;

    for(numeroCaracteres = 0; nome[numeroCaracteres] != '\0'; numeroCaracteres++);

    return numeroCaracteres <= 20;
}

bool validarCPF(char cpfString[12]) {
    int i;
    int j;
    int cpf[11];
    int dv1 = 0;
    int dv2 = 0;
    int primeiroDigito;
    int quantidadeDeDuplicados = 0;
    
    for (i = 0; cpfString[i] != '\0'; i++)
        cpf[i] = cpfString[i] - '0';
    
    if (i != 11)
        return false;

    for (i = 0, j = 10; j >= 2; i++, j--)
        dv1 += cpf[i] * j;

    dv1 = dv1 * 10 % 11;
    dv1 = dv1 == 10 ? 0: dv1;

    if (dv1 != cpf[9])
        return false;


    for (i = 0, j = 11; j >= 2; i++, j--)
        dv2 += cpf[i] * j;

    dv2 = dv2 * 10 % 11;
    dv2 = dv2 == 10 ? 0: dv2;

    if (dv2 != cpf[10])
        return false;

    
    primeiroDigito = cpf[0];

    for(i = 1; i < 11; i++)
        if (cpf[i] == primeiroDigito) 
            quantidadeDeDuplicados++;

    if (quantidadeDeDuplicados == 10)
        return false;

    return true;
}

bool validarSexo(char sexo) {
    return sexo == 'm' || sexo == 'M' || 
           sexo == 'f' || sexo == 'F' ||
           sexo == 'o' || sexo == 'O';
}

bool validarNacimento(Data data) {
    
    if (data.ano < 0 || data.mes < 0 || data.dia < 0)
        return false;
    
    if (data.mes > 12)
        return false;

    if (data.dia >= 1 && data.dia <= ultimoDiaDoMes(data.ano, data.mes))
        return true;
    
    return false;
}


bool anoEhBissexto(int ano) {
    if ( ((ano % 4 == 0) && (ano % 100 != 0)) || (ano % 400 == 0) )
        return true;

    return false;
}

int ultimoDiaDoMes(int ano, int mes) {

    if (mes == 2 && anoEhBissexto(ano))
        return 29;
    
    if (mes == 2 && !anoEhBissexto(ano))
        return 28;

    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 
        || mes == 8 || mes == 10 || mes == 12)
        return 31;

    if (mes == 4 || mes == 6 || mes == 9 || mes == 11 )
        return 30;

    return -1;

}

