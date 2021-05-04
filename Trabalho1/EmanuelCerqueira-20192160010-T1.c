// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Emanuel Pereira Cerqueira
//  email: emanuelcerqueira07@gmail.com
//  Matrícula: 20192160010
//  Semestre: 2021.1

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016

// #################################################

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int validar_data(int dia, int mes, int ano);
typedef struct Data {
    int dia;
    int mes;
    int ano;
    int valor;
} Data;
Data paraData(char *data);
/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma = 0;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
    int fat = 1;
    return fat;
}


/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */

int q1(char *data)
{
    int tamanhoData = strlen(data);
    int quantidadeDeBarra = 0;
    int i;
    int j;
    int k;
    int strIndexInicial;
    int strIndexFinal;
    int diaMesAno;
    diaMesAno = 0;

    if (tamanhoData < 6)
        return 0;

    for (i = 0; i < tamanhoData; i++) {
        if (data[i] == '/')
            quantidadeDeBarra++;
    }

    if (quantidadeDeBarra != 2)
        return 0;

    char sDia[3];
    char sMes[3];
    char sAno[5];
    int iDia;
    int iMes;
    int iAno;

    //quebrar a string data em strings sDia, sMes, sAno
    
    for (i = 0, j = 0; i < tamanhoData; i++, j++) {
        if (diaMesAno == 0) {
            if (data[i] == '/') {
                sDia[j] = '\0';
                j = -1;
                diaMesAno++;
            }
            else {
                sDia[j] = data[i];
            }
        }
        else if (diaMesAno == 1) {
            if (data[i] == '/') {
                sMes[j] = '\0';
                j = -1;
                diaMesAno++;
            }
            else {
                sMes[j] = data[i];
            }
        }
        else if (diaMesAno == 2) {
           if (data[i] == '/' || i == tamanhoData) {
                sAno[j] = '\0';
                j = -1;
                diaMesAno++;
            }
            else {
                sAno[j] = data[i];
            }
        }
    }
    
    if (strlen(sDia) == 0 || strlen(sMes) == 0 || strlen(sAno) == 0)
        return 0;

    if (strlen(sAno) == 3)
        return 0;

    //converter sDia, sMes e sAno em inteiros (ex: atoi)
    //criar as variáveis iDia, iMes, iAno
    iDia = atoi(sDia);
    iMes = atoi(sMes);
    iAno = atoi(sAno);

    // Caso o ano seja de dois digitios somar 2000, conforme foi combinado em aula
    if (strlen(sAno) == 2)
        iAno = 2000 + iAno;

    if (validar_data(iDia, iMes, iAno) == 1)
        return 1;
    else
        return 0;

}

int eh_bissexto(int ano) {
    if (((ano % 4 == 0) && (ano % 100 != 0)) || (ano % 400 == 0))
        return 1;
    return 0;
}

int ultimo_dia_do_mes(int ano, int mes) {

    if (mes == 2 && eh_bissexto(ano) == 1)
        return 29;
    
    if (mes == 2 && eh_bissexto(ano) == 0)
        return 28;

    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 
        || mes == 8 || mes == 10 || mes == 12)
        return 31;

    if (mes == 4 || mes == 6 || mes == 9 || mes == 11 )
        return 30;

    return -1;

}

int validar_data(int dia, int mes, int ano) {
    
    if (ano < 1 || mes < 1 || dia < 1 || mes > 12)
        return 0;
        
    if (dia >= 1 && dia <= ultimo_dia_do_mes(ano, mes))
        return 1;
    
    return 0;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos)
{

    //calcule os dados e armazene nas três variáveis a seguir
    int nDias = 0, nMeses = 0, nAnos = 0;

    if (q1(datainicial) == 0)
        return 2;

    if (q1(datafinal) == 0)
        return 3;

    Data dtInicial;
    Data dtFinal;

    dtInicial = paraData(datainicial);
    dtFinal = paraData(datafinal);

    if (dtInicial.valor > dtFinal.valor)
        return 4;

    int valorDiferenca = dtFinal.valor - dtInicial.valor;
    nAnos = valorDiferenca / 10000;
    nMeses = 12 - ((10000 - ( (valorDiferenca % 10000 / 100 * 100) )) / 100);
    
    if (nMeses < 0)
        nMeses = valorDiferenca % 10000 / 100;

    nDias = valorDiferenca % 1000 % 100;

    if (nDias > 31) {
        nDias = nDias - 70;

        if (ultimo_dia_do_mes(dtFinal.ano, dtFinal.mes - 1) == 28)
            nDias -= 2;
        else if (ultimo_dia_do_mes(dtFinal.ano, dtFinal.mes - 1) == 29)
            nDias--;
        else if (ultimo_dia_do_mes(dtFinal.ano, dtFinal.mes - 1) == 31)
            nDias++;
    }
    
    /*mantenha o código abaixo, para salvar os dados em 
    nos parâmetros da funcao
    */
    *qtdDias = nDias;
    *qtdAnos = nAnos;
    *qtdMeses = nMeses;

    //coloque o retorno correto
    return 1;
}


