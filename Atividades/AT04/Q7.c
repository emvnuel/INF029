/*
7. Crie um programa que tenha uma função ler3Palavras. Essa função deve ler três palavras do
usuário e retornar as três palavras. A função main deve imprimir essas três palavras
*/

#include <stdio.h>
typedef struct Palavras {
    char palavra1[256];
    char palavra2[256];
    char palavra3[256];
} Palavras;

Palavras ler3Palavras();

int main(){

    Palavras palavras;
    palavras = ler3Palavras();

    printf("%s%s%s", palavras.palavra1, palavras.palavra2, palavras.palavra3);

    printf("\n");

    return 0;
}

Palavras ler3Palavras() {
	
    Palavras palavaras;

    printf("DIGITE A PRIMEIRA PALAVRA:\n");
    fgets(palavaras.palavra1, 256, stdin);

    printf("DIGITE A SEGUNDA PALAVRA:\n");
    fgets(palavaras.palavra2, 256, stdin);

    printf("DIGITE A TERCEIRA PALAVRA:\n");
    fgets(palavaras.palavra3, 256, stdin);

    printf("\n");

    return palavaras;
}