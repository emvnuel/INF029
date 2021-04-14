#include <stdbool.h>
#include <string.h>
#include "models.h"
#include "data.h"

bool eh_bissexto(int ano) {
    return ((ano % 4 == 0) && (ano % 100 != 0)) || (ano % 400 == 0);
}

int ultimo_dia_do_mes(int ano, int mes) {

    if (mes == 2 && eh_bissexto(ano))
        return 29;
    
    if (mes == 2 && !eh_bissexto(ano))
        return 28;

    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 
        || mes == 8 || mes == 10 || mes == 12)
        return 31;

    if (mes == 4 || mes == 6 || mes == 9 || mes == 11 )
        return 30;

    return -1;

}

bool validar_data(int dia, int mes, int ano) {
    
    if (ano < 0 || mes < 0 || dia < 0 || mes > 12)
        return false;
        
    return dia >= 1 && dia <= ultimo_dia_do_mes(ano, mes);
}

bool validar_sexo(char sexo) {
    return sexo == 'm' || sexo == 'M' || 
           sexo == 'f' || sexo == 'F';
}

bool validar_cpf(char cpfString[12]) {
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

bool existe_professor_com_matricula(int matricula) {
    int i;
    for (i = 0; i < professores_tamanho; i++)
        if (professores[i].matricula == matricula)
            return true;
    return false;
}

bool existe_aluno_com_matricula(int matricula) {
    int i;
    for (i = 0; i < alunos_tamanho; i++)
        if (alunos[i].matricula == matricula)
            return true;
    return false;
}

bool existe_disciplina_com_codigo(char *codigo) {
    int i;
    for (i = 0; i < disciplinas_tamanho; i++)
        if (strcmp(disciplinas[i].codigo, codigo) == 0)
            return true;
    return false;
}

bool aluno_esta_matriculado_na_disciplina(char *codigo) {
    int i;
    for (i = 0; i < disciplinas_tamanho; i++)
        if (strcmp(disciplinas[i].codigo, codigo) == 0)
            return true;
    return false;
}