Data paraData(char *data) {
    int tamanhoData = strlen(data);
    char sDia[3];
    char sMes[3];
    char sAno[5];
    int i;
    int j;
    int diaMesAno = 0;

    
    for (i = 0, j = 0; i < tamanhoData; i++, j++) {
        if (diaMesAno == 0) {
            if (data[i] == '/') {
                sDia[j] = '\0';
                j = -1;
                diaMesAno++;
            }
            else {
                sDia[j] = data[i];
            }
        }
        else if (diaMesAno == 1) {
            if (data[i] == '/') {
                sMes[j] = '\0';
                j = -1;
                diaMesAno++;
            }
            else {
                sMes[j] = data[i];
            }
        }
        else if (diaMesAno == 2) {
           if (data[i] == '/' || i == tamanhoData) {
                sAno[j] = '\0';
                j = -1;
                diaMesAno++;
            }
            else {
                sAno[j] = data[i];
            }
        }
    }

    Data dataStruct;
    dataStruct.dia = atoi(sDia);
    dataStruct.mes = atoi(sMes);
    dataStruct.ano = atoi(sAno);
    
    if (strlen(sAno) == 2) {
        dataStruct.ano = 2000 + dataStruct.ano;
    }
    dataStruct.valor = ((dataStruct.ano * 100 + dataStruct.mes) * 100) + dataStruct.dia;
    return dataStruct;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;
    int i;
    char correspondentCharacter;
    int tamanhoTexto = strlen(texto);

    for (i = 0; i < tamanhoTexto; i++)
        if (c == texto[i])
            qtdOcorrencias++;

    if (isCaseSensitive != 1) {
        if (c > 'a' && c < 'z') 
            correspondentCharacter = c - 32;
        else if (c > 'A' && c < 'Z') {
            correspondentCharacter = c + 32;
        }

        for (i = 0; i < tamanhoTexto; i++)
            if (correspondentCharacter == texto[i])
                qtdOcorrencias++;
    }

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    
    int indicePocisoes = 0;
    int tamanhoTexto = strlen(strTexto);
    int tamanhoBusca = strlen(strBusca);
    int contadorBuscaString = 0;

    int i;
    int j;
    int k;
    int qtdOcorrencias = 0;
    int contadorCaracterEspecial = 0;

    for (i = 0, j = 0, k = 0; k < tamanhoTexto; i++, j++) {
        
        if (!(strTexto[i] > 0 && strTexto[i] < 127)) {
            contadorBuscaString = 0;
            k++;
            i = k - 1;
            j = -1;
            contadorCaracterEspecial++;
            
        }

        if (strTexto[i] == strBusca[j]) {
            contadorBuscaString++;
            if (contadorBuscaString == tamanhoBusca) {
                posicoes[indicePocisoes] = k + 1 - contadorCaracterEspecial;
                posicoes[indicePocisoes + 1] = k + tamanhoBusca - contadorCaracterEspecial;
                indicePocisoes+=2;

                contadorBuscaString = 0;
                k++;
                i = k - 1;
                j = -1;
                qtdOcorrencias++;
            }
        }
        else {
            contadorBuscaString = 0;
            k++;
            i = k - 1;
            j = -1;
        }
    }
    

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
    int ultimoDigito;
    int reverso = 0;
    
    while (num > 0)
    {
        ultimoDigito = num % 10;
        reverso = (reverso * 10) + ultimoDigito;
        num = num / 10;
    }

    return reverso;
}

/*
 Q5 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias = 0;

    char numerobaseStr[11]; 
    sprintf(numerobaseStr,"%d", numerobase);
    int tamanhoBase = strlen(numerobaseStr);

    char numerobuscaStr[11]; 
    sprintf(numerobuscaStr,"%d", numerobusca);
    int tamanhoBusca = strlen(numerobuscaStr);
    
    int i;
    int j;
    int k;
    int contadorCaracterEspecial = 0;
    int contadorBuscaString = 0;

    for (i = 0, j = 0, k = 0; k < tamanhoBase; i++, j++) {

        if (numerobaseStr[i] == numerobuscaStr[j]) {
            contadorBuscaString++;
            if (contadorBuscaString == tamanhoBusca) {
                
                qtdOcorrencias++;

                contadorBuscaString = 0;
                k++;
                i = k - 1;
                j = -1;
            }
        }
        else {
            contadorBuscaString = 0;
            k++;
            i = k - 1;
            j = -1;
        }
    }
    

    return qtdOcorrencias;
}
